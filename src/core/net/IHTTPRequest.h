#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QString>
#include <QUrl>
#include <QMap>
#include "HTTPParsingException.h"

///
/// \brief The IHTTPRequest class Интерфейс для создания и обработки HTTP-запроса
///
class IHTTPRequest
{
public:
    ///
    /// \brief methodName Виртуальный метод. Реализующий класс, должен вернуть текстовое предаствление метода HTTP-запроса.
    /// \return
    ///
    virtual QString methodName() = 0;
    ///
    /// \brief compile Виртуальный метод. Реализующий класс, должен вернуть корректный, готовый к отправке HTTP-запрос.
    /// \return
    ///
    virtual QString compile() = 0;
    ///
    /// \brief setUrl устанавливает url для запроса
    /// \param value url запроса
    ///
    void setUrl(QUrl value);
    ///
    /// \brief getUrl возвращает установленный url
    /// \return
    ///
    QUrl getUrl();
    ///
    /// \brief setContent устанавливает тело сообщения
    /// \param value
    ///
    void setContent(QString value) { _content = value; }
    ///
    /// \brief getContent возвращает тело сообщения
    /// \return
    ///
    QString getContent() { return _content; }
    ///
    /// \brief setHeader устанавливает пользовательский заголовок запроса
    /// \param name имя заголовка
    /// \param value значение заголовка
    ///
    void setHeader(QString name, QString value);
    ///
    /// \brief getHeader возвращает значение заголовка, или NULL, если заголовка нет
    /// \param name
    /// \return
    ///
    QString getHeader(QString name);

protected:
    IHTTPRequest();
    QString compileHeaders();
    QMap<QString, QString> _headers;
    QString _content;

private:
    QUrl _url;
};

#endif // HTTPREQUEST_H
