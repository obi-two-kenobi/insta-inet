//
//  insta-inet.hpp
//  InstaLight2022
//
//  Created by Ali Alhalabi on 13.07.25.
//

#ifndef INSTA_INET_HPP
#define INSTA_INET_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <thread>
#include <opencv2/opencv.hpp>

/**
 * @namespace INSTAINET
 * @brief Namespace containing classes and functions for controlling Insta Light 2022 panels over a network.
 *        This covers the undocumented protocol created by Instalight, called Insta-inet.
 * 
 * @note This API is based on reverse engineering of the Insta Light 2022 protocol and is not complete.
 *       Some fields and behaviors may be unknown or subject to change.
 *
 * Classes:
 *   - instaLight2022: Represents a single Insta Light 2022 panel and provides methods to configure and render frames.
 *     - DataPacket: Internal structure representing the data packet sent to the panel. Many fields are based on observed protocol data and may be partially understood.
 *     - Methods to set IP address, brightness, contrast, luminance time, frequency, and maximum RGB values for left and right channels.
 *     - Method to render a frame to the panel.
 *
 * Functions:
 *   - sendUDP: Sends a UDP packet to the specified IP and port.
 *   - discoverPanels: Discovers available panels on the network within a given time frame.
 *   - TransmitData: Transmits data to a list of panels at a specified frame rate.
 *   - cropImgToGrid: Crops an image into a grid of frames for panel rendering.
 *
 * Global Variables:
 *   - Panels: List of discovered or configured instaLight2022 panels.
 *   - Cropped: List of cropped image frames.
 *   - IPs: List of discovered panel IP addresses.
 *
 * @warning This documentation and the associated code are incomplete and may not fully represent the actual device protocol.
 */
namespace INSTAINET {
class instaLight2022 {
public:
    char* IP_Adress;
    int port;
    struct DataPacket {
        uint8_t Insta_identifier[11] = {0x49, 0x4E, 0x53, 0x54, 0x41, 0x2D, 0x49, 0x4E, 0x45, 0x54, 0x00}; //with null terminator
        uint8_t version[2] = {0x01, 0x00};//with null terminator
        uint8_t unknown0[2] = {0,1};
        uint8_t TargetIP[5] = {0x00, 0x00, 0x00, 0x00, 0x00}; //with null terminator
        uint8_t op[2] = {0x01,0x00}; //with null terminator
        uint8_t unknown1[2] = {0x01, 0x21};
        uint8_t counter = 0x00;
        uint8_t unknown2[9] = {0,0,    0,0,1,0xE6,0,0x1A,0};
        uint8_t RGB_Left[162*3];
        uint8_t L_Brightness = 0xc1;
        uint8_t L_Contrast = 0x7d;
        uint8_t L_Lumin_Time = 0x0;
        uint8_t L_Freq = 0x0;
        uint8_t L_Red_max = 0xff;
        uint8_t L_Green_max = 0xff;
        uint8_t L_Blue_max= 0xff;
        uint8_t unknown3[46] = {0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0x14,    0x91,    0x49,    0x45,    1,    1,    0,    1,    0x6C,    0x80,    0x16,    0x8,    0xCA,    0xC5,    0x78,    0xB5,    0x58,    0xC9,    0x38,    0xC5,    0x48,    0,    0,    0,    0,    0,    0};
        uint8_t RGB_Right[162*3];//Brightness, Contrast, Lumin_Time, Freq, Red_max, Green_max, Blue_max
        uint8_t R_Brightness = 0xc1;
        uint8_t R_Contrast = 0x7d;
        uint8_t R_Lumin_Time = 0x0;
        uint8_t R_Freq = 0x0;
        uint8_t R_Red_max = 0xff;
        uint8_t R_Green_max = 0xff;
        uint8_t R_Blue_max= 0xff;
        uint8_t unknown4[46] = {0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0x14,    0x91,    0x49,    0x45,    1,    1,    0,    1,    0x6C,    0x80, 0x16,    0x8,    0xFF,    0xC1,    0x16,    0xB4,    0xAE,    0xC4,    0xC5,    0xC4,    0xDE,    0,    0,    0,    0,    0,    0};
    }data;
    instaLight2022(char* IP_Adress, int port = 9410);
    bool render(cv::Mat& frame);
    void setIpAddress(char* IP_Adress);
    void setBrightness (uint8_t Left_Brightness, uint8_t Right_Brightness);
    void setContrast (uint8_t Left_Contrast, uint8_t Right_Contrast);
    void setLuminTime (uint8_t Left_Lumin_Time, uint8_t Right_Lumin_Time);
    void setFrequency (uint8_t Left_Freq, uint8_t Right_Freq);
    void setMaxRGB (uint8_t Left_Red_max, uint8_t Left_Green_max, uint8_t Left_Blue_max,
                   uint8_t Right_Red_max, uint8_t Right_Green_max, uint8_t Right_Blue_max);
};

void sendUDP(const char* ip, int port, const uint8_t* data, size_t length);
void discoverPanels(uint8_t seconds);
void discoverPanels(std::vector<char*>& IPs,uint8_t seconds);
void TransmitData(std::vector<instaLight2022>* panels, int port = 9410, bool debug = false, float fps = 30.0f);
bool cropImgToGrid(uint8_t rows, uint8_t cols, cv::Mat& toBeCroppedFrame, std::vector<cv::Mat>& croppedFrames);

extern std::vector <instaLight2022> Panels;
extern std::vector<cv::Mat> Cropped;
extern std::vector <char*> IPs;
} // namespace insta_inet


#endif // INSTA_INET_HPP
