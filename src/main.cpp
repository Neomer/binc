#include <QDebug>
#include <QCoreApplication>
#include <core/net/PortMapping.h>
#include <core/net/NetDataStreamException.h>
#include <core/net/HTTPParsingException.h>
#include <core/net/HTTPgetRequest.h>
#include <core/net/HTTPClient.h>

int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
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

        qDebug() << "Error line" << ex.line() << ex.what();
    }

    return a.exec();
}
