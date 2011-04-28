#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chat = new Chat(this);
    this->switchWidgets(DISCONNECTED);
    connect(this->chat, SIGNAL(receivedMsg(Message)), this, SLOT(receivedmsg(Message)));
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->chat;
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
        ui->server->setDisabled(true);
    }
    else if (state == Qt::Unchecked)
    {
        chat->becomeClient();
        ui->server->setEnabled(true);
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
    else
    {
        if (!ui->becomeserver->isChecked())
        {
            this->chat->setIp(ui->server->text());
            Message entering;
            entering.setVars(ui->nickname->text(), "JOIN", "joining...");
            this->chat->sendMsg(entering);
        }

        this->switchWidgets(CONNECTED);
    }
}

void MainWindow::on_disconnectButton_clicked()
{
    delete this->chat;
    this->chat = new Chat;
    ui->becomeserver->setChecked(false);
    this->switchWidgets(DISCONNECTED);
}

void MainWindow::switchWidgets(bool connected)
{
    ui->server->setDisabled(connected);
    ui->nickname->setDisabled(connected);
    ui->becomeserver->setDisabled(connected);
    ui->connectButton->setDisabled(connected);
    ui->disconnectButton->setEnabled(connected);
    ui->lineEdit->setEnabled(connected);
    ui->send->setEnabled(connected);
}

void MainWindow::on_send_clicked()
{
    Message msg;
    msg.setVars(ui->nickname->text(), "MSG", ui->lineEdit->text());
    this->chat->sendMsg(msg);
    ui->lineEdit->setText("");
}

void MainWindow::receivedmsg(Message msg)
{
    QString parsedMsg;

    if (msg.getAction() == "JOIN")
    {
        parsedMsg = "*" + msg.getNickName() + " joined the chat";
    }
    else if (msg.getAction() == "EXIT")
    {
        parsedMsg = "*" + msg.getNickName() + " quitted the chat";
    }
    else
    {
        parsedMsg = msg.getNickName() + ":" + " " + msg.getMessage();
    }

    ui->textEdit->append(parsedMsg);
}
