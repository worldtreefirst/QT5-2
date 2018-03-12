#include "oventimer.h"
#include<cmath>
#include<QtWidgets>

#ifndef M_PI
#define M_PI 3.1415926
#endif
/*
 * 烤箱定时器外观常量
**/
const double DegreesPerMinute = 7.0;
const double DegressPerSecond = DegreesPerMinute / 60;
const int MaxMinutes = 45;
const int MaxSeconds = MaxMinutes * 60;
const int UpdateInterval = 5;
oventimer::oventimer(QWidget *parent)
    : QWidget(parent)
{
finishTime = QDateTime::currentDateTime();
updateTimer= new QTimer(this);
connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
finishTimer->setSingleShot(true);
connect(finishTimer,SIGNAL(timeout()),this,SIGNAL(timeout()));
connect(finishTimer,SIGNAL(timeout()),updateTimer,SLOT(stop()));

QFont font;
font.setPointSize(8);
setFont(font);;
}

/*
 * sertDuration函数设置了烤箱定时器的持续时间为给定的秒数
 * */
void oventimer::setDuration(int secs)
{
    secs = qBound(0,secs,MaxSeconds);
    finishTime = QDateTime::currentDateTime().addSecs(secs);//获得当前时间在加上间隔时间得到结束时间，保存到finishtime的私有变量之中
    if(secs > 0 )
    {
        updateTimer->start(UpdateInterval * 1000);
        finishTimer->start(secs * 1000);
    }
    else
    {
        updateTimer->stop();
        finishTimer->stop();
    }
    update();//用新的间隔时间重绘窗口
}

/*
 * 返回定时器完成前剩余的秒数
 * */
int oventimer::duration() const
{
    int secs = QDateTime::currentDateTime().secsTo(finishTime);
    if (secs < 0)

           secs = 0;

       return secs;
}

void oventimer::mousePressEvent(QMouseEvent *event)
{
    QPointF point = event->pos()-rect().center();
    double theta = std::atan2(-point.x(), -point.y()) * 180.0 / M_PI;

       setDuration(duration() + int(theta / DegressPerSecond));

       update();

}

void oventimer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    int side = qMin(width(),height());//返回两个参数中最小的一个
    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(-50, -50, 100, 100);
    draw(&painter);
}

void oventimer::draw(QPainter *painter)
{
    static const int triangle[3][2] = {

          { -2, -49 }, { +2, -49 }, { 0, -47 }

      };

      QPen thickPen(palette().foreground(), 1.5);

      QPen thinPen(palette().foreground(), 0.5);

      QColor niceBlue(150, 150, 200);



      painter->setPen(thinPen);

      painter->setBrush(palette().foreground());

      painter->drawPolygon(QPolygon(3, &triangle[0][0]));



      QConicalGradient coneGradient(0, 0, -90.0);

      coneGradient.setColorAt(0.0, Qt::darkGray);

      coneGradient.setColorAt(0.2, niceBlue);

      coneGradient.setColorAt(0.5, Qt::white);

      coneGradient.setColorAt(1.0, Qt::darkGray);



      painter->setBrush(coneGradient);

      painter->drawEllipse(-46, -46, 92, 92);



      QRadialGradient haloGradient(0, 0, 20, 0, 0);

      haloGradient.setColorAt(0.0, Qt::lightGray);

      haloGradient.setColorAt(0.8, Qt::darkGray);

      haloGradient.setColorAt(0.9, Qt::white);

      haloGradient.setColorAt(1.0, Qt::black);



      painter->setPen(Qt::NoPen);

      painter->setBrush(haloGradient);

      painter->drawEllipse(-20, -20, 40, 40);



      QLinearGradient knobGradient(-7, -25, 7, -25);

      knobGradient.setColorAt(0.0, Qt::black);

      knobGradient.setColorAt(0.2, niceBlue);

      knobGradient.setColorAt(0.3, Qt::lightGray);

      knobGradient.setColorAt(0.8, Qt::white);

      knobGradient.setColorAt(1.0, Qt::black);



      painter->rotate(duration() * DegressPerSecond);

      painter->setBrush(knobGradient);

      painter->setPen(thinPen);

      painter->drawRoundRect(-7, -25, 14, 50, 99, 49);



      for (int i = 0; i <= MaxMinutes; ++i) {

          if (i % 5 == 0) {

              painter->setPen(thickPen);

              painter->drawLine(0, -41, 0, -44);

              painter->drawText(-15, -41, 30, 30,

                                Qt::AlignHCenter | Qt::AlignTop,

                                QString::number(i));

          } else {

              painter->setPen(thinPen);

              painter->drawLine(0, -42, 0, -44);

          }

          painter->rotate(-DegreesPerMinute);

      }
}



