#include "TcpStream.h"
#include <core/JsonSerializableEntity.h>

TcpStream::TcpStream() :
    _socket(new QTcpSocket(this))
{
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

TcpStream::~TcpStream()
{

}

void TcpStream::open()
{

}

void TcpStream::close()
{

}

void TcpStream::read(IJsonSerializable *data)
{
    Q_UNUSED(data);
}

void TcpStream::write(IJsonSerializable *data)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    auto block = new TransportDataBlock();
    block->setTransactionId(Guid::randomGuid());
    block->setStatus(TransportDataBlock::enStatusLast);
    block->setPreviousBlockId(Guid::emptyGuid());
    block->setData(IJsonSerializable::toByteArray(data));
    block->toDataStream(stream);
    if (_socket->write(buffer) != buffer.size())
    {
        throw BaseException("Not all data was sent!");
    }
}

void TcpStream::readData()
{
    do
    {
        int len = _socket->bytesAvailable();
        _buffer.resize(len);
        _socket->read(_buffer.data(), len);
    }
    while (_socket->bytesAvailable() > 0);

    QDataStream stream(&_buffer, QIODevice::ReadOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    TransportDataBlock block;
    block.fromDataStream(stream);
    if (!block.isReady() || !block.isValid())
    {
        return;
    }

    if (block.getStatus() == TransportDataBlock::enStatusLast && block.getPreviousBlockId().isEmpty())
    {
        //если блок единственный в транзакции
        JsonSerializableEntity entity;
        IJsonSerializable::fromString(&entity, block.getData());
        JsonSerializableEntity *e = static_cast<JsonSerializableEntity *>(_entity_factory.createEntity(entity.getEntityName()));
        if (e)
        {
            IJsonSerializable::fromString(e, block.getData());
            update(e);
        }
    }
    else
    {
        TransportTransaction *tr = static_cast<TransportTransaction *>(_transaction_cache.get(block.getTransactionId()));
        if (!tr) tr = new TransportTransaction();
        tr->addBlock(&block);
        _transaction_cache.add(tr);
    }
}
