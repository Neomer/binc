#include "DatabaseIndexRecord.h"

DatabaseIndexRecord::DatabaseIndexRecord() :
    IDatabaseDataBlock(),
    _guid(Guid::randomGuid()),
    _is_deleted(false),
    _length(0),
    _offset(0)
{

}

void DatabaseIndexRecord::toDataStream(QDataStream &out)
{
    out << _guid;
    out << _is_deleted;
    out << _length;
    out << _offset;
}

void DatabaseIndexRecord::fromDataStream(QDataStream &in)
{
    in >> _guid;
    in >> _is_deleted;
    in >> _length;
    in >> _offset;
}

quint64 DatabaseIndexRecord::blockSize()
{
    return 33;
}
