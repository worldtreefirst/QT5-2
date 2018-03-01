#include<QtWidgets>
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QWidget windows;
    QLabel *label = new QLabel(QApplication::translate("windowslayout","name"));
    QLineEdit *= new QLineEdit();

    QHBoxLayout *layout = new QHBoxLayout();

    layout->addWidget(label);
    layout->addWidget(lineEdit);
    window.setLayout(layout);
    window.setWindowTitle(
        QApplication::translate("windowlayout", "Window layout"));
    window.show();
    return app.exec();
}
