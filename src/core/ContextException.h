#ifndef CONTEXTEXCEPTION_H
#define CONTEXTEXCEPTION_H

#include <core/BaseException.h>

class ContextException : public BaseException
{
public:
    ContextException(const char * message);
};
#endif // CONTEXTEXCEPTION_H
