#include "IHTTPMessage.h"

IHTTPMessage::IHTTPMessage() :
    INetMessageWithHeaders(),
    _version(Version(1, 1))
{

}
