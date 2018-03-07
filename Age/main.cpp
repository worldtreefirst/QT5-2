#include<QApplication>
#include<QHBoxLayout>
#include<QSlider>
#include<QSpinBox>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QWidget *windows= new QWidget;
    windows->setWindowTitle("Enter you Age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0,1000);
    slider->setRange(1,1000);

    spinBox->setValue(10);
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    windows->setLayout(layout);

    windows->show();
    return app.exec();
}
