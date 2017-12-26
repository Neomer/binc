#include "HeaderDataBlock.h"

HeaderDataBlock::HeaderDataBlock() :
    _bytesUsed(0)
{

}

void HeaderDataBlock::serialize(QDataStream &out)
{
    out << (quint64)_bytesUsed;
}

void HeaderDataBlock::deserialize(QDataStream &in)
{
    in >> _bytesUsed;
}

quint64 HeaderDataBlock::blockSize()
{
    return sizeof(_bytesUsed);
}
