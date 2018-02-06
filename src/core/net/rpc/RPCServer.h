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
/// Нужен для доступа к узлолу посредством HTTP протокола. Подключение с помощью RPC является временным и не относится к
/// одноранговой сети.
///
class RPCServer : QObject
{
    Q_OBJECT

public:
    RPCServer(QObject *parent = 0);
    ~RPCServer();

    ///
    /// \brief start запускает сервер
    ///
    void start();
    ///
    /// \brief stop останавливает сервер
    ///
    void stop();

    void registerController(IAbstractRpcController *controller) { _controllers << controller; }

private slots:
    ///
    /// \brief acceptConnection выполняется при новом подключении
    ///
    void acceptConnection();
    ///
    /// \brief threadFinished выполняется при завершении сессии
    ///
    void threadFinished(RPCCommunicationThread *);

private:
    QTcpServer *_srv;
    QList<RPCCommunicationThread *> _threads;
    QList<IAbstractRpcController *> _controllers;
};

#endif // RPCSERVER_H
