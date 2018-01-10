#ifndef CONSOLEINPUTEXCEPTION_H
#define CONSOLEINPUTEXCEPTION_H

#include <core/BaseException.h>

class ConsoleInputException : public BaseException
{
public:
    ConsoleInputException(const char * message);
};

#endif // CONSOLEINPUTEXCEPTION_H
