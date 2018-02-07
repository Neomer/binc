#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <core/net/rpc/RPCRequestThread.h>
#include <model/NodeCollectionModel.h>

///
/// \brief RPCClient класс осуществляет запрос с удаленных нодов с помощью RPC списка известных нодов.
/// При успешном получении списка отбрасывает ранее известные ноды. Список нодов сохраняется/читается из файла.
///
class RPCClient : public QObject
{
    Q_OBJECT

public:
    RPCClient(QObject *parent = 0);

    ///
    /// \brief updateNodes обновляет список известных нодов
    ///
    void updateNodes();

private slots:
    void processResponse(RPCRequestThread *thread);
};

#endif // RPCCLIENT_H
