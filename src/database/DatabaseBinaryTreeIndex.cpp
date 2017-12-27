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
    _file.setFileName(".INDEX");
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

    if (!_file.open(QIODevice::ReadWrite))
    {
        throw DatabaseFileException(_file.fileName(), "Index file access failed!");
    }
    _file.write(result);
    _file.flush();
    _file.close();
}

bool DatabaseBinaryTreeIndex::find(dbkey key, DatabaseIndexRecord *result)
{
    Q_UNUSED(key); Q_UNUSED(result);

    if (!_file.open(QIODevice::ReadOnly))
    {
        throw DatabaseFileException(_file.fileName(), "Index file access failed!");
    }
    _file.read(result);
    _file.close();
    return true;
}


