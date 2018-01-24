#include "Database.h"
#include <QFile>

#include <core/StreamedBuffer.h>
#include <model/DatabaseIndexRecord.h>

Database::Database() :
    _file("data.bin")
{
}

void Database::open()
{
    if (!_file.open(QIODevice::ReadWrite))
    {
        throw BaseException("File access error!");
    }
    _file.seek(0);
}

void Database::close()
{
    _file.flush();
    _file.close();
}

void Database::write(IDatabaseWritable *object)
{
    StreamedBuffer buffer;
    object->toDataStream(buffer.stream());

    if (_file.write(buffer) != buffer.size())
    {
        throw BaseException("Not all data was written!");
    }
}

void Database::read(Guid id, IDatabaseWritable *object)
{
    _file.seek(0);
    while (!_file.atEnd())
    {
        object->fromDataStream(_file.stream());
        if (Guid::isEqual(object->getId(), id))
        {
            return;
        }
    }
    object = 0;
}
