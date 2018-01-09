#include "HTTPResponse.h"
#include "HTTPParsingException.h"
#include <core/StringUtils.h>

HTTPResponse::HTTPResponse(IHTTPRequest *request, QByteArray reply)
{
    _request = request;
    _raw = QString::fromUtf8(reply);
    parse();
}

HTTPResponse::HTTPResponse(IHTTPRequest *request) :
    _version("1.1"),
    _status(200)
{
    _request = request;
}

QString HTTPResponse::header(QString name)
{
    if (_headers.keys().contains(name))
    {
        return _headers[name];
    }
    else
    {
        return StringUtils::EmptyString();
    }
}

QByteArray HTTPResponse::compile()
{
    QString ret;

}

void HTTPResponse::parse()
{
    QString row;
    int tmp, tmp2;
    bool ok;

    // Парсим статусную строку
    int rownum = 0;
    row = _raw.left(_raw.indexOf('\n')).trimmed();
    if (row.left(4) != "HTTP")
    {
        throw HTTPParsingException(1, "Unknown data format!");
    }
    tmp = row.indexOf(' ');
    _version = row.mid(5, tmp - 5);
    _status = row.mid(tmp + 1, 3).toInt(&ok);
    if (!ok)
    {
        throw HTTPParsingException(1, "Unknown data format!");
    }
    _statusMessage = row.mid(tmp + 5);
    tmp = _raw.indexOf('\n', tmp + 1);
    // Парсим заголовки
    do
    {
        if ((tmp2 = _raw.indexOf(':', tmp)) == -1) break;
        QString name = _raw.mid(tmp + 1, tmp2 - tmp - 1);
        tmp = _raw.indexOf('\n', tmp + 1);
        if (tmp == -1)
        {
            throw HTTPParsingException(rownum, "Unexpected end of data!");
        }
        QString value = formatHeaderValue(_raw.mid(tmp2 + 1, tmp - tmp2 - 1));
        _headers[name.toLower()] = value;
        rownum++;
    }
    while (true);
    _content = _raw.mid(tmp + 1);
}

QString HTTPResponse::formatHeaderValue(QString text)
{
    return text.trimmed().replace(QRegExp("[\r\n]"), "");
}
