#include "HeaderDataBlock.h"

HeaderDataBlock::HeaderDataBlock()
{

}

void HeaderDataBlock::serialize(QDataStream &out)
{
    out << _bytesUsed;
}

void HeaderDataBlock::deserialize(QDataStream &in)
{
    in >> _bytesUsed;
}

quint64 HeaderDataBlock::blockSize()
{
    return sizeof(_bytesUsed);
}
