#include "IDatabaseRandomAccessFile.h"

IDatabaseRandomAccessFile::IDatabaseRandomAccessFile(HeaderDataBlock *header, quint64 blockSize) :
    IDatabaseFile(header)
{
    _block_size = blockSize;
}

void IDatabaseRandomAccessFile::toBegin()
{
    seek(0);
}

void IDatabaseRandomAccessFile::toEnd()
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->bytesUsed());
}

void IDatabaseRandomAccessFile::seek(quint64 index)
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + index * _block_size);
}

void IDatabaseRandomAccessFile::write(IDatabaseDataBlock *block)
{
    block->serialize(_stream);
    static_cast<HeaderDataBlock *>(header())->addBytesUsed(_block_size);
    QFile::seek(0);
    header()->serialize(_stream);
}

void IDatabaseRandomAccessFile::read(IDatabaseDataBlock *block)
{
    block->deserialize(_stream);
}
