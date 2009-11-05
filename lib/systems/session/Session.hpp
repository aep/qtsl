#ifndef QOMV_SESSION_H
#define QOMV_SESSION_H

#include <QObject>
#include <QUrl>
#include <QUuid>
#include <memory>
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

        SessionState state() const;
        QUuid sessionId() const;
        QUuid agentId() const;
        QUuid inventoryRoot() const;

    public slots:
        void login(QUrl url, QString firstName, QString lastName, QString password);
        void logout();

    signals:
        void teleporting(Simulator *  target);
        void teleportComplete(Simulator *  target);
        void teleportFailed(Simulator *  target,Simulator::DisconnectReason reason);
        void disconnected(Session::DisconnectReason reason);

    private:
        struct Private;
        const std::auto_ptr<Private> d;
        friend class Private;
        Q_PRIVATE_SLOT( d, void d_rpcRequestFinished());
        Q_PRIVATE_SLOT( d, void d_simulatorDisconnected(Simulator::DisconnectReason reason))
        Q_PRIVATE_SLOT( d, void d_simulatorConnected());
    };
};

#endif
