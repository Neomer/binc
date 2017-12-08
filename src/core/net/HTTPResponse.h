#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "IHTTPRequest.h"

class HTTPResponse
{
public:
    HTTPResponse(IHTTPRequest *request, QByteArray reply);
    IHTTPRequest *request() { return _request; }

    int status() { return _status; }

private:
    void parse();

    IHTTPRequest *_request;
    QString _raw;
    int _status;
};

#endif // HTTPRESPONSE_H
