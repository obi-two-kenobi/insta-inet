#pragma once

#include <QObject>
#include <QComboBox>
#include <opencv2/opencv.hpp>
#include <vector>

/**
 * @class cameraWorker
 * @brief Handles video stream processing for Instalight 2022 panels.
 *
 * This class manages the acquisition of frames from a video file,
 * processes the frames (such as cropping), and interacts with a 4x4 grid of QComboBox widgets
 * that represent the position of the panels in real life.
 * It supports pausing, resuming, and stopping the camera processing thread.
 *
 * @note This class is designed to be used with Qt's signal/slot mechanism.
 *
 * @param path to video file.
 * @param rows Number of active rows in the combo box grid.
 * @param cols Number of active columns in the combo box grid.
 * @param boxes 4x4 array of pointers to QComboBox widgets for UI interaction.
 * @param cropped Reference to a vector of cv::Mat objects where cropped frames are stored.
 *
 * @fn void run()
 *      Starts or continues the camera processing loop.
 * @fn void pause()
 *      Pauses the camera processing.
 * @fn void resume()
 *      Resumes the camera processing if paused.
 * @fn void stop()
 *      Stops the camera processing.
 * @fn void togglePause()
 *      Toggles between paused and running states.
 *
 * @private
 * @var QComboBox* comboBoxes[4][4]
 *      4x4 array of pointers to QComboBox widgets for user interaction.
 * @var std::vector<cv::Mat>& croppedRef
 *      Reference to the vector storing cropped frame regions.
 * @var int activeRows
 *      Number of active rows in the combo box grid.
 * @var int activeCols
 *      Number of active columns in the combo box grid.
 * @var bool isPaused
 *      Indicates whether the processing is currently paused.
 * @var bool isStopped
 *      Indicates whether the processing has been stopped.
 * @var cv::VideoCapture* cam
 *      Pointer to the camera capture device.
 */

class videoWorker : public QObject {
    Q_OBJECT

public:
    videoWorker(QString path, int rows, int cols, QComboBox* boxes[4][4], std::vector<cv::Mat>& cropped);

public slots:
    void run();
    void pause();
    void resume();
    void stop();
    void togglePause();


private:
    QString pathToVideo;
    int activeRows, activeCols;
    QComboBox* comboBoxes[4][4];
    std::vector<cv::Mat>& croppedRef;

    bool isPaused= false;
    bool isStopped = false;
};
