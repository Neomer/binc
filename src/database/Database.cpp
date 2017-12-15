#include "Database.h"
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include "DatabaseException.h"

Database::Database()
{
    _databasePath = QDir(QStandardPaths::displayName(QStandardPaths::DataLocation)).absoluteFilePath("db");
    _lockFile = new QLockFile(QDir(_databasePath).absoluteFilePath(".LOCK"));
}

Database::~Database()
{
    delete _lockFile;
}

/* Проверяем наличие директорий, системных файлов.
 * Если чего-то не хватает, создаем. Поверяем наличие блокировки, если свободно,
 * то блокируем.
 */
bool Database::open()
{
    QDir dir(_databasePath);
    if (!dir.exists())
    {
        if (!dir.mkpath(_databasePath))
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
}

void Database::write(dbkey key, IDatabaseObject object)
{
    Q_UNUSED(key);
    Q_UNUSED(object);
}
