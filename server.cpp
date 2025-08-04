#include "server.h"

server::server(QObject *parent)
    : QObject{parent}
{}

void server::run()
{
    INSTAINET::TransmitData(&INSTAINET::Panels, 9410, false, 50);
    this->deleteLater();
}
