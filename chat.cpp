#include "chat.h"

Chat::Chat(QObject *parent) :
    QObject(parent)
{
    this->server = 0;
    this->client = new chatclient(this);
    connect(this->client, SIGNAL(newMsg(QString)), this, SLOT(recvMsg(QString)));
}

Chat::~Chat()
{
    if (this->server)
    {
        delete this->server;
    }
    else if (this->client)
    {
        delete (this->client);
    }
}


void Chat::setIp(const QString& str)
{
    if (this->client)
    {
        this->client->setIPAddress(str);
        this->client->startConnection();
    }
}

void Chat::becomeServer()
{
  if (this->client)
  {
    delete this->client;
    this->client = 0;
    this->server = new chatserver(this);
  }
  else
  {
      delete this->server;
      this->server = new chatserver(this);
  }

  connect(this->server, SIGNAL(receveidMsg(QString)), this, SLOT(recvMsg(QString)));
}

void Chat::becomeClient()
{
    if (this->server)
    {
        delete this->server;
        this->server = 0;
        this->client = new chatclient(this);
    }
    else
    {
        delete this->client;
        this->client = new chatclient(this);
    }

    connect(this->client, SIGNAL(newMsg(QString)), this, SLOT(recvMsg(QString)));
}

void Chat::sendMsg(Message msg)
{
    if (this->server)
    {
        this->server->broadcast( msg.toString() );
    }
    else
    {
        this->client->sendMsg( msg.toString() );
    }
}

void Chat::recvMsg(QString msg)
{
    Message tmp;
    tmp.fromString(msg);
    emit (receivedMsg(tmp));
}


