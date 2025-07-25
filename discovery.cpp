/*
 *Remodified class that reimplements INSTAINET::discoverpanels to use QThread
 *and signals and slots to not block UI animations.
 */

#include "discovery.h"
#include "insta-inet.h"
#include <QtCore/qdebug.h>

discovery::discovery(std::vector<char *> &IPs, int time)
    : IPs(IPs), time(time)
{

}

void discovery::detect()
{
    qDebug() << "Started1";

    // get IP address of the host(this code) and srt it to discoveryPacket.hostIP
    // Get the actual local IP address (IPv4, non-loopback)
    int sock1 = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock1 < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    sockaddr_in remote_addr{};
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80); // arbitrary port
    inet_pton(AF_INET, "8.8.8.8", &remote_addr.sin_addr); // arbitrary external IP

    // Connect to remote address (no packets sent, just to get local IP)
    if (::connect(sock1, (sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("connect");
        close(sock1);
        exit(EXIT_FAILURE);
    }
    sockaddr_in local_addr{};
    socklen_t addr_len = sizeof(local_addr);
    if (getsockname(sock1, (sockaddr*)&local_addr, &addr_len) < 0) {
        perror("getsockname");
        close(sock1);
        exit(EXIT_FAILURE);
    }
    close(sock1);

    uint32_t ip = ntohl(local_addr.sin_addr.s_addr);
    discoveryPacket.hostIP[0] = (ip >> 24) & 0xFF;
    discoveryPacket.hostIP[1] = (ip >> 16) & 0xFF;
    discoveryPacket.hostIP[2] = (ip >> 8) & 0xFF;
    discoveryPacket.hostIP[3] = ip & 0xFF;
    discoveryPacket.hostIP[4] = 0x00; // null terminator

    //start a thread to listen for responses on port 9411, if a response of size 540 is received, create an instaLight2022 object with the IP address from the response and add it to the discoveredPanels vector

        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(9411);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        if (bind(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
            perror("bind");
            close(sock);
            exit(EXIT_FAILURE);
        }

        INSTAINET::sendUDP("255.255.255.255", 9410, reinterpret_cast<const uint8_t*>(&discoveryPacket), sizeof(discoveryPacket));

        auto start = std::chrono::steady_clock::now();
        int lastSecond=-1;
        while (true) {
            // Check if 10 seconds have passed
            auto now = std::chrono::steady_clock::now();
            int secondsPassed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
            if (secondsPassed != lastSecond) {
                emit tick(secondsPassed);  // Emit signal with number of seconds passed
                lastSecond = secondsPassed;
            }

            if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= time) {
                break;
            }

            // Set a short timeout for recvfrom to allow periodic time checks
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = 200 * 1000; // 200 ms
            setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

            uint8_t buffer[540];
            sockaddr_in senderAddr{};
            socklen_t senderAddrLen = sizeof(senderAddr);
            ssize_t bytesReceived = recvfrom(sock, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr*>(&senderAddr), &senderAddrLen);
            if (bytesReceived < 0) {
                // Timeout or error, just continue
                continue;
            }
            if (bytesReceived == 540) {
                // Extract 4 bytes for IP address starting at byte 30
                char* ipStr = new char[16];
                snprintf(ipStr, 16, "%u.%u.%u.%u",
                         buffer[30], buffer[31], buffer[32], buffer[33]);
                //std::cout << ipStr << "\n";
                IPs.push_back(ipStr);
            }
        }
        close(sock);

    emit valueChanged();
    qDebug() << "Emitting valueChanged";
    return;
}
