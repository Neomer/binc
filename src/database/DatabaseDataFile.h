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
    void write(IDatabaseDataBlock *block) override;


};

#endif // DATABASEDATAFILE_H
