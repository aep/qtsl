#include "Session.hpp"
#include <QHash>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QCryptographicHash>
#include <QStringList>
#include <QCoreApplication>
#include <QxtXmlRpcClient>
#include <QxtXmlRpcCall>
#include "Simulator.hpp"
#include "pkg/pkg.hpp"

using namespace qtsl;


struct Session::Private{
    Private(Session *s)
        :pub(s)
        ,m_state(Disconnected){
    }
    ~Private(){
    }

    Session * pub;

    SessionState m_state;

    //login parameters
    QUrl d_url;
    QString d_firstName;
    QString d_lastName;
    QString d_password;

    //session parameters
    QUuid d_session_id;
    QUuid d_agent_id;
    QUuid d_inventory_root;

    //xmlrpc
    int authRetryLeft;
    QxtXmlRpcClient rpc;

    //caps
    QMap<QString,QUrl> caps;

    void d_rpcRequestFinished();
    void d_simulatorDisconnected(Simulator::DisconnectReason reason);
    void d_simulatorConnected();

};


Session::SessionState Session::state() const{
    return d->m_state;
}
QUuid Session::sessionId() const{
    return d->d_session_id;
}
QUuid Session::agentId() const{
    return d->d_agent_id;
}
QUuid Session::inventoryRoot() const{
    return d->d_inventory_root;
}


Session::Session(QObject * parent)
 :QObject(parent)
 ,simCurrent(0)
 ,simNorth(0)
 ,simSouth(0)
 ,simEast(0)
 ,simWest(0)
 ,simNorthEast(0)
 ,simNorthWest(0)
 ,simSouthEast(0)
 ,simSouthWest(0)
 ,simTarget(0)
 ,d(new Private(this)){
}

Session::~Session(){
    if(simCurrent)
        simCurrent->deleteLater();
    if(simNorth)
        simNorth->deleteLater();
    if(simSouth)
        simSouth->deleteLater();
    if(simWest)
        simWest->deleteLater();
    if(simNorthEast)
        simNorthEast->deleteLater();
    if(simNorthWest)
        simNorthWest->deleteLater();
    if(simSouthEast)
        simSouthEast->deleteLater();
    if(simSouthWest)
        simSouthWest->deleteLater();
}

void Session::login(QUrl url, QString firstName, QString lastName, QString password ){

    if(d->m_state!=Disconnected){
        return;
    }
    d->m_state=Authenticating;

    d->d_url=url;
    d->d_firstName=firstName;
    d->d_lastName=lastName;
    d->d_password=password;

    d->rpc.setServiceUrl(url);

    d->authRetryLeft=2;

    QVariantMap st;
    st["mac"]="00:00:00:00:00:00";
    st["first"]=firstName;
    st["id0"]="00:00:00:00:00:00";
    st["options"]=(QStringList()
                   <<"inventory-root"
                   <<"inventory-skeleton"
                   <<"inventory-lib-root"
                   <<"inventory-lib-owner"
                   <<"inventory-skel-lib"
                   <<"initial-outfit"
                   <<"gestures"
                   <<"event_categories"
                   <<"event_notifications"
                   <<"classified_categories"
                   <<"buddy-list"
                   <<"ui-config"
                   <<"tutorial_settings"
                   <<"login-flags"
                   <<"global-textures"
                   );
    st["read_critical"]=true;
    st["last"]=lastName;
    st["viewer_digest"]="";
    st["channel"]=" (OpenMetaverse)";
    st["version"]="IRCGateway";
    st["platform"]="Linux";
    st["agree_to_tos"]=true;
    st["last_exec_event"]=0;
    st["passwd"]=QString::fromAscii("$1$"+QCryptographicHash::hash(password.toAscii(),QCryptographicHash::Md5).toHex());
    st["start"]="last";

    QxtXmlRpcCall * response= d->rpc.call("login_to_simulator",(QVariantList()<<st));
    this->connect(response,SIGNAL(finished()),SLOT(d_rpcRequestFinished()));
}

void Session::logout(){
    //TODO
}

void Session::Private::d_rpcRequestFinished(){
    QxtXmlRpcCall* reply = qobject_cast<QxtXmlRpcCall*>(pub->sender());

    if(m_state==Authenticating){
        if(reply->error()==QNetworkReply::NoError){
            QVariantMap r=reply->result().toMap();

            if(r["login"].toString()=="false"){
                m_state=Disconnected;

                if((r["reason"].toString()=="presence") && (--authRetryLeft>0)){
                    int authRetryLeft_=authRetryLeft;
                    qDebug("[LOGIN] server claims we are logged in,  try one more time");
                    pub->login(this->d_url, this->d_firstName, this->d_lastName, this->d_password );
                    authRetryLeft=authRetryLeft_; //login resets it
                } else {
                    emit pub->disconnected(AuthenticationFailed);
                    qDebug("[LOGIN] %s",qPrintable(r["message"].toString()));
                }
            } else {
                qDebug("[LOGIN] success");
                d_session_id=r["session_id"].toString();
                d_agent_id=r["agent_id"].toString();
                QVariantList inventoryrootl =r["inventory-root"].toList();
                if(inventoryrootl.count()){
                    d_inventory_root=inventoryrootl[0].toMap()["folder_id"].toString();
                }else {
                    qWarning("[Login] got no inventory root");
                }

                caps["seed_capability"]=r["seed_capability"].toString();

                m_state=Teleporting;
                pub->simTarget=new Simulator(pub);
                connect(pub->simTarget,SIGNAL(disconnected(Simulator::DisconnectReason)),pub,SLOT(d_simulatorDisconnected(Simulator::DisconnectReason )));
                connect(pub->simTarget,SIGNAL(connected()),pub,SLOT(d_simulatorConnected()));
                emit pub->teleporting(pub->simTarget);
                pub->simTarget->connect(r["sim_ip"].toString(),r["sim_port"].toInt(),r["circuit_code"].toUInt(),r["session_id"].toString(),r["agent_id"].toString());
            }

        } else{
            m_state=Disconnected;
            emit pub->disconnected(NetworkError);
            qDebug("Connection not successful: %i",reply->error());
        }
        reply->deleteLater();
    } else {
        qWarning("[Session] rpc response, but i didn't ask for any. bug?");
    }
}



void Session::Private::d_simulatorDisconnected(Simulator::DisconnectReason reason){
    Simulator * sim=qobject_cast<Simulator*>(pub->sender());
    if(sim==pub->simCurrent){
        qCritical("[Session] Current sim disconnected. Should propably teleport or something. For now i'm going to disconnect the session.");
        emit pub->disconnected(NetworkError);
        pub->simCurrent->deleteLater();
        pub->simCurrent=0;
    }else if(sim==pub->simTarget){
        qWarning("[Session] Teleport failed");
        emit pub->teleportFailed(sim,reason);
        if(pub->simCurrent==0){
            m_state=Disconnected;
            emit pub->disconnected(InitialTeleportFailed);
        }
        delete sim;
    } else {
        qWarning("[Session] Some surrounding sim disconnected. Should i reconnect? For now doing nothing.");
    }
}

void Session::Private::d_simulatorConnected(){
    Simulator * sim=qobject_cast<Simulator*>(pub->sender());
    if(sim==pub->simTarget || m_state==Teleporting){

        //TODO: whats with the other regions?
        if(pub->simCurrent){
            pub->simCurrent->deleteLater();
            pub->simCurrent=0;
        }
        pub->simCurrent=pub->simTarget;
        pub->simTarget=0;
        emit pub->teleportComplete(pub->simCurrent);
    } else {
    }
}





#include "moc_Session.cpp"

