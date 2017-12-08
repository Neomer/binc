#ifndef PORTMAPPING_H
#define PORTMAPPING_H

#include <QObject>
#include <QByteArray>

class PortMapping
{
public:
    PortMapping();

    static bool tryMapPort(quint16 internalPort, quint16 *mappedPort);

    //template<class T> static QByteArray mapType(T data);
};

#endif // PORTMAPPING_H
