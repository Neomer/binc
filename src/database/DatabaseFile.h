#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include <QFile>
#include "DatabaseFileException.h"

#define PAGE_SIZE       10240 // Размер считываемого за цикл блока при добавлении записи в серердину файла

///
/// \brief The DatabaseFile class добавляет некоторый функционал к стандартному классу работы с файлами.
/// Поддерживаются функции:
///  - Блочное выделения памяти
///  - Создание, ведение, контроль заголовка (системная информация файла)
///
class DatabaseFile : public QFile
{
    Q_OBJECT

public:
    DatabaseFile();
    DatabaseFile(QString filename);

    ///
    /// \brief open открывает файл, читает заголовок файла
    /// \param flags
    ///
    bool open(OpenMode flags) override;
    ///
    /// \brief insert вставляет блок данных в произвольное место файла
    /// \param offset смещение в байтах относительно начала файла
    /// \param data блок данных
    ///
    void insert(quint64 offset, void *data);
    ///
    /// \brief insert вставляет массив блоков данных в произвольное место файла
    /// \param offset смещение в байтах относительно начала файла
    /// \param data массив блоков данных
    /// \param count количество блоков
    ///
    void insert(quint64 offset, void **data, int count);
    ///
    /// \brief append дописывает в конец блок данных
    /// \param data
    ///
    void append(void *data);
    ///
    /// \brief toBegin перемещает каретку на первый байт следующий за заголовком
    ///
    void toBegin();
    ///
    /// \brief toEnd перемещает каретку в конец данных (не файла)
    ///
    void toEnd();
    ///
    /// \brief moveTo перемещает каретку на начало указанного блока с номером index
    /// \param index номер блока данных
    ///
    void moveTo(quint64 index);
    ///
    /// \brief seek перемещает каретку на указанный байт + длина заголовка
    /// \param offset
    /// \return
    ///
    bool seek(qint64 offset);
    ///
    /// \brief close записывает в файл заголовок и закрывает его
    ///
    void close();
    ///
    /// \brief fileName возвращает имя файла (без пути)
    /// \return
    ///
    QString fileName();
    ///
    /// \brief isValid проверяет файл на наличие повреждений. Происходит проверка хэш-суммы заголовка.
    /// \return
    ///
    bool isValid();
    ///
    /// \brief bytesUsed Возвращает количество используемых байт
    /// \return
    ///
    quint64 bytesUsed() { return _header.BytesUsed; }
    ///
    /// \brief recordSize возвращает размер записи
    /// \return
    ///
    virtual quint16 recordSize() = 0;
    ///
    /// \brief bytesOffsetByIndex смещение в байтах для указанного номера блока
    /// \param index
    /// \return
    ///
    quint64 bytesOffsetByIndex(int index);
    ///
    /// \brief get получает блок из файла
    /// \param buffer
    ///
    void get(void *buffer);
    ///
    /// \brief get получает блок из файлаs
    /// \param buffer
    /// \param count
    ///
    void get(void **buffer, int count);

protected:
    ///
    /// \brief headerSize Возвращает размер защищенного заголовка
    ///
    virtual quint16 headerSize() = 0;
    ///
    /// \brief writeHeader Переписывает заголовок файла
    /// \param buffer
    ///
    virtual void writeHeader(void *data) = 0;
    ///
    /// \brief readHeader Читает заголовок файла
    /// \param buffer
    ///
    virtual void readHeader(void *data) = 0;

private:
    /// \brief setUsedBytes записывает в заголовок файла новое значение количества используемых байт
    /// \param value
    ///
    void setUsedBytes(qint64 value);
    ///
    /// \brief write функция закрыта для публичного использования. Необходимо использовать DatabaseFile::insert()
    /// \param data
    /// \param len
    ///
    int write(const char *data, qint64 len);
    ///
    /// \brief read функция закрыта для публичного использования. Необходимо использовать DatabaseFile::get()
    /// \param data
    /// \param len
    ///
    int read(char *data, qint64 maxlen);

    struct DatabaseFileHeader
    {
        int BytesUsed;
    };
    DatabaseFileHeader _header;
};

#endif // DATABASEFILE_H
