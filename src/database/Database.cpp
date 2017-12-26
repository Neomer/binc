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

void Database::read(dbkey key, DatabaseDataFileRecord *data)
{
    Q_UNUSED(key); Q_UNUSED(data);
}

void Database::write(dbkey key, DatabaseDataFileRecord *data)
{
    Q_UNUSED(key); Q_UNUSED(data);
    DatabaseIndexRecord index_result;
    if (!_index->find(key, &index_result))
    {
        data = 0;
        return;
    }
}
