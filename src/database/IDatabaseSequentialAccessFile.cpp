#include "IDatabaseSequentialAccessFile.h"
#include <QDebug>

IDatabaseSequentialAccessFile::IDatabaseSequentialAccessFile(HeaderDataBlock *header) :
    IDatabaseFile(header)
{

}

quint64 IDatabaseSequentialAccessFile::write(IDatabaseDataBlock *block)
{
    quint64 ret = static_cast<HeaderDataBlock *>(header())->bytesUsed();
    toEnd();
    block->toDataStream(_stream);
    return ret;
}

void IDatabaseSequentialAccessFile::read(IDatabaseDataBlock *block)
{
    block->fromDataStream(_stream);
}

void IDatabaseSequentialAccessFile::seek(quint64 index)
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + index);
}
