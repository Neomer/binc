#include "DatabaseDataFileRecord.h"

DatabaseDataFileRecord::DatabaseDataFileRecord() :
    IDatabaseDataBlock(),
    _creationDate(QDateTime::currentDateTime()),
    _guid(Guid::randomGuid()),
    _number(0)
{

}

void DatabaseDataFileRecord::toDataStream(QDataStream &out)
{
    out << _guid;
    out << (quint64) _number;
    out << _creationDate;
    out << _data;
}

void DatabaseDataFileRecord::fromDataStream(QDataStream &in)
{
    in >> _guid;
    in >> _number;
    in >> _creationDate;
    in >> _data;
}

quint64 DatabaseDataFileRecord::blockSize()
{
    return 41 + _data.length();
}
