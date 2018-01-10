#include "HTTPRequest.h"

HTTPRequest::HTTPRequest() :
    IHTTPMessage()
{

}

HTTPRequest::HTTPRequest(QString method) :
    IHTTPMessage(),
    _method(method)
{

}

QString HTTPRequest::statusRow()
{
    setHeader("Host", getUrl().host() + ((getUrl().port() == -1) ? "" : ":" + QString::number(getUrl().port())));
    return getMethodName().toUpper() + " " + ((getUrl().path().isEmpty()) ? "/" : getUrl().path()) + " HTTP/" + getVersion().toString("J.N");
}

void HTTPRequest::parseStatusRow(QString data)
{
    QRegExp httpReqValidator("(POST|GET|DELETE|PUT)\\s+((\\/?[\\w\\.\\-\\+]+)*\\/|(\\/))(\\?([\\w\\d]+\\=[\\w\\d]+\\&)*([\\w\\d]+\\=[\\w\\d]+)?)?\\s+HTTP\\/1\\.1");
    if (httpReqValidator.indexIn(data) == -1)
    {
        throw HTTPParsingException(0, "Data is not valid HTTP request!");
    }

    // parsing status row
    int space = data.indexOf(' '), space2 = data.indexOf(' ', space + 1);
    _method = data.left(space);
    _url.setPath(data.mid(space + 1, space2 - space - 1));
}

void HTTPRequest::postParseActions()
{
    _url.setUrl(QString("http://") + getHeader("Host"));
}
