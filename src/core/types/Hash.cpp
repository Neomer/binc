#include "Hash.h"
#include <QJsonDocument>
#include <QCryptographicHash>

Hash::Hash()
{
    _buffer.resize(HASH_SIZE);
}

Hash::Hash(const Hash &other)
{
    _buffer = other._buffer;
}

Hash Hash::fromString(QString data)
{
    Hash ret;
    ret._buffer = data.toUtf8();
    return ret;
}

Hash Hash::fromJsonObject(QJsonObject &object)
{
    Hash ret;
    QJsonDocument json(object);
    ret._buffer = QCryptographicHash::hash(json.toJson(QJsonDocument::Compact), QCryptographicHash::Keccak_256);
    return ret;
}

QString Hash::toString()
{
    return QString::fromUtf8(_buffer.toHex());
}
