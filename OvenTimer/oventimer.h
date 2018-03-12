#ifndef OVENTIMER_H
#define OVENTIMER_H

#include <QWidget>
#include<QDateTime>
class oventimer : public QWidget
{
    Q_OBJECT

public:
    oventimer(QWidget *parent = 0);
    void setDuration(int secs);
    int duration() const;
    void draw(QPainter *painter);
signals:
    void timeout();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QDateTime finishTime;
    QTimer *updateTimer;
    QTimer *finishTimer;
};

#endif // OVENTIMER_H
