#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chat.h"

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

private:
    Ui::MainWindow *ui;

private slots:
    void on_connectButton_pressed();
    void on_becomeserver_stateChanged(int );
};

#endif // MAINWINDOW_H
