#include "IJsonSerializable.h"
#include <QJsonParseError>
#include <QFile>

QString IJsonSerializable::toString(IJsonSerializable *object)
{
    QJsonObject obj;
    object->toJsonObject(obj);
    QJsonDocument json(obj);
    return QString::fromUtf8(json.toJson(QJsonDocument::Compact));
}

QByteArray IJsonSerializable::toByteArray(IJsonSerializable *object)
{
    QJsonObject obj;
    object->toJsonObject(obj);
    QJsonDocument json(obj);
    return json.toJson(QJsonDocument::Compact);
}

void IJsonSerializable::fromString(IJsonSerializable *object, QString data)
{
    fromString(object, data.toUtf8());
}

void IJsonSerializable::fromString(IJsonSerializable *object, QByteArray data)
{
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError)
    {
        throw BaseException("Json parsing error!");
    }
    QJsonObject o = json.object();
    object->fromJsonObject(o);
}

void IJsonSerializable::toFile(IJsonSerializable *object, QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        throw BaseException("File access failed!");
    }
    file.seek(0);
    file.resize(0);
    file.write(IJsonSerializable::toByteArray(object));
    file.flush();
    file.close();
}

void IJsonSerializable::fromFile(IJsonSerializable *object, QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        throw BaseException("File access failed!");
    }
    file.seek(0);
    IJsonSerializable::fromString(object, file.readAll());
    file.close();
}
