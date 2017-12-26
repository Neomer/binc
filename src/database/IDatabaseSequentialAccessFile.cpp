#include "IDatabaseSequentialAccessFile.h"
#include <QDebug>

IDatabaseSequentialAccessFile::IDatabaseSequentialAccessFile(HeaderDataBlock *header) :
    IDatabaseFile(header)
{

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
