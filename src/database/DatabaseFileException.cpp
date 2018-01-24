#include "DatabaseFileException.h"

DatabaseFileException::DatabaseFileException(QString filename, const char *message) :
    DatabaseException(message),
    _filename(filename)
{

}

DatabaseFileException::DatabaseFileException(const char *filename, const char * message) :
    DatabaseException(message),
    _filename(filename)
{

}
