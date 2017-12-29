#include "DatabaseIndexFile.h"


DatabaseIndexFile::DatabaseIndexFile() :
    IDatabaseRandomAccessFile(new DatabaseIndexHeader(), DatabaseIndexRecord::blockSize())
{

}

quint64 DatabaseIndexFile::write(IDatabaseDataBlock *block)
{
    // Ищем место куда вставить запись, освобождаем место и переносим туда каретку
    DatabaseIndexRecord r;
    quint64 a = 0, c = static_cast<DatabaseIndexHeader *>(header())->records(), b;
    while (c - a > 1)
    {
        b = a + (c - a) * 0.5;
        seek(b);
        IDatabaseRandomAccessFile::read(&r);
        (r.guid() > static_cast<DatabaseIndexRecord *>(block)->guid()) ? c = b : a = b;
    }
    return IDatabaseRandomAccessFile::write(c, block);
}

void DatabaseIndexFile::read(IDatabaseDataBlock *block)
{
    return IDatabaseRandomAccessFile::read(block);
}

void DatabaseIndexFile::readHeader()
{
    QFile::seek(0);
     static_cast<DatabaseIndexHeader *>(header())->deserialize(_stream);
}
