#ifndef SSDPREQUEST_H
#define SSDPREQUEST_H

#include <core/net/http/IHTTPRequest.h>

#define SSDP_ACTION_ADDPORT            "AddPortMapping"

class SSDPRequest : public HTTPRequest
{
public:
    SSDPRequest();

    void setAction(QString value);

// IHTTPRequest interface
public:
    QString methodName() { return "M-SEARCH"; }
    QString compile();
};

#endif // SSDPREQUEST_H
