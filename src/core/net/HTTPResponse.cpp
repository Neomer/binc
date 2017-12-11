#include "HTTPResponse.h"
#include "HTTPParsingException.h"

HTTPResponse::HTTPResponse(IHTTPRequest *request, QByteArray reply)
{
    _request = request;
    _raw = QString::fromUtf8(reply);
    parse();
}

QString HTTPResponse::header(QString name)
{
    if (_headers.keys().contains(name))
    {
        return _headers[name];
    }
    else
    {
        return QString();
    }
}

void HTTPResponse::parse()
{
    QString row;
    int tmp;
    bool ok;

    int rownum = 0;
    row = _raw.left(_raw.indexOf('\n')).trimmed();
    if (row.left(4) != "HTTP")
    {
        throw HTTPParsingException(1, "Неизвестный формат сообщения!");
    }
    tmp = row.indexOf(' ');
    _version = row.mid(5, tmp - 5);
    _status = row.mid(tmp + 1, 3).toInt(&ok);
    if (!ok)
    {
        throw HTTPParsingException(1, "Неизвестный формат сообщения!");
    }
    _statusMessage = row.mid(tmp + 5);
    do
    {
        rownum++;
    }
    while (true);
}
