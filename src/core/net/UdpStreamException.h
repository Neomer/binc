#ifndef UDPSTREAMEXCEPTION_H
#define UDPSTREAMEXCEPTION_H

#include <core/DataStreamException.h>

class UdpStreamException : public DataStreamException
{
public:
    UdpStreamException(const char *message);
};

#endif // UDPSTREAMEXCEPTION_H
