#include "RPCRequestThread.h"
#include <QTcpSocket>

RPCRequestThread::RPCRequestThread(ConnectionPoint point, QString action) :
    _point(point),
    _action(action),
    _response(0)
{
    start();
}

RPCRequestThread::~RPCRequestThread()
{
    //if (_response) delete _response;
}

void RPCRequestThread::run()
{
    try
    {
        QTcpSocket socket;
        socket.connectToHost(_point.getAddress(), _point.getPort());
        if (!socket.waitForConnected(5000))
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_HostNotAvailable, "Connection timeout!");
        }
        auto req = new RPCRequest();
        req->setMethodName("GET");
        req->setUrl(QUrl("http://" + _point.getAddress().toString() + ":" + QString::number(_point.getPort()) + "/" + _action + "/"));
        req->setVersion(Version(1, 0));
        qDebug() << (quint32) currentThreadId() << "RPCRequestThread :: Send request...";
        socket.write(req->compile().toUtf8());
        if (!socket.waitForBytesWritten())
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Writing timeout!");
        }
        _response = new RPCResponse(req);
        while (!socket.waitForReadyRead(10000))
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_Timeout, "Reading timeout!");
        }
        qDebug() << (quint32) currentThreadId() << "RPCRequestThread :: Parse response...";

        try
        {
            _response->parse(QString::fromUtf8(socket.readAll()));
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
    }
    catch (NetDataStreamException &ex)
    {
        _response = 0;
        qDebug() << "Exception:" << ex.what();
    }
    qDebug() << (quint32) currentThreadId() << "RPCRequestThread :: Thread finished...";
    emit threadFinished(this);
}
