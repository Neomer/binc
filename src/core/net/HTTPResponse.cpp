#include "HTTPResponse.h"


HTTPResponse::HTTPResponse(IHTTPRequest *request, QByteArray reply)
{
    _request = request;
    _raw = QString::fromUtf8(reply);
}

void HTTPResponse::parse()
{
    QString row;

    row = _raw.left(_raw.indexOf('\n')).trimmed();

}
