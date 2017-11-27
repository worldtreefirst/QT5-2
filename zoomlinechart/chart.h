
/**
  QChart
  <summary>
The QChart class manages the graphical representation of the chart's series, legends, and axes.
QChart is a QGraphicsWidget that you can show in a QGraphicsScene.
It manages the graphical representation of different types of series and other chart related objects like legend and axes.
To simply show a chart in a layout, the convenience class QChartView can be used instead of QChart. In addition, line, spline, area,
and scatter series can be presented as polar charts by using the QPolarChart class.
See also QChartView and QPolarChart.
  </summary>
..............................................................................................
  QGraphicsItem
  <summary>
The QGraphicsItem class is the base class for all graphical items in a QGraphicsScene.
It provides a light-weight foundation for writing your own custom items. This includes defining the item's geometry, collision detection,
its painting implementation and item interaction through its event handlers. QGraphicsItem is part of the Graphics View Framework
  </summary>
**/

/**
 QCchart是一个QGraphicsWidget,可以在QGraphicsScene中显示，它管理不同类型系列的图标显示，以及其他与图标相关的对象
  .....................................................................................................
 QGraphicsItem类是QGraohicsScene中所有图形项目的基类,未编写自己的定制项目提供了一个轻量级的基础，包括通过事件程序定义项目的几何，碰撞检测，绘图实现和项目交互
 QGraphicsItem是图形视图框架的一部分
**/
#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>

QT_BEGIN_NAMESPACE
class QGestureEvent;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart : public QChart
//![1]
{
public:
    explicit Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);          //explict阻止不应该允许的转换构造函数进行的隐式转换的发生，声明为explict的构造函数不能在隐式转换中使用
    ~Chart();

protected:
    bool sceneEvent(QEvent *event);

private:
    bool gestureEvent(QGestureEvent *event);

private:

};

#endif // CHART_H

