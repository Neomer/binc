#include "DatabaseFileException.h"

DatabaseFileException::DatabaseFileException(QString filename, const char * message) :
    DatabaseException(message),
    _filename(filename)
{

}
