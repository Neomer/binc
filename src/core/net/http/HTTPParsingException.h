#ifndef HTTPPARSINGEXCEPTION_H
#define HTTPPARSINGEXCEPTION_H

#include <core/net/NetDataStreamException.h>

class HTTPParsingException : public NetDataStreamException
{
public:
    HTTPParsingException(int row, const char *message);

    int line() { return _row; }

private:
    int _row;
};

#endif // HTTPPARSINGEXCEPTION_H
