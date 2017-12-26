#ifndef CONSOLEINPUTEXCEPTION_H
#define CONSOLEINPUTEXCEPTION_H

#include <QObject>

class ConsoleInputException : public std::exception
{
public:
    ConsoleInputException(const char * message);

    char const* what() const throw() { return _message; }

private:
    const char * _message;
};

#endif // CONSOLEINPUTEXCEPTION_H
