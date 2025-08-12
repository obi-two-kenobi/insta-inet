#include "videoWorker.h"
#include "insta-inet.h"
#include <thread>

videoWorker::videoWorker(QString path, int rows, int cols, QComboBox* boxes[4][4],QGraphicsView* gvs[4][4], std::vector<cv::Mat>& cropped)
    : pathToVideo(path), activeRows(rows), activeCols(cols), croppedRef(cropped)
{
    // Copy QComboBox* array
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            comboBoxes[i][j] = boxes[i][j];
    //Copy SquareGraphicsView
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            this->graphicsViews[i][j] = gvs[i][j];
}

void videoWorker::run()
{
    vid = new cv::VideoCapture(pathToVideo.toStdString());
    cv::Mat img;
    double fps = vid->get(cv::CAP_PROP_FPS);
    int delay = static_cast<int>(1000.0 / fps);
    emit frameCount(static_cast<int>(vid->get(cv::CAP_PROP_FRAME_COUNT)));


    while (!isStopped) {
        if (isPaused) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        if (userFrameCount!=-1) {vid->set(cv::CAP_PROP_POS_FRAMES, userFrameCount-1); userFrameCount=-1;}
        if (!vid->read(img)) break;
        if (img.empty()) break;
        emit currentFrame(static_cast<int>(vid->get(cv::CAP_PROP_POS_FRAMES)));
        cv::resize(img, img, cv::Size(activeCols * 18, activeRows * 18));

        if (INSTAINET::cropImgToGrid(activeRows, activeCols, img, croppedRef)) {
            for (int row = 3; row >= 0; --row) {
                for (int col = 3; col >= 0; --col) {
                    int index = comboBoxes[row][col]->currentText().toInt();
                    if (index != -1 && !croppedRef.empty()) {
                        auto workingpart = croppedRef.back();
                        INSTAINET::Panels.at(index).render(workingpart);
                        cv::cvtColor(workingpart, workingpart, cv::COLOR_BGR2RGB);
                        QImage Qworkingpart(workingpart.data, workingpart.cols, workingpart.rows, workingpart.step, QImage::Format_RGB888);
                        QPixmap pixmap = QPixmap::fromImage(Qworkingpart);
                        QGraphicsScene* scene = new QGraphicsScene(graphicsViews[row][col]);
                        scene->addPixmap(pixmap);
                        graphicsViews[row][col] -> setScene(scene);
                        graphicsViews[row][col] -> fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
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

void videoWorker::setFrame(int frameNumber)
{
    userFrameCount = frameNumber;
    qDebug() << "\n\n\n" << "new frame: " << frameNumber << "recieved\n\n\n";

}
