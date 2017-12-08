#include "NetDataStreamException.h"

using namespace std;

NetDataStreamException::NetDataStreamException(NetDataStreamException::ExceptionType type, const char *message) :
    exception()
{
    _message = message;
    _type = type;
}
