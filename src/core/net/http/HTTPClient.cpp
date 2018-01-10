#include "HTTPClient.h"
#include "HTTPRequest.h"
#include <core/net/NetDataStreamException.h>

HTTPClient::HTTPClient()
{

}

HTTPResponse HTTPClient::get(QUrl url)
{
    QTcpSocket *socket = new QTcpSocket();
    if (!url.isValid())
    {
        throw BaseException("Invalid url!");
    }
    socket->connectToHost(url.host(), url.port(80));
    if (!socket->waitForConnected(3000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable ,"Host is unavailable!");
    }
    HTTPRequest req("GET");
    req.setUrl(QUrl("http://ya.ru/"));
    socket->write(req.compile().toUtf8());
    if (!socket->waitForBytesWritten(3000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Request sending timeout!");
    }
    if (!socket->waitForReadyRead(5000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Response timeout!");
    }
    QByteArray data = socket->readAll();
    delete socket;

    return HTTPResponse(&req, data);
}
