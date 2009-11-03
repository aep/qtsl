#ifndef QTSL_SIMULATOR_H
#define QTSL_SIMULATOR_H

#include <QObject>
#include <QUdpSocket>
#include <QUuid>
#include <QMap>

#include "UdpMessageHandlerInterface.hpp"
#include "pkg/pkg.hpp"

namespace qtsl{
    class Session;
    class Simulator : public QObject{
        Q_OBJECT;
    public:
        enum DisconnectReason{
            NetworkError,
            Timeout
        };

        enum State{
            Disconnected,
            Connecting,
            Connected,
            Disconnecting
        };

        Simulator(Session * session);

        void connect(QString host,int port,quint32 circuit_code, QUuid session_id, QUuid agent_id);

        template <typename M>
        quint32 sendMessage(const M & message,bool reliable=false){
            QByteArray d;
            QDataStream s(&d,QIODevice::WriteOnly);
            if(M::byte==udp::Low){
                s<<(quint16)0xFFFF;
                s<<(quint16)M::id;
            }
            else if(M::byte==udp::Medium){
                s<<(quint16)0xFF;
                s<<(quint8)M::id;
            }
            else if(M::byte==udp::High){
                s<<(quint8)M::id;
            }
            else if(M::byte==udp::Fixed){
                s<<(quint32)M::id;
            }
            s<<message;
            return sendMessageData(d,reliable);
        }

        inline void registerReceiver(UdpMessageHandlerInterface * i){
            receivers.append(i);
        }
        inline void unregisterReceiver(UdpMessageHandlerInterface * i){
            receivers.removeOne(i);
        }

        inline quint32 circuitCode() const{
            return circuit_code;
        }

    signals:
        void connected();
        void disconnected(Simulator::DisconnectReason reason);

    private slots:
        void socketReadyRead();
        void socketError( QAbstractSocket::SocketError socketError );
        void socketStateChanged ( QAbstractSocket::SocketState socketState);
    private:
        State m_state;
        Session * session;
        QUdpSocket socket;
        QString host;
        QString port;
        quint32 circuit_code;
        QUuid session_id;
        QUuid agent_id;

        quint64 sequenceOut;

        struct QueuedMessage{
            QByteArray payload;
            quint8 iterationsStuck;
        };
        QMap <quint32,QueuedMessage*> queue;
        virtual void timerEvent ( QTimerEvent * event );
        int timerId;

        QList<UdpMessageHandlerInterface *> receivers;

        quint32 sendMessageData(const QByteArray & message,bool reliable=false, bool resent=false);
    };
};


#endif
