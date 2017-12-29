#include "IHTTPRequest.h"

void IHTTPRequest::parse(QByteArray data)
{
    QString sData = QString::fromUtf8(data).trimmed();
    QRegExp httpReqValidator("(POST|GET|DELETE|PUT)\\s+((\\/?[\\w\\.\\-\\+]+)|(\\/))(\\?([\\w\\d]+\\=[\\w\\d]+\\&)*([\\w\\d]+\\=[\\w\\d]+)?)?\\s+HTTP\\/1\\.1");
    if (!httpReqValidator.exactMatch(sData.left(sData.indexOf('\n'))))
    {
        throw HTTPParsingException(0, "Unknown format!");
    }
}

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
