#include "serverWorker.h"
#include <QtCore/qdebug.h>

serverWorker::serverWorker(std::vector<INSTAINET::instaLight2022> *panels, int port, float fps)
    :panels(panels), port(port), fps(fps)
{

}

void serverWorker::sendUDP(const char *ip, int port, const uint8_t *data, size_t length)
{
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return; }

    sockaddr_in dest{};
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    inet_pton(AF_INET, ip, &dest.sin_addr);

    // Enable broadcast if sending to 255.255.255.255
    if (strcmp(ip, "255.255.255.255") == 0) {
        int broadcastEnable = 1;
        setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    }

    sendto(sock, data, length, 0, (sockaddr*)&dest, sizeof(dest));
    close(sock);
}

void serverWorker::run()
{
    while (this->active)
    {
        sendUDP("255.255.255.255", port, reinterpret_cast<const uint8_t*>(&preData), sizeof(preData));

        for (auto& panel : *panels) {
            // Send the main data packet
            sendUDP(panel.IP_Adress, port, reinterpret_cast<const uint8_t*>(&panel.data), sizeof(panel.data));
        }

        // Sleep to maintain the desired FPS
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000 / fps)));
    }
    close(sock);
    this->deleteLater();
}

void serverWorker::stop()
{
    this->active = false;
}
