#include "RPCServerCollectionModel.h"

RPCServerCollectionModel::RPCServerCollectionModel()
{

}

void RPCServerCollectionModel::toJsonObject(QJsonObject &out)
{
    QJsonArray a;
    foreach (auto item, _list)
    {
        QJsonObject o;
        item->toJsonObject(o);
        a << o;
    }
    out["rpc-server-collection"] = a;
}

void RPCServerCollectionModel::fromJsonObject(QJsonObject &in)
{
    _list.clear();
    foreach (auto item, in["rpc-server-collection"].toArray())
    {
        auto s = new RPCServerModel();
        auto obj = item.toObject();
        s->fromJsonObject(obj);
        _list.append(s);
    }
}
