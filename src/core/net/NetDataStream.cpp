#include "NetDataStream.h"
#include "NetDataStreamException.h"

NetDataStream::NetDataStream(ConnectionPoint point, QObject *parent) :
    IObservableDataStream(),
    QObject(parent),
    _point(point)
{
    _socket = new QTcpSocket(this);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
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

void NetDataStream::read(IJsonSerializable *data)
{
    Q_UNUSED(data);
}

void NetDataStream::write(IJsonSerializable *data)
{
    Q_UNUSED(data);
}

void NetDataStream::readData()
{
}
