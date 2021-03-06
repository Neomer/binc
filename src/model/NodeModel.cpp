#include "NodeModel.h"

NodeModel::NodeModel() :
    _last_activity(),
    _fails(0)
{

}

NodeModel::NodeModel(QHostAddress address, quint16 port) :
    ConnectionPoint(address, port),
    _last_activity(),
    _fails(0)
{

}

void NodeModel::toJsonObject(QJsonObject &out)
{
    out["address"] = getAddress().toString();
    out["port"] = getPort();
    out["last_activity"] = _last_activity.toString("yyyy-MM-ddThh:mm:ss");
}

void NodeModel::fromJsonObject(QJsonObject &in)
{
    setAddress(QHostAddress(in["address"].toString()));
    setPort(in["port"].toInt());
    _last_activity = QDateTime::fromString(in["last_activity"].toString(), "yyyy-MM-ddThh:mm:ss");
}
