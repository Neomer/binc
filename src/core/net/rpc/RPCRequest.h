#ifndef RPCREQUEST_H
#define RPCREQUEST_H

#include <core/net/http/HTTPRequest.h>

///
/// \brief The RPCRequest class класс расширяющий AbstractHTTPRequest для работы с RPC-запросами
///
class RPCRequest : public HTTPRequest
{
public:
    RPCRequest();

    ///
    /// \brief action возвращает запрошенный метод
    /// \return
    ///
    QString getAction();
};

#endif // RPCREQUEST_H
