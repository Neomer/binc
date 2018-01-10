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
    virtual void serialize(QJsonObject &out) = 0;
    ///
    /// \brief deserialize преобразует Json-объект в класс
    /// \param data
    ///
    virtual void deserialize(QJsonObject &in) = 0;
    ///
    /// \brief toString преобразует Json-объект в строку
    /// \param object
    /// \return
    ///
    static QString toString(IJsonSerializable *object);
};

#endif // IJSONSERIALIZABLE_H
