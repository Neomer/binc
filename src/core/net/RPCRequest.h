#ifndef RPCREQUEST_H
#define RPCREQUEST_H

#include <core/net/http/AbstractHTTPRequest.h>

///
/// \brief The RPCRequest class класс расширяющий AbstractHTTPRequest для работы с RPC-запросами
///
class RPCRequest : public AbstractHTTPRequest
{
public:
    RPCRequest();

    ///
    /// \brief action возвращает запрошенный метод
    /// \return
    ///
    QString action();
};

#endif // RPCREQUEST_H
