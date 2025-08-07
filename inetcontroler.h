#ifndef INETCONTROLER_H
#define INETCONTROLER_H

#include <QMainWindow>
#include <QFileDialog>

#include "discovery.h"
#include "serverClass.h"
#include "ui_inetcontroler.h"
#include "insta-inet.h"
#include "videoworker.h"
#include "camerWorkerClass.h"
#include "imageWorker.h"
#include <QtCore/qthread.h>
#include <QCloseEvent>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui {
class inetControler;
}
QT_END_NAMESPACE

class inetControler : public QMainWindow
{
    Q_OBJECT

public:
    inetControler(QWidget *parent = nullptr);
    ~inetControler();

private slots:
    void on_scanbtn_clicked();

    void on_brightnessSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);

    void on_luminSlider_valueChanged(int value);

    void on_freqSlider_valueChanged(int value);

    void on_maxRedSlider_valueChanged(int value);

    void on_maxGreenSlider_valueChanged(int value);

    void on_maxBlueSlider_valueChanged(int value);

    void on_pathSelector_clicked();

    void on_toggleIds_clicked();

    void on_unToggleIds_clicked();

    void on_masterToggle_toggled(bool checked);

    void on_isCamera_clicked(bool checked);

    void on_renderBtn_clicked();

    void closeEvent( QCloseEvent* event );

signals:
    void windowIsClosing();

protected:
    Ui::inetControler *ui;
    QThread* serverWorkerThread;
    serverClass* serverWorker;
    QThread* discoveryWorkerThread;
    discovery* discoveryWorker;
    cv::VideoCapture* cam;
    QComboBox* idbx[4][4]; //id boxes
    SquareGraphicsView* gvs[4][4]; //graphics views

};
#endif // INETCONTROLER_H
