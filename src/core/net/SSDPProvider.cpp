#include "SSDPProvider.h"
#include "SSDPRequest.h"
#include "HTTPUdpClient.h"
#include "NetDataStreamException.h"
#include "HTTPParsingException.h"

SSDPProvider::SSDPProvider()
{

}

void SSDPProvider::registerPort(quint16 port)
{
    SSDPRequest req;
    try
    {
        HTTPResponse resp = HTTPUdpClient::send(&req);
        foreach (QString h, resp.headers())
        {
            qDebug() << h << "=>" << resp.header(h);
        }
        QString h = resp.header("location");
        if (!h.isEmpty())
        {
            req.setAction(SSDP_ACTION_ADDPORT);
            req.setUrl(QUrl(h));
            resp = HTTPUdpClient::send(&req);
        }
        else
        {
            qDebug() << "Location not set!";
        }
    }
    catch (HTTPParsingException &ex)
    {
        qDebug() << "Error: line" << ex.line() << ex.what();
    }
    catch (NetDataStreamException &ex)
    {
        qDebug() << "Error:" << ex.what();
    }
}
