#ifndef WORKER_H
#define WORKER_H

#include "Work.h"
#include <QThread>

class Worker : public QThread
{
public:
    Worker();

    void setWork(Work *value) { _work = value; }
    void start();
    void stop();

private:
    Work *_work;
    bool _run;

    // QThread interface
protected:
    void run() override;
};

#endif // WORKER_H
