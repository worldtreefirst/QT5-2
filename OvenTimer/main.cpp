#include "oventimer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    oventimer w;
    w.setWindowTitle(QObject::tr("Oven timer"));
    w.resize(300,300);
    w.show();
    return a.exec();
}
