#include "chatserver.h"

chatserver::chatserver(QObject *parent) :
    QObject(parent)
{
    this->first = 0;
    this->server = new QTcpServer(this);
    this->server->listen("127.0.0.1", PORT);
    connect (this->server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void chatserver::onNewConnection()
{
    if (this->first)
    {
        Buddy* ptr;
        ptr = this->first;
        bool notdone = true;

        do
        {
            if (ptr->sock==0)
            {
                ptr->sock = this->server->nextPendingConnection();
                notdone = false;
                connect(ptr->sock, SIGNAL(haveToRead(TcpSocket*)), this, SLOT(receivedMsg(TcpSocket*)));
            }
        } while (ptr->next && notdone);

        if (notdone)
        {
            ptr->next = new Buddy;
            ptr = ptr->next;
            ptr->sock = this->server->nextPendingConnection();
            connect(ptr->sock, SIGNAL(haveToRead(TcpSocket*)), this, SLOT(receivedMsg(TcpSocket*)));
            ptr->next = 0;
        }
    }
}


void chatserver::broadcast(QString msg)
{
    Buddy* ptr = this->first;

    while (ptr)
    {
        if (ptr->sock)
        {
            ptr->sock->write(msg.toAscii());
        }

        ptr = ptr->next;
    }
}


void chatserver::receivedMsg(TcpSocket* s)
{
    QString msg = s->readAll();
    broadcast(msg);
}
