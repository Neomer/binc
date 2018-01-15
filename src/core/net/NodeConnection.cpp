#include "NodeConnection.h"

NodeConnection::NodeConnection(QObject *parent) :
    QObject(parent)
{
    _ping_timer = new QTimer(this);
    connect(_ping_timer, SIGNAL(timeout()), this, SLOT(ping()));
    _ping_timer->setInterval(10000);
    _ping_timer->start();
}

void NodeConnection::ping()
{

}
