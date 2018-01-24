#ifndef IJSONSERIALIZABLE_H
#define IJSONSERIALIZABLE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <core/BaseException.h>

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
    ///
    /// \brief fromString преобразует Json-строку в экзмепляр класса
    /// \param object
    /// \param data
    ///
    static void fromString(IJsonSerializable *object, QByteArray data);
    ///
    /// \brief toFile Сериализует объект object и сохраняет его в файл filename. Внимание! Все содержимое файла будет перезаписано!
    /// \param object Объект для сериализации
    /// \param filename Наименование файла
    ///
    static void toFile(IJsonSerializable *object, QString filename);
    ///
    /// \brief fromFile Читает все содержимое файла и пытается десереализовать создержимое как Json-строку.
    /// \param object Объект
    /// \param filename Наименование файла
    ///
    static void fromFile(IJsonSerializable *object, QString filename);
};

#endif // IJSONSERIALIZABLE_H
