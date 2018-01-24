#include "DatabaseDataHeader.h"

DatabaseDataHeader::DatabaseDataHeader() :
    _bytesUsed(0)
{

}

void DatabaseDataHeader::toDataStream(QDataStream &out)
{
    out << _bytesUsed;
}

void DatabaseDataHeader::fromDataStream(QDataStream &in)
{
    in >> _bytesUsed;
}
