#include "DatabaseBinaryTreeIndexRoot.h"
#include "DatabaseException.h"

DatabaseBinaryTreeIndexRoot::DatabaseBinaryTreeIndexRoot(QFile *file)
{
    _file = file;
    bool ex = file->exists();
    if (!_file->isOpen())
    {
        _file->open(QIODevice::ReadWrite);
    }
    if (!ex) setCount(0);
}

quint16 DatabaseBinaryTreeIndexRoot::count()
{
    BTreeIndexRootHeader hdr;
    _file->seek(0);
    if (_file->read((char *)&hdr, sizeof(BTreeIndexRootHeader)) != sizeof(BTreeIndexRootHeader))
    {
        throw DatabaseException("Data reading error!");
    }
    return hdr.Filecount;
}

void DatabaseBinaryTreeIndexRoot::setCount(quint16 value)
{
    BTreeIndexRootHeader hdr;
    hdr.Filecount = value;
    _file->seek(0);
    if (_file->write((char *)&hdr, sizeof(BTreeIndexRootHeader)) != sizeof(BTreeIndexRootHeader))
    {
        throw DatabaseException("Data writing error!");
    }
}

QString DatabaseBinaryTreeIndexRoot::getFile(dbkey key, qint64 *size)
{
    Q_UNUSED(key);
    BTreeIndexRootRecord rootRec;
    bool found = false;
    while (!_file->atEnd() && !found)
    {
        if (_file->read((char *)&rootRec, sizeof(BTreeIndexRootRecord)) != sizeof(BTreeIndexRootRecord))
        {
            throw DatabaseException("Data reading error!");
        }
        found = rootRec.StartKey < key && key < rootRec.EndKey;
    }
    if (!found)
    {
        setCount(count() + 1);
        memset(&rootRec, 0, sizeof(BTreeIndexRootRecord));
        rootRec.AllocSize = ALLOCATION_SIZE;
        rootRec.StartKey = key;
        rootRec.EndKey = key;
        strcpy(rootRec.Filename, QString(QString::number(count()) + ".INDEX").toUtf8().constData());
        rootRec.DataSize = 0;
    }
    if (size) size = 0;
    return "0.INDEX";
}
