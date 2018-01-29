#include "Net.h"
#include <QDebug>
#include <core/JsonSerializableEntity.h>
#include <core/Context.h>
#include <model/Block.h>
#include <core/SerializableEntityFactory.h>

Net::Net(QObject *parent) :
    QObject(parent),
    _rpc_server(this),
    _node(this)
{
    _node.subscribe(this);

    QObject::connect(&_transport_provider, SIGNAL(streamCountChanged(int)), this, SLOT(onConnectionCountChanged(int)));
    QObject::connect(&_transport_provider, SIGNAL(onEntityReady(JsonSerializableIdentifyedEntity*)), this, SLOT(onEntityReady(JsonSerializableIdentifyedEntity*)));
}

void Net::connect()
{
    try
    {
        _rpc_server.start();
    }
    catch (NetDataStreamException &ex)
    {
        qDebug() << "RPC Server starting failed!" << ex.what();
        return;
    }
    try
    {
        _node.open();
    }
    catch (NetDataStreamException &ex)
    {
        qDebug() << "Node Server starting failed!" << ex.what();
        return;
    }

    auto udpStream = new UdpStream();
    udpStream->subscribe(this);
    _transport_provider.add(udpStream);
    _tcp_provider.start();
}

void Net::close()
{
    _rpc_server.stop();
    _node.close();
}

void Net::write(JsonSerializableIdentifyedEntity *data)
{
    try
    {
        _transport_provider.write(data);
    }
    catch (BaseException &ex)
    {
        qDebug() << "Object sending error!" << ex.what();
    }
}

void Net::update(const Guid &subject, void *data)
{
    if (Guid::isEqual(subject, _node.guid()))
    {
        TcpStream *stream = static_cast<TcpStream *>(data);
        _transport_provider.add(stream);
    }
    else if (Guid::isEqual(subject, _transport_provider.guid()))
    {
        JsonSerializableEntity *entity = static_cast<JsonSerializableEntity *>(data);
        if (SerializableEntityFactory::IsBlock(entity))
        {
            Block * b = static_cast<Block *>(entity), find_block;
            if (Context::Instance().database()->read(b->getId(), &find_block))
            {
                qDebug() << "Duplicate block!";
                return;
            }
            Context::Instance().database()->write(b);
            qDebug() << "New Block!" << b->getId().toString();
        }
    }
}

void Net::onConnectionCountChanged(int count)
{
    qDebug() << "Connection count" << count;
    if (Context::Instance().settings()->getConnectionsLimit() > count)
    {
        //_tcp_provider.start();
    }
}

void Net::onEntityReady(JsonSerializableIdentifyedEntity *entity)
{
    qDebug() << "New Entity" << entity->getEntityName();
    if (SerializableEntityFactory::IsBlock(entity))
    {
    }
}
