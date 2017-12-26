#include "DatabaseDataFile.h"
#include "DatabaseDataFileHeader.h"
#include <QDebug>

DatabaseDataFile::DatabaseDataFile() :
    IDatabaseSequentialAccessFile(new DatabaseDataFileHeader())
{

}

void DatabaseDataFile::write(IDatabaseDataBlock *block)
{
    IDatabaseSequentialAccessFile::write(block);
    static_cast<DatabaseDataFileHeader *>(header())->addBytesUsed(static_cast<DatabaseDataFileRecord *>(block)->blockSize());
    static_cast<DatabaseDataFileHeader *>(header())->addRecords(1);
    QFile::seek(0);
    static_cast<DatabaseDataFileHeader *>(header())->serialize(_stream);
}

void DatabaseDataFile::toBegin()
{
    QFile::seek(static_cast<DatabaseDataFileHeader *>(header())->blockSize());
}

void DatabaseDataFile::toEnd()
{
    QFile::seek(static_cast<HeaderDataBlock *>(header())->blockSize() + static_cast<HeaderDataBlock *>(header())->bytesUsed());
}
