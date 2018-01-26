#ifndef DATABASE_H
#define DATABASE_H

#include <QDir>

#include <core/types/Guid.h>
#include <database/IDatabaseWritable.h>
#include <core/StreamedFile.h>

///
/// \brief Database класс для работы с базой данных.
///
class Database
{
public:
    Database();

    void open();
    void close();
    void write(IDatabaseWritable *object);
    ///
    /// \brief read читает запись из базы данных
    /// \param id Идентификатор искомой сущности
    /// \param object найденный объект
    /// \return возвращает TRUE, если объект найден
    ///
    bool read(Guid id, IDatabaseWritable *object);

private:
    StreamedFile _file;
    QDir _database_dir;
};

#endif // DATABASE_H
