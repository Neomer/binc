#include "Guid.h"
#include <cstdlib>
#include <QDateTime>

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
                QString::number(_data.Data1, 16),
                QString::number(_data.Data2, 16),
                QString::number(_data.Data3, 16),
                QString::number((quint16)((_data.Data4 & 0xffff0000) >> 16), 16),
                QString::number((quint16)( _data.Data4 & 0x0000ffff), 16),
                QString::number( _data.Data5, 16));
}

bool Guid::isEqual(const Guid &v1, const Guid &v2)
{
    return memcmp(&(v2._data), &(v1._data), sizeof(GuidStructure)) == 0;
}

Guid Guid::randomGuid()
{
    Guid ret;
    srand(QDateTime::currentDateTime().currentMSecsSinceEpoch());
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
