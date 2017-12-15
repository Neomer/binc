#ifndef DATABASEBINARYTREEINDEX_H
#define DATABASEBINARYTREEINDEX_H

#include <QFile>
#include "DatabaseGeneral.h"
#include "IDatabaseIndex.h"
#include "DatabaseBinaryTreeIndexRoot.h"


class DatabaseBinaryTreeIndex : public IDatabaseIndex
{
public:
    DatabaseBinaryTreeIndex();
    ~DatabaseBinaryTreeIndex();

    // IDatabaseIndex interfaces
    void init();
    void find(dbkey key, IDatabaseIndexResult *result);
    void write(void *data, IDatabaseIndexResult *result);

private:
};

#endif // DATABASEBINARYTREEINDEX_H
