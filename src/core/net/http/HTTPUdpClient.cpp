#include "HTTPUdpClient.h"
#include <QUdpSocket>
#include <core/net/NetDataStreamException.h>

HTTPUdpClient::HTTPUdpClient()
{

}

HTTPResponse HTTPUdpClient::send(IHTTPRequest *request)
{
    QUdpSocket *socket = new QUdpSocket();
    if (!request->getUrl().isValid())
    {
        throw std::runtime_error("Invalid url!");
    }
    if (!socket->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_PortIsBusy, "Port is busy!");
    }
    socket->joinMulticastGroup(QHostAddress::AnyIPv4);
    QString sData = request->compile();
    qint64 len = socket->writeDatagram(sData.toUtf8(), QHostAddress(request->getUrl().host()), request->getUrl().port());
    if (len == -1)
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Sending error!");
    }
    if (!socket->waitForReadyRead(4000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Response timeout!");
    }
    QByteArray ba;
    while (socket->hasPendingDatagrams())
    {
        ba.resize(socket->pendingDatagramSize());
        socket->readDatagram(ba.data(), ba.size());
    }
    delete socket;

    return HTTPResponse(request, ba);
}
