/********************************************************************************
** Form generated from reading UI file 'inetcontroler.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INETCONTROLER_H
#define UI_INETCONTROLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inetControler
{
public:
    QWidget *centralwidget;
    QColumnView *masterControl;
    QFrame *frame;
    QPushButton *scanbtn;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpinBox *detectionTimeSelector;
    QLabel *label_10;
    QProgressBar *detectionBar;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QSlider *luminSlider;
    QSlider *freqSlider;
    QSlider *maxRedSlider;
    QSlider *maxGreenSlider;
    QSlider *maxBlueSlider;
    QRadioButton *masterToggle;
    QFrame *frame_3;
    QPushButton *toggleIds;
    QPushButton *unToggleIds;
    QSlider *redSlider;
    QSlider *greenSlider;
    QSlider *blueSlider;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line;
    QColumnView *columnView;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox00;
    QVBoxLayout *verticalLayout_11;
    QComboBox *comboBox33;
    QVBoxLayout *verticalLayout_9;
    QComboBox *comboBox21;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBox02;
    QVBoxLayout *verticalLayout_10;
    QComboBox *comboBox22;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox12;
    QVBoxLayout *verticalLayout_7;
    QComboBox *comboBox11;
    QVBoxLayout *verticalLayout_8;
    QComboBox *comboBox20;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox01;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBox13;
    QVBoxLayout *verticalLayout_13;
    QComboBox *comboBox32;
    QVBoxLayout *verticalLayout_14;
    QComboBox *comboBox31;
    QVBoxLayout *verticalLayout_15;
    QComboBox *comboBox30;
    QVBoxLayout *verticalLayout_16;
    QComboBox *comboBox23;
    QVBoxLayout *verticalLayout_17;
    QComboBox *comboBox03;
    QVBoxLayout *verticalLayout_18;
    QComboBox *comboBox10;
    QPushButton *pathSelector;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_17;
    QVBoxLayout *verticalLayout_19;
    QRadioButton *isImage;
    QRadioButton *isVideo;
    QPushButton *renderBtn;
    QPushButton *stopBtn;
    QPushButton *pauseBtn;
    QCheckBox *isCamera;

    void setupUi(QMainWindow *inetControler)
    {
        if (inetControler->objectName().isEmpty())
            inetControler->setObjectName("inetControler");
        inetControler->resize(800, 470);
        inetControler->setMinimumSize(QSize(800, 470));
        inetControler->setMaximumSize(QSize(800, 470));
        centralwidget = new QWidget(inetControler);
        centralwidget->setObjectName("centralwidget");
        masterControl = new QColumnView(centralwidget);
        masterControl->setObjectName("masterControl");
        masterControl->setGeometry(QRect(10, 10, 291, 451));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 271, 71));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        scanbtn = new QPushButton(frame);
        scanbtn->setObjectName("scanbtn");
        scanbtn->setGeometry(QRect(10, 34, 81, 31));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 6, 91, 16));
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(103, 4, 61, 23));
        lcdNumber->setSmallDecimalPoint(false);
        detectionTimeSelector = new QSpinBox(frame);
        detectionTimeSelector->setObjectName("detectionTimeSelector");
        detectionTimeSelector->setGeometry(QRect(180, 6, 42, 22));
        detectionTimeSelector->setMinimum(1);
        detectionTimeSelector->setMaximum(15);
        detectionTimeSelector->setValue(6);
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(230, 11, 58, 16));
        detectionBar = new QProgressBar(frame);
        detectionBar->setObjectName("detectionBar");
        detectionBar->setGeometry(QRect(100, 33, 161, 31));
        detectionBar->setMinimum(0);
        detectionBar->setValue(24);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 90, 271, 241));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 91, 16));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 60, 91, 16));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 90, 91, 16));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 91, 16));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 150, 91, 16));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 180, 91, 16));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 210, 91, 16));
        brightnessSlider = new QSlider(frame_2);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setEnabled(false);
        brightnessSlider->setGeometry(QRect(100, 30, 160, 25));
        brightnessSlider->setMaximum(255);
        brightnessSlider->setPageStep(200);
        brightnessSlider->setOrientation(Qt::Orientation::Horizontal);
        brightnessSlider->setTickPosition(QSlider::TickPosition::NoTicks);
        contrastSlider = new QSlider(frame_2);
        contrastSlider->setObjectName("contrastSlider");
        contrastSlider->setEnabled(false);
        contrastSlider->setGeometry(QRect(100, 60, 160, 25));
        contrastSlider->setMaximum(255);
        contrastSlider->setPageStep(200);
        contrastSlider->setOrientation(Qt::Orientation::Horizontal);
        luminSlider = new QSlider(frame_2);
        luminSlider->setObjectName("luminSlider");
        luminSlider->setEnabled(false);
        luminSlider->setGeometry(QRect(100, 90, 160, 25));
        luminSlider->setMaximum(255);
        luminSlider->setPageStep(200);
        luminSlider->setOrientation(Qt::Orientation::Horizontal);
        freqSlider = new QSlider(frame_2);
        freqSlider->setObjectName("freqSlider");
        freqSlider->setEnabled(false);
        freqSlider->setGeometry(QRect(100, 120, 160, 25));
        freqSlider->setMaximum(255);
        freqSlider->setPageStep(200);
        freqSlider->setOrientation(Qt::Orientation::Horizontal);
        maxRedSlider = new QSlider(frame_2);
        maxRedSlider->setObjectName("maxRedSlider");
        maxRedSlider->setEnabled(false);
        maxRedSlider->setGeometry(QRect(100, 150, 160, 25));
        maxRedSlider->setMaximum(255);
        maxRedSlider->setPageStep(200);
        maxRedSlider->setOrientation(Qt::Orientation::Horizontal);
        maxGreenSlider = new QSlider(frame_2);
        maxGreenSlider->setObjectName("maxGreenSlider");
        maxGreenSlider->setEnabled(false);
        maxGreenSlider->setGeometry(QRect(100, 180, 160, 25));
        maxGreenSlider->setMaximum(255);
        maxGreenSlider->setPageStep(200);
        maxGreenSlider->setOrientation(Qt::Orientation::Horizontal);
        maxBlueSlider = new QSlider(frame_2);
        maxBlueSlider->setObjectName("maxBlueSlider");
        maxBlueSlider->setEnabled(false);
        maxBlueSlider->setGeometry(QRect(100, 210, 160, 25));
        maxBlueSlider->setMaximum(255);
        maxBlueSlider->setPageStep(200);
        maxBlueSlider->setOrientation(Qt::Orientation::Horizontal);
        maxBlueSlider->setTickPosition(QSlider::TickPosition::NoTicks);
        masterToggle = new QRadioButton(frame_2);
        masterToggle->setObjectName("masterToggle");
        masterToggle->setEnabled(false);
        masterToggle->setGeometry(QRect(70, 7, 121, 20));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 329, 271, 121));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        toggleIds = new QPushButton(frame_3);
        toggleIds->setObjectName("toggleIds");
        toggleIds->setEnabled(false);
        toggleIds->setGeometry(QRect(4, 0, 201, 41));
        unToggleIds = new QPushButton(frame_3);
        unToggleIds->setObjectName("unToggleIds");
        unToggleIds->setEnabled(false);
        unToggleIds->setGeometry(QRect(208, 0, 61, 41));
        redSlider = new QSlider(frame_3);
        redSlider->setObjectName("redSlider");
        redSlider->setEnabled(false);
        redSlider->setGeometry(QRect(89, 40, 161, 25));
        redSlider->setMaximum(255);
        redSlider->setOrientation(Qt::Orientation::Horizontal);
        greenSlider = new QSlider(frame_3);
        greenSlider->setObjectName("greenSlider");
        greenSlider->setEnabled(false);
        greenSlider->setGeometry(QRect(90, 66, 160, 25));
        greenSlider->setMaximum(255);
        greenSlider->setOrientation(Qt::Orientation::Horizontal);
        blueSlider = new QSlider(frame_3);
        blueSlider->setObjectName("blueSlider");
        blueSlider->setEnabled(false);
        blueSlider->setGeometry(QRect(90, 93, 160, 25));
        blueSlider->setMaximum(255);
        blueSlider->setOrientation(Qt::Orientation::Horizontal);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 43, 61, 16));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 69, 61, 16));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 97, 61, 16));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(298, -10, 20, 531));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        columnView = new QColumnView(centralwidget);
        columnView->setObjectName("columnView");
        columnView->setGeometry(QRect(315, 71, 481, 391));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(320, 80, 471, 381));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        comboBox00 = new QComboBox(gridLayoutWidget_2);
        comboBox00->setObjectName("comboBox00");

        verticalLayout_2->addWidget(comboBox00);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        comboBox33 = new QComboBox(gridLayoutWidget_2);
        comboBox33->setObjectName("comboBox33");

        verticalLayout_11->addWidget(comboBox33);


        gridLayout_2->addLayout(verticalLayout_11, 3, 3, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        comboBox21 = new QComboBox(gridLayoutWidget_2);
        comboBox21->setObjectName("comboBox21");

        verticalLayout_9->addWidget(comboBox21);


        gridLayout_2->addLayout(verticalLayout_9, 2, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        comboBox02 = new QComboBox(gridLayoutWidget_2);
        comboBox02->setObjectName("comboBox02");

        verticalLayout_4->addWidget(comboBox02);


        gridLayout_2->addLayout(verticalLayout_4, 0, 2, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        comboBox22 = new QComboBox(gridLayoutWidget_2);
        comboBox22->setObjectName("comboBox22");

        verticalLayout_10->addWidget(comboBox22);


        gridLayout_2->addLayout(verticalLayout_10, 2, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        comboBox12 = new QComboBox(gridLayoutWidget_2);
        comboBox12->setObjectName("comboBox12");

        verticalLayout_6->addWidget(comboBox12);


        gridLayout_2->addLayout(verticalLayout_6, 1, 2, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        comboBox11 = new QComboBox(gridLayoutWidget_2);
        comboBox11->setObjectName("comboBox11");

        verticalLayout_7->addWidget(comboBox11);


        gridLayout_2->addLayout(verticalLayout_7, 1, 1, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        comboBox20 = new QComboBox(gridLayoutWidget_2);
        comboBox20->setObjectName("comboBox20");

        verticalLayout_8->addWidget(comboBox20);


        gridLayout_2->addLayout(verticalLayout_8, 2, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        comboBox01 = new QComboBox(gridLayoutWidget_2);
        comboBox01->setObjectName("comboBox01");

        verticalLayout_3->addWidget(comboBox01);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        comboBox13 = new QComboBox(gridLayoutWidget_2);
        comboBox13->setObjectName("comboBox13");

        verticalLayout_5->addWidget(comboBox13);


        gridLayout_2->addLayout(verticalLayout_5, 1, 3, 1, 1);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        comboBox32 = new QComboBox(gridLayoutWidget_2);
        comboBox32->setObjectName("comboBox32");

        verticalLayout_13->addWidget(comboBox32);


        gridLayout_2->addLayout(verticalLayout_13, 3, 2, 1, 1);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        comboBox31 = new QComboBox(gridLayoutWidget_2);
        comboBox31->setObjectName("comboBox31");

        verticalLayout_14->addWidget(comboBox31);


        gridLayout_2->addLayout(verticalLayout_14, 3, 1, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        comboBox30 = new QComboBox(gridLayoutWidget_2);
        comboBox30->setObjectName("comboBox30");

        verticalLayout_15->addWidget(comboBox30);


        gridLayout_2->addLayout(verticalLayout_15, 3, 0, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        comboBox23 = new QComboBox(gridLayoutWidget_2);
        comboBox23->setObjectName("comboBox23");

        verticalLayout_16->addWidget(comboBox23);


        gridLayout_2->addLayout(verticalLayout_16, 2, 3, 1, 1);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        comboBox03 = new QComboBox(gridLayoutWidget_2);
        comboBox03->setObjectName("comboBox03");

        verticalLayout_17->addWidget(comboBox03);


        gridLayout_2->addLayout(verticalLayout_17, 0, 3, 1, 1);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        comboBox10 = new QComboBox(gridLayoutWidget_2);
        comboBox10->setObjectName("comboBox10");

        verticalLayout_18->addWidget(comboBox10);


        gridLayout_2->addLayout(verticalLayout_18, 1, 0, 1, 1);

        pathSelector = new QPushButton(centralwidget);
        pathSelector->setObjectName("pathSelector");
        pathSelector->setEnabled(false);
        pathSelector->setGeometry(QRect(320, 0, 411, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 31, 41, 16));
        verticalLayoutWidget_17 = new QWidget(centralwidget);
        verticalLayoutWidget_17->setObjectName("verticalLayoutWidget_17");
        verticalLayoutWidget_17->setGeometry(QRect(360, 30, 71, 41));
        verticalLayout_19 = new QVBoxLayout(verticalLayoutWidget_17);
        verticalLayout_19->setObjectName("verticalLayout_19");
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        isImage = new QRadioButton(verticalLayoutWidget_17);
        isImage->setObjectName("isImage");
        isImage->setEnabled(false);

        verticalLayout_19->addWidget(isImage);

        isVideo = new QRadioButton(verticalLayoutWidget_17);
        isVideo->setObjectName("isVideo");
        isVideo->setEnabled(false);

        verticalLayout_19->addWidget(isVideo);

        renderBtn = new QPushButton(centralwidget);
        renderBtn->setObjectName("renderBtn");
        renderBtn->setEnabled(false);
        renderBtn->setGeometry(QRect(450, 30, 151, 41));
        QFont font;
        font.setBold(false);
        renderBtn->setFont(font);
        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setEnabled(false);
        stopBtn->setGeometry(QRect(700, 30, 90, 41));
        pauseBtn = new QPushButton(centralwidget);
        pauseBtn->setObjectName("pauseBtn");
        pauseBtn->setEnabled(false);
        pauseBtn->setGeometry(QRect(610, 30, 90, 41));
        isCamera = new QCheckBox(centralwidget);
        isCamera->setObjectName("isCamera");
        isCamera->setGeometry(QRect(736, 5, 61, 21));
        inetControler->setCentralWidget(centralwidget);

        retranslateUi(inetControler);

        QMetaObject::connectSlotsByName(inetControler);
    } // setupUi

    void retranslateUi(QMainWindow *inetControler)
    {
        inetControler->setWindowTitle(QCoreApplication::translate("inetControler", "inetControler", nullptr));
        scanbtn->setText(QCoreApplication::translate("inetControler", "Scan", nullptr));
        label->setText(QCoreApplication::translate("inetControler", "Panels found:", nullptr));
        label_10->setText(QCoreApplication::translate("inetControler", "Sec.", nullptr));
        label_3->setText(QCoreApplication::translate("inetControler", "Brightness", nullptr));
        label_4->setText(QCoreApplication::translate("inetControler", "Contrast", nullptr));
        label_5->setText(QCoreApplication::translate("inetControler", "Lumin time", nullptr));
        label_6->setText(QCoreApplication::translate("inetControler", "Frequency", nullptr));
        label_7->setText(QCoreApplication::translate("inetControler", "Max. Red", nullptr));
        label_8->setText(QCoreApplication::translate("inetControler", "Max. Green", nullptr));
        label_9->setText(QCoreApplication::translate("inetControler", "Max. Blue", nullptr));
        masterToggle->setText(QCoreApplication::translate("inetControler", "Master Control", nullptr));
        toggleIds->setText(QCoreApplication::translate("inetControler", "show IDs", nullptr));
        unToggleIds->setText(QCoreApplication::translate("inetControler", "Clear", nullptr));
        label_11->setText(QCoreApplication::translate("inetControler", "Red", nullptr));
        label_12->setText(QCoreApplication::translate("inetControler", "Green", nullptr));
        label_13->setText(QCoreApplication::translate("inetControler", "Blue", nullptr));
        pathSelector->setText(QCoreApplication::translate("inetControler", "Select path of video or file", nullptr));
        label_2->setText(QCoreApplication::translate("inetControler", "File is:", nullptr));
        isImage->setText(QCoreApplication::translate("inetControler", "Image", nullptr));
        isVideo->setText(QCoreApplication::translate("inetControler", "Video", nullptr));
        renderBtn->setText(QCoreApplication::translate("inetControler", "\360\237\223\272", nullptr));
        stopBtn->setText(QCoreApplication::translate("inetControler", "\342\217\271\357\270\217", nullptr));
        pauseBtn->setText(QCoreApplication::translate("inetControler", "\342\217\257\357\270\217", nullptr));
        isCamera->setText(QCoreApplication::translate("inetControler", "\360\237\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inetControler: public Ui_inetControler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INETCONTROLER_H
