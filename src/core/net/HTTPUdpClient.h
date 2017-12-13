#ifndef HTTPUDPCLIENT_H
#define HTTPUDPCLIENT_H

#include "IHTTPRequest.h"
#include "HTTPResponse.h"

class HTTPUdpClient
{
public:
    HTTPUdpClient();

    static HTTPResponse send(IHTTPRequest *request);
};

#endif // HTTPUDPCLIENT_H
