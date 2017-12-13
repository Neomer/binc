#ifndef SSDPPROVIDER_H
#define SSDPPROVIDER_H

#include <QObject>

class SSDPProvider
{
public:
    SSDPProvider();

    static void registerPort(quint16 port);
};

#endif // SSDPPROVIDER_H
