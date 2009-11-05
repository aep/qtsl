#include "Inventory.hpp"
#include "pkg/pkg.hpp"

#include <QPersistentModelIndex>

using namespace qtsl;


struct Inventory::InventoryItem{
    InventoryItem(InventoryItem * p=0)
        :fetched(0)
        ,parent(p)
        ,isfolder(true){
        }
    QUuid id;
    QString name;
    QList<InventoryItem *> children;
    int fetched;
    InventoryItem * parent;
    bool isfolder;
};


Inventory::Inventory(Session & s)
    :QAbstractItemModel()
    ,UdpMessageHandlerInterface()
    ,simulator(0)
    ,session(s)
    ,root(new InventoryItem()){

    if(session.state()==Session::Connected){
        d_teleportComplete(session.simCurrent);
    }
    connect(&session,SIGNAL(teleportComplete(Simulator*)),this,SLOT(d_teleportComplete(Simulator*)));
}

Inventory::~Inventory(){
    delete root;
    qDeleteAll(items.values());
}


void Inventory::d_teleportComplete(Simulator *  target){

    if(simulator){
        simulator->unregisterReceiver(this);
        simulator=target;
        if(simulator)
            simulator->registerReceiver(this);
    }else{
        simulator=target;
        if(simulator)
            simulator->registerReceiver(this);
        /**
           first time!
           or should i clear the inventory on every teleport?  Whats with hypergrid and shit like that?
        */
        root->id=session.inventoryRoot();
        root->fetched=1;
        udp::FetchInventoryDescendentsMessage msg;
        msg.AgentData.AgentID=session.agentId();
        msg.AgentData.SessionID=session.sessionId();
        msg.InventoryData.FolderID=session.inventoryRoot();
        msg.InventoryData.OwnerID=session.agentId();
        msg.InventoryData.SortOrder=0;
        msg.InventoryData.FetchFolders=true;
        msg.InventoryData.FetchItems=true;

        simulator->sendMessage(msg,true);
    }

}


QModelIndex Inventory::index ( int row, int column, const QModelIndex & parent) const{
    if(column!=0)
        return QModelIndex();
    if(row<0){
        return QModelIndex();
    }

    InventoryItem * p;
    if(parent.isValid())
        p =static_cast<InventoryItem*>(parent.internalPointer());
    else
        p=root;

    if(p->fetched>1){
        if(p->children.count()>row){
            QModelIndex i=createIndex(row,column,p->children.at(row));
            const_cast<Inventory*>(this)->fetchMore(i);
            return i;
        }else{
            return QModelIndex();
        }
    }else{
        const_cast<Inventory*>(this)->fetchMore(parent);
        return QModelIndex();
    }
}

QModelIndex Inventory::parent ( const QModelIndex & index ) const{
    if(!index.isValid())
        return QModelIndex();
    InventoryItem * i = static_cast<InventoryItem*>(index.internalPointer());
    if(i==root){
        qFatal("[Inventory] fatal corruption. (whatever the fsk happened)");
    }
    if(i->parent==root)
        return QModelIndex();
    return createIndex(i->parent->parent->children.indexOf(i->parent),0,i->parent);

}
int Inventory::rowCount ( const QModelIndex & parent) const{
    InventoryItem * p;
    if(parent.isValid())
        p =static_cast<InventoryItem*>(parent.internalPointer());
    else
        p=root;
    return p->children.count();
}
int Inventory::columnCount ( const QModelIndex &  ) const{
    return 1;
}

QVariant  Inventory::headerData ( int section, Qt::Orientation orientation, int role  ) const{
    if (orientation!=Qt::Horizontal)
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    if(section==0)
        return "Name";

    return QVariant();
}

QVariant Inventory::data ( const QModelIndex & parent, int role ) const{

    InventoryItem * p;
    if(parent.isValid())
        p =static_cast<InventoryItem*>(parent.internalPointer());
    else
        p=root;


    if(role== Qt::DisplayRole){
        return p->name;
    }else if (role== Qt::UserRole+1){
        return p->isfolder;
    }else if (role== Qt::UserRole+2){
        return p->fetched;
    }else if (role== Qt::UserRole+3){
        return p->id.toString();
    }

    return QVariant();



}
bool Inventory::canFetchMore ( const QModelIndex & parent ) const{
    InventoryItem * p;
    if(parent.isValid())
        p =static_cast<InventoryItem*>(parent.internalPointer());
    else
        p=root;
    return (p->isfolder && p->fetched!=2);
}



void Inventory::fetchMore ( const QModelIndex & parent ){
    if(!simulator)
        return;

    InventoryItem * p;
    if(parent.isValid())
        p =static_cast<InventoryItem*>(parent.internalPointer());
    else
        p=root;

    if(p->fetched || !p->isfolder)
        return;

    udp::FetchInventoryDescendentsMessage msg;
    msg.AgentData.AgentID=session.agentId();
    msg.AgentData.SessionID=session.sessionId();
    msg.InventoryData.FolderID=p->id;
    msg.InventoryData.OwnerID=session.agentId();
    msg.InventoryData.SortOrder=0;
    msg.InventoryData.FetchFolders=true;
    msg.InventoryData.FetchItems=true;

    simulator->sendMessage(msg,true);
    p->fetched=1;
}





void Inventory::udpMessageHandler(qtsl::udp::UdpMessage * m){
    if(m->type==udp::InventoryDescendentsType){
        udp::InventoryDescendentsMessage * message= static_cast<udp::InventoryDescendentsMessage *>(m);

        InventoryItem * parent= items[message->AgentData.FolderID];
        if(!parent){
            parent=root;
        }

        parent->fetched=2;

        QModelIndex ii;
        if(parent->parent)
            ii=createIndex(parent->parent->children.indexOf(parent),0,parent);
        beginInsertRows ( ii
                          ,parent->children.count()
                          ,parent->children.count()+message->FolderData.count()+ message->ItemData.count()
                          );


        for(int i=0;i<message->FolderData.count();i++){
            if(message->FolderData[i].FolderID.isNull())
                continue;
            if(items[message->FolderData[i].FolderID]){
                qDebug()<<"[Inventory] fixme: dup";
                continue;
            }
            InventoryItem * item=new InventoryItem(parent);
            item->id=message->FolderData[i].FolderID;
            item->name=QString::fromUtf8(message->FolderData[i].Name.data);
            items[item->id]=item;
            parent->children.append(item);
        }

        for(int i=0;i<message->ItemData.count();i++){
            if(message->ItemData[i].ItemID.isNull())
                continue;
            if(items[message->ItemData[i].ItemID]){
                qDebug()<<"[Inventory] fixme: dup";
                continue;
            }
            InventoryItem * item=new InventoryItem(parent);
            item->id=message->ItemData[i].ItemID;
            item->name=QString::fromUtf8(message->ItemData[i].Name.data);
            item->isfolder=false;
            items[item->id]=item;
            parent->children.append(item);
        }

        endInsertRows();
        dataChanged(ii,ii);
    }
}





