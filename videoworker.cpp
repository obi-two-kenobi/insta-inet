#include "videoWorker.h"
#include "insta-inet.h"
#include <thread>

videoWorker::videoWorker(QString path, int rows, int cols, QComboBox* boxes[4][4], std::vector<cv::Mat>& cropped)
    : pathToVideo(path), activeRows(rows), activeCols(cols), croppedRef(cropped)
{
    // Copy QComboBox* array
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            comboBoxes[i][j] = boxes[i][j];
}

void videoWorker::run()
{
    cv::VideoCapture vid(pathToVideo.toStdString());
    cv::Mat img;
    double fps = vid.get(cv::CAP_PROP_FPS);
    int delay = static_cast<int>(1000.0 / fps);


    while (!isStopped) {
        if (isPaused) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        vid >> img;
        if (img.empty()) break;
        cv::resize(img, img, cv::Size(activeCols * 18, activeRows * 18));

        if (INSTAINET::cropImgToGrid(activeRows, activeCols, img, croppedRef)) {
            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    int index = comboBoxes[row][col]->currentText().toInt();
                    if (index != -1 && !croppedRef.empty()) {
                        INSTAINET::Panels.at(index).render(croppedRef.back());
                        croppedRef.pop_back();
                    }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    this->deleteLater();  // Automatically clean up
}

void videoWorker::pause()
{
    isPaused = true;
}

void videoWorker::resume()
{
    isPaused = false;
}

void videoWorker::stop()
{
    isStopped = true;
}

void videoWorker::togglePause() {
    isPaused = !isPaused;
}
