#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <core/net/RPCServer.h>

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

//    Chat chat;
//    chat.run();

    int ret = a.exec();

    Context::Instance().unload();

    return ret;
}
