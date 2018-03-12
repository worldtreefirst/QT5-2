#include "threaddialog.h"
#include<QHBoxLayout>
#include<QPushButton>
ThreadDialog::ThreadDialog(QWidget *parent)
    : QDialog(parent)
{
    threadA.setMessage("A");
    threadB.setMessage("B");

    threadAButton = new QPushButton(tr("Start A"));
    threadBButton = new QPushButton(tr("Start B"));
    quitButton = new QPushButton(tr("quit"));
    quitButton->setDefault(true);

    connect(threadAButton,SIGNAL(clicked(bool)),this,SLOT(startOrStopThreadA()));
    connect(threadBButton,SIGNAL(clicked(bool)),this,SLOT(startOrStopThreadB()));
    connect(quitButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(threadAButton);
    mainlayout->addWidget(threadBButton);
    mainlayout->addWidget(quitButton);
    setLayout(mainlayout);

    setWindowTitle(tr("threads"));
}

void ThreadDialog::startOrStopThreadA()
{
    if(threadA.isRunning())
    {
        threadA.stop();
        threadAButton->setText(tr("Start A"));
    }
    else
    {
        threadA.start();
        threadAButton->setText(tr("Stop A"));
    }
}

void ThreadDialog::startOrStopThreadB()
{
    if(threadB.isRunning())
    {
        threadB.stop();
        threadBButton->setText(tr("Start b"));
    }
    else
    {
        threadB.start();
        threadBButton->setText(tr("Start B"));
    }
}

void ThreadDialog::closeEvent(QCloseEvent *event)
{
    threadA.stop();
    threadB.stop();
    threadA.wait();
    threadB.wait();
}

