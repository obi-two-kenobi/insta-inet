#include "imageWorker.h"


imageWorker::imageWorker(QString path, int rows, int cols, QComboBox *boxes[4][4], QGraphicsView* gvs[4][4], std::vector<cv::Mat> &cropped)
    : pathToImage(path), activeRows(rows), activeCols(cols), croppedRef(cropped)
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

void imageWorker::run()
{
    cv::Mat img = cv::imread(pathToImage.toStdString().c_str());
    cv::resize(img,img,cv::Size(activeCols*18,activeRows*18));
    if(INSTAINET::cropImgToGrid(activeRows, activeCols, img, inet::Cropped)){
        for(int row = 3; row >= 0; --row){
            for(int col = 3; col >= 0; --col){
                auto index = comboBoxes[row][col]->currentText().toInt();
                if (index!=-1){
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

    this->deleteLater();  // Automatically clean up
}
