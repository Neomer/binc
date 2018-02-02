#include "Net.h"
#include <QDebug>
#include <core/JsonSerializableEntity.h>
#include <core/Context.h>
#include <model/Block.h>
#include <core/SerializableEntityFactory.h>

Net::Net() :
    QObject(),
    ISubject(),
    _rpc_server(this),
    _node(this),
    _rpc_client(this)
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
    //_transport_provider.add(new TcpStream(ConnectionPoint(QHostAddress("127.0.0.1"), 16845)));

    _rpc_client.updateNodes();
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
    Q_UNUSED(subject); Q_UNUSED(data);
}

void Net::onConnectionCountChanged(int count)
{
    qDebug() << "Connection count" << count;
}

void Net::onEntityReady(JsonSerializableIdentifyedEntity *entity)
{
    ISubject::update(entity);
}
