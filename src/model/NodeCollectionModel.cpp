#include "NodeCollectionModel.h"

NodeCollectionModel::NodeCollectionModel()
{

}

void NodeCollectionModel::toJsonObject(QJsonObject &out)
{
    QJsonArray a;
    foreach (NodeModel *n, _nodes)
    {
        QJsonObject o;
        n->toJsonObject(o);
        a << o;
    }
    out["nodeList"] = a;
}

void NodeCollectionModel::fromJsonObject(QJsonObject &in)
{
    QJsonArray a = in["nodeList"].toArray();
    foreach (QJsonValue v, a)
    {
        QJsonObject o = v.toObject();
        NodeModel *node = new NodeModel();
        node->fromJsonObject(o);
        add(node);
    }
}

NodeModel *NodeCollectionModel::first()
{
    return _nodes.first();
}

NodeModel *NodeCollectionModel::last()
{
    return _nodes.last();
}

NodeModel *NodeCollectionModel::get(int index)
{
    Q_ASSERT(index < _nodes.count());
    return _nodes.at(index);
}

void NodeCollectionModel::add(NodeModel *item)
{
    bool found = false;

    foreach (auto it, _nodes)
    {
        if (item->getAddress() == it->getAddress() && item->getPort() == it->getPort())
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        _nodes << item;
    }
}

void NodeCollectionModel::add(ICollection<NodeModel *> &other)
{
    for (auto i = 0; i < other.count(); i++)
    {
        add(other.get(i));
    }
}

void NodeCollectionModel::add(NodeModel *item, int after)
{
    bool found = false;

    foreach (auto it, _nodes)
    {
        if (item->getAddress() == it->getAddress() && item->getPort() == it->getPort())
            {
            found = true;
            break;
        }
    }

    if (!found)
    {
        _nodes.insert(after, item);
    }
}

void NodeCollectionModel::remove(int index)
{
    _nodes.removeAt(index);
}

int NodeCollectionModel::count()
{
    return _nodes.count();
}
