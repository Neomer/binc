#ifndef DATABASEBINARYTREEINDEX_H
#define DATABASEBINARYTREEINDEX_H

#include <QFile>
#include "DatabaseGeneral.h"
#include "IDatabaseIndex.h"
#include "DatabaseIndexRecord.h"
#include "DatabaseIndexFile.h"


class DatabaseBinaryTreeIndex : public IDatabaseIndex
{
public:
    DatabaseBinaryTreeIndex();
    ~DatabaseBinaryTreeIndex();

    // IDatabaseIndex interfaces
    void init();
    bool find(dbkey key, DatabaseIndexRecord *result);
    void write(dbkey key, DatabaseIndexRecord *result);

private:
    DatabaseIndexFile _file;
};

#endif // DATABASEBINARYTREEINDEX_H
