// video_renderer.cpp
#include "video_renderer.h"
#include "insta-inet.h"
#include <thread>
namespace inet = INSTAINET;

extern std::vector<INSTAINET::instaLight2022> inet::Panels;
extern std::vector<cv::Mat> inet::Cropped;

VideoRenderer::VideoRenderer(cv::VideoCapture cap, int rows, int cols, QComboBox* boxes[4][4])
    : vid(std::move(cap)), activeRows(rows), activeCols(cols) {
    // Copy 2D combo box pointers into internal array
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            comboBoxes[i][j] = boxes[i][j];
}

void VideoRenderer::process() {
    cv::Mat img;

    while (vid.grab()) {
        vid >> img;
        cv::resize(img, img, cv::Size(activeCols * 18, activeRows * 18));

        if (INSTAINET::cropImgToGrid(activeRows, activeCols, img, inet::Cropped)) {
            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    int index = comboBoxes[row][col]->currentText().toInt();
                    if (index != -1 && !inet::Cropped.empty()) {
                        inet::Panels.at(index).render(inet::Cropped.back());
                        inet::Cropped.pop_back();
                    }
                }
            }
        }

        emit frameProcessed();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
    }

    emit finished();
}

