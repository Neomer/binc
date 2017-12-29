#include "DatabaseFile.h"
#include "DatabaseFile.h"
#include <QCryptographicHash>
#include <QDebug>

DatabaseFile::DatabaseFile() :
    QFile()
{
}

DatabaseFile::DatabaseFile(QString filename) :
    QFile(filename)
{
}

bool DatabaseFile::open(QIODevice::OpenMode flags)
{
    bool ex = exists();
    bool ret = QFile::open(flags);
    if (ret)
    {
        if (!ex)
        {
            resize(sizeof(DatabaseFileHeader));
            memset(&_header, 0, sizeof(DatabaseFileHeader));
            setUsedBytes(0);
        }
        else
        {
            if (QFile::read((char *)&_header, sizeof(DatabaseFileHeader)) != sizeof(DatabaseFileHeader))
            {
                throw DatabaseFileException(fileName(), "File reading error!");
            }
        }
    }
    else
    {
        throw DatabaseFileException(fileName(), "File access error!");
    }
    return ret;
}

void DatabaseFile::insert(quint64 offset, void *data)
{
    toEnd();

    // При необходимости пакетно смещаем содержимое файла на необходимое количество байт, чтобы
    // освободить место в сердине файла
    if (offset < bytesUsed())
    {
        char buf[PAGE_SIZE];
        quint64 carrier = bytesUsed(), // Указатель для чтения
                l = 0;
        while (carrier > offset)
        {
            l = qMin((quint64)PAGE_SIZE, carrier);
            carrier -= l;
            seek(carrier);
            if ((quint64)QFile::read(buf, l) != l)
            {
                throw DatabaseFileException(fileName(), "File reading error!");
            }
            seek(carrier + recordSize());
            if ((quint64)QFile::write(buf, l) != l)
            {
                throw DatabaseFileException(fileName(), "File writing error!");
            }
        }
        setUsedBytes(bytesUsed() + recordSize());
    }

    else
    {
        setUsedBytes(offset + recordSize());
    }
    seek(offset);
    QFile::write((const char *)data, recordSize());
}

void DatabaseFile::insert(quint64 offset, void **data, int count)
{
    toEnd();

    quint64 size = count * recordSize();

    // При необходимости пакетно смещаем содержимое файла на необходимое количество байт, чтобы
    // освободить место в сердине файла
    if (offset < bytesUsed())
    {
        char buf[PAGE_SIZE];
        quint64 carrier = bytesUsed(), // Указатель для чтения
                l = 0;
        while (carrier > offset)
        {
            l = qMin((quint64)PAGE_SIZE, carrier);
            carrier -= l;
            seek(carrier);
            if ((quint64)QFile::read(buf, l) != l)
            {
                throw DatabaseFileException(fileName(), "File reading error!");
            }
            seek(carrier + size);
            if ((quint64)QFile::write(buf, l) != l)
            {
                throw DatabaseFileException(fileName(), "File writing error!");
            }
        }
        setUsedBytes(bytesUsed() + size);
    }

    else
    {
        setUsedBytes(offset + size);
    }
    seek(offset);
    QFile::write((const char *)data, size);
}

void DatabaseFile::append(void *data)
{
    toEnd();
    write((const char *)data, recordSize());
}

void DatabaseFile::toEnd()
{
    seek(bytesUsed());
}

void DatabaseFile::moveTo(quint64 index)
{
    seek(index * recordSize());
}

bool DatabaseFile::seek(qint64 offset)
{
    return QFile::seek(offset + headerSize() + sizeof(DatabaseFileHeader));
}

void DatabaseFile::toBegin()
{
    seek(0);
}

QString DatabaseFile::fileName()
{
    QString name = QFile::fileName();
    name = name.right(name.length() - name.lastIndexOf('/') - 1);
    return name;
}

bool DatabaseFile::isValid()
{
    return false;
}

void DatabaseFile::setUsedBytes(qint64 value)
{
    _header.BytesUsed = value;
    QFile::seek(0);
    if (QFile::write((const char *)&_header, sizeof(DatabaseFileHeader)) != sizeof(DatabaseFileHeader))
    {
        throw DatabaseFileException(fileName(), "File writing error!");
    }
}

quint64 DatabaseFile::bytesOffsetByIndex(int index)
{
    return index * recordSize() + headerSize();
}

void DatabaseFile::get(void *buffer)
{
    if (QFile::read((char *)buffer, recordSize()) != recordSize())
    {
        throw DatabaseFileException(fileName(), "File reading error!");
    }
}

void DatabaseFile::get(void **buffer, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (QFile::read((char *)buffer[i], recordSize()) != recordSize())
        {
            throw DatabaseFileException(fileName(), "File reading error!");
        }
    }
}

void DatabaseFile::close()
{
    QFile::close();
}

int DatabaseFile::write(const char *data, qint64 len)
{
    if (QFile::write(data, len) != len)
    {
        throw DatabaseFileException(fileName(), "File writing error!");
    }
    return len;
}
