#include "RPCServerCollectionModel.h"

RPCServerCollectionModel::RPCServerCollectionModel()
{

}

RPCServerCollectionModel::RPCServerCollectionModel(const RPCServerCollectionModel &other) :
    _list(other._list)
{

}

RPCServerCollectionModel &RPCServerCollectionModel::operator =(const RPCServerCollectionModel &other)
{
    _list = other._list;
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

RPCServerModel *RPCServerCollectionModel::first()
{
    return _list.first();
}

RPCServerModel *RPCServerCollectionModel::last()
{
    return _list.last();
}

RPCServerModel *RPCServerCollectionModel::get(int index)
{
    Q_ASSERT(index < _list.count());
    return _list.at(index);
}

void RPCServerCollectionModel::add(RPCServerModel *item)
{
    bool found = false;

    foreach (auto it, _list)
    {
        if (item->getAddress() == it->getAddress() && item->getPort() == it->getPort())
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        _list << item;
    }
}

void RPCServerCollectionModel::add(ICollection<RPCServerModel *> &other)
{
    for (auto i = 0; i < other.count(); i++)
    {
        add(other.get(i));
    }
}

void RPCServerCollectionModel::add(RPCServerModel *item, int after)
{
    bool found = false;

    foreach (auto it, _list)
    {
        if (item->getAddress() == it->getAddress() && item->getPort() == it->getPort())
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        _list.insert(after, item);
    }
}

void RPCServerCollectionModel::remove(int index)
{
    Q_ASSERT(index >= 0 && index < _list.count());
    _list.removeAt(index);
}

int RPCServerCollectionModel::count()
{
    return _list.count();
}
