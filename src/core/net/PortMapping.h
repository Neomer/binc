#ifndef PORTMAPPING_H
#define PORTMAPPING_H

#include <QObject>

class PortMapping
{
public:
    PortMapping();

    static bool tryMapPort(quint16 internalPort, quint16 *mappedPort);
};

#endif // PORTMAPPING_H
