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

public:
    quint64 write(IDatabaseDataBlock *block);
    void read(IDatabaseDataBlock *block) override;

// IDatabaseFile interface
protected:
    void readHeader() override;
};

#endif // DATABASEINDEXFILE_H
