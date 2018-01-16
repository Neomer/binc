#include "NodeModel.h"

NodeModel::NodeModel()
{

}

NodeModel::NodeModel(QHostAddress address, quint16 port) :
    ConnectionPoint(address, port)
{

}

void NodeModel::serialize(QJsonObject &out)
{
    out["address"] = getAddress().toString();
    out["port"] = getPort();
}

void NodeModel::deserialize(QJsonObject &in)
{
    setAddress(QHostAddress(in["address"].toString()));
    setPort(in["port"].toInt());
}
