#include "RPCServer.h"
#include <core/Context.h>
#include <QTcpSocket>

RPCServer::RPCServer(QObject *parent) :
    QObject(parent),
    _srv(new QTcpServer(this))
{
    connect(_srv, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

RPCServer::~RPCServer()
{
    delete _srv;
}

void RPCServer::start()
{
    if (!_srv->listen(QHostAddress::Any, Context::Instance().settings()->RPCport()))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_PortIsBusy, "Port is busy!");
    }
}

void RPCServer::acceptConnection()
{
    while (QTcpSocket *socket = _srv->nextPendingConnection())
    {
        socket->setParent(0);
        auto rpc = new RPCCommunicationThread(socket, this);
        connect(rpc, SIGNAL(finish(RPCCommunicationThread*)), this, SLOT(threadFinished(RPCCommunicationThread*)));
        rpc->start();
        socket->moveToThread(rpc);
        _threads.append(rpc);
    }
}

void RPCServer::threadFinished(RPCCommunicationThread *thread)
{
    _threads.removeOne(thread);
}
