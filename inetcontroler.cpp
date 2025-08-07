#include "inetcontroler.h"

namespace inet = INSTAINET;

inetControler::inetControler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inetControler)
{

    ui->setupUi(this);
    ui->detectionBar->setValue(0);


    serverWorkerThread = new QThread(this);
    serverWorkerThread->setObjectName(QString("serverWorkerThread"));
    serverWorker = new serverClass(); //Server is used as a private instace in class inetControler
    serverWorker->moveToThread(serverWorkerThread);

    QObject::connect(serverWorkerThread, &QThread::started, serverWorker, &serverClass::run);
    QObject::connect(this, &inetControler::windowIsClosing, serverWorker, &serverClass::stop);
    serverWorkerThread->start();

    idbx[0][0]=ui->comboBox00;
    idbx[0][1]=ui->comboBox01;
    idbx[0][2]=ui->comboBox02;
    idbx[0][3]=ui->comboBox03;

    idbx[1][0]=ui->comboBox10;
    idbx[1][1]=ui->comboBox11;
    idbx[1][2]=ui->comboBox12;
    idbx[1][3]=ui->comboBox13;

    idbx[2][0]=ui->comboBox20;
    idbx[2][1]=ui->comboBox21;
    idbx[2][2]=ui->comboBox22;
    idbx[2][3]=ui->comboBox23;

    idbx[3][0]=ui->comboBox30;
    idbx[3][1]=ui->comboBox31;
    idbx[3][2]=ui->comboBox32;
    idbx[3][3]=ui->comboBox33;

    gvs[0][0]=ui->gv00;
    gvs[0][1]=ui->gv01;
    gvs[0][2]=ui->gv02;
    gvs[0][3]=ui->gv03;

    gvs[1][0]=ui->gv10;
    gvs[1][1]=ui->gv11;
    gvs[1][2]=ui->gv12;
    gvs[1][3]=ui->gv13;

    gvs[2][0]=ui->gv20;
    gvs[2][1]=ui->gv21;
    gvs[2][2]=ui->gv22;
    gvs[2][3]=ui->gv23;

    gvs[3][0]=ui->gv30;
    gvs[3][1]=ui->gv31;
    gvs[3][2]=ui->gv32;
    gvs[3][3]=ui->gv33;

}

inetControler::~inetControler()
{
    //serverWorker->stop();
    delete serverWorkerThread;
    delete serverWorker;
    delete discoveryWorkerThread;
    delete discoveryWorker;
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
    discoveryWorkerThread = new QThread(this);
    discoveryWorker = new discovery(inet::IPs,ui->detectionTimeSelector->value());

    discoveryWorker->moveToThread(discoveryWorkerThread);
    QObject::connect(discoveryWorkerThread, &QThread::started ,discoveryWorker , &discovery::detect);
    QObject::connect(discoveryWorker, &discovery::valueChanged, this , [this](){
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

    QObject::connect(discoveryWorker, &discovery::tick, this , [this](int count=1){
        ui->detectionBar->setValue(count);
    });

    discoveryWorkerThread->start();
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
    int activeRows = 0;
    int activeCols = 0;

    // Check rows
    for (int row = 0; row < 4; ++row) {
        bool hasActive = false;
        for (int col = 0; col < 4; ++col) {
            int value = idbx[row][col]->currentText().toInt();
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
            int value = idbx[row][col]->currentText().toInt();
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
        ui->videoSeekBar->setEnabled(0);

        cam = new cv::VideoCapture(0);

        cameraWorker* worker = new cameraWorker(cam,activeRows, activeCols,idbx,gvs,INSTAINET::Cropped);
        QThread* cameraWorkerThread = new QThread(this);
        cameraWorkerThread->setObjectName(QString("camerWorkerThread"));
        worker->moveToThread(cameraWorkerThread);

        QObject::connect(cameraWorkerThread, &QThread::started, worker, &cameraWorker::run);

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

        cameraWorkerThread->start();

    }else if (ui->isImage->isChecked()){
        ui->stopBtn->click();
        ui->pauseBtn->setEnabled(0);
        ui->stopBtn->setEnabled(0);
        ui->videoSeekBar->setEnabled(0);


        imageWorker* worker = new class imageWorker(ui->pathSelector->text(),activeRows, activeCols, idbx, gvs , INSTAINET::Cropped);
        QThread* imageWorkerThread = new QThread(this);
        imageWorkerThread->setObjectName(QString("imageWorkerThread"));
        worker->moveToThread(imageWorkerThread);
        connect(imageWorkerThread, &QThread::started, worker, &imageWorker::run);
        imageWorkerThread->start();


    }else if (ui->isVideo->isChecked()){
        ui->stopBtn->click();
        ui->stopBtn->setEnabled(1);
        ui->pauseBtn->setEnabled(1);
        ui->renderBtn->setEnabled(0);
        ui->isCamera->setEnabled(0);
        ui->videoSeekBar->setEnabled(1);

        vidWorker = new videoWorker(ui->pathSelector->text(), activeRows, activeCols, idbx, gvs, INSTAINET::Cropped);
        videoWorkerThread = new QThread(this);
        videoWorkerThread->setObjectName(QString("videoWorkerThread"));
        vidWorker->moveToThread(videoWorkerThread);

        QObject::connect(videoWorkerThread, &QThread::started, vidWorker, &videoWorker::run);

        QObject::connect(ui->stopBtn, &QPushButton::clicked, this, [=]() mutable {
            ui->renderBtn->setEnabled(1);
            ui->stopBtn->setEnabled(0);
            ui->pauseBtn->setEnabled(0);
            vidWorker->stop();
            ui->videoSeekBar->setMaximum(2);
            ui->videoSeekBar->setValue(2);
            ui->label_2->setText(QString("File is:"));
        });

        QObject::connect(vidWorker, &videoWorker::frameCount, this, [=](int max) mutable {
            ui->videoSeekBar->setMinimum(0);
            ui->videoSeekBar->setMaximum(max);
        });

        QObject::connect(vidWorker, &videoWorker::currentFrame, this, [=](int frameNum) mutable {
            ui->videoSeekBar->setValue(frameNum);
            ui->label_2->setText(QString::number(frameNum));
        });

        connect(ui->pauseBtn, &QPushButton::clicked, this, [=]() mutable {
            vidWorker->togglePause();
        });

        connect(ui->videoSeekBar, &QSlider::sliderMoved, vidWorker, &videoWorker::setFrame,Qt::DirectConnection);

        videoWorkerThread->start();
    }
}

void inetControler::closeEvent(QCloseEvent *event)
{
    emit windowIsClosing();
    event->accept();
}

