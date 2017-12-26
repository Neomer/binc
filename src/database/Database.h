#ifndef DATABASE_H
#define DATABASE_H

#include <QFile>
#include <QDir>
#include <QLockFile>
#include "DatabaseGeneral.h"

#include "IDatabaseIndex.h"
#include "IDatabaseData.h"

///
/// \brief The Database class класс для работы с базой данных
///
class Database
{
public:
    Database();
    ~Database();

    ///
    /// \brief open пытается открыть соединение с базой данных, в случае успеха,
    /// устанавливает блокировку на базу
    /// \return
    ///
    bool open();
    ///
    /// \brief close закрывает соединение с базой данных, снимает блокировку
    /// \return
    ///
    void close();
    ///
    /// \brief read возвращает запись из базы данных по переданному ключу key
    /// \param key ключ
    /// \return
    ///
    void read(dbkey key, DatabaseDataFileRecord *data);
    ///
    /// \brief write записывает объект в базу данных
    /// \param key ключ
    /// \param object объект
    ///
    void write(dbkey key, DatabaseDataFileRecord *data);
    ///
    /// \brief databasePath путь, по которому располагается база данных
    /// \return
    ///
    QString databasePath() { return _databasePath; }
    ///
    /// \brief databaseDir директория, в которой располагается база данных
    /// \return
    ///
    QDir databaseDir() { return _databaseDir; }

private:
    QString _databasePath;
    QLockFile *_lockFile;
    QDir _databaseDir;
    IDatabaseIndex *_index;
    IDatabaseData *_data;
};



#endif // DATABASE_H
