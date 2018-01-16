#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <core/IJsonSerializable.h>
#include <core/types/ConnectionPoint.h>

class NodeModel : public ConnectionPoint, public IJsonSerializable
{
public:
    NodeModel();
    NodeModel(QHostAddress address, quint16 port);

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

};

#endif // NODEMODEL_H
