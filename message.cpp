#include "message.h"


void Message::setVars(QString nick, QString act, QString msg)
{
    this->nickname = nick;
    this->action = act;
    this->message = msg;
}

QString Message::getNickName()
{
    return this->nickname;
}

void Message::setNickName(QString nick)
{
    this->nickname = nick;
}

QString Message::getAction()
{
    return this->action;
}

void Message::setAction(QString act)
{
    this->action = act;
}

QString Message::getMessage()
{
    return this->message;
}

void Message::setMessage(QString msg)
{
    this->message = msg;
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
