#ifndef DISCOVERY_H
#define DISCOVERY_H

#include <QObject>
#include "insta-inet.h"

/**
 * @class discovery
 * @brief reimplementation of the discovery protocol that avoids blocking the UI.
 *
 * This class is responsible for detecting Instalight 2022 on the network
 * by sending and receiving discovery packets. It utilizes Qt's signal-slot
 * mechanism for asynchronous event handling.
 *
 * @note Requires Qt's meta-object system (Q_OBJECT macro).
 *
 * @param IPs Reference to a vector of IP addresses (as char pointers) to be used in discovery.
 * @param time Time interval or timeout value for discovery operations.
 *
 * Signals:
 *   - void valueChanged(): Emitted when a relevant value changes.
 *   - void tick(int): Emitted periodically or on specific events, passing an integer value.
 *
 * Private Members:
 *   - std::vector<char*>& IPs: Reference to the list of IP addresses.
 *   - int time: Time interval or timeout for discovery.
 *   - struct DiscoveryPacket: Structure representing the custom discovery packet format.
 *
 * Usage:
 *   Instantiate the class with a reference to an IP vector and a time value,
 *   then call detect() to start the discovery process.
 */
class discovery : public QObject {
    Q_OBJECT  // Required for signal-slot system

public:
    discovery(std::vector<char*>& IPs, int time);
    void detect();

signals:
    void valueChanged();  // Only declare it — no body
    void tick(int);

private:
    std::vector<char*>& IPs;
    int time;
    struct DiscoveryPacket {
        uint8_t Insta_identifier[10] = {0x49, 0x4E, 0x53, 0x54, 0x41, 0x2D, 0x49, 0x4E, 0x45, 0x54};
        uint8_t nul_terminator = 0x00;
        uint8_t version[2] = {0x01, 0x00};
        uint8_t sendIndicator[2] = {0, 0x3};
        uint8_t hostIP[5] = {0xC0, 0xA8, 0x02, 0xA7, 0x00}; //with null terminator
        uint8_t op = 2;
        uint8_t unknown[5] = {0x55, 0, 0, 0, 0};
    } discoveryPacket;
};


#endif // DISCOVERY_H

