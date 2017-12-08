#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QString>
#include <QUrl>
#include <QMap>

class IHTTPRequest
{
public:
    virtual QString methodName() = 0;
    virtual QString compile() = 0;

    void setUrl(QUrl value);
    QUrl getUrl();

    void setHeader(QString name, QString value);

protected:
    IHTTPRequest();
    QString compileHeaders();
    QMap<QString, QString> _headers;

private:
    QUrl _url;
};

#endif // HTTPREQUEST_H
