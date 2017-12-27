#ifndef DATABASEDATAFILE_H
#define DATABASEDATAFILE_H

#include "IDatabaseSequentialAccessFile.h"
#include "DatabaseGeneral.h"
#include "DatabaseDataFileHeader.h"
#include "DatabaseDataFileRecord.h"

class DatabaseDataFile : public IDatabaseSequentialAccessFile
{
public:
    DatabaseDataFile();

    // IDatabaseFile interface
public:
    quint64 write(IDatabaseDataBlock *block) override;
    void toBegin() override;
    void toEnd() override;
};

#endif // DATABASEDATAFILE_H
