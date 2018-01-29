#include "JsonSerializableIdentifyedEntity.h"

JsonSerializableIdentifyedEntity::JsonSerializableIdentifyedEntity(QString entityName) :
    _entity_name(entityName)
{

}

JsonSerializableIdentifyedEntity::JsonSerializableIdentifyedEntity()
{

}

void JsonSerializableIdentifyedEntity::toJsonObject(QJsonObject &out)
{
    out["entity-name"] =  getEntityName();
    out["id"] = getId().toString();
}

void JsonSerializableIdentifyedEntity::fromJsonObject(QJsonObject &in)
{
    _entity_name = in["entity-name"].toString();
    setId(Guid::fromString(in["id"].toString()));
}
