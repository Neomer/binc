#ifndef RPCREQUESTTHREAD_H
#define RPCREQUESTTHREAD_H

#include <QThread>

#include <core/net/NetDataStreamException.h>
#include <core/types/ConnectionPoint.h>
#include <core/net/rpc/RPCRequest.h>

///
///\brief RPCRequestThread атомарный сеанс связи с RPC-сервером
///
class RPCRequestThread : public QThread
{
    ConnectionPoint _point;

public:
    RPCRequestThread(ConnectionPoint point, QString action);

    // QThread interface
protected:
    void run() override;

private:
    QString _action;
};

#endif // RPCREQUESTTHREAD_H
