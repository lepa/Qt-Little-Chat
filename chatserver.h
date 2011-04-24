#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QObject>
#include <QtNetwork>
#include "tcpsocket.h"
#include "config.h"

struct Buddy
{
    TcpSocket* sock;
    Buddy* next;
};


class chatserver : public QObject
{
Q_OBJECT
protected:
    QTcpServer* server;
    Buddy* first;
public:
    explicit chatserver(QObject *parent = 0);

public slots:
    void onNewConnection();
    void broadcast(QString msg);
    void receivedMsg(TcpSocket* s);
};

#endif // CHATSERVER_H
