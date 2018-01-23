#include "Worker.h"

Worker::Worker()
{

}

void Worker::start()
{
    _run = true;
    QThread::start();
}

void Worker::stop()
{
    _run = false;
}

void Worker::run()
{
    while (_run)
    {

    }
}
