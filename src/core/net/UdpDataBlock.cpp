#include "UdpDataBlock.h"

UdpDataBlock::UdpDataBlock() :
    IHashedDataBlock()
{

}

UdpDataBlock::UdpDataBlock(QByteArray data) :
    IHashedDataBlock(data)
{

}
