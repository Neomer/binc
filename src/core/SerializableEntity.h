#ifndef SERIALIZABLEENTITY_H
#define SERIALIZABLEENTITY_H

#include <core/IJsonSerializable.h>
#include <core/IEntity.h>

class SerializableEntity : public IEntity, public IJsonSerializable
{
public:
    SerializableEntity(QString entityName = QString()) { _entityName = entityName; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override
    {
        out["entityName"] = _entityName;
    }

    void fromJsonObject(QJsonObject &in) override
    {
        _entityName = in["entityName"].toString();
    }

    // IEntity interface
public:
    QString getEntityName() override { return _entityName; }

private:
    QString _entityName;
};

#endif // SERIALIZABLEENTITY_H
