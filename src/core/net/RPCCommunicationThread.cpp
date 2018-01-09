#include "RPCCommunicationThread.h"
#include "AbstractHTTPRequest.h"

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
        AbstractHTTPRequest req;
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
    }
    emit finish(this);
}
