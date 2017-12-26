#include "DatabaseDataFile.h"
#include "DatabaseDataFileHeader.h"

DatabaseDataFile::DatabaseDataFile() :
    IDatabaseFile(new DatabaseDataFileHeader())
{

}
