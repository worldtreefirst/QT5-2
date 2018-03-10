#include "ticker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticker w;
    w.setWindowTitle(QObject::tr("Ticker"));
    w.setText(QObject::tr("How long it lasted was impossible to say ++"));
    w.show();
    return a.exec();
}
