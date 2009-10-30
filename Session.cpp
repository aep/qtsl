#include "Session.hpp"
#include "RpcCallWriter.hpp"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QCryptographicHash>

#include <QCoreApplication>
#include <QDebug>

using namespace qomv;

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

    QByteArray buff;

    RpcCallWriter writer(&buff,"login_to_simulator");
    writer.writeBeginParams();
    writer.writeStringMember("mac","00:00:00:00:00:00");
    writer.writeStringMember("first",firstName);
    writer.writeStringMember("id0","00:00:00:00:00:00");
    writer.writeArrayMember("options",QStringList()
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
    writer.writeBooleanMember("read_critical",true);
    writer.writeStringMember("last",lastName);
    writer.writeStringMember("viewer_digest","");
    writer.writeStringMember("channel"," (OpenMetaverse)");
    writer.writeStringMember("version","IRCGateway");
    writer.writeStringMember("platform","Linux");
    writer.writeBooleanMember("agree_to_tos",true);
    writer.writeIntegerMember("last_exec_event",0);
    writer.writeStringMember("passwd","$1$"+QCryptographicHash::hash(password.toAscii(),QCryptographicHash::Md5).toHex());
    writer.writeStringMember("start","last");
    writer.writeEndParams();

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/xml");
    //    request.setHeader(QNetworkRequest::ContentLengthHeader,fifo->bytesAva);
    request.setRawHeader("Connection","close");
    request.setUrl(url);

    QNetworkReply * reply = http.post(request,buff);
    this->connect(reply,SIGNAL(finished()),SLOT(httpLoginFinished()));

}


void Session::httpLoginFinished(){
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    qDebug()<<reply;

    if(reply->error()==QNetworkReply::NoError){
        m_state=Connected;
        emit connected();
        qDebug("Connection successful: %s",reply->readAll().data());
    } else{
        m_state=Disconnected;
        emit disconnected(reply->error());
        qDebug("Connection not successful: %i",reply->error());
    }
    reply->deleteLater();
    qApp->quit();
}
