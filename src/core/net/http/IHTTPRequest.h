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
class IHTTPRequest : public IHTTPMessage
{
public:
    IHTTPRequest();

    ///
    /// \brief methodName Виртуальный метод. Реализующий класс, должен вернуть текстовое предаствление метода HTTP-запроса.
    /// \return
    ///
    virtual QString methodName() = 0;

    QUrl getUrl() { return _url; }
    void setUrl(QUrl value) { _url = value; }

    // INetMessageWithHeaders interface
protected:
    QString statusRow() override;
    void parseStatusRow(QString data) override;

private:
    QUrl _url;
};

#endif // HTTPREQUEST_H
