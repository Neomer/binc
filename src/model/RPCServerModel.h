#ifndef RPCSERVERMODEL_H
#define RPCSERVERMODEL_H

#include <core/IJsonSerializable.h>
#include <core/types/ConnectionPoint.h>
#include <core/types/Version.h>

class RPCServerModel : public IJsonSerializable
{
private:
    ConnectionPoint _point;
    Version _version;

public:
    RPCServerModel();

    quint16 getPort() { return _point.getPort(); }
    void setPort(quint16 value) { _point.setPort(value); }

    QHostAddress getAddress() { return _point.getAddress(); }
    void setAddress(QHostAddress value) { _point.setAddress(value); }

    Version getVersion() { return _version; }
    void setVersion(Version value) { _version = value; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // RPCSERVERMODEL_H
