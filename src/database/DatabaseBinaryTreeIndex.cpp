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

    DatabaseIndexFile::DatabaseIndexFileRecord *record = static_cast<DatabaseIndexFile::DatabaseIndexFileRecord *>(data);

    DatabaseIndexFile file;
    //TODO: поиск файла для разделения индекса на неколько файлов
    file.setFileName(Context::Instance().database()->databaseDir().absoluteFilePath(".INDEX"));
    if (!file.open(QIODevice::ReadWrite))
    {
        throw DatabaseException("Index file not found!");
    }
    //Ищем по индексному файлу куда записать новую запись для поддержания упорядоченности
    file.toBegin();
    DatabaseIndexFile::DatabaseIndexFileRecord rec;
    int a = 0, b = 0, c = file.recordCount();
    if (c > 0)
    {
        // Проверяем первый элемент
        file.moveTo(0);
        file.get(&rec);
        if (rec.Key > record->Key)
        {
            c = 0;
        }
        else
        {
            while (c - a > 1)
            {
                b = a + (c - a) * 0.5;
                file.moveTo(b);
                file.get(&rec);
                if (rec.Key == record->Key) throw DatabaseFileException(file.fileName(), "Key duplicate");
                (rec.Key > record->Key)? c = b: a = b;
            }
        }
    }
    file.moveTo(c);
    file.insert(file.bytesOffsetByIndex(c), data);
    file.close();
}

