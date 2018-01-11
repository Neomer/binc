#include "UdpStream.h"
#include <QDebug>


UdpStream::UdpStream() :
    QObject(),
    ISubject(),
    _port(16789)
{
    _socket = new QUdpSocket(this);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()), Qt::DirectConnection);
}

UdpStream::~UdpStream()
{
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
}

void UdpStream::read(IDataBlock *data)
{
    UdpDataBlock *udpBlock = static_cast<UdpDataBlock *>(data);
    QHostAddress addr;
    quint16 port;
    int len = 0;
    do
    {
        memset(_data_buffer, 0, UDP_BUFFER_SIZE);
        len = _socket->readDatagram(_data_buffer, UDP_BUFFER_SIZE, &addr, &port);
        if (len <= 0) break;
        udpBlock->append(QByteArray(_data_buffer, len));
        udpBlock->setRemoteAddress(addr);
        udpBlock->setRemotePort(port);
    }
    while (len > 0);
    try
    {
        udpBlock->parse();
    }
    catch (DataStreamException &)
    {
        qDebug() << "Parsing error!";
    }
}

void UdpStream::write(IDataBlock *data)
{
    auto ba = ((UdpDataBlock *)data)->compiled();
    _socket->writeDatagram(ba.constData(), ba.size(), QHostAddress::Broadcast, _port);
}

void UdpStream::readDatagram()
{
    UdpDataBlock block;
    read(&block);
    update(&block);
}

