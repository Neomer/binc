#include "StringUtils.h"
#include <QRegExp>

bool StringUtils::IsNullOrEmpty(QString value)
{
    return value.isNull() || value.isEmpty();
}

QString StringUtils::TrimEx(QString value)
{
    int st = value.indexOf(QRegExp("[^\\s\\t\\n\\r]")), en = value.lastIndexOf(QRegExp("[^\\s\\t\\n\\r]"));
    return value.mid(st, en - st + 1);
}

StringUtils::StringUtils()
{

}
