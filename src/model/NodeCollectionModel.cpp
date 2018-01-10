#include "NodeCollectionModel.h"

NodeCollectionModel::NodeCollectionModel()
{

}

void NodeCollectionModel::serialize(QJsonObject &out)
{
    QJsonArray a;
    foreach (NodeModel *n, _models)
    {
        QJsonObject o;
        n->serialize(o);
        a << o;
    }
    out["nodes"] = a;
}

void NodeCollectionModel::deserialize(QJsonObject &in)
{
    QJsonArray a = in["nodes"].toArray();
    foreach (QJsonValue v, a)
    {
        QJsonObject o = v.toObject();
        NodeModel *node = new NodeModel();
        node->deserialize(o);
        addNode(node);
    }
}
