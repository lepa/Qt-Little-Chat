#include "chatclient.h"

chatclient::chatclient(QObject *parent) :
    QObject(parent)
{
    this->ip = "";
    this->sock = 0;
}


chatclient::~chatclient()
{
    this->stopConnection();
}


void chatclient::setIPAddress(const QString &addr)
{
    this->ip = addr;
}


void chatclient::startConnection()
{
    if ( ip != "" )
    {
       this->sock = new TcpSocket (this);
       this->sock->connectToHost( ip, PORT);
       this->sock->write(entrymsg.toAscii());
       connect(this->sock, SIGNAL(readyRead()), this, SLOT(incomingMsg()));
    }
    else
    {
        ipNotSet ins;
        throw ins;
    }
}


void chatclient::stopConnection()
{
    if (this->sock)
    {
        delete this->sock;
    }
    this->sock = 0;
}


void chatclient::sendMsg(const QString &msg)
{
    this->sock->write(msg.toAscii());
}


void chatclient::incomingMsg()
{
    emit newMsg ( QString ( this->sock->readAll() ) );
}
