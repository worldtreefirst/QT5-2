#ifndef GRAPHMODIFIER_H
#define GRAPHMODIFIER_H

#include<QtDataVisualization/q3dbars.h>// 提供绘制三维条形图的方法
#include<QtDataVisualization/qbardataproxy.h>  //数据代理
#include<QtDataVisualization/qabstract3dseries.h>  //数据细节基类

#include<QtGui/QFont>//绘图字体
#include<QtCore/QDebug> //消息处理
#include<QtCore/QStringList>  //提供字符串列表，提供基于索引的快速访问和快速删除
#include<QtCore/QPropertyAnimation>  //动画


using namespace QtDataVisualization;
class GraphModifier: public QObject
{
    Q_OBJECT
public:
    explicit GraphModifier(Q3DBars *bargraph);
    ~GraphModifier();

    void resetTemperatureData();//重置温度数据
    void changePresetCamera();//重置视角
    void changeLabelBackground();//标签背景
    void changeFont(const QFont &font);
    void changeFontSize(int fontsize);//字体大小

};

#endif // GRAPHMODIFIER_H
