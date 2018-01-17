#include "NetDataStream.h"
#include "NetDataStreamException.h"

NetDataStream::NetDataStream(ConnectionPoint point, QObject *parent) :
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

void NetDataStream::read(IDataBlock *data)
{
    NetDataBlock *netBlock = static_cast<NetDataBlock *>(data);
    int len = 0;
    do
    {
        memset(_data_buffer, 0, NET_BUFFER_SIZE);
        len = _socket->read(_data_buffer, NET_BUFFER_SIZE);
        if (len <= 0) break;
        netBlock->append(QByteArray(_data_buffer, len));
        netBlock->setPoint(ConnectionPoint(_socket->peerAddress(), _socket->peerPort()));
    }
    while (len > 0);
    try
    {
        netBlock->parse();
    }
    catch (DataStreamException &)
    {
        qDebug() << "Parsing error!";
    }
}

void NetDataStream::write(IDataBlock *data)
{
    _socket->write(data->data().constData(), data->size());
}

void NetDataStream::readData()
{
    NetDataBlock block;
    read(&block);
    update(&block);
}
