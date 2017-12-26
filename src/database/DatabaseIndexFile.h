#ifndef DATABASEINDEXFILE_H
#define DATABASEINDEXFILE_H

#include "DatabaseGeneral.h"
#include "IDatabaseRandomAccessFile.h"
#include "DatabaseIndexHeader.h"

class DatabaseIndexFile : public IDatabaseRandomAccessFile
{
public:
    DatabaseIndexFile();
};

#endif // DATABASEINDEXFILE_H
