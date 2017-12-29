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

    int ret = a.exec();

    Context::Instance().unload();

    return ret;
}
