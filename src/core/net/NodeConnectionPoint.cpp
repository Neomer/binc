#include "NodeConnectionPoint.h"
#include <core/Context.h>

NodeConnectionPoint::NodeConnectionPoint(QObject *parent) :
     QObject(parent),
     _server(parent)
{
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onConnectionAccept()));
}

void NodeConnectionPoint::open()
{
    auto cp = Context::Instance().settings()->getP2PConnectionPoint();
    if (!_server.listen(cp.getAddress(), cp.getPort()))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_PortIsBusy, "Port is busy!");
    }
}

void NodeConnectionPoint::close()
{
    _server.close();
}

void NodeConnectionPoint::onConnectionAccept()
{
    while (_server.hasPendingConnections())
    {
        update(new TcpStream(_server.nextPendingConnection()));
    }
}
