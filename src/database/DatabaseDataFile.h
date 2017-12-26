#ifndef DATABASEDATAFILE_H
#define DATABASEDATAFILE_H

#include "DatabaseFile.h"
#include "DatabaseGeneral.h"

class DatabaseDataFile : public IDatabaseFile
{
public:
    struct DatabaseDataFileRecord
    {
        dbkey Key;
        int Data;
    };

    DatabaseDataFile();

public:
    quint16 recordSize() override { return sizeof(DatabaseDataFileRecord); }

protected:
    quint16 headerSize() override { return 0; }
    void writeHeader(void *data) override;
    void readHeader(void *data) override;
};

#endif // DATABASEDATAFILE_H
