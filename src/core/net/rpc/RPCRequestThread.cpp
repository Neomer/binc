#include "RPCRequestThread.h"
#include <QTcpSocket>
#include <core/net/rpc/RPCRequest.h>
#include <core/net/rpc/RPCResponse.h>

RPCRequestThread::RPCRequestThread(ConnectionPoint point) :
    _point(point)
{
    start();
}

void RPCRequestThread::run()
{
    QTcpSocket socket;
    socket.connectToHost(_point.getAddress(), _point.getPort());
    if (!socket.waitForConnected(5000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable, "Connection timeout!");
    }
    RPCRequest req;
    req.setMethodName("GET");
    req.setUrl(QUrl("http://" + _point.getAddress().toString() + ":" + QString::number(_point.getPort()) + "/nodes/"));
    req.setVersion(Version(1, 0));
    socket.write(req.compile().toUtf8());
    if (!socket.waitForBytesWritten())
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Writing timeout!");
    }
    RPCResponse resp(&req);
    while (!socket.waitForReadyRead(10000))
    {
        throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Reading timeout!");
    }

    try
    {
        resp.parse(QString::fromUtf8(socket.readAll()));
    }
    catch (HTTPParsingException &ex)
    {
        qDebug() << "Parsing error at line" << ex.line() << ex.what();
        return;
    }
    catch (BaseException &ex)
    {
        qDebug() << "Error:" << ex.what();
        return;
    }

    qDebug() << resp.getContent();

}
