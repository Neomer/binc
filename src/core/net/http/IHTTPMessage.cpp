#include "IHTTPMessage.h"
#include <QDateTime>

IHTTPMessage::IHTTPMessage() :
    INetMessageWithHeaders(),
    _version(Version(1, 1))
{
    setHeader("Date", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}
