#ifndef FINFFILEDIALOG_H
#define FINFFILEDIALOG_H

#include <QDialog>
QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
class QLineEdit;
class QTableWidget;
class QPushButton;

class finffiledialog : public QDialog
{
    Q_OBJECT

public:
    finffiledialog(QWidget *parent = 0);
private:
       QLabel *nameLabel;
       QLabel *lookInLabel;
       QLineEdit *lookInLineEdit;
       QLineEdit *namedLineEdit;
       QCheckBox *subfoldersCheckBox;
       QTableWidget *tableWidget;
       QLabel *messageLabel;
       QPushButton *findButton;
       QPushButton *stopButton;
       QPushButton *closeButton;
       QPushButton *helpButton;
};

#endif // FINFFILEDIALOG_H
