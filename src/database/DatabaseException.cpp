#include "DatabaseException.h"

DatabaseException::DatabaseException(const char *message)
{
    _message = message;
}

DatabaseException::DatabaseException(QString message)
{
    _message = message;
}
