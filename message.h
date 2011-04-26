#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QRegExp>
#include <QStringList>

/* Azioni del messaggio */
enum { MESSAGE, ENTER, EXIT };

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
    Message& operator=(const Message& msg);
    QString toString();
    void fromString(QString str);
};

#endif // MESSAGE_H
