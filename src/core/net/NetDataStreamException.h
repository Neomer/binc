#ifndef NETDATASTREAMEXCEPTION_H
#define NETDATASTREAMEXCEPTION_H

#include <QDebug>
#include <core/DataStreamException.h>

class NetDataStreamException : public DataStreamException
{
public:
    enum ExceptionType
    {
        enNDSE_HostNotAvailable,
        enNDSE_Timeout,
        enNDSE_PortIsBusy,
        enNDSE_TransferError,
        enNDSE_DataFormatError,
    };

    NetDataStreamException(ExceptionType type, const char * message);

    ExceptionType type() { return _type; }

private:
    ExceptionType _type;
};

#endif // NETDATASTREAMEXCEPTION_H
