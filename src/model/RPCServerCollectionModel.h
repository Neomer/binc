#ifndef RPCSERVERCOLLECTIONMODEL_H
#define RPCSERVERCOLLECTIONMODEL_H

#include <core/ICollection.h>
#include <core/IJsonSerializable.h>
#include <model/RPCServerModel.h>

///
/// \brief RPCServerCollectionModel модель данных список RPC-серверов. Используется для ответа RPC-сервера.
///
class RPCServerCollectionModel :
        public IJsonSerializable,
        public ICollection<RPCServerModel *>
{
private:
    QList<RPCServerModel *> _list;

public:
    RPCServerCollectionModel();
    RPCServerCollectionModel(const RPCServerCollectionModel &other);
    RPCServerCollectionModel &operator =(const RPCServerCollectionModel &other);

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

    // ICollection interface
public:
    RPCServerModel *first() override;
    RPCServerModel *last() override;
    RPCServerModel *get(int index) override;
    void add(RPCServerModel * item) override;
    void add(ICollection<RPCServerModel *> &other) override;
    void add(RPCServerModel * item, int after) override;
    void remove(int index) override;
    int count() override;
};

#endif // RPCSERVERCOLLECTIONMODEL_H
