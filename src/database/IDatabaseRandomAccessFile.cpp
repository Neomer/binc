#include "IDatabaseRandomAccessFile.h"

// Размер буффера при освобождении пространства для новой записи
#define PAGE_SIZE       102400

IDatabaseRandomAccessFile::IDatabaseRandomAccessFile(HeaderDataBlock *header, quint64 blockSize)
{
    _block_size = blockSize;
}

void IDatabaseRandomAccessFile::toBegin()
{
    seek(0);
}

void IDatabaseRandomAccessFile::toEnd()
{
}

void IDatabaseRandomAccessFile::seek(quint64 index)
{
}

quint64 IDatabaseRandomAccessFile::write(IDatabaseDataBlock *block)
{
}

void IDatabaseRandomAccessFile::read(IDatabaseDataBlock *block)
{
}

quint64 IDatabaseRandomAccessFile::write(quint64 index, IDatabaseDataBlock *block)
{
}
