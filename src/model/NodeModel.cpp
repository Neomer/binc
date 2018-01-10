#include "NodeModel.h"

NodeModel::NodeModel()
{

}

void NodeModel::serialize(QJsonObject &out)
{
    out["address"] = _address.toString();
    out["port"] = _port;
}

void NodeModel::deserialize(QJsonObject &in)
{
    _address.setAddress(in["address"].toString());
    _port = in["port"].toInt();
}
