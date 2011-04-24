#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <new>
#include <cstdlib>

class TcpSocket : public QTcpSocket
{
Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = 0);
    ~TcpSocket();
    void* operator new (size_t size);
    void* operator new[] (size_t size);
    void operator delete (void* ptr);
    void operator delete[] (void* ptr);
signals:
    void haveToRead(TcpSocket* sock);
public slots:
    void whenCanRead();
};

#endif // TCPSOCKET_H
