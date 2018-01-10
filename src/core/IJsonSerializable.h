#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>
#include <QJsonArray>

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
};

#endif // IJSONSERIALIZABLE_H
