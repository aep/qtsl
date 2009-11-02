#include "Circuit.hpp"
#include <QtEndian>
#include <QDebug>

using namespace qtsl;
using namespace udp;


QByteArray zeroDecode(QByteArray in){
    QByteArray ret;
    for(int i=0;i<in.length();i++){
        if((char)in[i]==0){
            char t=in[i+1];
            while(t--){
                ret.append((char)0);
            }
        }
        ret.append(in[i]);
    }
    return ret;
}

Circuit::Circuit(QObject * parent)
    :QObject(parent){
    QObject::connect(&socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    QObject::connect(&socket,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(socketStateChanged ( QAbstractSocket::SocketState)));
    QObject::connect(&socket,SIGNAL(error( QAbstractSocket::SocketError )),this,SLOT(socketError( QAbstractSocket::SocketError )));
}

void Circuit::connect(QString host,int port,quint32 circuit_code,QUuid session_id,QUuid agent_id){
    this->host=host;
    this->port=port;
    this->circuit_code=circuit_code;
    this->session_id=session_id;
    this->agent_id=agent_id;
    this->sequenceOut=1;
    socket.connectToHost(host,port);
    timerId=startTimer(1000);
}

void Circuit::socketReadyRead(){
    qDebug()<<"[Circuit] Incomming Message with size "<<socket.pendingDatagramSize();

    QByteArray d=socket.read(socket.pendingDatagramSize());

    MessageFlags f=(MessageFlags)*d.data();
    quint32 sequence=*((quint32*)(d.data()+1));
    quint8 extraheaderlen=*(d.data()+5);
    d=d.mid(6+extraheaderlen);

    if (f &  ZeroencodedMessage){
        d=zeroDecode(d);
    }
    if (f &  ReliableMessage){
        //TODO:  maybe should attach those to other messages instead
        PacketAckMessage m;
        PacketAckMessage::PacketsBlock b;
        b.ID=sequence;
        m.Packets<<b;
        sendMessage(m,NoMessageFlags);
    }

    quint8  * data8 =(quint8 *)d.data();
    quint16 * data16=(quint16*)data8;
    quint32 * data32=(quint32*)data8;

    if(qFromBigEndian(data32[0])==PacketAckMessage::id){
        PacketAckMessage ack;
        d=d.mid(4);
        QDataStream s(&d,QIODevice::ReadOnly);
        s>>ack;
        for(int i=0;i<ack.Packets.size();i++){
            qDebug()<<"[Circuit] Ack " <<ack.Packets[i].ID;
            delete queue.take(ack.Packets[i].ID);
        }
    } else {

        if (data8[0]==255){
            if (data8[1]==255){
                if (data8[2]==255){
                    qDebug()<<"[Circuit] Fixed"<<qFromBigEndian(data32[0]);
                }else{
                    qDebug()<<"[Circuit] Low"<<data16[1];
                }
            }else{
                qDebug()<<"[Circuit] Medium"<<data8[1];
            }
        }else{
            qDebug()<<"[Circuit] High"<<data8[0];
        }
    }
}

void Circuit::socketStateChanged ( QAbstractSocket::SocketState socketState){
    qDebug()<<"[Circuit] "<<socketState;
    if(socketState== QAbstractSocket::ConnectedState){
        UseCircuitCodeMessage m;
        m.CircuitCode.Code=this->circuit_code;
        m.CircuitCode.SessionID=this->session_id;
        m.CircuitCode.ID=this->agent_id;
        sendMessage(m,ReliableMessage);
    }
}

void Circuit::socketError( QAbstractSocket::SocketError socketError ){
    qDebug()<<"[Circuit] error connecting to  "<<this->host<<":"<<this->port<<"  "<<socketError;
}

void Circuit::sendMessageData(const QByteArray & message,bool reliable,quint32 resendSeq){
    QByteArray d;
    QDataStream o(&d,QIODevice::WriteOnly);
    int flags=0;
    if(reliable && (resendSeq==0)){
        flags |= ReliableMessage;
        QueuedMessage *q=new QueuedMessage();
        q->payload=message;
        q->iterationsStuck=0;
        queue[this->sequenceOut]=q;
    }
    if(resendSeq){
        flags |= ResentMessage;
    }
    o<<(quint8)flags;

    if(resendSeq){
        o<<resendSeq;
    }else {
        o<<(quint32)this->sequenceOut++;
    }
    o<<(quint8)0;  //extra
    d.append(message);
    socket.write(d);
}

void Circuit::timerEvent ( QTimerEvent * ){
    foreach(quint32 i,queue.keys()){
        queue[i]->iterationsStuck+=1;
        if(queue[i]->iterationsStuck>10){
            qDebug()<<"[Circuit] queue stuck";
            killTimer(timerId);
            emit disconnected(Timeout);
        }
        sendMessageData(queue[i]->payload,true,i);
    }
}
