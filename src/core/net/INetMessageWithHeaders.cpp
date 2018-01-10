#include "INetMessageWithHeaders.h"
#include <core/StringUtils.h>

INetMessageWithHeaders::INetMessageWithHeaders()
{

}

QString INetMessageWithHeaders::compile()
{
    return statusRow() + "\r\n" + compileHeaders() + "\r\n\r\n";
}

void INetMessageWithHeaders::setHeader(QString name, QString value)
{
    _headers[name] = value;
}

QString INetMessageWithHeaders::getHeader(QString name)
{
    if (!_headers.contains(name)) return StringUtils::EmptyString();
    return _headers[name];
}

void INetMessageWithHeaders::parse(QString data)
{
    data = StringUtils::TrimEx(data);

    // parsing status row
    QRegExp regex("\r?\n");
    int space = regex.indexIn(data), space2;
    parseStatusRow(data.left(space));
    space += regex.matchedLength();

    QString name, value;
    // parsing headers
    while (regex.indexIn(data, space) > 0)
    {
        space2 = data.indexOf(':', space);
        name = StringUtils::TrimEx(data.mid(space, space2 - space));
        space = space2 + 1;
        space2 = regex.indexIn(data, space);
        value = StringUtils::TrimEx(data.mid(space, space2 - space));
        space = space2 + regex.matchedLength();
        setHeader(name, value);
    }
    setContent(data.mid(space));
}

QString INetMessageWithHeaders::compileHeaders()
{
    QString ret;
    foreach (QString k, _headers.keys()) ret += k + ":" + _headers[k] + "\r\n";
    return ret;
}
