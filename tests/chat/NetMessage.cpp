#include "NetMessage.h"

NetMessage::NetMessage() :
    JsonSerializableIdentifyedEntity("NetMessage")
{

}

void NetMessage::toJsonObject(QJsonObject &out)
{
    JsonSerializableIdentifyedEntity::toJsonObject(out);
    out["message"] = _msg;
}

void NetMessage::fromJsonObject(QJsonObject &in)
{
    JsonSerializableIdentifyedEntity::fromJsonObject(in);
    _msg = in["message"].toString();
}
