#include "IDatabaseRandomAccessFile.h"

// Размер буффера при освобождении пространства для новой записи
#define PAGE_SIZE       102400

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

quint64 IDatabaseRandomAccessFile::write(IDatabaseDataBlock *block)
{
    block->serialize(_stream);
    static_cast<HeaderDataBlock *>(header())->addBytesUsed(_block_size);
    static_cast<HeaderDataBlock *>(header())->addRecords(1);
    QFile::seek(0);
    header()->serialize(_stream);
    return 0;
}

void IDatabaseRandomAccessFile::read(IDatabaseDataBlock *block)
{
    block->deserialize(_stream);
}

quint64 IDatabaseRandomAccessFile::write(quint64 index, IDatabaseDataBlock *block)
{
    quint64 carrier = static_cast<HeaderDataBlock *>(header())->blockSize() + static_cast<HeaderDataBlock *>(header())->bytesUsed(),
            offset = static_cast<HeaderDataBlock *>(header())->blockSize() + index * _block_size;

    char *b = 0;
    if (carrier > offset)
    {
        b = new char[PAGE_SIZE];
        memset(b, 0, PAGE_SIZE);
    }

    while (carrier > offset)
    {
        quint64 l = qMin(carrier - offset, (quint64)PAGE_SIZE);
        carrier -= l;
        QFile::seek(carrier);
        if ((quint64)QFile::read(b, l) != l)
        {
            throw DatabaseFileException(fileName(), "File reading error!");
        }
        QFile::seek(carrier + _block_size);
        if ((quint64)QFile::write(b, l) != l)
        {
            throw DatabaseFileException(fileName(), "File writing error!");
        }
    }

    if (b) delete [] b;
    seek(index);

    return IDatabaseRandomAccessFile::write(block);
}
