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
#include "database/DatabaseDataFile.h"
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

    DatabaseDataFile file;
    file.setFileName("test.data");
    file.open(QIODevice::ReadWrite);

    DatabaseDataFileRecord rec, rec2;
    rec.setData("asdfgh");
    file.write(&rec);

    rec.setData("asdfgh3eуык пйц4ей34пыаим ыкепй емкуп34й  4пывпыпва фfsdfbdfb");
    file.write(&rec);

    file.seek(0);
    file.read(&rec2);

    file.close();


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
