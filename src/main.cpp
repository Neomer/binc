#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <core/net/PortMapping.h>
#include <core/net/NetDataStreamException.h>
#include <core/net/HTTPParsingException.h>
#include <core/net/HTTPResponse.h>
#include <core/net/HTTPClient.h>
#include <core/net/SSDPProvider.h>
#include <core/net/UdpStream.h>


int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    Context::Instance().init();

    quint16 port = 0;
    try
    {
        PortMapping::tryMapPort(16787, &port);
    }
    catch (NetDataStreamException &ex)
    {
        qDebug() << ex.what();
    }

    try
    {
        HTTPResponse resp = HTTPClient::get(QUrl("http://yandex.ru"));
        if (resp.status() != 200)
        {
            qDebug() << resp.statusMessage();
        }
    }
    catch (HTTPParsingException &ex)
    {

        qDebug() << "Error: line" << ex.line() << ex.what();
    }

    //SSDPProvider::registerPort(1567);

    return a.exec();
}
