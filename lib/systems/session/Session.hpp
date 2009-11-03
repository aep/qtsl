#ifndef QOMV_SESSION_H
#define QOMV_SESSION_H

#include <QObject>
#include <QUrl>
#include <QHash>
#include <QxtXmlRpcClient>
#include <QNetworkReply>
#include "Simulator.hpp"

namespace qtsl{
    class Session : public QObject{
        Q_OBJECT;
    public:
        Session(QObject * parent=0);
        virtual ~Session();

        enum DisconnectReason{
            AuthenticationFailed,
            InitialTeleportFailed,
            NetworkError,
            Logout,
        };

        enum SessionState{
            Disconnected,
            Authenticating,
            Teleporting,
            Connected
        };


        inline SessionState state() const {
            return m_state;
        }

        Simulator * simCurrent,
            *simNorth,
            *simSouth,
            *simEast,
            *simWest,
            *simNorthEast,
            *simNorthWest,
            *simSouthEast,
            *simSouthWest,
            *simTarget;

        inline QUuid sessionId(){
            return d_session_id;
        }
        inline QUuid agentId(){
            return d_agent_id;
        }

    public slots:
        void login(QUrl url, QString firstName, QString lastName, QString password);
        void logout();

    signals:
        void teleporting(Simulator *  target);
        void teleportComplete(Simulator *  target);
        void teleportFailed(Simulator *  target,Simulator::DisconnectReason reason);
        void disconnected(Session::DisconnectReason reason);

    private slots:
        void rpcRequestFinished();
        void simulatorDisconnected(Simulator::DisconnectReason reason);
        void simulatorConnected();

    private:
        SessionState m_state;

        //login parameters
        QUrl d_url;
        QString d_firstName;
        QString d_lastName;
        QString d_password;

        //session parameters
        QUuid d_session_id;
        QUuid d_agent_id;

        //xmlrpc
        int authRetryLeft;
        QxtXmlRpcClient rpc;

        //caps
        QMap<QString,QUrl> caps;

    };
};

#endif
