#include "DatabaseDataFileHeader.h"

DatabaseDataFileHeader::DatabaseDataFileHeader()
{

}

quint64 DatabaseDataFileHeader::blockSize()
{
    return sizeof(_bytesUsed);
}

void DatabaseDataFileHeader::serialize(QDataStream &out)
{
    out << (quint64)_bytesUsed;
}

void DatabaseDataFileHeader::deserialize(QDataStream &in)
{
    in >> _bytesUsed;
}
