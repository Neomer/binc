#ifndef RPCSERVER_H
#define RPCSERVER_H

#include <QObject>
#include <QTcpServer>
#include <core/net/NetDataStreamException.h>
#include "RPCCommunicationThread.h"

class RPCServer : QObject
{
    Q_OBJECT

public:
    RPCServer(QObject *parent = 0);
    ~RPCServer();

    void start();

private slots:
    void acceptConnection();
    void threadFinished(RPCCommunicationThread *);

private:
    QTcpServer *_srv;
    QList<RPCCommunicationThread *> _threads;
};

#endif // RPCSERVER_H
