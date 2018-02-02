#include <QDebug>
#include <QCoreApplication>
#include <core/Context.h>
#include <QJsonDocument>
#include <time.h>

#include <core/net/rpc/RPCRequestThread.h>

#include "../tests/chat/Chat.h"

int main(int argc, char ** argv)
{
    int ret = 0;
    srand(time(NULL));

    QCoreApplication a(argc, argv);
    for (int i = 0; i < argc; i++)
    {
        qDebug("%s", argv[i]);
    }
    try
    {
        Context::Instance().load("binc.conf");

        RPCServerCollectionModel coll;
        coll.add(new RPCServerModel(QHostAddress("127.0.0.1"), Context::Instance().settings()->getRPCport()));
        Context::Instance().updateRpcServers(coll);

        Chat chat;
        chat.run();

        Context::Instance().settings()->save();

        ret = a.exec();
    }
    catch (BaseException &ex)
    {
        qDebug() << "Execution failed:" << ex.what();
    }

    Context::Instance().unload();

    return ret;
}
