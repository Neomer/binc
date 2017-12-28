#ifndef IDATABASEFILE_H
#define IDATABASEFILE_H

#include "IDatabaseDataBlock.h"
#include <QFile>

///
/// \brief The IDatabaseFile class интерфейс для реализации работы с файлами.
/// В случае записи не в начало файла происходит освобождение необходимого пространства.
///
class IDatabaseFile : public QFile
{
public:
    IDatabaseFile(IDatabaseDataBlock *header);

    ///
    /// \brief open открывает файл для чтения или записи в зависимости от значения flags
    /// \param flags
    /// \return
    ///
    bool open(OpenMode flags);
    ///
    /// \brief close закрывает файл
    ///
    void close();

    ///
    /// \brief toBegin перемещает каретку в начало файла
    ///
    virtual void toBegin() = 0;
    ///
    /// \brief toEnd перемещает каретку в конец файла
    ///
    virtual void toEnd() = 0;
    ///
    /// \brief seek перемещает каретку на указанный блок
    /// \param offset смещение в байтах от начала файла
    ///
    virtual void seek(quint64 index) = 0;

    ///
    /// \brief write записывает в файл блок данных
    /// \param block
    /// \return возвращает смещение в байтах от начала файла записи
    ///
    virtual quint64 write(IDatabaseDataBlock *block) = 0;
    ///
    /// \brief read читает из файла блок данных
    /// \param block
    ///
    virtual void read(IDatabaseDataBlock *block) = 0;

private:
    IDatabaseDataBlock *_header;

protected:
    IDatabaseDataBlock *header() { return _header; }
    virtual void readHeader() = 0;

    QDataStream _stream;
};

#endif // IDATABASEFILE_H
