#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <core/net/rpc/RPCServer.h>
#include <model/NodeCollectionModel.h>
#include <QJsonDocument>

#include "../tests/chat/Chat.h"

int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    Context::Instance().load("binc.conf");

    RPCServer server;
    server.start();

    QJsonObject obj;

    NodeCollectionModel nodecollection;
    NodeModel node;
    node.setAddress(QHostAddress::Any);
    node.setPort(3444);
    nodecollection.addNode(&node);
    nodecollection.serialize(obj);

    QJsonDocument json(obj);

    qDebug() << QString::fromUtf8(json.toJson(QJsonDocument::Compact));

//    Chat chat;
//    chat.run();

    int ret = a.exec();

    Context::Instance().unload();

    return ret;
}
