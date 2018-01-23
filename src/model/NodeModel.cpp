#include "NodeModel.h"

NodeModel::NodeModel()
{

}

NodeModel::NodeModel(QHostAddress address, quint16 port) :
    ConnectionPoint(address, port)
{

}

void NodeModel::toJsonObject(QJsonObject &out)
{
    out["address"] = getAddress().toString();
    out["port"] = getPort();
}

void NodeModel::fromJsonObject(QJsonObject &in)
{
    setAddress(QHostAddress(in["address"].toString()));
    setPort(in["port"].toInt());
}
