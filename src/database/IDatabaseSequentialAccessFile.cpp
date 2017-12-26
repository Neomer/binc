#include "IDatabaseSequentialAccessFile.h"

IDatabaseSequentialAccessFile::IDatabaseSequentialAccessFile(HeaderDataBlock *header) :
    IDatabaseFile(header)
{

}

void IDatabaseSequentialAccessFile::toBegin()
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize());
}

void IDatabaseSequentialAccessFile::toEnd()
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + static_cast<HeaderDataBlock *>(header())->bytesUsed());
}

void IDatabaseSequentialAccessFile::write(IDatabaseDataBlock *block)
{
    toEnd();
    block->serialize(_stream);
}

void IDatabaseSequentialAccessFile::read(IDatabaseDataBlock *block)
{
    block->deserialize(_stream);
}

void IDatabaseSequentialAccessFile::seek(quint64 index)
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + index);
}
