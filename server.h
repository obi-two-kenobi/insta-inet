#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "insta-inet.h"


class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
    void run();

signals:
};

#endif // SERVER_H
