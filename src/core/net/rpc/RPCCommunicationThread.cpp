#include "RPCCommunicationThread.h"
#include <QMetaObject>
#include <model/NodeCollectionModel.h>

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
        catch (std::exception &ex)
        {
            qDebug() << ex.what();
            run = false;
            continue;
        }
        QString action = req.action();
        RPCResponse resp(&req);
        resp.setHeader("Server", "RPC-Server");
        resp.setHeader("Connection", "close");
        if (action.isEmpty())
        {
            resp.setStatus(400);
            resp.setStatusMessage("Bad request");
        }
        else if (!QMetaObject::invokeMethod(this, action.toLatin1().constData(), Qt::DirectConnection, QGenericArgument("HTTPResponse *", &resp)))
        {
            resp.setStatus(404);
            resp.setStatusMessage("Unknown command!");
        }
        QString r = resp.compile();
        _socket->write(r.toUtf8());
    }
    emit finish(this);
}

void RPCCommunicationThread::nodes(HTTPResponse *response)
{
    NodeCollectionModel nodes;
    nodes.addNode(new NodeModel(QHostAddress::Any, 15648));
    response->setContent(IJsonSerializable::toString(&nodes));
}
