#include "HTTPgetRequest.h"

HTTPgetRequest::HTTPgetRequest() :
    HTTPRequest()
{
    _query.clear();
}

void HTTPgetRequest::setQuery(QString value)
{
    _query = value;
}

