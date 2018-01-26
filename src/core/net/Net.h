#ifndef NET_H
#define NET_H

#include <QObject>
#include <QList>

#include <core/net/rpc/RPCServer.h>
#include <core/net/UdpStream.h>
#include <core/net/TransportProvider.h>
#include <core/net/NodeConnection.h>
#include <core/net/NodeConnectionPoint.h>
#include <model/NodeCollectionModel.h>
#include <core/net/TcpStreamProvider.h>

///
/// \brief The Net основной класс для подключения к p2p-сети.
/// Осуществляет поиск активных узлов в сети, подключение к ним, обмен системной информацией, необходимой для поддержки подключения.
/// Содержит методы для возможности входа в сеть, отключения от сети, отправку информации по сети.
///
class Net : public QObject, public IObserver
{
    Q_OBJECT

public:
    Net(QObject *parent = 0);

    ///
    /// \brief connect начинает подключение к сети. При успешном подключении хотя бы к 1му узлу сети формируется сигнал Connected.
    ///
    void connect();
    ///
    /// \brief close закрывает все активные подключения.
    ///
    void close();
    void write(IJsonSerializable *data);
    void read();

    NodeCollectionModel &getNodes() { return _nodes; }

    // IObserver interface
public:
    void update(const Guid &subject, void *data) override;

signals:
    ///
    /// \brief Connected Удалось подключиться хотя бы к 1 узлу
    ///
    void Connected();

private slots:
    ///
    /// \brief ConnectionCountChanged Количество подключенных узлов изменилось
    ///
    void onConnectionCountChanged(int);
    void onEntityReady(JsonSerializableEntity *entity);

private:
    RPCServer _rpc_server;
    NodeCollectionModel _nodes;
    TransportProvider _transport_provider;
    NodeConnectionPoint _node;
    TcpStreamProvider _tcp_provider;
};

#endif // NET_H
