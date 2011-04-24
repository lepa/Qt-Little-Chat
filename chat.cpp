#include "chat.h"

Chat::Chat(QObject *parent) :
    QObject(parent)
{
    state = CLIENT;
    sock = 0;
    server = 0;
    ip = "0";
}


void Chat::startConnection()
{
    if (ip != "0")
    {
        if (state == SERVER)
        {
            this->server = new QTcpServer(this);
            server->listen( QHostAddress ( this->ip ), PORT );
            connect( this->server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()) );
        }
        else
        {
            this->sock = new QTcpSocket(this);
            connect ( this->sock, SIGNAL(readyRead()), this, SLOT(onMessageReceived()) );
        }
    }
    else
    {
        ipnotset ins;
        throw ins;
    }
}


void Chat::setServerIP(QString &addr)
{
    this->ip = addr;
}


void Chat::becomeServer()
{
    this->state = SERVER;
    this->ip = "127.0.0.1";
}


void Chat::sendMessage(QString msg)
{
    this->sock->write( msg.toAscii() );
}


void Chat::onMessageReceived()
{

}
