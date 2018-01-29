#ifndef NETMESSAGE_H
#define NETMESSAGE_H

#include <core/JsonSerializableIdentifyedEntity.h>

class NetMessage : public JsonSerializableIdentifyedEntity
{
    QString _msg;

public:
    NetMessage();

    QString getMessage() { return _msg; }
    void setMessage(QString value) { _msg = value; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // NETMESSAGE_H
