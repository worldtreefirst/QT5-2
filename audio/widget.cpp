#include"widget.h"
#include<QtMultimedia/QAudioDeviceInfo>
#include<QtMultimedia/QAudioInput>
#include<QtCharts/QChartView>
#include<QtCharts/QLineSeries>
#include<QtCharts/QChart>
#include<QtCharts/QChart>
#include<QtWidgets/QHBoxLayout>
#include<QtCharts/QValueAxis>
#include"xyseriesiodevice.h"

QT_CHARTS_BEGIN_NAMESPACE
Widget::Widget(QWidget *parent)
    :QWidget(parent),
      m_device(0),
      m_chart(0),
      m_series(0),
      m_audioInput(0)
{
   m_chart = new QChart;
   QChartView *chartView = new QChartView(m_chart);

}
