#include "IJsonSerializable.h"
#include <QJsonParseError>

QString IJsonSerializable::toString(IJsonSerializable *object)
{
    QJsonObject obj;
    object->serialize(obj);
    QJsonDocument json(obj);
    return QString::fromUtf8(json.toJson(QJsonDocument::Compact));
}

void IJsonSerializable::fromString(IJsonSerializable *object, QString data)
{
    fromString(object, data.toUtf8());
}

void IJsonSerializable::fromString(IJsonSerializable *object, QByteArray data)
{
    QJsonParseError err;
    QJsonDocument json = QJsonDocument::fromJson(data, &err);
    QJsonObject o = json.object();
    object->deserialize(o);
}
