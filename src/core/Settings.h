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
    ///
    /// \brief save записывает изменения в файл конифгурации
    ///
    void save();
    ///
    /// \brief RPCport возвращает порт прослушивания RPC-сервера
    /// \return
    ///
    quint16 RPCport() { return _rpc_port; }
    ///
    /// \brief setRPCport
    /// \param value
    ///
    void setRPCport(quint16 value) { _rpc_port = value; }

    ///
    /// \brief nodes возвращает список известных узлов сети
    /// \return
    ///
    NodeCollectionModel &nodes() { return _nodes; }
    void close();

private:
    QFile _file;

    // Serializable properties
    quint16 _rpc_port;
    NodeCollectionModel _nodes;


    // IJsonSerializable interface
private:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // SETTINGS_H
