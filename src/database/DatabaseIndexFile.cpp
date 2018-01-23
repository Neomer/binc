#include "DatabaseIndexFile.h"


DatabaseIndexFile::DatabaseIndexFile() :
    IDatabaseRandomAccessFile(new DatabaseIndexHeader(), DatabaseIndexRecord::blockSize())
{

}

quint64 DatabaseIndexFile::write(IDatabaseDataBlock *block)
{
}

void DatabaseIndexFile::read(IDatabaseDataBlock *block)
{
}

void DatabaseIndexFile::readHeader()
{
}
