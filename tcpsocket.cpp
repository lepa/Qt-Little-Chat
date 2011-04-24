#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
    : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(whenCanRead()));
}


TcpSocket::~TcpSocket()
{
    this->disconnectFromHost();
}


void whenCanRead()
{
    emit haveToRead(this);
}


void* TcpSocket::operator new(size_t size)
{
    void* ptr = malloc (size);

    if (!ptr)
    {
        std::bad_alloc ba;
        throw ba;
    }

    return ptr;
}


void* TcpSocket::operator new[](size_t size)
{
    void* ptr = malloc (size);

    if (!ptr)
    {
        std::bad_alloc ba;
        throw ba;
    }

    return ptr;
}


void TcpSocket::operator delete(void* ptr)
{
    if (ptr)
    {
        free(ptr);
    }

    ptr = 0;
}


void TcpSocket::operator delete[](void* ptr)
{
    if (ptr)
    {
        free(ptr);
    }

    ptr = 0;
}
