#ifndef QTSL_CHAT_H
#define QTSL_CHAT_H

#include "Session.hpp"
#include "UdpMessageHandlerInterface.hpp"

namespace qtsl{
    class Chat : public QObject, public UdpMessageHandlerInterface{
        Q_OBJECT;
    public:
        Chat(Session * session);

        struct SimulatorMessage{
            enum SenderType{
                AvatarSender,
                ObjectSender
            };
            enum ChatType{
                WhisperVolume=0,
                NormalVolume=1,
                ShoutVolume=2,
                SpeechVolume=3,
                StartTyping=4,
                StopTyping=5
            };
            SenderType senderType;
            QUuid source;
            ChatType chatType;
            QString message;
            QString fromName;
            QUuid owner;
            lltypes::LLVector3 position;
        };

    public slots:
        void sendSimulatorMessage(QString message, qtsl::Chat::SimulatorMessage::ChatType volume);
    signals:
        void simulatorMessage(const qtsl::Chat::SimulatorMessage & message);


    private slots:
        void d_teleportComplete(Simulator *  target);

    private:
        Simulator *  simulator;
        Session   *  session;
        virtual void udpMessageHandler(qtsl::udp::UdpMessage * message);

    };
};

#endif
