#include <QApplication>
#include "mainwindow.hpp"

int main (int argc, char ** argv){
    if(argc<5){
        qDebug("usage: ./chat http://slserver:9000/ First Last Secret");
        return 2;
    }
    QApplication app(argc,argv);

    MainWindow win;
    win.show();

    return app.exec();
}

