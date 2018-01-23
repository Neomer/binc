#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <QJsonDocument>

#include <core/net/Net.h>
#include <core/transport/TransportTransaction.h>
#include <model/Block.h>
#include "../tests/chat/Chat.h"

int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    Context::Instance().load("binc.conf");

    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1564));
    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1565));
    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1566));
    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1567));

    QFile file("test.bin");
    file.open(QIODevice::ReadWrite);
    QDataStream stream(&file);

    Block b, copy;
    b.setPreviousBlock(Guid::randomGuid());
    b.setNonce(78234);
    b.setVersion(Version(1, 43, 23));
    file.write(IJsonSerializable::toString(&b).toUtf8());
    file.close();

    Net net;
    net.connect();

    Chat chat;
    chat.run();

    int ret = a.exec();

    Context::Instance().unload();

    return ret;
}
