#include "inetcontroler.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inetControler w;
    w.show();
    return a.exec();
}
