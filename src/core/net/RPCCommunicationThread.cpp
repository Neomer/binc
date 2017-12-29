#include "RPCCommunicationThread.h"

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
        if (!_socket->waitForReadyRead(10000))
        {
            run = false;
            break;
        }
    }
    emit finish(this);
}
