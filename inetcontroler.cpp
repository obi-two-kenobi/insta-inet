#include "inetcontroler.h"
#include "discovery.h"
#include "server.h"
#include "ui_inetcontroler.h"
#include "insta-inet.h"
#include "videoworker.h"
#include "cameraworker.h"
#include <QtCore/qthread.h>
namespace inet = INSTAINET;

inetControler::inetControler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inetControler)
{
    std::thread transmitter(INSTAINET::TransmitData, &INSTAINET::Panels, 9410, false, 50); transmitter.detach();
    //QThread* serverWorker = new QThread(this);
    //server* Server = new server();

    //Server->moveToThread(serverWorker);
    //serverWorker->start();

    ui->setupUi(this);
    ui->detectionBar->setValue(0);
}

inetControler::~inetControler()
{
    delete ui;
}

void inetControler::on_scanbtn_clicked()
{
    this->ui->brightnessSlider->setSliderPosition(0xc1);
    this->ui->contrastSlider->setSliderPosition(0x7d);
    this->ui->luminSlider->setSliderPosition(0x00);
    this->ui->freqSlider->setSliderPosition(0x00);
    this->ui->maxBlueSlider->setSliderPosition(0xff);
    this->ui->maxGreenSlider->setSliderPosition(0xff);
    this->ui->maxRedSlider->setSliderPosition(0xff);
    ui->detectionBar->setMaximum(ui->detectionTimeSelector->value());

    inet::IPs.clear();
    inet::Panels.clear();

    //inet::discoverPanels(inet::IPs, ui->detectionTimeSelector->value()); //blocking. used the discovery library.
    QThread* discThread = new QThread(this);
    discovery* discoverer = new discovery(inet::IPs,ui->detectionTimeSelector->value());

    discoverer->moveToThread(discThread);
    QObject::connect(discThread, &QThread::started ,discoverer , &discovery::detect);
    QObject::connect(discoverer, &discovery::valueChanged, this , [this](){
        this->ui->scanbtn->setText(QString("Rescan"));

        QList<QComboBox*> boxes = {
            ui->comboBox00, ui->comboBox01, ui->comboBox02, ui->comboBox03,
            ui->comboBox10, ui->comboBox11, ui->comboBox12, ui->comboBox13,
            ui->comboBox20, ui->comboBox21, ui->comboBox22, ui->comboBox23,
            ui->comboBox30, ui->comboBox31, ui->comboBox32, ui->comboBox33
        };
        for (auto box : boxes) box->clear();
        for (auto box : boxes) box->addItem(QString::number(-1));

        if (inet::IPs.size() < 1) {this->ui->lcdNumber->display(0);}
        else{
            ui->pathSelector->setEnabled(1);
            ui->isCamera->setEnabled(1);
            for (auto& IP : inet::IPs){
                inet::Panels.push_back(inet::instaLight2022(IP));
            }
            this->ui->lcdNumber->display((int)inet::Panels.size());
            for (size_t i=0; i<inet::Panels.size();i++){
                for (auto box : boxes) box->addItem(QString::number(i));
            }
        }


        inet::IPs.clear();
        ui->masterToggle->setEnabled(1);
    });

    QObject::connect(discoverer, &discovery::tick, this , [this](int count=1){
        ui->detectionBar->setValue(count);
    });

    discThread->start();
    this->ui->scanbtn->setText(QString("Scanning..."));
}


void inetControler::on_brightnessSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setBrightness(value,value);
        }
    }
}


void inetControler::on_contrastSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setContrast(value,value);
        }
    }
}


void inetControler::on_luminSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setLuminTime(value,value);
        }
    }
}


void inetControler::on_freqSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setFrequency(value,value);
        }
    }
}


void inetControler::on_maxRedSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setMaxRGB(value,this->ui->maxGreenSlider->value(),this->ui->maxBlueSlider->value(),value,this->ui->maxGreenSlider->value(),this->ui->maxBlueSlider->value());
        }
    }
}


void inetControler::on_maxGreenSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setMaxRGB(this->ui->maxRedSlider->value(),value,this->ui->maxBlueSlider->value(),this->ui->maxRedSlider->value(),value,this->ui->maxBlueSlider->value());
        }
    }

}


void inetControler::on_maxBlueSlider_valueChanged(int value)
{
    if(this->ui->masterToggle->isChecked()){
        for(auto& panel : inet::Panels){
            panel.setMaxRGB(this->ui->maxRedSlider->value(),this->ui->maxGreenSlider->value(),value,this->ui->maxRedSlider->value(),this->ui->maxGreenSlider->value(),value);
        }
    }

}


void inetControler::on_pathSelector_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Select Image or Video"),                // Dialog title
                                                    QDir::homePath(),                   // Starting directory
                                                    tr("Images and Videos (*.png *.jpg *.jpeg *.bmp *.mp4 *.mov);;All Files (*)")); // File filters

    if (!filePath.isEmpty()) {
        this->ui->pathSelector->setText(filePath);
        ui->renderBtn->setEnabled(1);
        ui->isImage->setEnabled(1);
        ui->isVideo->setEnabled(1);

        QFileInfo fileInfo(filePath);
        QString extension = fileInfo.suffix().toLower();

        if (extension == "jpg" || extension == "png" || extension == "jpeg" || extension == "bmp") {
            this->ui->isImage->setChecked(1);
            this->ui->isVideo->setChecked(0);
        } else if (extension == "mp4" || extension == "mov" ) {
            this->ui->isImage->setChecked(0);
            this->ui->isVideo->setChecked(1);
        }

    }
}


void inetControler::on_toggleIds_clicked()
{
    cv::Mat img;
    int counter = 0;
    for(auto& panel : inet::Panels){
        img = cv::Mat(18, 18, CV_8UC3, cv::Scalar(ui->blueSlider->value(),ui->greenSlider->value(),ui->redSlider->value()));
        cv::putText(img, std::to_string(counter++), cv::Point(2, 15), cv::FONT_HERSHEY_PLAIN , 1.3, cv::Scalar(0));
        panel.render(img);
    }
    img.release();
}


void inetControler::on_unToggleIds_clicked()
{
    cv::Mat img;
    for(auto& panel : inet::Panels){
        img = cv::Mat(18, 18, CV_8UC3, cv::Scalar(ui->blueSlider->value(),ui->greenSlider->value(),ui->redSlider->value()));
        panel.render(img);
    }
    img.release();
}


void inetControler::on_masterToggle_toggled(bool checked)
{
    QList<QSlider*> masterSliders ={
        ui->brightnessSlider,ui->contrastSlider, ui->freqSlider, ui->luminSlider,
        ui->maxBlueSlider, ui->maxGreenSlider, ui->maxRedSlider, ui->redSlider,
        ui->blueSlider, ui->greenSlider
    };
    for (auto slider : masterSliders) slider->setEnabled(checked);
    ui->toggleIds->setEnabled(checked);
    ui->unToggleIds->setEnabled(checked);

}


void inetControler::on_isCamera_clicked(bool checked)
{
    ui->pathSelector->setEnabled(!checked);
    if(checked) ui->renderBtn->setEnabled(1);
    if(!checked && !ui->isVideo->isEnabled())ui->renderBtn->setEnabled(0);

}


void inetControler::on_renderBtn_clicked()
{

    QComboBox* boxes[4][4] = {
        {ui->comboBox00, ui->comboBox01, ui->comboBox02, ui->comboBox03},
        {ui->comboBox10, ui->comboBox11, ui->comboBox12, ui->comboBox13},
        {ui->comboBox20, ui->comboBox21, ui->comboBox22, ui->comboBox23},
        {ui->comboBox30, ui->comboBox31, ui->comboBox32, ui->comboBox33}
    };
    int activeRows = 0;
    int activeCols = 0;

    // Check rows
    for (int row = 0; row < 4; ++row) {
        bool hasActive = false;
        for (int col = 0; col < 4; ++col) {
            int value = boxes[row][col]->currentText().toInt();
            if (value != -1) {
                hasActive = true;
                break;
            }
        }
        if (hasActive) activeRows++;
    }

    // Check columns
    for (int col = 0; col < 4; ++col) {
        bool hasActive = false;
        for (int row = 0; row < 4; ++row) {
            int value = boxes[row][col]->currentText().toInt();
            if (value != -1) {
                hasActive = true;
                break;
            }
        }
        if (hasActive) activeCols++;
    }
    if(activeCols == 0) return;

    if (ui->isCamera->isChecked()){

        ui->pauseBtn->setEnabled(1);
        ui->stopBtn->setEnabled(1);
        ui->renderBtn->setEnabled(0);

        cv::VideoCapture* cam = new cv::VideoCapture(0);

        cameraWorker* worker = new cameraWorker(cam,activeRows, activeCols,boxes,INSTAINET::Cropped);
        QThread* workerThread = new QThread(this);
        worker->moveToThread(workerThread);

        QObject::connect(workerThread, &QThread::started, worker, &cameraWorker::run);

        QObject::connect(ui->stopBtn, &QPushButton::clicked, this, [=]() mutable {
            ui->renderBtn->setEnabled(1);
            ui->stopBtn->setEnabled(0);
            ui->pauseBtn->setEnabled(0);
            ui->isCamera->setEnabled(1);
            ui->isCamera->setChecked(0);
            worker->stop();
            cam->release();
        });

        bool isPaused = false;
        connect(ui->pauseBtn, &QPushButton::clicked, this, [=, &isPaused]() mutable {
            worker->togglePause();
            isPaused = !isPaused;
        });

        workerThread->start();

    }else if (ui->isImage->isChecked()){
        ui->stopBtn->click();
        ui->pauseBtn->setEnabled(0);
        ui->stopBtn->setEnabled(0);
        cv::Mat img = cv::imread(ui->pathSelector->text().toStdString().c_str());
        cv::resize(img,img,cv::Size(activeCols*18,activeRows*18));
        if(INSTAINET::cropImgToGrid(activeRows, activeCols, img, inet::Cropped)){
            for(int row = 0; row < 4; ++row){
                for(int col = 0; col < 4; ++col){
                    auto index = boxes[row][col]->currentText().toInt();
                    if (index!=-1){
                        inet::Panels.at(index).render(inet::Cropped.back());
                        inet::Cropped.pop_back();
                    }
                }
            }
        }


    }else if (ui->isVideo->isChecked()){
        ui->stopBtn->click();
        ui->stopBtn->setEnabled(1);
        ui->pauseBtn->setEnabled(1);
        ui->renderBtn->setEnabled(0);
        ui->isCamera->setEnabled(0);

        videoWorker* worker = new videoWorker(ui->pathSelector->text(), activeRows, activeCols, boxes, INSTAINET::Cropped);
        QThread* workerThread = new QThread(this);

        worker->moveToThread(workerThread);

        QObject::connect(workerThread, &QThread::started, worker, &videoWorker::run);

        QObject::connect(ui->stopBtn, &QPushButton::clicked, this, [=]() mutable {
            ui->renderBtn->setEnabled(1);
            ui->stopBtn->setEnabled(0);
            ui->pauseBtn->setEnabled(0);
            worker->stop();
        });

        bool isPaused = false;
        connect(ui->pauseBtn, &QPushButton::clicked, this, [=, &isPaused]() mutable {
            worker->togglePause();
            isPaused = !isPaused;
        });



        workerThread->start();
    }

}



