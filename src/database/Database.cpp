#include "Database.h"
#include <QStandardPaths>
#include <QFile>
#include <QDir>

Database::Database()
{
    _databasePath = QDir(QStandardPaths::displayName(QStandardPaths::DataLocation)).absoluteFilePath("db");
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
        if (dir.mkpath(_databasePath))
        {
            return false;
        }
    }
    return true;
}

void Database::close()
{

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
