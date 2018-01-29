#include "JsonSerializableIdentifyedEntity.h"

JsonSerializableIdentifyedEntity::JsonSerializableIdentifyedEntity()
{

}

void JsonSerializableIdentifyedEntity::toJsonObject(QJsonObject &out)
{
    out["entity-name"] =  getEntityName();
}

void JsonSerializableIdentifyedEntity::fromJsonObject(QJsonObject &in)
{
    _entity_name = in["entity-name"].toString();
}
