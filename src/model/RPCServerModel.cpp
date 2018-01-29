#include "RPCServerModel.h"

RPCServerModel::RPCServerModel()
{

}

void RPCServerModel::toJsonObject(QJsonObject &out)
{
    out["address"] = _point.getAddress().toString();
    out["port"] = _point.getPort();
}

void RPCServerModel::fromJsonObject(QJsonObject &in)
{
    _point.setPort(in["port"].toInt());
    _point.setAddress(QHostAddress(in["address"].toString()));
}
