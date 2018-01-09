#include "IHTTPRequest.h"
#include <core/StringUtils.h>

void IHTTPRequest::setUrl(QUrl value)
{
    _url = value;
}

QUrl IHTTPRequest::getUrl()
{
    return _url;
}

void IHTTPRequest::setHeader(QString name, QString value)
{
    _headers[name] = value;
}

QString IHTTPRequest::getHeader(QString name)
{
    if (!_headers.contains(name)) return StringUtils::EmptyString();
    return _headers[name];

}

IHTTPRequest::IHTTPRequest()
{

}

QString IHTTPRequest::compileHeaders()
{
    QString ret;

    foreach (QString k, _headers.keys())
    {
        ret += k + ":" + _headers[k] + "\r\n";
    }

    return ret;
}
