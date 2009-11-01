#include "udp/pkg.hpp"
#include "Circuit.hpp"
#include <QDebug>

using namespace qtsl;
using namespace udp;

Circuit::Circuit(QObject * parent)
 :QObject(parent){
    QObject::connect(&socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    QObject::connect(&socket,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(socketStateChanged ( QAbstractSocket::SocketState)));
    QObject::connect(&socket,SIGNAL(error( QAbstractSocket::SocketError )),this,SLOT(socketError( QAbstractSocket::SocketError )));
}

void Circuit::connect(QString host,int port,quint32 circuit_code,QUuid session_id){
    this->host=host;
    this->port=port;
    this->circuit_code=circuit_code;
    this->session_id=session_id;
    socket.connectToHost(host,port);
}

void Circuit::socketReadyRead(){
    qDebug()<<"data:"<<socket.read(socket.pendingDatagramSize());
}

void Circuit::socketStateChanged ( QAbstractSocket::SocketState socketState){
    qDebug()<<"[Circuit] "<<socketState;
    if(socketState== QAbstractSocket::ConnectedState){
        UseCircuitCodeMessage m;
        m.CircuitCode.Code=this->circuit_code;
        m.CircuitCode.SessionID=this->session_id;
        m.CircuitCode.ID=this->session_id;
        sendMessage(m,ReliableMessage);
    }
}

void Circuit::socketError( QAbstractSocket::SocketError socketError ){
    qDebug()<<"[Circuit] error connecting to  "<<this->host<<":"<<this->port<<"  "<<socketError;
}


void Circuit::sendMessageData(const QByteArray & message,MessageFlags flags){
    QByteArray d;
    QDataStream o(&d,QIODevice::WriteOnly);
    o<<(quint8)flags;
    o<<(quint32)1; //seq
    o<<(quint8)0;  //extra
    d.append(message);
    socket.write(d);
}
