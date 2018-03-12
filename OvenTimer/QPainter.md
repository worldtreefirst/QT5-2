* 在绘图设备(如窗口等）绘图，只需创建一个QPainter在将指针传到该设备中

    void MyWidget::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
    }
*  调用setRenderHint()启动反走样，已得到平滑的边缘

