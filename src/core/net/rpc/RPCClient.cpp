#include "RPCClient.h"
#include <core/Context.h>
#include <core/StringUtils.h>

RPCClient::RPCClient(QObject *parent) :
    QObject(parent)
{
}

void RPCClient::updateNodes()
{
    auto nodes = Context::Instance().getRpcServers();

    if (nodes.count() == 0)
    {
        qDebug() << "There were no rpc servers registered in the system!";
        return;
    }

    for (auto i = 0; i < nodes.count(); i++)
    {
        auto thr = new RPCRequestThread(*(nodes.get(i)), "nodes");
        connect(thr, SIGNAL(threadFinished(RPCRequestThread*)), this, SLOT(processResponse(RPCRequestThread*)));
    }
}

void RPCClient::processResponse(RPCRequestThread *thread)
{
    if (!thread->response()) return;
    RPCRequest *req = static_cast<RPCRequest *>(thread->response()->request());

    if (!req) return;
    if (req->getAction() == "nodes")
    {
        NodeCollectionModel nodes;
        try
        {
            IJsonSerializable::fromString(&nodes, thread->response()->getContent());
        }
        catch (BaseException &ex)
        {
            qDebug() << ex.what();
            return;
        }
        Context::Instance().updateNodes(nodes);
    }
    delete thread;
}

