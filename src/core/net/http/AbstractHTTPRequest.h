#ifndef ABSTRACTHTTPREQUEST_H
#define ABSTRACTHTTPREQUEST_H

#include "IHTTPRequest.h"
#include <QMap>

///
/// \brief The AbstractHTTPRequest class класс для парсинга входящих HTTP-запросов
///
class AbstractHTTPRequest : public HTTPRequest
{
public:
    AbstractHTTPRequest();

private:
    QString _method;
};

#endif // ABSTRACTHTTPREQUEST_H
