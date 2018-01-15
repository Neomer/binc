#include "Net.h"
#include <QDebug>

Net::Net(QObject *parent) :
    QObject(parent),
    _rpc_server(this)
{

}

void Net::connect()
{
    try
    {
        _rpc_server.start();
    }
    catch (NetDataStreamException &ex)
    {
        qDebug() << "RPC Server starting failed!" << ex.what();
        return;
    }
}

void Net::close()
{
    _rpc_server.stop();
}
