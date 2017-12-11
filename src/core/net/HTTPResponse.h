#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "IHTTPRequest.h"

class HTTPResponse
{
public:
    HTTPResponse(IHTTPRequest *request, QByteArray reply);
    IHTTPRequest *request() { return _request; }

    ///
    /// \brief status Статус HTTP запроса
    /// \return
    ///
    int status() { return _status; }
    ///
    /// \brief version Версия протокола HTTP
    /// \return
    ///
    QString version() { return _version; }
    ///
    /// \brief statusMessage статусное сообщение
    /// \return
    ///
    QString statusMessage() { return _statusMessage; }

private:
    void parse();

    IHTTPRequest *_request;
    QString _raw, _version, _statusMessage;
    int _status;
};

#endif // HTTPRESPONSE_H
