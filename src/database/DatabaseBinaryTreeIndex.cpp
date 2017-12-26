#include "DatabaseBinaryTreeIndex.h"
#include <QDebug>
#include <QFileInfo>
#include <core/Context.h>
#include "DatabaseDataFile.h"
#include "DatabaseIndexFile.h"
#include "DatabaseException.h"

DatabaseBinaryTreeIndex::DatabaseBinaryTreeIndex()
{

}

DatabaseBinaryTreeIndex::~DatabaseBinaryTreeIndex()
{
}

void DatabaseBinaryTreeIndex::init()
{
}

void DatabaseBinaryTreeIndex::find(dbkey key, IDatabaseIndexResult *result)
{
    Q_UNUSED(key); Q_UNUSED(result);
}

void DatabaseBinaryTreeIndex::write(void *data, IDatabaseIndexResult *result)
{
    Q_UNUSED(result);

}

