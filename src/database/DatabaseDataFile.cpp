#include "DatabaseDataFile.h"

DatabaseDataFile::DatabaseDataFile() :
    DatabaseFile()
{

}

void DatabaseDataFile::writeHeader(void *data)
{
    Q_UNUSED(data);
}

void DatabaseDataFile::readHeader(void *data)
{
    Q_UNUSED(data);
}
