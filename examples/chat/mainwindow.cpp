#include "mainwindow.hpp"
#include <QApplication>
MainWindow::MainWindow()
 :QWidget()
 ,session()
 ,avatar(session)
 ,chat(session){
    setupUi(this);
    connect(&chat,SIGNAL(simulatorMessage(const qtsl::Chat::SimulatorMessage & )),
            this,SLOT   (simulatorMessage(const qtsl::Chat::SimulatorMessage &)));
    session.login(QUrl(QApplication::arguments()[1]),QApplication::arguments()[2],QApplication::arguments()[3],QApplication::arguments()[4]);
}

void MainWindow::simulatorMessage(const qtsl::Chat::SimulatorMessage & m){
    if(m.chatType==qtsl::Chat::SimulatorMessage::StartTyping){
        log->append(m.fromName + " is typing");
    }else if(m.chatType==qtsl::Chat::SimulatorMessage::StopTyping){
        log->append(m.fromName + " has stopped typing");
    }else if(m.chatType==qtsl::Chat::SimulatorMessage::WhisperVolume){
        log->append(m.fromName + " whispers: "+m.message);
    }else if(m.chatType==qtsl::Chat::SimulatorMessage::ShoutVolume){
        log->append(m.fromName + " shouts: "+m.message);
    }else {
        log->append(m.fromName + ": "+m.message);
    }
    log->moveCursor ( QTextCursor::End );
    log->ensureCursorVisible();
}


void MainWindow::on_send_clicked(bool){
    chat.sendSimulatorMessage(input->text(),qtsl::Chat::SimulatorMessage::NormalVolume);
    input->clear();
}
