#include "StringUtils.h"
#include <QRegExp>

bool StringUtils::IsNullOrEmpty(QString value)
{
    return value.isNull() || value.isEmpty();
}

bool StringUtils::IsVersion(QString value)
{
    QRegExp validator("\\d+(\\.\\d+){0,2}[\\-\\s]*(pre-alpha|alpha|beta|rc|pre-a|a|b)?");
    return validator.exactMatch(value);
}

QString StringUtils::TrimEx(QString value)
{
    int st = value.indexOf(QRegExp("[^\\s\\t\\n\\r]")), en = value.lastIndexOf(QRegExp("[^\\s\\t\\n\\r]"));
    return value.mid(st, en - st + 1);
}

QString StringUtils::EmptyString()
{
    return QString();
}

StringUtils::StringUtils()
{

}
