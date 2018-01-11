#include "Deal.h"

Deal::Deal() :
    _amount(0),
    _reward(0)
{

}

void Deal::serialize(QJsonObject &out)
{
    out["recipient"] = _recipient.toString();
    out["sender"] = _sender.toString();
    out["amount"] = _amount;
    out["reward"] = _reward;
}

void Deal::deserialize(QJsonObject &in)
{
    _recipient.fromString(in["recipient"].toString());
    _sender.fromString(in["sender"].toString());
    _amount = in["amount"].toDouble();
    _reward = in["reward"].toDouble();
}
