#ifndef HASH_H
#define HASH_H

#include <QString>
#include <QJsonObject>
#include <core/BaseException.h>

#define HASH_SIZE       32

///
/// \brief The Hash класс для хранения и работы с HASH-суммами
///
class Hash
{
public:
    Hash();
    Hash(const Hash &other);

    static Hash fromString(QString data);
    static Hash fromJsonObject(QJsonObject &object);

    QString toString();

private:
    QByteArray _buffer;
};

#endif // HASH_H
