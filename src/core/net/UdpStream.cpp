#include "UdpStream.h"

UdpStream::UdpStream() :
    _port(16789)
{
    _socket = new QUdpSocket(this);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

UdpStream::~UdpStream()
{
    delete _socket;
}

void UdpStream::close()
{

}

void UdpStream::open()
{
    if (!_socket->bind(QHostAddress::Any, _port, QAbstractSocket::ShareAddress))
    {
        throw UdpStreamException("Port binding failed!");
    }
}

qint64 UdpStream::readData(char *data, qint64 maxlen)
{

}

qint64 UdpStream::writeData(const char *data, qint64 len)
{

}

void UdpStream::readDatagram()
{

}
