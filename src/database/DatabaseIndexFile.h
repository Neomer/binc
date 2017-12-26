#ifndef DATABASEINDEXFILE_H
#define DATABASEINDEXFILE_H

#include "DatabaseFile.h"
#include "DatabaseGeneral.h"

class DatabaseIndexFile : public IDatabaseFile
{
public:
    struct DatabaseIndexFileRecord
    {
        dbkey Key;
        char Filename[FILENAME_LENGTH];
        qint64 Offset;
        quint32 Size;
    };

    DatabaseIndexFile();
    quint16 recordSize() override { return sizeof(DatabaseIndexFileRecord); }
    quint64 recordCount() { return (bytesUsed() - headerSize()) / recordSize(); }


private:

    // DatabaseFile interface
protected:
    quint16 headerSize() override { return 0; }
    void writeHeader(void *data) override;
    void readHeader(void *data) override;
};

#endif // DATABASEINDEXFILE_H
