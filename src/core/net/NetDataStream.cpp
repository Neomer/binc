#include "NetDataStream.h"
#include "NetDataStreamException.h"

NetDataStream::NetDataStream(QHostAddress address)
{
    _socket = new QTcpSocket(this);
    _remoteHost = address;
    _port = 15789;
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
    _socket->connectToHost(_remoteHost, _port);
    if (!_socket->waitForConnected(3000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable, "Host is unavailable!");
    }
}

void NetDataStream::close()
{
    _socket->close();
}

qint64 NetDataStream::readData(char *data, qint64 maxlen)
{
    return _socket->read(data, maxlen);
}

qint64 NetDataStream::writeData(const char *data, qint64 len)
{
    return _socket->write(data, len);
}
