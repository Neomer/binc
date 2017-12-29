#ifndef CONTEXTEXCEPTION_H
#define CONTEXTEXCEPTION_H

#include <QObject>

class ContextException : public std::exception
{
public:
    ContextException(const char * message);

    char const* what() const throw() { return _message; }

private:
    const char * _message;
};
#endif // CONTEXTEXCEPTION_H
