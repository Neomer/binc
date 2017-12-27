#ifndef DATABASEINDEXPROVIDER_H
#define DATABASEINDEXPROVIDER_H

#include "DatabaseDataFileRecord.h"


///
/// \brief The DatabaseIndexProvider class Работа с коллекцией файлов данных (найти нужный файл, поддержание в актуальном состоянии)
///
class DatabaseIndexProvider
{
public:
    DatabaseIndexProvider();

    ///
    /// \brief insertToIndex добавляет в индекс новую запись, основанную на записи, добавленную в файл данных
    /// \param data
    ///
    void insertToIndex(quint64 offset, DatabaseDataFileRecord *data);
};

#endif // DATABASEINDEXPROVIDER_H
