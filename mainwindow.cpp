#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chat = new Chat(this);
    ui->disconnectButton->setDisabled(true);
    ui->lineEdit->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_becomeserver_stateChanged(int state)
{
    if (state == Qt::Checked)
    {
        chat->becomeServer();
    }
    else if (state == Qt::Unchecked)
    {
        chat->becomeClient();
    }
}

void MainWindow::on_connectButton_pressed()
{
    if ((ui->server->text().isEmpty() || ui->nickname->text().isEmpty()) && (!ui->becomeserver->isChecked()))
    {
        ui->errorLabel->setText("I campi devono essere riempiti.");
    }
    else if (ui->nickname->text().isEmpty() && ui->becomeserver->isChecked())
    {
        ui->errorLabel->setText("Il campo \"nickname\" deve essere riempito");
    }
    else if (!ui->becomeserver->isChecked())
    {
        this->chat->client->startConnection();
        this->chat->sendMsg(Message::fromString());
    }


}
