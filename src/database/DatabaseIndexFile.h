#ifndef DATABASEINDEXFILE_H
#define DATABASEINDEXFILE_H

#include "DatabaseGeneral.h"
#include "IDatabaseRandomAccessFile.h"
#include "DatabaseIndexHeader.h"
#include "DatabaseIndexRecord.h"

class DatabaseIndexFile : public IDatabaseRandomAccessFile
{
public:
    DatabaseIndexFile();

    // IDatabaseFile interface
public:
    quint64 write(IDatabaseDataBlock *block) override;
};

#endif // DATABASEINDEXFILE_H
