#include "INetMessageWithHeaders.h"
#include <core/StringUtils.h>

INetMessageWithHeaders::INetMessageWithHeaders()
{

}

QString INetMessageWithHeaders::compile()
{
    setHeader("Content-Length", QString::number(getContent().length()));
    QString ret = statusRow() + "\r\n";
    return ret + compileHeaders() + "\r\n" + getContent();
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
    int space = regex.indexIn(data), space2, next = 99999;
    parseStatusRow(data.left(space));
    space += regex.matchedLength();

    QString name, value;
    // parsing headers
    while (regex.indexIn(data, space) > 0)
    {
        next = regex.indexIn(data, space);
        if (next - space <= regex.matchedLength()) break;
        space2 = data.indexOf(':', space);
        name = StringUtils::TrimEx(data.mid(space, space2 - space));
        space = space2 + 1;
        space2 = next;
        value = StringUtils::TrimEx(data.mid(space, space2 - space));
        space = space2 + regex.matchedLength();
        setHeader(name, value);
    }
    setContent(StringUtils::TrimEx(data.mid(space)));
    postParseActions();
}

QString INetMessageWithHeaders::compileHeaders()
{
    QString ret;
    foreach (QString k, _headers.keys()) ret += k + ":" + _headers[k] + "\r\n";
    return ret;
}
