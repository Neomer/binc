#ifndef DATASTREAMEXCEPTION_H
#define DATASTREAMEXCEPTION_H

#include <core/BaseException.h>

class DataStreamException : public BaseException
{
public:
    DataStreamException(const char * message);
};

#endif // DATASTREAMEXCEPTION_H
