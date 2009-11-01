#include <QObject>
#include <QUdpSocket>

namespace qtsl{

    class Circuit : public QObject{
    Q_OBJECT
    public:
        enum DisconnectReason{
            NetworkError,
            Timeout
        };

        Circuit(QObject * parent=0);

        void connect(QString host,int port,QString circuit_code);

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
        QString circuit_code;
    };
};
