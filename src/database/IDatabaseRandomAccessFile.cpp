#include "IDatabaseRandomAccessFile.h"

IDatabaseRandomAccessFile::IDatabaseRandomAccessFile(HeaderDataBlock *header) :
    IDatabaseFile(header)
{

}

void IDatabaseRandomAccessFile::toBegin()
{
    QFile::seek(header()->blockSize());
}

void IDatabaseRandomAccessFile::seek(quint64 index)
{

}

void IDatabaseRandomAccessFile::write(IDatabaseDataBlock *block)
{

}
