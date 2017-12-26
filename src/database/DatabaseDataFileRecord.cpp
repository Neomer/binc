#include "DatabaseDataFileRecord.h"

DatabaseDataFileRecord::DatabaseDataFileRecord()
{
    _creationDate = QDateTime::currentDateTime();
}

void DatabaseDataFileRecord::serialize(QDataStream &out)
{
    out << (quint64) _number;
    out << _creationDate;
    out << _body;
}

void DatabaseDataFileRecord::deserialize(QDataStream &in)
{
    in >> _number;
    in >> _creationDate;
    in >> _body;
}

quint64 DatabaseDataFileRecord::blockSize()
{
    return 0;
}
