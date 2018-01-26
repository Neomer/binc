#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include "IJsonSerializable.h"
#include "ContextException.h"
#include <model/NodeCollectionModel.h>

///
/// \brief The Settings class класс для работы с файлом настроек.
/// При добавлении новых свойств обязательно добавлять инциализацию значения по-умолчанию в конструктор!
///
class Settings : public IJsonSerializable
{
public:
    Settings();
    ~Settings();

    ///
    /// \brief load загружает настройки из файла конфигурации
    /// \param filename
    ///
    void load(QString filename);
    void close();
    ///
    /// \brief save записывает изменения в файл конифгурации
    ///
    void save();
    ///
    /// \brief RPCport порт прослушивания RPC-сервера
    /// \return
    ///
    quint16 getRPCport() { return _rpc_port; }
    ///
    /// \brief setRPCport порт прослушивания RPC-сервера
    /// \param value
    ///
    void setRPCport(quint16 value) { _rpc_port = value; }
    ///
    /// \brief getDatabasePath директория базы данных
    ///
    QString getDatabasePath() { return _database_path; }
    ///
    /// \brief getDatabasePath директория базы данных
    ///
    void setDatabasePath(QString value) { _database_path = value; }
    ///
    /// \brief nodes возвращает список известных узлов сети
    /// \return
    ///
    NodeCollectionModel &nodes() { return _nodes; }
    ///
    /// \brief getP2PConnectionPoint точка подключения для входящих подключению с помощью p2p-сети
    /// \return
    ///
    ConnectionPoint getP2PConnectionPoint() { return _p2p_cp; }
    ///
    /// \brief setP2PConnectionPoint точка подключения для входящих подключению с помощью p2p-сети
    /// \param value
    ///
    void setP2PConnectionPoint(ConnectionPoint value) { _p2p_cp = value; }
    ///
    /// \brief getConnectionsLimit максимальное количество одновременно установленных соединений
    /// \return
    ///
    int getConnectionsLimit() { return _connection_limit; }
    ///
    /// \brief setConnectionsLimit максимальное количество одновременно установленных соединений
    /// \param value
    ///
    void setConnectionsLimit(int value) { _connection_limit = value; }


private:
    QFile _file;

    // Serializable properties
    quint16 _rpc_port;
    NodeCollectionModel _nodes;
    QString _database_path;
    ConnectionPoint _p2p_cp;
    int _connection_limit;


    // IJsonSerializable interface
private:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // SETTINGS_H
