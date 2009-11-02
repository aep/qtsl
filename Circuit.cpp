#include "Circuit.hpp"
#include <QtEndian>
#include <QDebug>
#include <cassert>

using namespace qtsl;
using namespace udp;


QByteArray zeroDecode(QByteArray in){
    QByteArray ret;
    for(int i=0;i<in.length();i++){
        if((char)in[i]==0){
            char t=in[++i];
            while(t--){
                ret.append((char)0);
            }
        }else {
            ret.append(in[i]);
        }
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

    QByteArray d=socket.read(socket.pendingDatagramSize());

    MessageFlags f=(MessageFlags)*d.data();
    quint32 sequence=qFromBigEndian(*((quint32*)(d.data()+1)));
    quint8 extraheaderlen=*(d.data()+5);
    d=d.mid(6+extraheaderlen);


    if (f &  ReliableMessage){
        //TODO:  maybe should attach those to other messages instead
        PacketAckMessage m;
        PacketAckMessage::PacketsBlock b;
        b.ID=sequence;
        m.Packets<<b;
        sendMessage(m);
    }

    if (f &  AckAppendedMessage){
        quint8 acks=d[d.size()-1];
        quint32 n=d.size()-2;
        for(qint8 i=0;i<acks;i++){
            char x[4];
            x[3]=d[n--];
            x[2]=d[n--];
            x[1]=d[n--];
            x[0]=d[n--];
            quint32 id=qFromBigEndian(*(quint32*)x);
            delete  queue.take(id);
        }
        d=d.left(n+1);
    }

    if (f &  ZeroencodedMessage){
        d=zeroDecode(d);
    }
    UdpMessage * msg=qtsl::udp::fromBytes(d);
    assert(msg!=0);

    if(d.size())
        qDebug()<<"[Circuit] warning: "<<d.size()<<" bytes left after decoding message. "<<d.toHex();



    qDebug()<<"[Circuit]"<<qtsl::udp::typeName(msg->type);

    if(msg->type==PacketAckType){
        PacketAckMessage * ack=static_cast<PacketAckMessage *>(msg);
        for(int i=0;i<ack->Packets.size();i++){
            qDebug()<<"[Circuit] Ack "<<ack->Packets[i].ID;
            delete queue.take(ack->Packets[i].ID);
        }
    }else if(msg->type==StartPingCheckType){
        StartPingCheckMessage * ping=static_cast<StartPingCheckMessage *>(msg);
        CompletePingCheckMessage pong;
        pong.PingID.PingID=ping->PingID.PingID;
        sendMessage(pong);
    }else{
    }

    delete msg;

}

void Circuit::socketStateChanged ( QAbstractSocket::SocketState socketState){
    qDebug()<<"[Circuit] "<<socketState;
    if(socketState== QAbstractSocket::ConnectedState){
        UseCircuitCodeMessage m;
        m.CircuitCode.Code=this->circuit_code;
        m.CircuitCode.SessionID=this->session_id;
        m.CircuitCode.ID=this->agent_id;
        sendMessage(m,true);

        CompleteAgentMovementMessage c;
        c.AgentData.CircuitCode=this->circuit_code;
        c.AgentData.SessionID=this->session_id;
        c.AgentData.AgentID=this->agent_id;
        sendMessage(c,true);
    }
}

void Circuit::socketError( QAbstractSocket::SocketError socketError ){
    qDebug()<<"[Circuit] error connecting to  "<<this->host<<":"<<this->port<<"  "<<socketError;
}

void Circuit::sendMessageData(const QByteArray & message,bool reliable,uint resent){
    QByteArray d;
    QDataStream o(&d,QIODevice::WriteOnly);
    int flags=0;
    if(reliable ){
        flags |= ReliableMessage;
        QueuedMessage *m =new QueuedMessage();
        m->payload=message;
        m->iterationsStuck=resent;
        queue[this->sequenceOut]=m;
        if (resent!=0){
            flags |= ResentMessage;
        }
    }
    o<<(quint8)flags;
    o<<(quint32)this->sequenceOut++;
    o<<(quint8)0;  //extra
    d.append(message);
    socket.write(d);
}

void Circuit::timerEvent ( QTimerEvent * ){
    foreach(quint32 i,queue.keys()){
        if(queue[i]->iterationsStuck>10){
            qDebug("[Circuit] no ack in 10 seconds.   queue  is stuck <<<  ");
            killTimer(timerId);
            emit disconnected(Timeout);
        }
        sendMessageData(queue[i]->payload,true,queue[i]->iterationsStuck);
        delete queue.take(i);
    }
}
