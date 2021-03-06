#include "UdpStream.h"
#include <QDebug>
#include <core/JsonSerializableEntity.h>

UdpStream::UdpStream() :
    IObservableDataStream(),
    _port(16789)
{
    _socket = new QUdpSocket(this);
    _stream.setDevice(_socket);
    _stream.setVersion(QDataStream::Qt_5_9);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()), Qt::DirectConnection);
}

UdpStream::~UdpStream()
{
    _transaction_cache.clear();
    delete _socket;
}

void UdpStream::close()
{
    _socket->close();
}

void UdpStream::open()
{
    if (!_socket->bind(QHostAddress::Any, _port))
    {
        throw UdpStreamException("Port binding failed!");
    }
    _transaction_cache.clear();
}

void UdpStream::write(JsonSerializableIdentifyedEntity *data)
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
    _socket->writeDatagram(buffer, QHostAddress::Broadcast, _port);
}

void UdpStream::readDatagram()
{
    do
    {
        int len = _socket->pendingDatagramSize();
        _buffer.resize(len);
        _socket->readDatagram(_buffer.data(), len);
    }
    while (_socket->hasPendingDatagrams());

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
        JsonSerializableIdentifyedEntity entity;
        IJsonSerializable::fromString(&entity, block.getData());
        JsonSerializableIdentifyedEntity *e = static_cast<JsonSerializableIdentifyedEntity *>(_entity_factory.createEntity(entity.getEntityName()));
        if (e)
        {
            IJsonSerializable::fromString(e, block.getData());
            emit onEntityReady(e);
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

