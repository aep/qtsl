#include <QApplication>
#include <QTreeView>
#include "Session.hpp"
#include "Avatar.hpp"
#include "Inventory.hpp"
#include <QSortFilterProxyModel>
#include <QFileIconProvider>


class IconInventory : public qtsl::Inventory{
public:
    IconInventory(qtsl::Session & session)
        :Inventory(session){
    }
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const{
        if(!index.isValid())
            return QVariant();
        if(role==Qt::DecorationRole){
            if(qtsl::Inventory::data(index,Qt::UserRole+1).toBool()){
                if(qtsl::Inventory::data(index,Qt::UserRole+2).toInt()<2){
                    return provider.icon(QFileIconProvider::Network);
                }else{
                    return provider.icon(QFileIconProvider::Folder);
                }
            }else{
                return provider.icon(QFileIconProvider::File);
            }
        }else{
            return qtsl::Inventory::data(index,role);
        }
    }
private:
    QFileIconProvider provider;

};



int main (int argc, char ** argv){
    if(argc<5){
        qDebug("usage: ./inventory http://slserver:9000/ First Last Secret");
        return 2;
    }
    QApplication app(argc,argv);


    qtsl::Session session;
    qtsl::Avatar avatar(&session);
    IconInventory inventory(session);

    session.login(QUrl(argv[1]),argv[2],argv[3],argv[4]);

    QTreeView view;
    view.setModel(&inventory);
    view.show();



    return app.exec();
}



