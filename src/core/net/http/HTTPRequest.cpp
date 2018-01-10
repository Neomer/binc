#include "IHTTPRequest.h"

HTTPRequest::HTTPRequest() :
    IHTTPMessage()
{

}

QString HTTPRequest::statusRow()
{

    setHeader("Host", getUrl().host() + ((getUrl().port() == -1) ? "" : ":" + QString::number(getUrl().port())));
    return methodName() + " " + ((getUrl().path().isEmpty()) ? "/" : getUrl().path()) + " HTTP/" + getVersion().toString("J.N");
}

void HTTPRequest::parseStatusRow(QString data)
{
    QRegExp httpReqValidator("(POST|GET|DELETE|PUT)\\s+((\\/?[\\w\\.\\-\\+]+)*\\/|(\\/))(\\?([\\w\\d]+\\=[\\w\\d]+\\&)*([\\w\\d]+\\=[\\w\\d]+)?)?\\s+HTTP\\/1\\.1");
    if (httpReqValidator.indexIn(data) == -1)
    {
        throw HTTPParsingException(0, "Data is not valid HTTP request!");
    }
}
