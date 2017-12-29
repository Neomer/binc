#include "AbstractHTTPRequest.h"

AbstractHTTPRequest::AbstractHTTPRequest() :
    IHTTPRequest()
{

}

void AbstractHTTPRequest::parse(QByteArray data)
{
    QString sData = QString::fromUtf8(data).trimmed();
    QRegExp httpReqValidator("(POST|GET|DELETE|PUT)\\s+((\\/?[\\w\\.\\-\\+]+)|(\\/))(\\?([\\w\\d]+\\=[\\w\\d]+\\&)*([\\w\\d]+\\=[\\w\\d]+)?)?\\s+HTTP\\/1\\.1");
    if (!httpReqValidator.exactMatch(sData.left(sData.indexOf('\n'))))
    {
        throw HTTPParsingException(0, "Unknown format!");
    }
    int space = sData.indexOf(' ');
    _method = sData.left(space);
    setUrl(QUrl(sData.mid(sData.indexOf(' ', space + 1))));
}
