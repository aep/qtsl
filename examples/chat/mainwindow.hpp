#include <QMainWindow>
#include "ui_mainwindow.h"

#include "Session.hpp"
#include "Avatar.hpp"
#include "Chat.hpp"

class MainWindow :  public QWidget , private Ui::MainWindow{
    Q_OBJECT;
public:
    MainWindow();

private:
    qtsl::Session session;
    qtsl::Avatar avatar;
    qtsl::Chat chat;

private slots:
    void simulatorMessage(const qtsl::Chat::SimulatorMessage &);
    void on_send_clicked(bool);

};

