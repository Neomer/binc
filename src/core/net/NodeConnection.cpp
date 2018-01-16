#include "NodeConnection.h"

NodeConnection::NodeConnection(QHostAddress address, QObject *parent) :
    NetDataStream(address, parent)
{
    _ping_timer = new QTimer(this);
    connect(_ping_timer, SIGNAL(timeout()), this, SLOT(ping()));
    _ping_timer->setInterval(10000);
    _ping_timer->start();
}

void NodeConnection::ping()
{

}
