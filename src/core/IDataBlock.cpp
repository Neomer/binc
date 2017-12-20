#include "IDataBlock.h"

IDataBlock::IDataBlock()
{

}

IDataBlock::IDataBlock(QByteArray data) :
    _buffer(data)
{

}
