#ifndef RPCRESPONSE_H
#define RPCRESPONSE_H

#include <core/net/http/HTTPResponse.h>
#include "RPCRequest.h"

class RPCResponse : public HTTPResponse
{
public:
    RPCResponse(RPCRequest *request);
};

#endif // RPCRESPONSE_H
