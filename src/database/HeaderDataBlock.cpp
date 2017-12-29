#include "HeaderDataBlock.h"

HeaderDataBlock::HeaderDataBlock() :
    _bytesUsed(0),
    _records(0)
{

}

void HeaderDataBlock::serialize(QDataStream &out)
{
    out << (quint64)_bytesUsed;
    out << (quint64) _records;
}

void HeaderDataBlock::deserialize(QDataStream &in)
{
    in >> _bytesUsed;
    in >> _records;
}

quint64 HeaderDataBlock::blockSize()
{
    return sizeof(_bytesUsed) + sizeof(_records);
}
