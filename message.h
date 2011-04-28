#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QRegExp>
#include <QStringList>


class Message
{
protected:
    QString nickname;
    QString action;
    QString message;
public:
    void setVars(QString nick, QString act, QString msg);
    QString getNickName();
    void setNickName(QString nick);
    QString getAction();
    void setAction(QString act);
    QString getMessage();
    void setMessage(QString msg);
    Message& operator=(Message& msg);
    QString toString();
    Message& fromString(QString str);
};

#endif // MESSAGE_H
