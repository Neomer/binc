#include "DatabaseDataFile.h"
#include "DatabaseDataFileHeader.h"
#include <QDebug>

DatabaseDataFile::DatabaseDataFile() :
    IDatabaseSequentialAccessFile(new DatabaseDataFileHeader())
{

}

quint64 DatabaseDataFile::write(IDatabaseDataBlock *block)
{
}

void DatabaseDataFile::toBegin()
{
}

void DatabaseDataFile::toEnd()
{
}

void DatabaseDataFile::readHeader()
{
}
