#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chat.h"

#define CONNECTED true
#define DISCONNECTED false

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    Chat* chat;
    void switchWidgets(bool connected);

private:
    Ui::MainWindow *ui;

private slots:
    void on_send_clicked();
    void on_disconnectButton_clicked();
    void on_connectButton_pressed();
    void on_becomeserver_stateChanged(int );

public slots:
    void receivedmsg(Message msg);
};

#endif // MAINWINDOW_H
