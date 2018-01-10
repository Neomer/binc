#ifndef NODEMODEL_H
#define NODEMODEL_H

#include <core/IJsonSerializable.h>
#include <QHostAddress>

class NodeModel : public IJsonSerializable
{
public:
    NodeModel();
    NodeModel(QHostAddress address, quint16 port);

    QHostAddress getAddress() { _address; }
    void setAddress(QHostAddress value) { _address = value; }

    quint16 getPort() { return _port; }
    void setPort(quint16 value) { _port = value; }

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

private:
    QHostAddress _address;
    quint16 _port;
};

#endif // NODEMODEL_H
