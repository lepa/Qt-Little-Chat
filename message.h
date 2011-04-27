#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QRegExp>
#include <QStringList>


class Message
{
private:
    QString nickname;
    QString action;
    QString message;
public:
    QString getNickName();
    QString getAction();
    QString getMessage();
    Message& operator=(Message& msg);
    QString toString();
    void fromString(QString str);
};

#endif // MESSAGE_H
