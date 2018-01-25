#ifndef PINGREQUEST_H
#define PINGREQUEST_H

#include <core/JsonSerializableEntity.h>
#include <core/IIdentifyed.h>

class PingRequest : public JsonSerializableEntity, public IIdentifyed
{
public:
    PingRequest();

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // PINGREQUEST_H
