#include "dialog.h"
#include<QtWidgets>
#include<QPushButton>
FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    label  = new QLabel(tr("Find &What"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit,SIGNAL(textChanged(QString&)),this,SLOT(enableFindButton(QString&)));
    connect(findButton,SIGNAL(clicked(bool)),this,SLOT(findClicked()));
    connect(closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));

    QHBoxLayout *toplayout = new QHBoxLayout;
    toplayout->addWidget(label);
    toplayout->addWidget(lineEdit);

    QVBoxLayout *leftlayout = new QVBoxLayout;
    leftlayout->addWidget(caseCheckBox);
    leftlayout->addWidget(backwardCheckBox);
    leftlayout->addLayout(topLevelWidget());

    QVBoxLayout *rightlayout = new QVBoxLayout;
    leftlayout->addWidget(findButton);
    leftlayout->addWidget(closeButton);
    leftlayout->addStretch();

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);
    setLayout(mainlayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

}

Dialog::~Dialog()
{

}

