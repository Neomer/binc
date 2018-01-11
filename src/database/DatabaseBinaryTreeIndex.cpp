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
    bool ret = false;
    if (!_file.open(QIODevice::ReadOnly))
    {
        throw DatabaseFileException(_file.fileName(), "Index file access failed!");
    }

    DatabaseIndexRecord r;
    quint64 a = 0, c = static_cast<DatabaseIndexHeader *>(_file.header())->records(), b;
    while (c - a > 1)
    {
        b = a + (c - a) * 0.5;
        _file.seek(b);
        _file.read(&r);
        if (r.guid() == key)
        {
            *result = r;
            ret = true;
            break;
        }
        else
        {
            (r.guid() > key) ? c = b : a = b;
        }
    }
    _file.seek(a);
    _file.read(&r);
    if (r.guid() == key)
    {
        *result = r;
        ret = true;
    }
    _file.seek(c);
    _file.read(&r);
    if (r.guid() == key)
    {
        *result = r;
        ret = true;
    }
    _file.close();
    return ret;
}


