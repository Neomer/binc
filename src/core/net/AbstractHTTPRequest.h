#ifndef ABSTRACTHTTPREQUEST_H
#define ABSTRACTHTTPREQUEST_H

#include "IHTTPRequest.h"
#include <QMap>

///
/// \brief The AbstractHTTPRequest class класс для парсинга входящих HTTP-запросов
///
class AbstractHTTPRequest : public IHTTPRequest
{
public:
    AbstractHTTPRequest();

    ///
    /// \brief parse Функция парсит полученный HTTP-запрос
    /// \param data
    ///
    void parse(QByteArray data);

    // IHTTPRequest interface
public:
    QString methodName() override { return _method; }
    QString compile() override { return ""; }

private:
    QString _method;
};

#endif // ABSTRACTHTTPREQUEST_H
