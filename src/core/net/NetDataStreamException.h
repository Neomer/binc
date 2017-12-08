#ifndef NETDATASTREAMEXCEPTION_H
#define NETDATASTREAMEXCEPTION_H

#include <QDebug>

class NetDataStreamException : public std::exception
{
public:
    enum ExceptionType
    {
        enNDSE_HostNotAvailable,
        enNDSE_Timeout,
    };

    NetDataStreamException(ExceptionType type, const char * message);

    ExceptionType type() { return _type; }
    char const* what() const throw() { return _message; }

private:
    ExceptionType _type;
    const char * _message;
};

#endif // NETDATASTREAMEXCEPTION_H
