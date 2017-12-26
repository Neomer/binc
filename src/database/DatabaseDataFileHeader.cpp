#include "DatabaseDataFileHeader.h"

DatabaseDataFileHeader::DatabaseDataFileHeader()
{

}

quint64 DatabaseDataFileHeader::blockSize()
{
    return HeaderDataBlock::blockSize() + sizeof(_records);
}

void DatabaseDataFileHeader::serialize(QDataStream &out)
{
    HeaderDataBlock::serialize(out);
    out << (quint64) _records;
}

void DatabaseDataFileHeader::deserialize(QDataStream &in)
{
    HeaderDataBlock::deserialize(in);
    in >> _records;
}
