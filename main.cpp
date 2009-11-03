#include <QCoreApplication>
#include <QNetworkAccessManager>

#include "Session.hpp"

class MyChatClient : public QObject{
Q_OBJECT
public slots:
    void chatMessage(){}
};

int main (int argc, char ** argv){
    QCoreApplication app(argc,argv);

    qtsl::Session session;
    session.login(QUrl(argv[1]),argv[2],argv[3],argv[4]);

    return app.exec();
}



#include "main.moc"
