#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class IJsonSerializable
{
public:
    ///
    /// \brief serialize преобразует объект в Json-объект
    /// \return
    ///
    virtual void toJsonObject(QJsonObject &out) = 0;
    ///
    /// \brief deserialize преобразует Json-объект в класс
    /// \param data
    ///
    virtual void fromJsonObject(QJsonObject &in) = 0;
    ///
    /// \brief toString преобразует Json-объект в строку
    /// \param object
    /// \return
    ///
    static QString toString(IJsonSerializable *object);
    ///
    /// \brief toByteArray преобразует Json-объект в массив байт
    /// \param object
    /// \return
    ///
    static QByteArray toByteArray(IJsonSerializable *object);
    ///
    /// \brief fromString преобразует Json-строку в экзмепляр класса
    /// \param object
    /// \param data
    ///
    static void fromString(IJsonSerializable *object, QString data);
    static void fromString(IJsonSerializable *object, QByteArray data);
};

#endif // IJSONSERIALIZABLE_H
