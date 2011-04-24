#include "buddy.h"

Buddy::Buddy(QObject *parent) :
    QObject(parent)
{
    this->sock = 0;
}


void Buddy::setSocket(QTcpSocket s)
{
    this->sock = new QTcpSocket;
    this->sock = s;

    connect (this->sock, SIGNAL(bytesWritten(qint64)), this, SLOT(onReceivedMessage(qint64)));

}

void Buddy::onReceivedMessage(qint64 bytes)
{
    QByteArray msg = this->sock->readAll();

    emit ( message (msg) );
}
