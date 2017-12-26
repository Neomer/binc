#include "DatabaseIndexFile.h"


DatabaseIndexFile::DatabaseIndexFile() :
    IDatabaseRandomAccessFile(new DatabaseIndexHeader(), DatabaseIndexHeader::blockSize())
{

}
