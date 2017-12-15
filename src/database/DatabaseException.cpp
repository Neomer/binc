#include "DatabaseException.h"

DatabaseException::DatabaseException(const char *message)
{
    _message = message;
}

