#ifndef DATABASEFILEEXCEPTION_H
#define DATABASEFILEEXCEPTION_H

#include "DatabaseException.h"

class DatabaseFileException : public DatabaseException
{
public:
    DatabaseFileException(QString filename, const char *message);

    QString filename() { return _filename; }

private:
    QString _filename;

};

#endif // DATABASEFILEEXCEPTION_H
