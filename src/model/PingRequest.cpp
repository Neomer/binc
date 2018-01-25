#include "PingRequest.h"

PingRequest::PingRequest()
{

}

void PingRequest::toJsonObject(QJsonObject &out)
{
    out["id"] = getId().toString();
}

void PingRequest::fromJsonObject(QJsonObject &in)
{
    Guid id;

    id = Guid::fromString(in["id"].toString());

    setId(id);
}
