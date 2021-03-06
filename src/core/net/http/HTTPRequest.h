#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QString>
#include <QUrl>
#include <QMap>
#include "HTTPParsingException.h"
#include "IHTTPMessage.h"

///
/// \brief The IHTTPRequest class Интерфейс для создания и обработки HTTP-запроса
///
class HTTPRequest : public IHTTPMessage
{
public:
    HTTPRequest();
    HTTPRequest(QString method);

    QUrl getUrl() { return _url; }
    void setUrl(QUrl value) { _url = value; }

    QString getMethodName() { return _method; }
    void setMethodName(QString value) { _method = value; }

    // INetMessageWithHeaders interface
protected:
    QString statusRow() override;
    void parseStatusRow(QString data) override;
    void postParseActions() override;

private:
    QUrl _url;
    QString _method;
    QString _path;

};

#endif // HTTPREQUEST_H
