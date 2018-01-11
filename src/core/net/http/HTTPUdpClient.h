#ifndef HTTPUDPCLIENT_H
#define HTTPUDPCLIENT_H

#include "HTTPRequest.h"
#include "HTTPResponse.h"

class HTTPUdpClient
{
public:
    HTTPUdpClient();

    static HTTPResponse send(HTTPRequest *request);
};

#endif // HTTPUDPCLIENT_H
