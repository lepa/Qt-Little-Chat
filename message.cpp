#include "message.h"


QString Message::getNickName()
{
    return this->nickname;
}

QString Message::getAction()
{
    return this->action;
}

QString Message::getMessage()
{
    return this->message;
}

Message& Message::operator= (Message& msg)
{
    this->action = msg.getAction();
    this->nickname = msg.getNickName();
    this->message = msg.getMessage();
    return *this;
}

QString Message::toString()
{
    return  (":"+this->nickname+"!"+this->action+":"+this->message);
}

Message& Message::fromString(QString str)
{
    QRegExp rx(":(\\c+)!(\\d+):(.+)");
    rx.exactMatch(str);
    QStringList ls = rx.capturedTexts();

    this->nickname = ls[0];
    this->action = ls[1];
    this->message = ls[2];

    return *this;
}
