#include "IJsonSerializable.h"

QString IJsonSerializable::toString(IJsonSerializable *object)
{
    QJsonObject obj;
    object->serialize(obj);
    QJsonDocument json(obj);
    return QString::fromUtf8(json.toJson(QJsonDocument::Compact));
}
