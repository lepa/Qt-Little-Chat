#ifndef CHATLOGGER_H
#define CHATLOGGER_H

#include <QObject>

class chatlogger : public QObject
{
Q_OBJECT
public:
    explicit chatlogger(QObject *parent = 0);

signals:

public slots:

};

#endif // CHATLOGGER_H
