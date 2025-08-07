#ifndef IMAGEWORKER_H
#define IMAGEWORKER_H

#include <QWidget>
#include <QComboBox>
#include <opencv2/opencv.hpp>
#include <vector>
#include "insta-inet.h"
#include "squaregraphicsview.h"
namespace inet = INSTAINET;

class imageWorker : public QObject
{
    Q_OBJECT
public:
    explicit imageWorker(QString path, int rows, int cols, QComboBox* boxes[4][4],SquareGraphicsView* gvs[4][4], std::vector<cv::Mat>& cropped);

public slots:
    void run();

private:
    QString pathToImage;
    int activeRows, activeCols;
    QComboBox* comboBoxes[4][4];
    SquareGraphicsView* graphicsViews[4][4];
    std::vector<cv::Mat>& croppedRef;

signals:
};

#endif // IMAGEWORKER_H
