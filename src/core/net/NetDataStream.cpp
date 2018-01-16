#include "NetDataStream.h"
#include "NetDataStreamException.h"

NetDataStream::NetDataStream(ConnectionPoint point, QObject *parent) :
    QObject(parent),
    _point(point)
{
    _socket = new QTcpSocket(this);
}

NetDataStream::NetDataStream(QTcpSocket *socket)
{
    _socket = socket;
}

NetDataStream::~NetDataStream()
{

}

void NetDataStream::open()
{
    _socket->connectToHost(_point.getAddress(), _point.getPort());
    if (!_socket->waitForConnected(3000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable, "Host is unavailable!");
    }
}

void NetDataStream::close()
{
    _socket->close();
}

void NetDataStream::read(IDataBlock *data)
{
    _socket->read(0, 0);
}

void NetDataStream::write(IDataBlock *data)
{
    _socket->write(data->data().constData(), data->size());
}
