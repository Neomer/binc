#include "IHTTPRequest.h"

IHTTPRequest::IHTTPRequest() :
    IHTTPMessage()
{

}

QString IHTTPRequest::statusRow()
{
    setHeader("Host", getUrl().host() + ":" + QString::number(getUrl().port()));
    return methodName() + " " + _url.path() + " HTTP/" + getVersion().toString("J.N");
}

void IHTTPRequest::parseStatusRow(QString data)
{

}
