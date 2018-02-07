#ifndef JSONSERIALIZABLEIDENTIFYEDENTITY_H
#define JSONSERIALIZABLEIDENTIFYEDENTITY_H

#include <core/IJsonSerializable.h>
#include <core/IIdentifyed.h>
#include <core/IEntity.h>

class JsonSerializableIdentifyedEntity :
        public IIdentifyed,
        public IEntity,
        public IJsonSerializable
{
private:
    QString _entity_name;

public:
    JsonSerializableIdentifyedEntity(QString entityName);
    JsonSerializableIdentifyedEntity();

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

    // IEntity interface
public:
    QString getEntityName() override { return _entity_name; }
};

#endif // JSONSERIALIZABLEIDENTIFYEDENTITY_H
