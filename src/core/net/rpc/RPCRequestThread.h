#ifndef RPCREQUESTTHREAD_H
#define RPCREQUESTTHREAD_H

#include <QThread>

#include <core/net/NetDataStreamException.h>
#include <core/types/ConnectionPoint.h>

///
///\brief RPCRequestThread атомарный сеанс связи с RPC-сервером
///
class RPCRequestThread : public QThread
{
    ConnectionPoint _point;

public:
    RPCRequestThread(ConnectionPoint point);

    // QThread interface
protected:
    void run() override;
};

#endif // RPCREQUESTTHREAD_H
