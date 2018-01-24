#ifndef DATABASE_H
#define DATABASE_H

#include <core/types/Guid.h>
#include <database/IDatabaseWritable.h>
#include <core/StreamedFile.h>

class Database
{
public:
    Database();

    void open();
    void close();
    void write(IDatabaseWritable *object);
    void read(Guid id, IDatabaseWritable *object);

private:
    StreamedFile _file;
};

#endif // DATABASE_H
