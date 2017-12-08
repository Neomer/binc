#ifndef HTTPGETREQUEST_H
#define HTTPGETREQUEST_H

#include "IHTTPRequest.h"

class HTTPgetRequest : public IHTTPRequest
{
public:
    HTTPgetRequest();
    void setQuery(QString value);

public:
    QString methodName() { return "GET"; }
    QString compile();

private:
    QString _query;
};

#endif // HTTPGETREQUEST_H
