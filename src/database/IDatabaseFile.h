#ifndef IDATABASEFILE_H
#define IDATABASEFILE_H

#include <core/IFileWithStream.h>
#include "IDatabaseWritable.h"
#include "IDatabaseFileHeader.h"
#include "DatabaseFileException.h"

///
/// \brief Класс реализует работу с файлами базы данных.
/// Основное отличие от обычных файлов в том, что запись в файл осуществляется блоками данных, а не последовательностью байт.
/// Запись в базу данных доступна для моделей, которые реализуют интерфейс IDatabaseWritable. Файл базы данных - название условное,
/// так как фактически это ДВА файла - файл с данными и файл заголовок.
///
class IDatabaseFile
{
public:
    ///
    /// \brief Инициализирует интерфейс для работы с файлом
    /// \param filename Наименование файла
    ///
    IDatabaseFile(IDatabaseFileHeader * header, QString filename);
    ~IDatabaseFile();
    ///
    /// \brief open открывает файл для чтения и/или записи
    /// \return
    ///
    bool open();
    ///
    /// \brief close закрывает файл
    ///
    void close();
    ///
    /// \brief toBegin перемещает каретку в начало файла
    ///
    void toBegin();
    ///
    /// \brief toEnd перемещает каретку в конец файла
    ///
    void toEnd();
    ///
    /// \brief write Записывает в файл блок данных
    /// \param data
    ///
    void write(IDatabaseWritable *data);
    ///
    /// \brief read Читает из файла блок данных
    /// \param data
    ///
    void read(IDatabaseWritable *data);

private:
    IFileWithStream _datafile, _headerfile;
};

#endif // IDATABASEFILE_H
