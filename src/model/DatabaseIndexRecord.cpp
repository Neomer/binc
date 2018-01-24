#include "DatabaseIndexRecord.h"

DatabaseIndexRecord::DatabaseIndexRecord() :
    _offset(0), _length(0)
{

}

DatabaseIndexRecord::DatabaseIndexRecord(quint64 offset, quint32 length) :
    _offset(offset), _length(length)
{

}

void DatabaseIndexRecord::toDataStream(QDataStream &out)
{
    out << getId();
    out << getOffset();
    out << getLength();
}

void DatabaseIndexRecord::fromDataStream(QDataStream &in)
{
    Guid id;

    in >> id;
    in >> _offset;
    in >> _length;

    setId(id);
}

