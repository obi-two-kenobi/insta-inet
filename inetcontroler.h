#ifndef INETCONTROLER_H
#define INETCONTROLER_H

#include <QMainWindow>
#include <QFileDialog>



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

private:
    Ui::inetControler *ui;
};
#endif // INETCONTROLER_H
