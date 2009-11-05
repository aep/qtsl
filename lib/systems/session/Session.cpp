#include "Session.hpp"
#include <QxtXmlRpcCall>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QCryptographicHash>
#include <QStringList>
#include <QCoreApplication>

#include "Simulator.hpp"
#include "pkg/pkg.hpp"

using namespace qtsl;

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
 ,m_state(Disconnected){
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

    if(m_state!=Disconnected){
        return;
    }
    m_state=Authenticating;

    this->d_url=url;
    this->d_firstName=firstName;
    this->d_lastName=lastName;
    this->d_password=password;

    rpc.setServiceUrl(url);

    this->authRetryLeft=2;

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

    QxtXmlRpcCall * response= rpc.call("login_to_simulator",(QVariantList()<<st));
    this->connect(response,SIGNAL(finished()),SLOT(rpcRequestFinished()));
}

void Session::logout(){
    //TODO
}

void Session::rpcRequestFinished(){
    QxtXmlRpcCall* reply = qobject_cast<QxtXmlRpcCall*>(sender());

    if(m_state==Authenticating){
        if(reply->error()==QNetworkReply::NoError){
            QVariantMap r=reply->result().toMap();

            if(r["login"].toString()=="false"){
                m_state=Disconnected;

                if((r["reason"].toString()=="presence") && (--authRetryLeft>0)){
                    int authRetryLeft_=authRetryLeft;
                    qDebug("[LOGIN] server claims we are logged in,  try one more time");
                    login(this->d_url, this->d_firstName, this->d_lastName, this->d_password );
                    authRetryLeft=authRetryLeft_; //login resets it
                } else {
                    emit disconnected(AuthenticationFailed);
                    qDebug("[LOGIN] %s",qPrintable(r["message"].toString()));
                }
            } else {
                qDebug("[LOGIN] success");
                d_session_id=r["session_id"].toString();
                d_agent_id=r["agent_id"].toString();
                d_inventory_root=r["inventory-root"].toMap()["folder_id"].toString();

                caps["seed_capability"]=r["seed_capability"].toString();

                m_state=Teleporting;
                simTarget=new Simulator(this);
                connect(simTarget,SIGNAL(disconnected(Simulator::DisconnectReason)),this,SLOT(simulatorDisconnected(Simulator::DisconnectReason )));
                connect(simTarget,SIGNAL(connected()),this,SLOT(simulatorConnected()));
                emit teleporting(simTarget);
                simTarget->connect(r["sim_ip"].toString(),r["sim_port"].toInt(),r["circuit_code"].toUInt(),r["session_id"].toString(),r["agent_id"].toString());
            }

        } else{
            m_state=Disconnected;
            emit disconnected(NetworkError);
            qDebug("Connection not successful: %i",reply->error());
        }
        reply->deleteLater();
    } else {
        qWarning("[Session] rpc response, but i didn't ask for any. bug?");
    }
}



void Session::simulatorDisconnected(Simulator::DisconnectReason reason){
    Simulator * sim=qobject_cast<Simulator*>(sender());
    if(sim==simCurrent){
        qCritical("[Session] Current sim disconnected. Should propably teleport or something. For now i'm going to disconnect the session.");
        emit disconnected(NetworkError);
        simCurrent->deleteLater();
        simCurrent=0;
    }else if(sim==simTarget){
        qWarning("[Session] Teleport failed");
        emit teleportFailed(sim,reason);
        if(simCurrent==0){
            m_state=Disconnected;
            emit disconnected(InitialTeleportFailed);
        }
        delete sim;
    } else {
        qWarning("[Session] Some surrounding sim disconnected. Should i reconnect? For now doing nothing.");
    }
}

void Session::simulatorConnected(){
    Simulator * sim=qobject_cast<Simulator*>(sender());
    if(sim==simTarget || m_state==Teleporting){

        //TODO: whats with the other regions?
        if(simCurrent){
            simCurrent->deleteLater();
            simCurrent=0;
        }
        simCurrent=simTarget;
        simTarget=0;
        emit teleportComplete(simCurrent);
    } else {
    }
}

