#include "TcpStreamProvider.h"
#include <QTcpSocket>
#include <core/Context.h>

TcpStreamProvider::TcpStreamProvider()
{

}

void TcpStreamProvider::start()
{
    _run = true;
    QThread::start();
}

void TcpStreamProvider::terminate()
{
    _run = false;
}

void TcpStreamProvider::run()
{
    QTcpSocket *socket = 0;
    for (int i = 0; i < Context::Instance().settings()->nodes().count() && _run; i++)
    {
        if (!socket) socket = new QTcpSocket();
        NodeModel *node = Context::Instance().settings()->nodes().first();
        socket->connectToHost(node->getAddress(), node->getPort());
        if (socket->waitForConnected(3000))
        {
            update(new TcpStream(socket));
            socket = 0;
        }
    }
    if (socket) delete socket;
}
