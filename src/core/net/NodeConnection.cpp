#include "NodeConnection.h"

NodeConnection::NodeConnection(ConnectionPoint point, QObject *parent) :
    NetDataStream(point, parent),
    _last_activity(QDateTime::currentDateTime())
{
    _ping_timer = new QTimer(this);

}

NodeConnection::~NodeConnection()
{
    delete _ping_timer;
}

void NodeConnection::ping()
{

}
