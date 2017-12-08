/**
  Класс для отправки/получения зарпосов по протоколу HTTP версии 1.1
  */

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "HTTPResponse.h"
#include <QUrl>
#include <QTcpSocket>

class HTTPClient
{
public:
    HTTPClient();

    ///
    /// \brief get отправляет GET-запрос по указанному url. Функция работает в основном потоке!
    /// \param url Адрес
    /// \return
    ///
    static HTTPResponse get(QUrl &url);
};

#endif // HTTPCLIENT_H
