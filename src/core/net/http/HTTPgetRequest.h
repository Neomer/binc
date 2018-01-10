#ifndef HTTPGETREQUEST_H
#define HTTPGETREQUEST_H

#include "HTTPRequest.h"

class HTTPgetRequest : public HTTPRequest
{
public:
    HTTPgetRequest();
    void setQuery(QString value);

public:
    QString methodName() { return "GET"; }

private:
    QString _query;
};

#endif // HTTPGETREQUEST_H
