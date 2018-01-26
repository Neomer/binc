#include "TcpStream.h"
#include <core/JsonSerializableEntity.h>

TcpStream::TcpStream(ConnectionPoint point) :
    _socket(new QTcpSocket(this)),
    _point(point)
{
    initConnections();
    open();
}

TcpStream::TcpStream(QTcpSocket *socket) :
    _socket(socket)
{
    initConnections();
}

TcpStream::~TcpStream()
{

}

void TcpStream::open()
{
    _socket->connectToHost(_point.getAddress(), _point.getPort());
    if (!_socket->waitForConnected(3000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable, "Host not available!");
    }
}

void TcpStream::close()
{
    _socket->close();
}

void TcpStream::read(IJsonSerializable *data)
{
    Q_UNUSED(data);
}

void TcpStream::write(IJsonSerializable *data)
{
    TransportDataBlock block;
    block.setTransactionId(Guid::randomGuid());
    block.setStatus(TransportDataBlock::enStatusLast);
    block.setPreviousBlockId(Guid::emptyGuid());
    block.setData(IJsonSerializable::toByteArray(data));
    writeTransportBlock(&block);
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

void TcpStream::onDisconnected()
{
    emit Disconnected(this);
}

void TcpStream::onError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
}

void TcpStream::writeTransportBlock(TransportDataBlock *block)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    block->toDataStream(stream);
    if (_socket->write(buffer) != buffer.size())
    {
        throw BaseException("Not all data was sent!");
    }
}

void TcpStream::initConnections()
{
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
}
