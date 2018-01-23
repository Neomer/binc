#include "ConnectionPoint.h"

ConnectionPoint::ConnectionPoint() :
    _address(QHostAddress::Any),
    _port(0)
{

}

ConnectionPoint::ConnectionPoint(QHostAddress address, quint16 port) :
    _address(address),
    _port(port)
{

}

ConnectionPoint::ConnectionPoint(const ConnectionPoint &other):
    _address(other._address),
    _port(other._port)
{

}
