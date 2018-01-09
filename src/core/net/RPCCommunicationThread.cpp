#include "RPCCommunicationThread.h"
#include <QMetaObject>

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
        qDebug() << "Action:" << action;
        HTTPResponse resp(&req);
        if (!QMetaObject::invokeMethod(this, action.toLatin1().constData(), Qt::DirectConnection, QGenericArgument("request", &resp)))
        {
            resp.setStatus(404);
            resp.setStatusMessage("Unknown command!");
        }
    }
    emit finish(this);
}

void RPCCommunicationThread::nodes(HTTPResponse *request)
{
    Q_UNUSED(request);


}
