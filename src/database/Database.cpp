#include "Database.h"
#include <QFile>

#include <core/Context.h>
#include <core/StreamedBuffer.h>
#include <model/DatabaseIndexRecord.h>

Database::Database() :
    _file("data.bin")
{
}

void Database::open()
{
//    _database_dir.setPath(Context::Instance().settings()->getDatabasePath());
//    if (!_database_dir.exists())
//    {
//        if (!_database_dir.mkpath(Context::Instance().settings()->getDatabasePath()))
//        {
//            throw BaseException("Database directory creation failed!");
//        }
//    }

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
    _file.seek(_file.size());
    StreamedBuffer buffer;
    object->toDataStream(buffer.stream());

    if (_file.write(buffer) != buffer.size())
    {
        throw BaseException("Not all data was written!");
    }
}

bool Database::read(Guid id, IDatabaseWritable *object)
{
    _file.seek(0);
    while (!_file.atEnd())
    {
        object->fromDataStream(_file.stream());
        if (Guid::isEqual(object->getId(), id))
        {
            return true;
        }
    }
    return false;
}
