#ifndef RPCSERVERMODEL_H
#define RPCSERVERMODEL_H

#include <core/IJsonSerializable.h>
#include <core/types/ConnectionPoint.h>
#include <core/types/Version.h>

///
/// \brief NodeModel модель данных представляющая узел P2P-сети.
///
class RPCServerModel :
        public ConnectionPoint,
        public IJsonSerializable
{
private:
    Version _version;
    int _fails;

public:
    RPCServerModel();
    RPCServerModel(QHostAddress address, quint16 port);
    RPCServerModel(ConnectionPoint point);

    Version getVersion() { return _version; }
    void setVersion(Version value) { _version = value; }
    ///
    /// \brief getFailCount количество ошибок связи
    /// \return
    ///
    int getFailCount() { return _fails; }
    ///
    /// \brief setFailCount количество ошибок связи
    /// \param value
    ///
    void setFailCount(int value) { _fails = value; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // RPCSERVERMODEL_H
