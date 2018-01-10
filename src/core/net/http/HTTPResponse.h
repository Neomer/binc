#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "HTTPRequest.h"
#include <core/types/Version.h>
#include <QStringList>

class HTTPResponse : public IHTTPMessage
{
public:
    HTTPResponse(HTTPRequest *request, QByteArray reply);
    HTTPResponse(HTTPRequest *request);
    HTTPRequest *request() { return _request; }

    ///
    /// \brief status Статус HTTP ответа
    /// \return
    ///
    int status() { return _status; }
    ///
    /// \brief setStatus устанавливает статус ответа
    /// \param value
    ///
    void setStatus(int value) { _status = value; }

    ///
    /// \brief statusMessage статусное сообщение
    /// \return
    ///
    QString statusMessage() { return _statusMessage; }
    ///
    /// \brief setStatusMessage устанавливает статусное сообщение
    /// \param value
    ///
    void setStatusMessage(QString value) { _statusMessage = value; }

private:

    HTTPRequest *_request;
    QString _raw, _statusMessage;
    int _status;

    // INetMessageWithHeaders interface
protected:
    QString statusRow() override;
    void parseStatusRow(QString data) override;
    void postParseActions() override;
};

#endif // HTTPRESPONSE_H
