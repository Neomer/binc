#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "IHTTPRequest.h"
#include <QStringList>

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
    ///
    /// \brief header Возвращает заголовок с указанным именем из HTTP-ответа
    /// \param name Имя заголовка в нижнем регистре
    /// \return
    ///
    QString header(QString name);
    ///
    /// \brief headers возвращает все имена заголовоков в ответе
    /// \return
    ///
    QStringList headers() { return _headers.keys(); }
    ///
    /// \brief content возвращает тело из HTTP-ответа
    /// \return
    ///
    QString content() { return _content; }


private:
    ///
    /// \brief parse Разбирает HTTP-запрос на составляющие
    ///
    void parse();
    ///
    /// \brief formatHeaderValue Удаляет из значений заголовков ненужные символы
    /// \param text
    /// \return
    ///
    QString formatHeaderValue(QString text);

    IHTTPRequest *_request;
    QString _raw, _version, _statusMessage;
    int _status;
    QMap<QString, QString> _headers;
    QString _content;
};

#endif // HTTPRESPONSE_H
