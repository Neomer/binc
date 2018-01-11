#include "DatabaseDataFile.h"
#include "DatabaseDataFileHeader.h"
#include <QDebug>

DatabaseDataFile::DatabaseDataFile() :
    IDatabaseSequentialAccessFile(new DatabaseDataFileHeader())
{

}

quint64 DatabaseDataFile::write(IDatabaseDataBlock *block)
{
    quint64 ret = IDatabaseSequentialAccessFile::write(block);
    static_cast<DatabaseDataFileHeader *>(header())->addBytesUsed(static_cast<DatabaseDataFileRecord *>(block)->blockSize());
    static_cast<DatabaseDataFileHeader *>(header())->addRecords(1);
    QFile::seek(0);
    static_cast<DatabaseDataFileHeader *>(header())->serialize(_stream);
    return ret;
}

void DatabaseDataFile::toBegin()
{
    QFile::seek(static_cast<DatabaseDataFileHeader *>(header())->blockSize());
}

void DatabaseDataFile::toEnd()
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + static_cast<HeaderDataBlock *>(header())->bytesUsed());
}

void DatabaseDataFile::readHeader()
{
    static_cast<DatabaseDataFileHeader *>(header())->deserialize(_stream);
}
