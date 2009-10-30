#ifndef QOMV_SESSION_H
#define QOMV_SESSION_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>


namespace qomv{

    class Session : public QObject {
    Q_OBJECT
    enum SessionState{
        Disconnected,
        Authenticating,
        Connected
    };
    public:
        Session(QObject * parent=0);

        SessionState state() const {return m_state;}

    public slots:
        /**
           triggers connected on sucess and disconnected on failure
        */
        void login(QUrl url, QString firstName, QString lastName, QString passord );

    signals:
        void connected();
        void disconnected( QNetworkReply::NetworkError code );

    private slots:
        void httpLoginFinished();
    private:
        QUrl url;
        QString firstName;
        QString lastName;
        QString password;

        QNetworkAccessManager http;
        SessionState m_state;
    };
};

#endif

