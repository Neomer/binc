#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <QObject>

class DatabaseException : public std::exception
{
public:
    DatabaseException(const char * message);
    DatabaseException(QString message);

public:
    char const* what() const throw() { return _message.toUtf8().constData(); }

private:
    QString _message;
};

#endif // DATABASEEXCEPTION_H
