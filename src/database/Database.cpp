#include "Database.h"
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include "DatabaseIndexFile.h"
#include "DatabaseBinaryTreeIndex.h"
#include "DatabaseDataFile.h"

Database::Database()
{
    _databasePath = QDir(QStandardPaths::displayName(QStandardPaths::DataLocation)).absoluteFilePath("db");
    _databaseDir = QDir(_databasePath);
    _lockFile = new QLockFile(_databaseDir.absoluteFilePath(".LOCK"));
    _index = new DatabaseBinaryTreeIndex();

    _data = new IDatabaseData();
    _data->setFileName(".DATA");
}

Database::~Database()
{
    //delete _index;
    delete _lockFile;
}

/* Проверяем наличие директорий, системных файлов.
 * Если чего-то не хватает, создаем. Поверяем наличие блокировки, если свободно,
 * то блокируем.
 */
bool Database::open()
{
    _index->init();
    if (!_databaseDir.exists())
    {
        if (!_databaseDir.mkpath(_databasePath))
        {
            throw DatabaseException("Database path creation failed!");
        }
    }
    if (!_lockFile->tryLock(3000))
    {
        return false;
    }
    return true;
}

void Database::close()
{
    _lockFile->unlock();
}

bool Database::read(dbkey key, DatabaseDataFileRecord *data)
{
    DatabaseIndexRecord index_record;
    if (!_index->find(key, &index_record))
    {
        return false;
    }
    if (!_data->open(QIODevice::ReadWrite))
    {
        throw DatabaseFileException(_data->fileName(), "File access failed!");
    }
    _data->seek(index_record.offset());
    _data->read(data);
    _data->close();
    return true;
}

void Database::write(dbkey key, DatabaseDataFileRecord *data)
{
    if (!_data->open(QIODevice::ReadWrite))
    {
        throw DatabaseFileException(_data->fileName(), "File access failed!");
    }
    quint64 offset = _data->write(data);
    _data->close();

    DatabaseIndexRecord index_record;
    index_record.setGuid(data->guid());
    index_record.setIsDeleted(false);
    index_record.setLength(data->blockSize());
    index_record.setOffset(offset);
    _index->write(key, &index_record);

}
