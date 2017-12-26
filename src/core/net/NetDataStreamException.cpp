#include "NetDataStreamException.h"

using namespace std;

NetDataStreamException::NetDataStreamException(NetDataStreamException::ExceptionType type, const char *message) :
    DataStreamException(message)
{
    _type = type;
}
