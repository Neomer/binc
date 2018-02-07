#ifndef IABSTRACTRPCCONTROLLER_H
#define IABSTRACTRPCCONTROLLER_H

#include <core/BaseException.h>
#include <core/net/rpc/RPCRequest.h>
#include <core/net/rpc/RPCResponse.h>

///
/// \brief IAbstractRpcController абстрактный класс, который должны реализовывать все контроллеры, доступные через RPC
///
class IAbstractRpcController
{
public:
    ///
    /// \brief exec выполняет обработку, заполняет все необходимые для корректной обработки поля в HTTP ответе response
    /// \param response ответ контроллера, который отправляется клиенту
    ///
    virtual void exec(HTTPResponse *response) = 0;
    ///
    /// \brief getControllerName вовзращает наименование контроллера
    /// \return
    ///
    virtual QString getControllerName() = 0;
    ///
    /// \brief setRequest HTTP-запрос, который вызвал запуск контроллера
    /// \param value
    ///
    void setRequest(RPCRequest *value) { _request = value; }
    ///
    /// \brief getContent тело из HTTP-запроса
    /// \return
    ///
    QString getContent() { return _request->getContent(); }
    ///
    /// \brief getQuery Query-строка из HTTP-запроса
    /// \return
    ///
    QString getQuery() { return _request->getUrl().query(); }

private:
    RPCRequest *_request;
};

#endif // IABSTRACTCONTROLLER_H
