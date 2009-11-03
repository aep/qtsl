#include "Simulator.hpp"
#include <QtEndian>
#include <QDebug>
#include <cassert>

using namespace qtsl;
using namespace udp;

enum MessageFlags{
    NoMessageFlags = 0x0,
    AckAppendedMessage = 0x10,
    ResentMessage =0x20,
    ReliableMessage = 0x40,
    ZeroencodedMessage = 0x80
};

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

Simulator::Simulator(Session * s)
    :QObject()
    ,m_state(Disconnected)
    ,session(s){
    QObject::connect(&socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
    QObject::connect(&socket,SIGNAL(stateChanged ( QAbstractSocket::SocketState)),this,SLOT(socketStateChanged ( QAbstractSocket::SocketState)));
    QObject::connect(&socket,SIGNAL(error( QAbstractSocket::SocketError )),this,SLOT(socketError( QAbstractSocket::SocketError )));
}

void Simulator::connect(QString host,int port,quint32 circuit_code,QUuid session_id,QUuid agent_id){
    this->host=host;
    this->port=port;
    this->circuit_code=circuit_code;
    this->session_id=session_id;
    this->agent_id=agent_id;
    this->sequenceOut=1;
    m_state=Connecting;
    socket.connectToHost(host,port);
    timerId=startTimer(1000);
}

void Simulator::socketReadyRead(){
    QByteArray d=socket.read(socket.pendingDatagramSize());

    if(m_state==Connecting){
        m_state=Connected;
        emit connected();
    }

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
        foreach(UdpMessageHandlerInterface * i,receivers)
            i->udpMessageHandler(msg);
    }

    delete msg;

}

void Simulator::socketStateChanged ( QAbstractSocket::SocketState socketState){
    if(socketState== QAbstractSocket::ConnectedState && m_state==Connecting ){
        UseCircuitCodeMessage m;
        m.CircuitCode.Code=this->circuit_code;
        m.CircuitCode.SessionID=this->session_id;
        m.CircuitCode.ID=this->agent_id;
        sendMessage(m,true);
    }else if(socketState== QAbstractSocket::UnconnectedState){
        if (m_state!=Disconnecting){
            emit disconnected(NetworkError);
        }
    }
}

void Simulator::socketError( QAbstractSocket::SocketError socketError ){
    qDebug()<<"[Circuit] error connecting to  "<<this->host<<":"<<this->port<<"  "<<socketError;
}

quint32 Simulator::sendMessageData(const QByteArray & message,bool reliable,bool resent){
    QByteArray d;
    QDataStream o(&d,QIODevice::WriteOnly);
    int flags=0;
    if(reliable && !resent){
        flags |= ReliableMessage;
        QueuedMessage *m =new QueuedMessage();
        m->payload=message;
        m->iterationsStuck=0;
        queue[this->sequenceOut]=m;
    }
    if (resent){
        flags |= ReliableMessage;
        flags |= ResentMessage;
    }
    o<<(quint8)flags;
    o<<(quint32)this->sequenceOut;
    o<<(quint8)0;  //extra
    d.append(message);
    socket.write(d);
    return this->sequenceOut++;
}

void Simulator::timerEvent ( QTimerEvent * ){
    foreach(quint32 i,queue.keys()){
        if(queue[i]->iterationsStuck>10){
            qDebug("[Circuit] no ack in 10 seconds.   queue  is stuck <<<  ");
            killTimer(timerId);
            m_state=Disconnected;
            emit disconnected(Timeout);
        }
        queue[i]->iterationsStuck++;
        queue[sendMessageData(queue[i]->payload,true,true)]=queue.take(i);
    }
}
