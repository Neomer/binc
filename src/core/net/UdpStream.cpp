#include "UdpStream.h"
#include <QDebug>


UdpStream::UdpStream() :
    QObject(),
    ISubject(),
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

void UdpStream::read(IJsonSerializable *data)
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
    block.deserialize(stream);
    if (!block.isReady())
    {
        return;
    }
}

void UdpStream::write(IJsonSerializable *data)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    auto block = new TransportDataBlock();
    block->setTransactionId(Guid::randomGuid());
    block->setStatus(TransportDataBlock::enStatusLast);
    block->setPreviousBlockId(Guid::emptyGuid());
    block->setData(IJsonSerializable::toByteArray(data));
    block->serialize(stream);
    _socket->writeDatagram(buffer, QHostAddress::Broadcast, _port);
}

void UdpStream::readDatagram()
{
    read(0);
}

