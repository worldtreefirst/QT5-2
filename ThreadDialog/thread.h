#ifndef THREAD_H
#define THREAD_H
#include<QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void setMessage(const QString &message);
    void stop();
protected:
    void run();
private:
    QString messageStr;
    volatile bool stopped;//易矢性变量，因为需要它一只保持最新数据状态，在断电和中断后不可恢复数据，也拒绝了编译器的优化
};
#endif // THREAD_H
