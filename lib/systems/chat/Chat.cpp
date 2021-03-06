#include "Chat.hpp"
#include "pkg/pkg.hpp"

using namespace qtsl;

Chat::Chat(Session & s)
    :QObject()
    ,UdpMessageHandlerInterface()
    ,simulator(0)
    ,session(s){
    connect(&session,SIGNAL(teleportComplete(Simulator*)),this,SLOT(d_teleportComplete(Simulator*)));
}


void Chat::sendSimulatorMessage(QString message, SimulatorMessage::ChatType chattype){
    if(!simulator)
        return;
    udp::ChatFromViewerMessage msg;
    msg.AgentData.AgentID=session.agentId();
    msg.AgentData.SessionID=session.sessionId();
    msg.ChatData.Type=chattype;
    msg.ChatData.Channel=0;
    msg.ChatData.Message.data=(message.toUtf8());
    simulator->sendMessage(msg);
}

void Chat::d_teleportComplete(Simulator *  target){
    if(simulator)
        simulator->unregisterReceiver(this);
    simulator=target;
    if(simulator)
        simulator->registerReceiver(this);
}

void Chat::udpMessageHandler(qtsl::udp::UdpMessage * m){
    if(m->type==udp::ChatFromSimulatorType){
        udp::ChatFromSimulatorMessage * message= static_cast<udp::ChatFromSimulatorMessage *>(m);
        SimulatorMessage msg;


        qDebug()<<"[Chat] SourceType was"<<message->ChatData.SourceType;
        msg.senderType=SimulatorMessage::AvatarSender;

        if(message->ChatData.ChatType <= 5){
            msg.chatType=(SimulatorMessage::ChatType)message->ChatData.ChatType;
        }else{
            qDebug()<<"[Chat] FIXME ChatType was out of bounds: "<<message->ChatData.ChatType;
            msg.chatType=SimulatorMessage::NormalVolume;
        }

        msg.source=message->ChatData.SourceID;
        msg.owner=message->ChatData.OwnerID;
        msg.message=QString::fromUtf8(message->ChatData.Message.data);
        msg.fromName=QString::fromUtf8(message->ChatData.FromName.data);
        msg.position=message->ChatData.Position;
        emit simulatorMessage(msg);
    }
}



