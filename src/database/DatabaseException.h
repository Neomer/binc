#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <core/BaseException.h>

class DatabaseException : public BaseException
{
public:
    DatabaseException(const char * message);
};

#endif // DATABASEEXCEPTION_H
