#include "DatabaseDataFile.h"
#include "DatabaseDataFileHeader.h"

DatabaseDataFile::DatabaseDataFile() :
    IDatabaseSequentialAccessFile(new DatabaseDataFileHeader())
{

}

void DatabaseDataFile::write(IDatabaseDataBlock *block)
{
    IDatabaseSequentialAccessFile::write(block);
    static_cast<DatabaseDataFileHeader *>(header())->addBytesUsed(static_cast<DatabaseDataFileRecord *>(block)->blockSize());
    QFile::seek(0);
    header()->serialize(_stream);
}
