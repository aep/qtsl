#ifndef QOMV_SESSION_H
#define QOMV_SESSION_H

#include <QObject>
#include <QUrl>
#include <QHash>
#include <QxtXmlRpcClient>
#include <QNetworkReply>

#include "Circuit.hpp"

namespace qomv{

    class Session : public QObject {
    Q_OBJECT
    enum SessionState{
        Disconnected,
        Authenticating,
        ConnectingCircuit,
        Connected
    };
    public:
        Session(QObject * parent=0);

        SessionState state() const {return m_state;}

    public slots:
        void login(QUrl url, QString firstName, QString lastName, QString password );
    signals:
        void connected();
        void disconnected( QNetworkReply::NetworkError code );


    private slots:
        void rpcRequestFinished();

    private:
        QUrl url;
        QString firstName;
        QString lastName;
        QString password;


        QString session_id;
        QString agent_id;

        QHash<QString,QUrl> caps;

        QxtXmlRpcClient rpc;
        SessionState m_state;

        Circuit circuit;
    };
};

#endif

