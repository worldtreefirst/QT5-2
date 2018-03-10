#include "ticker.h"
#include<QtWidgets>

Ticker::Ticker(QWidget *parent)
    : QWidget(parent)
{
    offset = 0;   //绘制文本的X坐标值取决于这个值
    myTimerId = 0;//定时器的ID通常是非零的，所以可以使用0来表示定时器还没有启动
}

//返回文本所需空间的大小，以此作为窗口部件的理想尺寸
QSize Ticker::sizeHint() const
{
    return fontMetrics().size(0,text());
}
//设置需要显示的文本
void Ticker::setText(const QString &newText)
{
    myText = newText;
    update();//强绘
    updateGeometry();//通知对Ticker窗口部件负责的任意布局管理器，提示该窗口部件的大小发生了变化
}

void Ticker::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int textWidth = fontMetrics().width(text());//确定水平方向上的空间
    if(textWidth < 1)
        return;
    int x = -offset;
    while(x < width())//多次绘制，直到能够填充整个窗口部件的宽度为止
    {
       painter.drawText(x,0,textWidth,height(),Qt::AlignLeft | Qt::AlignVCenter,text());
       x += textWidth;
    }
}

//启动一个定时器
void Ticker::showEvent(QShowEvent *event)
{
    myTimerId = startTimer(30);//Qobject：：startTimer返回一个ID数字
}


void Ticker::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimerId)
    {
        ++offset;
        if(offset >= fontMetrics().width(text()))//QWidget::fontMetrics函数返回一个QFontMeterics对象，可以用这个对象查询并获得与这个窗口部件字体相关的信息
            offset = 0;
        scroll(-1,0);//Qwidget::scroll把窗口部件向左滚动一个像素
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void Ticker::hideEvent(QHideEvent *event)
{
    killTimer(myTimerId);
    myTimerId = 0;
}

















