#include "HTTPResponse.h"
#include "HTTPParsingException.h"
#include <core/StringUtils.h>

HTTPResponse::HTTPResponse(IHTTPRequest *request, QByteArray reply) :
    IHTTPMessage()
{
    _request = request;
    _raw = QString::fromUtf8(reply);
}

HTTPResponse::HTTPResponse(IHTTPRequest *request) :
    IHTTPMessage(),
    _status(200)
{
    _request = request;
}

QString HTTPResponse::statusRow()
{
    return QString("HTTP/") + getVersion().toString("J.N") + " " + QString::number(_status) + " " + _statusMessage;
}

void HTTPResponse::parseStatusRow(QString data)
{
    QRegExp statusRowValidator("HTTP\\/1\\.1\\s+\\d{3}\\s+\\w+");
    int s = statusRowValidator.indexIn(data);
    if (s == -1)
    {
        throw HTTPParsingException(0, "Status row unsupported format!");
    }
    bool ok = true;
    _status = data.mid(9, 3).toInt(&ok);
    if (!ok)
    {
        throw HTTPParsingException(0, "Unknown status value!");
    }
    setVersion(Version(data.mid(5, data.indexOf(' ') - 5)));
    _statusMessage = data.mid(13);
}
