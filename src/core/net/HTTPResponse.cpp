#include "HTTPResponse.h"
#include "NetDataStreamException.h"

HTTPResponse::HTTPResponse(IHTTPRequest *request, QByteArray reply)
{
    _request = request;
    _raw = QString::fromUtf8(reply);
    parse();
}

void HTTPResponse::parse()
{
    QString row;
    int rownum = 0;
    int tmp;
    bool ok;

    row = _raw.left(_raw.indexOf('\n')).trimmed();
    if (rownum == 0)
    {
        if (row.left(4) != "HTTP")
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Неизвестный формат сообщения!");
        }
        tmp = row.indexOf(' ');
        _version = row.mid(5, tmp - 5);
        _status = row.mid(tmp + 1, 3).toInt(&ok);
        if (!ok)
        {
            throw NetDataStreamException(NetDataStreamException::enNDSE_TransferError, "Неизвестный формат сообщения!");
        }
        _statusMessage = row.mid(tmp + 5);
    }
    else
    {

    }
    rownum++;
}
