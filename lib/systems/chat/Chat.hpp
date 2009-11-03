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
            enum Volume{
                WhisperVolume,
                NormalVolume,
                ShoutVolume,
                SpeechVolume
            };
            SenderType senderType;
            QUuid source;
            Volume volume;
            QString message;
            QString fromName;
            QUuid owner;
            lltypes::LLVector3 position;
        };

    public slots:
        void sendSimulatorMessage(QString message, SimulatorMessage::Volume volume=SimulatorMessage::NormalVolume);
    signals:
        void simulatorMessage(const SimulatorMessage & message);


    private slots:
        void d_teleportComplete(Simulator *  target);

    private:
        Simulator *  simulator;
        Session   *  session;
        virtual void udpMessageHandler(qtsl::udp::UdpMessage * message);

    };
};

#endif
