#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <QObject>

class DatabaseException : public std::exception
{
public:
    DatabaseException(const char * message);

public:
    char const* what() const throw() { return _message; }

private:
    const char *  _message;
};

#endif // DATABASEEXCEPTION_H
