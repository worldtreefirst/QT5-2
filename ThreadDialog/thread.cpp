#include "thread.h"
#include<iostream>
#include<QtCore>
Thread::Thread() //constructor
{
    stopped = false;
}

void Thread::setMessage(const QString &message)
{
    messageStr = message;
}
void Thread::run()
{
    while(!stopped) //只要stopped变量为false值就一直打印
    std::cerr<<qPrintable(messageStr)<<std::flush;
    stopped = false;
    std::cerr<<std::endl;
}

void Thread::stop()
{
    stopped = true;
}

