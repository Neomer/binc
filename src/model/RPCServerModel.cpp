#include "RPCServerModel.h"

RPCServerModel::RPCServerModel() :
    ConnectionPoint(),
    _version(1, 0),
    _fails(0)
{

}

RPCServerModel::RPCServerModel(QHostAddress address, quint16 port) :
    ConnectionPoint(address, port),
    _version(1, 0),
    _fails(0)
{

}

RPCServerModel::RPCServerModel(ConnectionPoint point) :
    ConnectionPoint(point)
{

}

void RPCServerModel::toJsonObject(QJsonObject &out)
{
    out["address"] = getAddress().toString();
    out["port"] = getPort();
}

void RPCServerModel::fromJsonObject(QJsonObject &in)
{
    setPort(in["port"].toInt());
    setAddress(QHostAddress(in["address"].toString()));
}
