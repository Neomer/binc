#ifndef RPCSERVERCOLLECTIONMODEL_H
#define RPCSERVERCOLLECTIONMODEL_H

#include <core/IJsonSerializable.h>
#include <model/RPCServerModel.h>

///
/// \brief RPCServerCollectionModel модель данных список RPC-серверов. Используется для ответа RPC-сервера.
///
class RPCServerCollectionModel : public IJsonSerializable
{
private:
    QList<RPCServerModel *> _list;

public:
    RPCServerCollectionModel();

    QList<RPCServerModel *> &servers() { return _list; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // RPCSERVERCOLLECTIONMODEL_H
