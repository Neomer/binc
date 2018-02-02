#include "Context.h"
#include <QDateTime>

#include <core/net/Net.h>

NodeCollectionModel Context::getNodes()
{
    NodeCollectionModel ret;

    _mtx_lock_nodes.lock();
    ret = _nodes;
    _mtx_lock_nodes.unlock();

    return ret;
}

void Context::updateNodes(NodeCollectionModel &nodes)
{
    _mtx_lock_nodes.lock();
    _nodes.add(nodes);
    _mtx_lock_nodes.unlock();
}

RPCServerCollectionModel Context::getRpcServers()
{
    RPCServerCollectionModel ret;

    _mtx_lock_rpc.lock();
    ret = _rpc_servers;
    _mtx_lock_rpc.unlock();

    return ret;
}

void Context::updateRpcServers(RPCServerCollectionModel &servers)
{
    _mtx_lock_rpc.lock();
    _rpc_servers.add(servers);
    _mtx_lock_rpc.unlock();
}

void Context::load(QString settings)
{
    // Настройки должны грузиться раньше всего остального!
    _sets.load(settings);

    _database = new Database();
    _database->open();

    _consoleInput = new ConsoleInput();
    _consoleInput->start();

    _mtx_lock_nodes.lock();
    _nodes.add(_sets.nodes());
    _mtx_lock_nodes.unlock();

    Net::Instance().connect();

    //_rpc_servers.servers().append(new RPCServerModel(ConnectionPoint(QHostAddress("127.0.0.1"), 15698)));

}

void Context::unload()
{
    _sets.save();
    _sets.close();
    _consoleInput->terminate();
    _database->close();
}

Context::Context()
{

}

Context::~Context()
{
    _consoleInput->terminate();
}
