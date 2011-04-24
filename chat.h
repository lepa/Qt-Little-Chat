#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QtNetwork>
#include "tcpsocket.h"

#define PORT          666

enum { CLIENT, SERVER  };

struct Buddies
{
    TcpSocket* sock;
    Buddies* next;
};


class ipnotset : public std::exception
{
    const char* what() const throw
    {
        return "Be sure that ip address is set up";
    }
};

class Chat : public QObject
{
Q_OBJECT
protected:
    short int state;
    QTcpServer* server;
    QTcpSocket* sock;
    QString ip;
    Buddies* list;

public:
    explicit Chat(QObject *parent = 0);
    void startConnection();
    void stopConnection();

signals:
    void messageReceived (QString msg);

public slots:
    void setServerIP(QString& addr);
    void becomeServer();
    void sendMessage(QString msg);
    void onMessageReceived();
    void onServerNewConnection();

};

#endif // CHAT_H
