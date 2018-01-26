#ifndef NODECOLLECTIONMODEL_H
#define NODECOLLECTIONMODEL_H

#include <QList>
#include <core/IJsonSerializable.h>
#include <core/ICollection.h>
#include "NodeModel.h"

class NodeCollectionModel :
        public IJsonSerializable,
        public ICollection<NodeModel *>
{
public:
    NodeCollectionModel();

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

private:
    QList<NodeModel *> _nodes;

    // ICollection interface
public:
    NodeModel *first() override;
    NodeModel *last() override;
    NodeModel *get(int index) override;
    void add(NodeModel * item) override;
    void add(NodeModel * item, int after) override;
    void remove(int index) override;
    int count() override;
};

#endif // NODECOLLECTIONMODEL_H
