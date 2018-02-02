#ifndef RPCREQUESTTHREAD_H
#define RPCREQUESTTHREAD_H

#include <QThread>

#include <core/net/NetDataStreamException.h>
#include <core/types/ConnectionPoint.h>
#include <core/net/rpc/RPCRequest.h>
#include <core/net/rpc/RPCResponse.h>

///
///\brief RPCRequestThread атомарный сеанс связи с RPC-сервером
///
class RPCRequestThread : public QThread
{
    Q_OBJECT

public:
    RPCRequestThread(ConnectionPoint point, QString action);
    ~RPCRequestThread();

    RPCResponse *response() { return _response; }

    // QThread interface
protected:
    void run() override;

signals:
    void threadFinished(RPCRequestThread *);

private:
    QString _action;
    ConnectionPoint _point;
    RPCResponse *_response;
};

#endif // RPCREQUESTTHREAD_H
