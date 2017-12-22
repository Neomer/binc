#ifndef DATASTREAMEXCEPTION_H
#define DATASTREAMEXCEPTION_H

#include <QObject>

class DataStreamException : public std::exception
{
public:
    DataStreamException(const char * message);

    char const* what() const throw() { return _message; }

private:
    const char * _message;
};

#endif // DATASTREAMEXCEPTION_H
