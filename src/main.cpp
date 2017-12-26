#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <core/net/PortMapping.h>
#include <core/net/NetDataStreamException.h>
#include <core/net/HTTPParsingException.h>
#include <core/net/HTTPResponse.h>
#include <core/net/HTTPClient.h>
#include <core/net/SSDPProvider.h>
#include <database/Database.h>

#include "database/DatabaseIndexFile.h"
#include <core/net/UdpStream.h>
#include <core/types/Guid.h>

int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    Context::Instance().load();

    DatabaseIndexFile file;
    file.open(QIODevice::WriteOnly);
    DatabaseIndexRecord rec;
    file.write();

    srand(QDateTime::currentDateTime().toMSecsSinceEpoch());
    QDateTime start = QDateTime::currentDateTime();
    for (int i = 0; i < 100; i++)
    {
        try
        {
            Context::Instance().database()->write(rand(), IDatabaseObject());
        }
        catch (DatabaseException &)
        {
        }
    }
    qDebug() << "Time elapsed:" << start.msecsTo(QDateTime::currentDateTime()) * 0.001;

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
    int ret = a.exec();

    Context::Instance().unload();

    return ret;
}
