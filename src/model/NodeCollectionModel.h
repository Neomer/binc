#ifndef NODECOLLECTIONMODEL_H
#define NODECOLLECTIONMODEL_H

#include <QList>
#include <core/IJsonSerializable.h>
#include "NodeModel.h"

class NodeCollectionModel : public IJsonSerializable
{
public:
    NodeCollectionModel();

    void addNode(NodeModel *node) { _models << node; }

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

private:
    QList<NodeModel *> _models;
};

#endif // NODECOLLECTIONMODEL_H
