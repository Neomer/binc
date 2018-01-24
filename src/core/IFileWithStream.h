#ifndef IFILEWITHSTREAM_H
#define IFILEWITHSTREAM_H

#include <QFile>
#include <QDataStream>

///
/// \brief Класс расширяющий QFile. Добавляет доступ к файлу через QDataStream.
///
class IFileWithStream : public QFile
{
public:
    ///
    /// \brief IFileWithStream Инициализирует файл
    /// \param filename Наименование файла
    ///
    IFileWithStream(QString filename) : QFile(filename) {}
    ///
    /// \brief open Открывает файл для чтения и записи
    /// \return
    ///
    bool open() { bool ret = QFile::open(QIODevice::ReadWrite); if (ret) _stream.setDevice(this); return ret; }
    ///
    /// \brief stream Поток данных
    /// \return
    ///
    QDataStream &stream() { return _stream; }

private:
    QDataStream _stream;
};

#endif // IFILEWITHSTREAM_H
