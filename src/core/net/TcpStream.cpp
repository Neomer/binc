#include "TcpStream.h"

TcpStream::TcpStream() :
    _socket(new QTcpSocket(this))
{

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
