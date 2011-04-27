#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include "chatserver.h"
#include "chatclient.h"
#include "message.h"


class Chat : public QObject
{
Q_OBJECT
protected:
    chatclient* client;
    chatserver* server;

public:
    explicit Chat(QObject *parent = 0);
    ~Chat();
    void becomeServer();
    void becomeClient();
    void setIp(QString& str);

signals:
    void receivedMsg(Message msg);

public slots:
    void sendMsg(Message msg);
    void recvMsg(QString msg);
};

#endif // CHAT_H
