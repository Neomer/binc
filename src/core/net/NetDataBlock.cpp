#include "NetDataBlock.h"

NetDataBlock::NetDataBlock() :
    IHashedDataBlock()
{

}

NetDataBlock::NetDataBlock(QByteArray data) :
    IHashedDataBlock(data)
{

}
