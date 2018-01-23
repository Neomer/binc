#include "Deal.h"

Deal::Deal() :
    IIdentifyed(),
    _amount(0),
    _reward(0)
{

}

void Deal::toJsonObject(QJsonObject &out)
{
    out["id"] = getId().toString();
    out["recipient"] = _recipient.toString();
    out["sender"] = _sender.toString();
    out["amount"] = _amount;
    out["reward"] = _reward;
    out["hash"] = Hash::fromJsonObject(out).toString();
}

void Deal::fromJsonObject(QJsonObject &in)
{
    setId(Guid::fromString(in["id"].toString()));
    _recipient = Guid::fromString(in["recipient"].toString());
    _sender = Guid::fromString(in["sender"].toString());
    _amount = in["amount"].toDouble();
    _reward = in["reward"].toDouble();
}
