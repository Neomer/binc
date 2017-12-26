#include "DatabaseIndexFile.h"


DatabaseIndexFile::DatabaseIndexFile() :
    IDatabaseRandomAccessFile(new DatabaseIndexHeader(), DatabaseIndexRecord::blockSize())
{

}
