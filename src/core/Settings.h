#ifndef SETTINGS_H
#define SETTINGS_H

#include "IBinarySerializable.h"
#include "ContextException.h"

///
/// \brief The Settings class класс для работы с файлом настроек.
/// При добавлении новых свойств обязательно добавлять инциализацию значения по-умолчанию в конструктор!
///
class Settings : public IBinarySerializable
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

    quint16 RPCport() { return _rpc_port; }
    void setRPCport(quint16 value) { _rpc_port = value; }

// IBinarySerializable interface
private:
    void serialize(QDataStream &out) override;
    void deserialize(QDataStream &in) override;

    QDataStream _stream;

// Serializable properties
private:
    quint16 _rpc_port;
};

#endif // SETTINGS_H
