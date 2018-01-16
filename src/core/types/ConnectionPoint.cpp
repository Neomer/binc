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
