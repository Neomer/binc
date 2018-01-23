#ifndef RPCSERVER_H
#define RPCSERVER_H

#include <QObject>
#include <QTcpServer>
#include <core/net/NetDataStreamException.h>
#include "RPCCommunicationThread.h"

///
/// \brief The RPCServer класс который реализует доступ к текущему узлы с помощью RPC.
/// Класс встает на прослушку порта, указанного в настройках. При новом подключении осуществляется
/// проверка лимита подключений. Если лимит не достигнут, то запускается новый поток для каждой сессии.
///
class RPCServer : QObject
{
    Q_OBJECT

public:
    RPCServer(QObject *parent = 0);
    ~RPCServer();

    void start();
    void stop();

private slots:
    void acceptConnection();
    void threadFinished(RPCCommunicationThread *);

private:
    QTcpServer *_srv;
    QList<RPCCommunicationThread *> _threads;
};

#endif // RPCSERVER_H
