#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include "insta-inet.h"
#include <QDebug>


class serverWorker : public QObject
{
    Q_OBJECT
public:
    explicit serverWorker(std::vector<INSTAINET::instaLight2022>* panels = &INSTAINET::Panels , int port= 9410, float fps=50.0);
    void sendUDP(const char* ip, int port, const uint8_t* data, size_t length);
    void stop();
public slots:
    void run();


signals:

private:
    int sock;
    std::vector<INSTAINET::instaLight2022>* panels;
    volatile bool active=true;
    int port;
    float fps;
    struct preDataPacket
    {
        uint8_t Insta_identifier[10] = {0x49, 0x4E, 0x53, 0x54, 0x41, 0x2D, 0x49, 0x4E, 0x45, 0x54};
        uint8_t nul_terminator0 = 0x00;
        uint8_t version = 0x01;
        uint8_t nul_terminator1 = 0x00;
        uint8_t unknown0[2] = {0,1};
        uint8_t TargetIP[4] = {0xFF, 0xFF, 0xFF, 0xFF};
        uint8_t nul_terminator2 = 0x00;
        uint8_t op = 0x08;
        uint8_t nul_terminator3 = 0x00;
        uint8_t unknown1[5]={0,0,0,0,0};
    }preData;

};

#endif // SERVERWORKER_H
