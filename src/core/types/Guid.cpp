#include "Guid.h"
#include <cstdlib>
#include <QDateTime>
#include <QStringList>
#include <QString>

Guid::Guid()
{
    memset(&_data, 0, sizeof(_data));
}

Guid::Guid(const Guid &other)
{
    memcpy(&_data, &(other._data), sizeof(_data));
}

QString Guid::toString()
{
    return QString("{%1-%2-%3-%4-%5%6}").arg(
                QString::number(_data.Data1, 16).rightJustified(8, '0'),
                QString::number(_data.Data2, 16).rightJustified(4, '0'),
                QString::number(_data.Data3, 16).rightJustified(4, '0'),
                QString::number((quint16)((_data.Data4 & 0xffff0000) >> 16), 16).rightJustified(4, '0'),
                QString::number((quint16)( _data.Data4 & 0x0000ffff), 16).rightJustified(4, '0'),
                QString::number( _data.Data5, 16).rightJustified(8, '0'));
}

Guid Guid::fromString(QString data)
{
    QRegExp guidValidator("\\{[\\da-fA-F]{8}\\-[\\da-fA-F]{4}\\-[\\da-fA-F]{4}\\-[\\da-fA-F]{4}\\-[\\da-fA-F]{12}\\}");
    if (!guidValidator.exactMatch(data))
    {
        throw BaseException("Unknown data format!");
    }
    QStringList r = data.split('-');
    bool ok = true;
    Guid ret;
    ret._data.Data1 = QString(r.at(0)).mid(1).toInt(&ok, 16);
    ret._data.Data2 = QString(r.at(1)).toInt(&ok, 16);
    ret._data.Data3 = QString(r.at(2)).toInt(&ok, 16);
    ret._data.Data4 = QString(r.at(3)).toInt(&ok, 16) << 16;
    ret._data.Data4 |= QString(r.at(4)).left(4).toInt(&ok, 16);
    ret._data.Data5 = QString(r.at(4)).right(12).toInt(&ok, 16);
    return ret;
}

bool Guid::isEqual(const Guid &v1, const Guid &v2)
{
    return memcmp(&(v2._data), &(v1._data), sizeof(GuidStructure)) == 0;
}

Guid Guid::randomGuid()
{
    Guid ret;
    unsigned char * cur = (unsigned char *)&(ret._data);
    for (uint i = 0; i < sizeof(_data); i++)
    {
        cur[i] = rand() % 0xff;
    }

    return ret;
}

bool Guid::operator ==(const Guid &other)
{
    return memcmp(&_data, &(other._data), sizeof(GuidStructure)) == 0;
}

Guid &Guid::operator =(const Guid &other)
{
    memcpy(&_data, &(other._data), sizeof(GuidStructure));
}

bool Guid::operator <(const Guid &other)
{
    return memcmp(&_data, &(other._data), sizeof(GuidStructure)) < 0;
}

bool Guid::operator >(const Guid &other)
{
    return memcmp(&_data, &(other._data), sizeof(GuidStructure)) > 0;
}

