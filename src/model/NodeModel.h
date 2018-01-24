#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <QDateTime>
#include <core/IJsonSerializable.h>
#include <core/types/ConnectionPoint.h>

class NodeModel : public ConnectionPoint, public IJsonSerializable
{
    QDateTime _last_activity;

public:
    NodeModel();
    NodeModel(QHostAddress address, quint16 port);

    QDateTime getLastActivity() { return _last_activity; }
    void setLastActivity(QDateTime value) { _last_activity = value; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

};

#endif // NODEMODEL_H
