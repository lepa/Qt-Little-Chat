#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include "tcpsocket.h"
#include <exception>
#include "config.h"

class ipNotSet : public std::exception
{
    const char* what() const throw()
    {
        return "The ip address must be set";
    }
};

class chatclient : public QObject
{
Q_OBJECT
protected:
    TcpSocket* sock;
    QString ip;
public:
    explicit chatclient(QObject *parent = 0);
    void startConnection(QString name);
    void stopConnection();

signals:
    void newMsg(QString msg);


public slots:
    void setIPAddress (const QString& addr);
    void sendMsg(const QString& msg);
    void incomingMsg();

};

#endif // CHATCLIENT_H
