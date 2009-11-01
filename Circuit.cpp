#include "Circuit.hpp"

#include <QDebug>

using namespace qomv;

Circuit::Circuit(QObject * parent)
 :QObject(parent){
    QObject::connect(&socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    QObject::connect(&socket,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(socketStateChanged ( QAbstractSocket::SocketState)));
    QObject::connect(&socket,SIGNAL(error( QAbstractSocket::SocketError )),this,SLOT(socketError( QAbstractSocket::SocketError )));
}

void Circuit::connect(QString host,int port,QString circuit_code){
    this->host=host;
    this->port=port;
    this->circuit_code=circuit_code;
    socket.connectToHost(host,port);
}

void Circuit::socketReadyRead(){
    qDebug()<<"data:"<<socket.read(socket.pendingDatagramSize());
}

void Circuit::socketStateChanged ( QAbstractSocket::SocketState socketState){
    qDebug()<<socketState;
    if(socketState== QAbstractSocket::ConnectedState){
        socket.write("HILOL\n\n");
    }
}

void Circuit::socketError( QAbstractSocket::SocketError socketError ){
    qDebug()<<"err"<<socketError;
}

