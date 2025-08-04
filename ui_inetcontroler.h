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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "squaregraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_inetControler
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *line_6;
    QFrame *line_7;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_11;
    QFrame *line_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *toggleIds;
    QPushButton *unToggleIds;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *masterToggle;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLabel *label_5;
    QSlider *maxRedSlider;
    QSlider *contrastSlider;
    QLabel *label_7;
    QSlider *maxBlueSlider;
    QSlider *maxGreenSlider;
    QLabel *label_9;
    QLabel *label_4;
    QSlider *freqSlider;
    QLabel *label_6;
    QLabel *label_3;
    QSlider *brightnessSlider;
    QSlider *luminSlider;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pathSelector;
    QCheckBox *isCamera;
    QSpacerItem *verticalSpacer_7;
    QFrame *line_9;
    QLabel *label_14;
    QFrame *line_3;
    QGridLayout *gridLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSlider *redSlider;
    QSlider *blueSlider;
    QSlider *greenSlider;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QRadioButton *isVideo;
    QRadioButton *isImage;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout;
    QComboBox *comboBox32;
    QComboBox *comboBox20;
    QComboBox *comboBox30;
    QComboBox *comboBox21;
    QComboBox *comboBox31;
    QComboBox *comboBox03;
    QComboBox *comboBox22;
    QComboBox *comboBox13;
    QComboBox *comboBox33;
    QComboBox *comboBox01;
    QComboBox *comboBox12;
    QComboBox *comboBox02;
    QComboBox *comboBox11;
    QComboBox *comboBox10;
    QComboBox *comboBox00;
    QComboBox *comboBox23;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *scanbtn;
    QProgressBar *detectionBar;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_8;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpinBox *detectionTimeSelector;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *renderBtn;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;
    QSpacerItem *verticalSpacer;
    QGridLayout *simGrid;
    SquareGraphicsView *gv21;
    SquareGraphicsView *gv23;
    SquareGraphicsView *gv03;
    SquareGraphicsView *gv00;
    SquareGraphicsView *gv20;
    SquareGraphicsView *gv13;
    SquareGraphicsView *gv01;
    SquareGraphicsView *gv02;
    SquareGraphicsView *gv10;
    SquareGraphicsView *gv12;
    SquareGraphicsView *gv22;
    SquareGraphicsView *gv11;
    SquareGraphicsView *gv30;
    SquareGraphicsView *gv31;
    SquareGraphicsView *gv32;
    SquareGraphicsView *gv33;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QMainWindow *inetControler)
    {
        if (inetControler->objectName().isEmpty())
            inetControler->setObjectName("inetControler");
        inetControler->resize(700, 713);
        inetControler->setMinimumSize(QSize(700, 700));
        inetControler->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(inetControler);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_6, 0, 3, 1, 1);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_7, 19, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 13, 1, 1, 1);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName("line_11");
        line_11->setFrameShape(QFrame::Shape::HLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_11, 14, 1, 1, 1);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_5, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        toggleIds = new QPushButton(centralwidget);
        toggleIds->setObjectName("toggleIds");
        toggleIds->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toggleIds->sizePolicy().hasHeightForWidth());
        toggleIds->setSizePolicy(sizePolicy);
        toggleIds->setMinimumSize(QSize(180, 32));
        toggleIds->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_2->addWidget(toggleIds);

        unToggleIds = new QPushButton(centralwidget);
        unToggleIds->setObjectName("unToggleIds");
        unToggleIds->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(unToggleIds->sizePolicy().hasHeightForWidth());
        unToggleIds->setSizePolicy(sizePolicy1);
        unToggleIds->setMinimumSize(QSize(55, 32));
        unToggleIds->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_2->addWidget(unToggleIds);


        gridLayout_2->addLayout(horizontalLayout_2, 16, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 10, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        masterToggle = new QCheckBox(centralwidget);
        masterToggle->setObjectName("masterToggle");
        masterToggle->setEnabled(false);

        horizontalLayout->addWidget(masterToggle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 7, 1, 3, 1);

        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName("splitter_3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy2);
        splitter_3->setOrientation(Qt::Orientation::Horizontal);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName("splitter_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy3);
        splitter_2->setOrientation(Qt::Orientation::Vertical);
        splitter_3->addWidget(splitter_2);

        gridLayout_2->addWidget(splitter_3, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(80, 32));
        label_8->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_8, 5, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(80, 32));
        label_5->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        maxRedSlider = new QSlider(centralwidget);
        maxRedSlider->setObjectName("maxRedSlider");
        maxRedSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(maxRedSlider->sizePolicy().hasHeightForWidth());
        maxRedSlider->setSizePolicy(sizePolicy);
        maxRedSlider->setMinimumSize(QSize(160, 32));
        maxRedSlider->setMaximumSize(QSize(16777215, 32));
        maxRedSlider->setMaximum(255);
        maxRedSlider->setPageStep(200);
        maxRedSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(maxRedSlider, 4, 1, 1, 1);

        contrastSlider = new QSlider(centralwidget);
        contrastSlider->setObjectName("contrastSlider");
        contrastSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(contrastSlider->sizePolicy().hasHeightForWidth());
        contrastSlider->setSizePolicy(sizePolicy);
        contrastSlider->setMinimumSize(QSize(160, 32));
        contrastSlider->setMaximumSize(QSize(16777215, 32));
        contrastSlider->setMaximum(255);
        contrastSlider->setPageStep(200);
        contrastSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(contrastSlider, 1, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(80, 32));
        label_7->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        maxBlueSlider = new QSlider(centralwidget);
        maxBlueSlider->setObjectName("maxBlueSlider");
        maxBlueSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(maxBlueSlider->sizePolicy().hasHeightForWidth());
        maxBlueSlider->setSizePolicy(sizePolicy);
        maxBlueSlider->setMinimumSize(QSize(160, 32));
        maxBlueSlider->setMaximumSize(QSize(16777215, 32));
        maxBlueSlider->setMaximum(255);
        maxBlueSlider->setPageStep(200);
        maxBlueSlider->setOrientation(Qt::Orientation::Horizontal);
        maxBlueSlider->setTickPosition(QSlider::TickPosition::NoTicks);

        gridLayout_3->addWidget(maxBlueSlider, 6, 1, 1, 1);

        maxGreenSlider = new QSlider(centralwidget);
        maxGreenSlider->setObjectName("maxGreenSlider");
        maxGreenSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(maxGreenSlider->sizePolicy().hasHeightForWidth());
        maxGreenSlider->setSizePolicy(sizePolicy);
        maxGreenSlider->setMinimumSize(QSize(160, 32));
        maxGreenSlider->setMaximumSize(QSize(16777215, 32));
        maxGreenSlider->setMaximum(255);
        maxGreenSlider->setPageStep(200);
        maxGreenSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(maxGreenSlider, 5, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(80, 32));
        label_9->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_9, 6, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(80, 32));
        label_4->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        freqSlider = new QSlider(centralwidget);
        freqSlider->setObjectName("freqSlider");
        freqSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(freqSlider->sizePolicy().hasHeightForWidth());
        freqSlider->setSizePolicy(sizePolicy);
        freqSlider->setMinimumSize(QSize(160, 32));
        freqSlider->setMaximumSize(QSize(16777215, 32));
        freqSlider->setMaximum(255);
        freqSlider->setPageStep(200);
        freqSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(freqSlider, 3, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(80, 32));
        label_6->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(80, 32));
        label_3->setMaximumSize(QSize(80, 32));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        brightnessSlider = new QSlider(centralwidget);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(brightnessSlider->sizePolicy().hasHeightForWidth());
        brightnessSlider->setSizePolicy(sizePolicy);
        brightnessSlider->setMinimumSize(QSize(160, 32));
        brightnessSlider->setMaximumSize(QSize(16777215, 32));
        brightnessSlider->setMaximum(255);
        brightnessSlider->setPageStep(200);
        brightnessSlider->setOrientation(Qt::Orientation::Horizontal);
        brightnessSlider->setTickPosition(QSlider::TickPosition::NoTicks);

        gridLayout_3->addWidget(brightnessSlider, 0, 1, 1, 1);

        luminSlider = new QSlider(centralwidget);
        luminSlider->setObjectName("luminSlider");
        luminSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(luminSlider->sizePolicy().hasHeightForWidth());
        luminSlider->setSizePolicy(sizePolicy);
        luminSlider->setMinimumSize(QSize(160, 32));
        luminSlider->setMaximumSize(QSize(16777215, 32));
        luminSlider->setMaximum(255);
        luminSlider->setPageStep(200);
        luminSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(luminSlider, 2, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 2);

        gridLayout_2->addLayout(gridLayout_3, 10, 1, 3, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        pathSelector = new QPushButton(centralwidget);
        pathSelector->setObjectName("pathSelector");
        pathSelector->setEnabled(false);
        sizePolicy.setHeightForWidth(pathSelector->sizePolicy().hasHeightForWidth());
        pathSelector->setSizePolicy(sizePolicy);
        pathSelector->setMinimumSize(QSize(180, 32));
        pathSelector->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_5->addWidget(pathSelector);

        isCamera = new QCheckBox(centralwidget);
        isCamera->setObjectName("isCamera");
        sizePolicy1.setHeightForWidth(isCamera->sizePolicy().hasHeightForWidth());
        isCamera->setSizePolicy(sizePolicy1);
        isCamera->setMinimumSize(QSize(50, 32));
        isCamera->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_5->addWidget(isCamera);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 13, 3, 1, 1);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_9, 19, 3, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_14, 16, 3, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_3, 9, 3, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setMinimumSize(QSize(80, 32));
        label_11->setMaximumSize(QSize(80, 32));

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);
        label_12->setMinimumSize(QSize(80, 32));
        label_12->setMaximumSize(QSize(80, 32));

        gridLayout_4->addWidget(label_12, 1, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        label_13->setMinimumSize(QSize(80, 32));
        label_13->setMaximumSize(QSize(80, 32));

        gridLayout_4->addWidget(label_13, 2, 0, 1, 1);

        redSlider = new QSlider(centralwidget);
        redSlider->setObjectName("redSlider");
        redSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(redSlider->sizePolicy().hasHeightForWidth());
        redSlider->setSizePolicy(sizePolicy);
        redSlider->setMinimumSize(QSize(160, 32));
        redSlider->setMaximumSize(QSize(16777215, 32));
        redSlider->setMaximum(255);
        redSlider->setValue(170);
        redSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_4->addWidget(redSlider, 0, 1, 1, 1);

        blueSlider = new QSlider(centralwidget);
        blueSlider->setObjectName("blueSlider");
        blueSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(blueSlider->sizePolicy().hasHeightForWidth());
        blueSlider->setSizePolicy(sizePolicy);
        blueSlider->setMinimumSize(QSize(160, 32));
        blueSlider->setMaximumSize(QSize(16777215, 32));
        blueSlider->setMaximum(255);
        blueSlider->setValue(170);
        blueSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_4->addWidget(blueSlider, 2, 1, 1, 1);

        greenSlider = new QSlider(centralwidget);
        greenSlider->setObjectName("greenSlider");
        greenSlider->setEnabled(false);
        sizePolicy.setHeightForWidth(greenSlider->sizePolicy().hasHeightForWidth());
        greenSlider->setSizePolicy(sizePolicy);
        greenSlider->setMinimumSize(QSize(160, 32));
        greenSlider->setMaximumSize(QSize(16777215, 32));
        greenSlider->setMaximum(255);
        greenSlider->setValue(170);
        greenSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_4->addWidget(greenSlider, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 17, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(50, 32));
        label_2->setMaximumSize(QSize(50, 32));

        horizontalLayout_9->addWidget(label_2);

        isVideo = new QRadioButton(centralwidget);
        isVideo->setObjectName("isVideo");
        isVideo->setEnabled(false);
        sizePolicy.setHeightForWidth(isVideo->sizePolicy().hasHeightForWidth());
        isVideo->setSizePolicy(sizePolicy);
        isVideo->setMinimumSize(QSize(0, 32));
        isVideo->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_9->addWidget(isVideo);

        isImage = new QRadioButton(centralwidget);
        isImage->setObjectName("isImage");
        isImage->setEnabled(false);
        sizePolicy.setHeightForWidth(isImage->sizePolicy().hasHeightForWidth());
        isImage->setSizePolicy(sizePolicy);
        isImage->setMinimumSize(QSize(0, 32));
        isImage->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_9->addWidget(isImage);


        gridLayout_2->addLayout(horizontalLayout_9, 3, 3, 5, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 1, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        sizePolicy.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy);
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_2, 5, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 15, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(1, 1, 1, 1);
        comboBox32 = new QComboBox(centralwidget);
        comboBox32->setObjectName("comboBox32");
        sizePolicy1.setHeightForWidth(comboBox32->sizePolicy().hasHeightForWidth());
        comboBox32->setSizePolicy(sizePolicy1);
        comboBox32->setMinimumSize(QSize(60, 32));
        comboBox32->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox32, 3, 2, 1, 1);

        comboBox20 = new QComboBox(centralwidget);
        comboBox20->setObjectName("comboBox20");
        sizePolicy1.setHeightForWidth(comboBox20->sizePolicy().hasHeightForWidth());
        comboBox20->setSizePolicy(sizePolicy1);
        comboBox20->setMinimumSize(QSize(60, 32));
        comboBox20->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox20, 2, 0, 1, 1);

        comboBox30 = new QComboBox(centralwidget);
        comboBox30->setObjectName("comboBox30");
        sizePolicy1.setHeightForWidth(comboBox30->sizePolicy().hasHeightForWidth());
        comboBox30->setSizePolicy(sizePolicy1);
        comboBox30->setMinimumSize(QSize(60, 32));
        comboBox30->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox30, 3, 0, 1, 1);

        comboBox21 = new QComboBox(centralwidget);
        comboBox21->setObjectName("comboBox21");
        sizePolicy1.setHeightForWidth(comboBox21->sizePolicy().hasHeightForWidth());
        comboBox21->setSizePolicy(sizePolicy1);
        comboBox21->setMinimumSize(QSize(60, 32));
        comboBox21->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox21, 2, 1, 1, 1);

        comboBox31 = new QComboBox(centralwidget);
        comboBox31->setObjectName("comboBox31");
        sizePolicy1.setHeightForWidth(comboBox31->sizePolicy().hasHeightForWidth());
        comboBox31->setSizePolicy(sizePolicy1);
        comboBox31->setMinimumSize(QSize(60, 32));
        comboBox31->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox31, 3, 1, 1, 1);

        comboBox03 = new QComboBox(centralwidget);
        comboBox03->setObjectName("comboBox03");
        sizePolicy1.setHeightForWidth(comboBox03->sizePolicy().hasHeightForWidth());
        comboBox03->setSizePolicy(sizePolicy1);
        comboBox03->setMinimumSize(QSize(60, 32));
        comboBox03->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox03, 0, 3, 1, 1);

        comboBox22 = new QComboBox(centralwidget);
        comboBox22->setObjectName("comboBox22");
        sizePolicy1.setHeightForWidth(comboBox22->sizePolicy().hasHeightForWidth());
        comboBox22->setSizePolicy(sizePolicy1);
        comboBox22->setMinimumSize(QSize(60, 32));
        comboBox22->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox22, 2, 2, 1, 1);

        comboBox13 = new QComboBox(centralwidget);
        comboBox13->setObjectName("comboBox13");
        sizePolicy1.setHeightForWidth(comboBox13->sizePolicy().hasHeightForWidth());
        comboBox13->setSizePolicy(sizePolicy1);
        comboBox13->setMinimumSize(QSize(60, 32));
        comboBox13->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox13, 1, 3, 1, 1);

        comboBox33 = new QComboBox(centralwidget);
        comboBox33->setObjectName("comboBox33");
        sizePolicy1.setHeightForWidth(comboBox33->sizePolicy().hasHeightForWidth());
        comboBox33->setSizePolicy(sizePolicy1);
        comboBox33->setMinimumSize(QSize(60, 32));
        comboBox33->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox33, 3, 3, 1, 1);

        comboBox01 = new QComboBox(centralwidget);
        comboBox01->setObjectName("comboBox01");
        sizePolicy1.setHeightForWidth(comboBox01->sizePolicy().hasHeightForWidth());
        comboBox01->setSizePolicy(sizePolicy1);
        comboBox01->setMinimumSize(QSize(60, 32));
        comboBox01->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox01, 0, 1, 1, 1);

        comboBox12 = new QComboBox(centralwidget);
        comboBox12->setObjectName("comboBox12");
        sizePolicy1.setHeightForWidth(comboBox12->sizePolicy().hasHeightForWidth());
        comboBox12->setSizePolicy(sizePolicy1);
        comboBox12->setMinimumSize(QSize(60, 32));
        comboBox12->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox12, 1, 2, 1, 1);

        comboBox02 = new QComboBox(centralwidget);
        comboBox02->setObjectName("comboBox02");
        sizePolicy1.setHeightForWidth(comboBox02->sizePolicy().hasHeightForWidth());
        comboBox02->setSizePolicy(sizePolicy1);
        comboBox02->setMinimumSize(QSize(60, 32));
        comboBox02->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox02, 0, 2, 1, 1);

        comboBox11 = new QComboBox(centralwidget);
        comboBox11->setObjectName("comboBox11");
        sizePolicy1.setHeightForWidth(comboBox11->sizePolicy().hasHeightForWidth());
        comboBox11->setSizePolicy(sizePolicy1);
        comboBox11->setMinimumSize(QSize(60, 32));
        comboBox11->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox11, 1, 1, 1, 1);

        comboBox10 = new QComboBox(centralwidget);
        comboBox10->setObjectName("comboBox10");
        sizePolicy1.setHeightForWidth(comboBox10->sizePolicy().hasHeightForWidth());
        comboBox10->setSizePolicy(sizePolicy1);
        comboBox10->setMinimumSize(QSize(60, 32));
        comboBox10->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox10, 1, 0, 1, 1);

        comboBox00 = new QComboBox(centralwidget);
        comboBox00->setObjectName("comboBox00");
        sizePolicy1.setHeightForWidth(comboBox00->sizePolicy().hasHeightForWidth());
        comboBox00->setSizePolicy(sizePolicy1);
        comboBox00->setMinimumSize(QSize(60, 32));
        comboBox00->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox00, 0, 0, 1, 1);

        comboBox23 = new QComboBox(centralwidget);
        comboBox23->setObjectName("comboBox23");
        sizePolicy1.setHeightForWidth(comboBox23->sizePolicy().hasHeightForWidth());
        comboBox23->setSizePolicy(sizePolicy1);
        comboBox23->setMinimumSize(QSize(60, 32));
        comboBox23->setMaximumSize(QSize(60, 32));

        gridLayout->addWidget(comboBox23, 2, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 17, 3, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(2, 2, 2, -1);
        scanbtn = new QPushButton(centralwidget);
        scanbtn->setObjectName("scanbtn");
        sizePolicy1.setHeightForWidth(scanbtn->sizePolicy().hasHeightForWidth());
        scanbtn->setSizePolicy(sizePolicy1);
        scanbtn->setMinimumSize(QSize(90, 32));
        scanbtn->setMaximumSize(QSize(90, 32));

        horizontalLayout_8->addWidget(scanbtn);

        detectionBar = new QProgressBar(centralwidget);
        detectionBar->setObjectName("detectionBar");
        sizePolicy.setHeightForWidth(detectionBar->sizePolicy().hasHeightForWidth());
        detectionBar->setSizePolicy(sizePolicy);
        detectionBar->setMinimumSize(QSize(160, 32));
        detectionBar->setMaximumSize(QSize(16777215, 32));
        detectionBar->setMinimum(0);
        detectionBar->setValue(0);

        horizontalLayout_8->addWidget(detectionBar);


        gridLayout_2->addLayout(horizontalLayout_8, 2, 1, 2, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 15, 1, 1, 1);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_8, 19, 2, 1, 1);

        line_10 = new QFrame(centralwidget);
        line_10->setObjectName("line_10");
        line_10->setFrameShape(QFrame::Shape::HLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_10, 14, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        sizePolicy4.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy4);
        line->setMinimumSize(QSize(10, 560));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(line);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 2, 17, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(90, 32));
        label->setMaximumSize(QSize(90, 32));

        horizontalLayout_7->addWidget(label);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setMinimumSize(QSize(40, 32));
        lcdNumber->setMaximumSize(QSize(16777215, 32));
        lcdNumber->setSmallDecimalPoint(false);

        horizontalLayout_7->addWidget(lcdNumber);

        detectionTimeSelector = new QSpinBox(centralwidget);
        detectionTimeSelector->setObjectName("detectionTimeSelector");
        sizePolicy1.setHeightForWidth(detectionTimeSelector->sizePolicy().hasHeightForWidth());
        detectionTimeSelector->setSizePolicy(sizePolicy1);
        detectionTimeSelector->setMinimumSize(QSize(40, 32));
        detectionTimeSelector->setMaximumSize(QSize(16777215, 32));
        detectionTimeSelector->setMinimum(1);
        detectionTimeSelector->setMaximum(15);
        detectionTimeSelector->setValue(6);

        horizontalLayout_7->addWidget(detectionTimeSelector);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(60, 32));
        label_10->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_7->addWidget(label_10);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        renderBtn = new QPushButton(centralwidget);
        renderBtn->setObjectName("renderBtn");
        renderBtn->setEnabled(false);
        sizePolicy.setHeightForWidth(renderBtn->sizePolicy().hasHeightForWidth());
        renderBtn->setSizePolicy(sizePolicy);
        renderBtn->setMinimumSize(QSize(48, 32));
        renderBtn->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setBold(false);
        renderBtn->setFont(font);

        horizontalLayout_6->addWidget(renderBtn);

        pauseBtn = new QPushButton(centralwidget);
        pauseBtn->setObjectName("pauseBtn");
        pauseBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(pauseBtn->sizePolicy().hasHeightForWidth());
        pauseBtn->setSizePolicy(sizePolicy1);
        pauseBtn->setMinimumSize(QSize(48, 32));
        pauseBtn->setMaximumSize(QSize(48, 32));

        horizontalLayout_6->addWidget(pauseBtn);

        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(stopBtn->sizePolicy().hasHeightForWidth());
        stopBtn->setSizePolicy(sizePolicy1);
        stopBtn->setMinimumSize(QSize(48, 32));
        stopBtn->setMaximumSize(QSize(48, 32));

        horizontalLayout_6->addWidget(stopBtn);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 18, 1, 1, 1);

        simGrid = new QGridLayout();
        simGrid->setObjectName("simGrid");
        gv21 = new SquareGraphicsView(centralwidget);
        gv21->setObjectName("gv21");
        gv21->setMinimumSize(QSize(54, 54));
        gv21->setMaximumSize(QSize(90, 90));
        gv21->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv21, 2, 1, 1, 1);

        gv23 = new SquareGraphicsView(centralwidget);
        gv23->setObjectName("gv23");
        gv23->setMinimumSize(QSize(54, 54));
        gv23->setMaximumSize(QSize(90, 90));
        gv23->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv23, 2, 3, 1, 1);

        gv03 = new SquareGraphicsView(centralwidget);
        gv03->setObjectName("gv03");
        gv03->setMinimumSize(QSize(54, 54));
        gv03->setMaximumSize(QSize(90, 90));
        gv03->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv03, 0, 3, 1, 1);

        gv00 = new SquareGraphicsView(centralwidget);
        gv00->setObjectName("gv00");
        gv00->setMinimumSize(QSize(54, 54));
        gv00->setMaximumSize(QSize(90, 90));
        gv00->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv00, 0, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        gv20 = new SquareGraphicsView(centralwidget);
        gv20->setObjectName("gv20");
        gv20->setMinimumSize(QSize(54, 54));
        gv20->setMaximumSize(QSize(90, 90));
        gv20->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv20, 2, 0, 1, 1);

        gv13 = new SquareGraphicsView(centralwidget);
        gv13->setObjectName("gv13");
        gv13->setMinimumSize(QSize(54, 54));
        gv13->setMaximumSize(QSize(90, 90));
        gv13->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv13, 1, 3, 1, 1);

        gv01 = new SquareGraphicsView(centralwidget);
        gv01->setObjectName("gv01");
        gv01->setMinimumSize(QSize(54, 54));
        gv01->setMaximumSize(QSize(90, 90));
        gv01->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv01, 0, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        gv02 = new SquareGraphicsView(centralwidget);
        gv02->setObjectName("gv02");
        gv02->setMinimumSize(QSize(54, 54));
        gv02->setMaximumSize(QSize(90, 90));
        gv02->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv02, 0, 2, 1, 1);

        gv10 = new SquareGraphicsView(centralwidget);
        gv10->setObjectName("gv10");
        gv10->setMinimumSize(QSize(54, 54));
        gv10->setMaximumSize(QSize(90, 90));
        gv10->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv10, 1, 0, 1, 1);

        gv12 = new SquareGraphicsView(centralwidget);
        gv12->setObjectName("gv12");
        gv12->setMinimumSize(QSize(54, 54));
        gv12->setMaximumSize(QSize(90, 90));
        gv12->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv12, 1, 2, 1, 1);

        gv22 = new SquareGraphicsView(centralwidget);
        gv22->setObjectName("gv22");
        gv22->setMinimumSize(QSize(54, 54));
        gv22->setMaximumSize(QSize(90, 90));
        gv22->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv22, 2, 2, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        gv11 = new SquareGraphicsView(centralwidget);
        gv11->setObjectName("gv11");
        gv11->setMinimumSize(QSize(54, 54));
        gv11->setMaximumSize(QSize(90, 90));
        gv11->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv11, 1, 1, 1, 1);

        gv30 = new SquareGraphicsView(centralwidget);
        gv30->setObjectName("gv30");
        gv30->setMinimumSize(QSize(54, 54));
        gv30->setMaximumSize(QSize(90, 90));
        gv30->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv30, 3, 0, 1, 1);

        gv31 = new SquareGraphicsView(centralwidget);
        gv31->setObjectName("gv31");
        gv31->setMinimumSize(QSize(54, 54));
        gv31->setMaximumSize(QSize(90, 90));
        gv31->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv31, 3, 1, 1, 1);

        gv32 = new SquareGraphicsView(centralwidget);
        gv32->setObjectName("gv32");
        gv32->setMinimumSize(QSize(54, 54));
        gv32->setMaximumSize(QSize(90, 90));
        gv32->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv32, 3, 2, 1, 1);

        gv33 = new SquareGraphicsView(centralwidget);
        gv33->setObjectName("gv33");
        gv33->setMinimumSize(QSize(54, 54));
        gv33->setMaximumSize(QSize(90, 90));
        gv33->setSizeIncrement(QSize(0, 0));

        simGrid->addWidget(gv33, 3, 3, 1, 1);


        gridLayout_2->addLayout(simGrid, 11, 3, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line_4, 0, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 8, 3, 1, 1);

        inetControler->setCentralWidget(centralwidget);

        retranslateUi(inetControler);

        QMetaObject::connectSlotsByName(inetControler);
    } // setupUi

    void retranslateUi(QMainWindow *inetControler)
    {
        inetControler->setWindowTitle(QCoreApplication::translate("inetControler", "inetControler", nullptr));
        toggleIds->setText(QCoreApplication::translate("inetControler", "show IDs", nullptr));
        unToggleIds->setText(QCoreApplication::translate("inetControler", "Clear", nullptr));
        masterToggle->setText(QCoreApplication::translate("inetControler", "Master Control", nullptr));
        label_8->setText(QCoreApplication::translate("inetControler", "Max. Green", nullptr));
        label_5->setText(QCoreApplication::translate("inetControler", "Lumin time", nullptr));
        label_7->setText(QCoreApplication::translate("inetControler", "Max. Red", nullptr));
        label_9->setText(QCoreApplication::translate("inetControler", "Max. Blue", nullptr));
        label_4->setText(QCoreApplication::translate("inetControler", "Contrast", nullptr));
        label_6->setText(QCoreApplication::translate("inetControler", "Frequency", nullptr));
        label_3->setText(QCoreApplication::translate("inetControler", "Brightness", nullptr));
        pathSelector->setText(QCoreApplication::translate("inetControler", "Select path of video or file", nullptr));
        isCamera->setText(QCoreApplication::translate("inetControler", "\360\237\216\245", nullptr));
        label_14->setText(QCoreApplication::translate("inetControler", "Panel Layout:", nullptr));
        label_11->setText(QCoreApplication::translate("inetControler", "Red", nullptr));
        label_12->setText(QCoreApplication::translate("inetControler", "Green", nullptr));
        label_13->setText(QCoreApplication::translate("inetControler", "Blue", nullptr));
        label_2->setText(QCoreApplication::translate("inetControler", "File is:", nullptr));
        isVideo->setText(QCoreApplication::translate("inetControler", "Video", nullptr));
        isImage->setText(QCoreApplication::translate("inetControler", "Image", nullptr));
        scanbtn->setText(QCoreApplication::translate("inetControler", "Scan", nullptr));
        label->setText(QCoreApplication::translate("inetControler", "Panels found:", nullptr));
        label_10->setText(QCoreApplication::translate("inetControler", "Sec.", nullptr));
#if QT_CONFIG(tooltip)
        renderBtn->setToolTip(QCoreApplication::translate("inetControler", "Render", nullptr));
#endif // QT_CONFIG(tooltip)
        renderBtn->setText(QCoreApplication::translate("inetControler", "\360\237\223\272", nullptr));
#if QT_CONFIG(tooltip)
        pauseBtn->setToolTip(QCoreApplication::translate("inetControler", "Play/Pause Video/Camera", nullptr));
#endif // QT_CONFIG(tooltip)
        pauseBtn->setText(QCoreApplication::translate("inetControler", "\342\217\257\357\270\217", nullptr));
#if QT_CONFIG(tooltip)
        stopBtn->setToolTip(QCoreApplication::translate("inetControler", "Stop!", nullptr));
#endif // QT_CONFIG(tooltip)
        stopBtn->setText(QCoreApplication::translate("inetControler", "\342\217\271\357\270\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inetControler: public Ui_inetControler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INETCONTROLER_H
