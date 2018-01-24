#include "DatabaseBinaryTreeIndex.h"
#include <QDebug>
#include <QFileInfo>
#include <core/Context.h>
#include "DatabaseFileException.h"
#include "DatabaseDataFile.h"
#include "DatabaseIndexFile.h"
#include "DatabaseException.h"

DatabaseBinaryTreeIndex::DatabaseBinaryTreeIndex() :
    IDatabaseIndex()
{
}

DatabaseBinaryTreeIndex::~DatabaseBinaryTreeIndex()
{
}

void DatabaseBinaryTreeIndex::init()
{
}

void DatabaseBinaryTreeIndex::write(dbkey key, DatabaseIndexRecord *result)
{
    Q_UNUSED(key); Q_UNUSED(result);

}

bool DatabaseBinaryTreeIndex::find(dbkey key, DatabaseIndexRecord *result)
{
}


