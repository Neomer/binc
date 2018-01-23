#include "NodeCollectionModel.h"

NodeCollectionModel::NodeCollectionModel()
{

}

void NodeCollectionModel::toJsonObject(QJsonObject &out)
{
    QJsonArray a;
    foreach (NodeModel *n, _models)
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
        addNode(node);
    }
}
