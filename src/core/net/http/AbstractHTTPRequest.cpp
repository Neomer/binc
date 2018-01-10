#include "AbstractHTTPRequest.h"
#include <core/StringUtils.h>

AbstractHTTPRequest::AbstractHTTPRequest() :
    HTTPRequest()
{

}

void AbstractHTTPRequest::parse(QByteArray data)
{
    QString sData = QString::fromUtf8(data).trimmed();
    QRegExp httpReqValidator("(POST|GET|DELETE|PUT)\\s+((\\/?[\\w\\.\\-\\+]+)*\\/|(\\/))(\\?([\\w\\d]+\\=[\\w\\d]+\\&)*([\\w\\d]+\\=[\\w\\d]+)?)?\\s+HTTP\\/1\\.1");
    if (httpReqValidator.indexIn(sData.left(sData.indexOf('\n'))) == -1)
    {
        throw HTTPParsingException(0, "Data is not valid HTTP request!");
    }
    QString path;

    // parsing status row
    int space = sData.indexOf(' '), space2 = sData.indexOf(' ', space + 1);
    _method = sData.left(space);
    path = sData.mid(space + 1, space2 - space - 1);
    space2 = space;
    QRegExp regex("\r?\n");
    space = regex.indexIn(sData, space) + regex.matchedLength();

    QString name, value;
    // parsing headers
    while (regex.indexIn(sData, space) > 0)
    {
        space2 = sData.indexOf(':', space);
        name = StringUtils::TrimEx(sData.mid(space, space2 - space));
        space = space2 + 1;
        space2 = regex.indexIn(sData, space);
        value = StringUtils::TrimEx(sData.mid(space, space2 - space));
        space = space2 + regex.matchedLength();
        setHeader(name, value);
    }
    QString host = getHeader("Host");
    if (StringUtils::IsNullOrEmpty(host))
    {
        throw HTTPParsingException(0, "Host header not found!");
    }
    setUrl(QUrl("http://" + host + path));
    setContent(sData.mid(space));
}

