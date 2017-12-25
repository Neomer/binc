#ifndef DATABASEDATAFILE_H
#define DATABASEDATAFILE_H

#include "DatabaseFile.h"

class DatabaseDataFile : public DatabaseFile
{
public:
    DatabaseDataFile();

    // DatabaseFile interface
protected:
    quint16 headerSize() override { return sizeof(DatabaseDataFileHeader); }

private:
    struct DatabaseDataFileHeader
    {
        qint64 _bytesUsed;
        qint64 _records;
    };
    DatabaseDataFileHeader _header;
};

#endif // DATABASEDATAFILE_H
