//
//  insta-inet.cpp
//  InstaLight2022
//
//  Created by Ali Alhalabi on 13.07.25.
//

#include "insta-inet.h"

INSTAINET::instaLight2022::instaLight2022(char* IP_Adress, int port) {
    this->IP_Adress = IP_Adress;
    this->port = port;
    // Parse the IP_Adress string and set the first 4 bytes of data.TargetIP
    unsigned int ip_bytes[4] = {0};
    sscanf(IP_Adress, "%u.%u.%u.%u", &ip_bytes[0], &ip_bytes[1], &ip_bytes[2], &ip_bytes[3]);
    for (int i = 0; i < 4; ++i) {
        data.TargetIP[i] = static_cast<uint8_t>(ip_bytes[i]);
    }
    memset(data.RGB_Left,255,sizeof(data.RGB_Left));
    memset(data.RGB_Right,255,sizeof(data.RGB_Right));
}
bool INSTAINET::instaLight2022::render(cv::Mat& frame){
    if (frame.empty() || frame.rows != 18 || frame.cols != 18 || frame.channels() != 3 || frame.type() != CV_8UC3) {
        std::cerr << "Frame must be 18x18 and of type CV_8UC3! Is frame empty?" << std::endl;
        return false;
    }
    //convert the frame to rgb
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    cv::Mat leftFrame = frame(cv::Rect(0, 0, 9, 18)).clone();
    cv::Mat rightFrame = frame(cv::Rect(9, 0, 9, 18)).clone();

    std::vector<uint8_t> leftflatFrame(leftFrame.data, leftFrame.data + leftFrame.total() * leftFrame.elemSize());
    // Fill the RGB_Left and RGB_Right arrays with the frame data
    for (int j = 0; j < 162; j++) {
        if (j < leftflatFrame.size() ) {
            data.RGB_Left[j * 3] = leftflatFrame[j * 3];
            data.RGB_Left[j * 3 + 1] = leftflatFrame[j * 3 + 1];
            data.RGB_Left[j * 3 + 2] = leftflatFrame[j * 3 + 2];
        }
    }
    std::vector<uint8_t> rightflatFrame(rightFrame.data, rightFrame.data + rightFrame.total() * rightFrame.elemSize());
    for (int j = 0; j < 162; j++) {
        if (j < rightflatFrame.size()) {
            data.RGB_Right[j * 3] = rightflatFrame[j * 3];
            data.RGB_Right[j * 3 + 1] = rightflatFrame[j * 3 + 1];
            data.RGB_Right[j * 3 + 2] = rightflatFrame[j * 3 + 2];
        }
    }
    leftFrame.release();
    rightFrame.release();
    //convert the back to bgr
    cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
    return true;
}
void INSTAINET::instaLight2022::setIpAddress(char* IP_Adress){
    this->IP_Adress = IP_Adress;
    // Parse the IP_Adress string and set the first 4 bytes of data.TargetIP
    unsigned int ip_bytes[4] = {0};
    sscanf(IP_Adress, "%u.%u.%u.%u", &ip_bytes[0], &ip_bytes[1], &ip_bytes[2], &ip_bytes[3]);
    for (int i = 0; i < 4; ++i) {
        data.TargetIP[i] = static_cast<uint8_t>(ip_bytes[i]);
    }

}
void INSTAINET::instaLight2022::setBrightness (uint8_t Left_Brightness, uint8_t Right_Brightness) {
    data.L_Brightness = Left_Brightness;
    data.R_Brightness = Right_Brightness;
}
void INSTAINET::instaLight2022::setContrast (uint8_t Left_Contrast, uint8_t Right_Contrast) {
    data.L_Contrast = Left_Contrast;
    data.R_Contrast = Right_Contrast;
}
void INSTAINET::instaLight2022::setLuminTime (uint8_t Left_Lumin_Time, uint8_t Right_Lumin_Time) {
    data.L_Lumin_Time = Left_Lumin_Time;
    data.R_Lumin_Time = Right_Lumin_Time;
}
void INSTAINET::instaLight2022::setFrequency (uint8_t Left_Freq, uint8_t Right_Freq) {
    data.L_Freq = Left_Freq;
    data.R_Freq = Right_Freq;
}
void INSTAINET::instaLight2022::setMaxRGB (uint8_t Left_Red_max, uint8_t Left_Green_max, uint8_t Left_Blue_max,
                                          uint8_t Right_Red_max, uint8_t Right_Green_max, uint8_t Right_Blue_max) {
    data.L_Red_max = Left_Red_max;
    data.L_Green_max = Left_Green_max;
    data.L_Blue_max = Left_Blue_max;
    data.R_Red_max = Right_Red_max;
    data.R_Green_max = Right_Green_max;
    data.R_Blue_max = Right_Blue_max;
}

void INSTAINET::sendUDP(const char* ip, int port, const uint8_t* data, size_t length) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
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

void INSTAINET::TransmitData(std::vector<instaLight2022>* panels, int port, bool debug, float fps) {
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

    // Send the preData packet first
    while (true)
    {
        sendUDP("255.255.255.255", port, reinterpret_cast<const uint8_t*>(&preData), sizeof(preData));

        for (auto& panel : *panels) {
            // Send the main data packet
            sendUDP(panel.IP_Adress, port, reinterpret_cast<const uint8_t*>(&panel.data), sizeof(panel.data));
        }

        // Sleep to maintain the desired FPS
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000 / fps)));
    }
}

void INSTAINET::discoverPanels(uint8_t seconds) {
    struct DiscoveryPacket {
        uint8_t Insta_identifier[10] = {0x49, 0x4E, 0x53, 0x54, 0x41, 0x2D, 0x49, 0x4E, 0x45, 0x54};
        uint8_t nul_terminator = 0x00;
        uint8_t version[2] = {0x01, 0x00};
        uint8_t sendIndicator[2] = {0, 0x3};
        uint8_t hostIP[5] = {0xC0, 0xA8, 0x02, 0xA7, 0x00}; //with null terminator
        uint8_t op = 2;
        uint8_t unknown[5] = {0x55, 0, 0, 0, 0};
    } discoveryPacket;

    // get IP address of the host(this code) and srt it to discoveryPacket.hostIP
    // Get the actual local IP address (IPv4, non-loopback)
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    sockaddr_in remote_addr{};
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80); // arbitrary port
    inet_pton(AF_INET, "8.8.8.8", &remote_addr.sin_addr); // arbitrary external IP

    // Connect to remote address (no packets sent, just to get local IP)
    if (connect(sock, (sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }
    sockaddr_in local_addr{};
    socklen_t addr_len = sizeof(local_addr);
    if (getsockname(sock, (sockaddr*)&local_addr, &addr_len) < 0) {
        perror("getsockname");
        close(sock);
        exit(EXIT_FAILURE);
    }
    close(sock);

    uint32_t ip = ntohl(local_addr.sin_addr.s_addr);
    discoveryPacket.hostIP[0] = (ip >> 24) & 0xFF;
    discoveryPacket.hostIP[1] = (ip >> 16) & 0xFF;
    discoveryPacket.hostIP[2] = (ip >> 8) & 0xFF;
    discoveryPacket.hostIP[3] = ip & 0xFF;
    discoveryPacket.hostIP[4] = 0x00; // null terminator

    //start a thread to listen for responses on port 9411, if a response of size 540 is received, create an instaLight2022 object with the IP address from the response and add it to the discoveredPanels vector
    std::thread listener([&seconds]() {
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

        auto start = std::chrono::steady_clock::now();
        while (true) {
            // Check if 10 seconds have passed
            auto now = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= seconds) {
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
                char ipStr[16];
                snprintf(ipStr, 16, "%u.%u.%u.%u",
                         buffer[30], buffer[31], buffer[32], buffer[33]);
            }
        }
        close(sock);
    });

    sendUDP("255.255.255.255", 9410, reinterpret_cast<const uint8_t*>(&discoveryPacket), sizeof(discoveryPacket));

    // Wait for the listener thread to finish (10 seconds)
    listener.join();

    return;
}

void INSTAINET::discoverPanels(std::vector<char*>& IPs,uint8_t seconds ){
    struct DiscoveryPacket {
        uint8_t Insta_identifier[10] = {0x49, 0x4E, 0x53, 0x54, 0x41, 0x2D, 0x49, 0x4E, 0x45, 0x54};
        uint8_t nul_terminator = 0x00;
        uint8_t version[2] = {0x01, 0x00};
        uint8_t sendIndicator[2] = {0, 0x3};
        uint8_t hostIP[5] = {0xC0, 0xA8, 0x02, 0xA7, 0x00}; //with null terminator
        uint8_t op = 2;
        uint8_t unknown[5] = {0x55, 0, 0, 0, 0};
    } discoveryPacket;

    // get IP address of the host(this code) and srt it to discoveryPacket.hostIP
    // Get the actual local IP address (IPv4, non-loopback)
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    sockaddr_in remote_addr{};
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80); // arbitrary port
    inet_pton(AF_INET, "8.8.8.8", &remote_addr.sin_addr); // arbitrary external IP

    // Connect to remote address (no packets sent, just to get local IP)
    if (connect(sock, (sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }
    sockaddr_in local_addr{};
    socklen_t addr_len = sizeof(local_addr);
    if (getsockname(sock, (sockaddr*)&local_addr, &addr_len) < 0) {
        perror("getsockname");
        close(sock);
        exit(EXIT_FAILURE);
    }
    close(sock);

    uint32_t ip = ntohl(local_addr.sin_addr.s_addr);
    discoveryPacket.hostIP[0] = (ip >> 24) & 0xFF;
    discoveryPacket.hostIP[1] = (ip >> 16) & 0xFF;
    discoveryPacket.hostIP[2] = (ip >> 8) & 0xFF;
    discoveryPacket.hostIP[3] = ip & 0xFF;
    discoveryPacket.hostIP[4] = 0x00; // null terminator

    //start a thread to listen for responses on port 9411, if a response of size 540 is received, create an instaLight2022 object with the IP address from the response and add it to the discoveredPanels vector
    std::thread listener([&IPs, &seconds]() {
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

        auto start = std::chrono::steady_clock::now();
        while (true) {
            // Check if 10 seconds have passed
            auto now = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - start).count() >= seconds) {
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
                IPs.push_back(ipStr);
            }
        }
        close(sock);
    });

    INSTAINET::sendUDP("255.255.255.255", 9410, reinterpret_cast<const uint8_t*>(&discoveryPacket), sizeof(discoveryPacket));

    // Wait for the listener thread to finish (10 seconds)
    listener.join();

    return;
}

bool INSTAINET::cropImgToGrid(uint8_t rows, uint8_t cols, cv::Mat& toBeCroppedFrame, std::vector<cv::Mat>& croppedFrames ){
    if(toBeCroppedFrame.rows % 18 != 0) {return false;}
    if(toBeCroppedFrame.cols % 18 != 0) {return false;}
    if(toBeCroppedFrame.rows % rows != 0) { return false;}
    if(toBeCroppedFrame.cols % cols != 0) {return false;}

    croppedFrames.clear();

    auto cell_height = toBeCroppedFrame.rows / rows;
    auto cell_width  = toBeCroppedFrame.cols / cols;

    if(cell_height != 18 | cell_width != 18 ) { return false;}

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int x = j * cell_width;
            int y = i * cell_height;

            // Ensure ROI doesn't go out of bounds
            if ((x + cell_width <= toBeCroppedFrame.cols) && (y + cell_height <= toBeCroppedFrame.rows)) {
                cv::Rect roi(x, y, cell_width, cell_height);
                cv::Mat cropped = toBeCroppedFrame(roi).clone();  // Explicit deep copy
                croppedFrames.push_back(cropped);
            } else {
                std::cout << "Skipping invalid ROI at (" << x << ", " << y << ")" << std::endl;
            }
        }
    }


    return true;
}

std::vector<INSTAINET::instaLight2022> INSTAINET::Panels = {}; // Define a vector to hold panel objects
std::vector<cv::Mat> INSTAINET::Cropped;// Define a vector to hold the parts of frame
std::vector <char*> INSTAINET::IPs; // Define a vector to hold panel IPs
