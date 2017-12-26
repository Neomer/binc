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
    QFile::seek(static_cast<HeaderDataBlock *>(header())->bytesUsed());
}

void IDatabaseSequentialAccessFile::write(IDatabaseDataBlock *block)
{
    toEnd();
    block->serialize(_stream);
}
