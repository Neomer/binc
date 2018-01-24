#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <QJsonDocument>
#include <time.h>

#include <core/net/Net.h>
#include <core/transport/TransportTransaction.h>
#include <model/Block.h>
#include "../tests/chat/Chat.h"

int main(int argc, char ** argv)
{
    srand(time(NULL));

    QCoreApplication a(argc, argv);
    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    Context::Instance().load("binc.conf");

//    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1564));
//    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1565));
//    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1566));
//    Context::Instance().settings()->nodes().addNode(new NodeModel(QHostAddress("192.168.0.20"), 1567));

    Chat chat;
    chat.run();

    Context::Instance().settings()->save();

    int ret = 0;
    try
    {
        ret = a.exec();
    }
    catch (BaseException &ex)
    {
        qDebug() << "Execution failed:" << ex.what();
    }
    Context::Instance().unload();

    return ret;
}
