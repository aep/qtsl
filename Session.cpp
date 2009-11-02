#include "Session.hpp"
#include <QxtXmlRpcCall>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QCryptographicHash>
#include <QStringList>
#include <QCoreApplication>
#include <QDebug>
#include "udp/pkg.hpp"

using namespace qtsl;

Session::Session(QObject * parent)
 :QObject(parent)
 ,m_state(Disconnected){

}


void Session::login(QUrl url, QString firstName, QString lastName, QString password ){

    if(m_state!=Disconnected){
        return;
    }
    m_state=Authenticating;

    this->url=url;
    this->firstName=firstName;
    this->lastName=lastName;
    this->password=password;

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


void Session::rpcRequestFinished(){
    QxtXmlRpcCall* reply = qobject_cast<QxtXmlRpcCall*>(sender());

    if(reply->error()==QNetworkReply::NoError){
        QVariantMap r=reply->result().toMap();

        if(r["login"].toString()=="false"){
            m_state=Disconnected;

            if((r["reason"].toString()=="presence") && (--authRetryLeft>0)){
                int authRetryLeft_=authRetryLeft;
                qDebug("[LOGIN] server claims we are logged in,  try one more time");
                login(this->url, this->firstName, this->lastName, this->password );
                authRetryLeft=authRetryLeft_; //login resets it
            } else {
                emit disconnected(QNetworkReply::ProxyAuthenticationRequiredError);
                qDebug("[LOGIN] %s",qPrintable(r["message"].toString()));
            }
        } else {
            qDebug("[LOGIN] success");
            session_id=r["session_id"].toString();
            agent_id=r["agent_id"].toString();
            caps["seed_capability"]=r["seed_capability"].toString();

            m_state=ConnectingCircuit;
            circuit.connect(r["sim_ip"].toString(),r["sim_port"].toInt(),r["circuit_code"].toUInt(),r["session_id"].toString(),r["agent_id"].toString());
        }

    } else{
        m_state=Disconnected;
        emit disconnected(reply->error());
        qDebug("Connection not successful: %i",reply->error());
    }
    reply->deleteLater();
}
