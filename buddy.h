#ifndef BUDDY_H
#define BUDDY_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Buddy : public QObject
{
Q_OBJECT

private:
    QString nickname;
    QTcpSocket* sock;

public:
    explicit Buddy(QObject *parent = 0);
    QString name();
    void setSocket(QTcpSocket* s);

signals:
    void message(QString);

public slots:
    void onReceivedMessage(qint64 bytes);
};

#endif // BUDDY_H
