#include "HTTPClient.h"


HTTPClient::HTTPClient()
{

}

HTTPResponse HTTPClient::get(QUrl &url)
{
    QTcpSocket *socket = new QTcpSocket();
    if (!url.isValid())
    {
        throw std::runtime_error("Invalid url!");
    }
    socket->connectToHost(url.host(), url.port(80));
    if (!socket->waitForConnected(3000))
    {
        throw std::runtime_error("Host is unavailable!");
    }

    socket->write()

    HTTPResponse ret;
    return ret;
}
