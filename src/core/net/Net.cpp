#include "Net.h"
#include <QDebug>
#include <core/JsonSerializableEntity.h>
#include <core/Context.h>
#include <model/Block.h>

Net::Net(QObject *parent) :
    QObject(parent),
    _rpc_server(this)
{

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
    auto udpStream = new UdpStream();
    udpStream->subscribe(this);
    _transport_provider.add(udpStream);
}

void Net::close()
{
    _rpc_server.stop();
}

void Net::write(IJsonSerializable *data)
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
    Q_UNUSED(subject);

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
        write(b);
    }
}
