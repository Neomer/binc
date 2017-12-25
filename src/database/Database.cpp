#include "Database.h"
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include "DatabaseIndexFile.h"
#include "DatabaseBinaryTreeIndex.h"

Database::Database()
{
    _databasePath = QDir(QStandardPaths::displayName(QStandardPaths::DataLocation)).absoluteFilePath("db");
    _databaseDir = QDir(_databasePath);
    _lockFile = new QLockFile(_databaseDir.absoluteFilePath(".LOCK"));
    _index = new DatabaseBinaryTreeIndex();
}

Database::~Database()
{
    delete _index;
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

IDatabaseObject Database::read(dbkey key)
{
    Q_UNUSED(key);
    return IDatabaseObject();
}

void Database::write(dbkey key, IDatabaseObject object)
{
    Q_UNUSED(object);

    DatabaseIndexFile::DatabaseIndexFileRecord record;
    memset(&record, 0, sizeof(DatabaseIndexFile::DatabaseIndexFileRecord));
    strcpy(record.Filename, ".DATA");
    record.Key = key;
    record.Offset = 0;
    record.Size = 0;
    _index->write(&record, 0);
}
