#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QString>

class IHTTPRequest
{
public:
    virtual QString methodName() = 0;

protected:
    IHTTPRequest();
};

#endif // HTTPREQUEST_H
