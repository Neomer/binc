#include "IDatabaseSequentialAccessFile.h"

IDatabaseSequentialAccessFile::IDatabaseSequentialAccessFile(HeaderDataBlock *header) :
    IDatabaseFile(header)
{

}

void IDatabaseSequentialAccessFile::toBegin()
{
    QFile::seek(header()->blockSize());
}

void IDatabaseSequentialAccessFile::write(IDatabaseDataBlock *block)
{
    toEnd();
    block->serialize(_stream);
}
