
#include <QApplication>
#include"finffiledialog.h"
int main(int argc, char *argv[])

{

    QApplication app(argc, argv);

   finffiledialog dialog;

    dialog.show();

    return app.exec();

}
