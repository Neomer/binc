#include "RPCCommunicationThread.h"
#include <QMetaObject>
#include <model/NodeCollectionModel.h>
#include <core/Context.h>

RPCCommunicationThread::RPCCommunicationThread(QTcpSocket *socket, QObject *parent) :
    QThread(parent),
    _socket(socket)
{

}

void RPCCommunicationThread::run()
{
    bool run = true;
    while (run)
    {
        // Kill thread by timeout
        if (!_socket->waitForReadyRead(10000))
        {
            qDebug() << "Timeout! Killing thread...";
            run = false;
            continue;
        }
        RPCRequest req;
        try
        {
            req.parse(_socket->readAll());
        }
        catch (HTTPParsingException &ex)
        {
            qDebug() << "Parsing error at line" << ex.line() << ex.what();
            run = false;
            continue;
        }
        catch (BaseException &ex)
        {
            qDebug() << ex.what();
            run = false;
            continue;
        }
        QString action = req.getAction();
        RPCResponse resp(&req);
        resp.setHeader("Server", "RPC-Server");
        resp.setHeader("Connection", "close");
        if (action.isEmpty())
        {
            resp.setStatus(400);
            resp.setStatusMessage("Bad request");
        }
        else
        {
            IAbstractRpcController *ctrl = getController(action);
            if (!ctrl)
            {
                resp.setStatus(404);
                resp.setStatusMessage("Unknown command!");
            }
            else
            {
                ctrl->setRequest(&req);
                try
                {
                    ctrl->exec(&resp);
                }
                catch (BaseException &)
                {
                    resp.setStatus(401);
                    resp.setStatusMessage("Controller exception!");
                }
            }
        }
        QString r = resp.compile();
        _socket->write(r.toUtf8());
    }
    emit finish(this);
}

IAbstractRpcController *RPCCommunicationThread::getController(QString name)
{
    foreach (auto c, _controllers) if (c->getControllerName() == name) return c;
    return nullptr;
}
