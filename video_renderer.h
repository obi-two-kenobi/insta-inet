// video_renderer.h
#pragma once
#include <QObject>
#include <QtWidgets/qcombobox.h>
#include <opencv2/opencv.hpp>

/**
 * @class VideoRenderer
 * @brief Handles video frame processing and interaction with a grid of QComboBox widgets.
 *
 * The VideoRenderer class is responsible for processing video frames from a given
 * cv::VideoCapture source and updating a 4x4 grid of QComboBox widgets accordingly.
 * It emits signals when a frame is processed and when processing is finished.
 *
 * @note This class inherits from QObject to support Qt's signal and slot mechanism.
 *
 * @signals
 *   void frameProcessed() - Emitted after a video frame has been processed.
 *   void finished() - Emitted when video processing is complete.
 *
 * @constructor
 *   VideoRenderer(cv::VideoCapture cap, int rows, int cols, QComboBox* boxes[4][4])
 *     Constructs a VideoRenderer with the specified video capture source, grid dimensions,
 *     and pointers to the QComboBox widgets.
 *
 * @slot
 *   void process()
 *     Processes the next video frame and updates the associated QComboBox widgets.
 *
 * @private
 *   cv::VideoCapture vid - The video capture source.
 *   int activeRows, activeCols - The number of active rows and columns in the grid.
 *   QComboBox* comboBoxes[4][4] - Pointers to the 4x4 grid of QComboBox widgets.
 */
class VideoRenderer : public QObject {
    Q_OBJECT
public:
signals:
    void frameProcessed ();
    void finished();
    VideoRenderer (cv:: VideoCapture cap, int rows, int cols, QComboBox* boxes[4][4]);
public slots:
    void process ();
private:
    cv:: VideoCapture vid; int activeRows, activeCols;
    QComboBox* comboBoxes[4][4];
} ;
