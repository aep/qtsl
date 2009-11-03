#include <QCoreApplication>
#include "Session.hpp"
#include "Avatar.hpp"
#include "Chat.hpp"

int main (int argc, char ** argv){
    QCoreApplication app(argc,argv);

    qtsl::Session session;
    session.login(QUrl(argv[1]),argv[2],argv[3],argv[4]);

    qtsl::Avatar avatar(&session);
    qtsl::Chat chat(&session);

    return app.exec();
}

