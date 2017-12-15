#include "HTTPgetRequest.h"

HTTPgetRequest::HTTPgetRequest() :
    IHTTPRequest()
{
    _query.clear();
}

void HTTPgetRequest::setQuery(QString value)
{
    _query = value;
}

QString HTTPgetRequest::compile()
{
    return methodName() + " " + (getUrl().path().isEmpty() ? "/" : getUrl().path()) + (_query.isEmpty() ? "" : "?" + _query) + " HTTP/1.1\r\n" +
           "Host: " + getUrl().host() + ":" + QString::number(getUrl().port(80)) + "\r\n" +
           compileHeaders() +
           "\r\n";
}
