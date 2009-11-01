#ifndef QTSL_CIRCUIT_H
#define QTSL_CIRCUIT_H

#include <QObject>
#include <QUdpSocket>
#include <QUuid>

namespace qtsl{
    namespace udp{
        struct UdpMessage;

        #ifndef QTSL_UDP_PKG_H
        enum IdByte{
            Low,
            High,
            Medium,
            Fixed
        };
        #endif
    };

    enum MessageFlags{
        NoMessageFlags = 0x0,
        AckAppendedMessage = 0x10,
        ResentMessage =0x20,
        ReliableMessage = 0x40,
        ZeroencodedMessage = 0x80
    };

    class Circuit : public QObject{
    Q_OBJECT
    public:
        enum DisconnectReason{
            NetworkError,
            Timeout
        };

        Circuit(QObject * parent=0);

        void connect(QString host,int port,quint32 circuit_code, QUuid session_id);


        template <typename M>
        void sendMessage(const M & message,MessageFlags flags){
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
            sendMessageData(d,flags);
        }

        void sendMessageData(const QByteArray & message,MessageFlags flags);

    signals:
        void connected();
        void disconnected(DisconnectReason);

    private slots:
        void socketReadyRead();
        void socketError( QAbstractSocket::SocketError socketError );
        void socketStateChanged ( QAbstractSocket::SocketState socketState);
    private:
        QUdpSocket socket;
        QString host;
        QString port;
        quint32 circuit_code;
        QUuid session_id;
    };
};


#endif
