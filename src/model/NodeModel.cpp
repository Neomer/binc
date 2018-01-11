#include "NodeModel.h"

NodeModel::NodeModel()
{

}

NodeModel::NodeModel(QHostAddress address, quint16 port) :
    _address(address),
    _port(port)
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
