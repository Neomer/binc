#include "SSDPRequest.h"
/*
"01-nls" => "bde3d1e1c805ff3dc6a2d0da3d8e072d"
"cache-control" => "max-age=1800"
"ext" => ""
"location" => "http://192.168.18.67:2869/upnphost/udhisapi.dll?content=uuid:b82a7e13-6cf1-45d5-9da4-6d9f55379e6c"
"opt" => "\"http://schemas.upnp.org/upnp/1/0/\"; ns=01"
"server" => "Microsoft-Windows/6.3 UPnP/1.0 UPnP-Device-Host/1.0"
"st" => "urn:schemas-upnp-org:device:InternetGatewayDevice:1"
"usn" => "uuid:b82a7e13-6cf1-45d5-9da4-6d9f55379e6c::urn:schemas-upnp-org:device:InternetGatewayDevice:1"
*/


SSDPRequest::SSDPRequest() :
    IHTTPRequest()
{
    setUrl(QUrl("SSDP://239.255.255.250:1900"));
}

void SSDPRequest::setAction(QString value)
{
    setHeader("SOAPAction", "\"urn:schemas-upnp-org:service:WANIPConnection:1#" + value + "\"");
}

QString SSDPRequest::compile()
{
    return methodName() + " * HTTP/1.1\r\n" +
           "Host: " + getUrl().host() + ":" + QString::number(getUrl().port(1900)) + "\r\n" +
           "ST:urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n" +
           "Man:\"ssdp:discover\"\r\n" +
           "MX:3\r\n" +
           "\r\n";
}
