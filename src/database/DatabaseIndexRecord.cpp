#include "DatabaseIndexRecord.h"

DatabaseIndexRecord::DatabaseIndexRecord() :
    IDatabaseDataBlock(),
    _guid(Guid::randomGuid()),
    _creationDate(QDateTime::currentDateTime()),
    _number(0)
{

}

void DatabaseIndexRecord::serialize(QDataStream &out)
{
    out << _guid.toString();
    out << _creationDate;
    out << _number;
}

void DatabaseIndexRecord::deserialize(QDataStream &in)
{
    in >> _guid;
    in >> _creationDate;
    in >> _number;
}

quint64 DatabaseIndexRecord::blockSize()
{
    return 0;
}
