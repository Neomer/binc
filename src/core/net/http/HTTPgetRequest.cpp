#include "HTTPgetRequest.h"

HTTPgetRequest::HTTPgetRequest() :
    IHTTPRequest()
{
    _query.clear();
}

void HTTPgetRequest::setQuery(QString value)
{
    _query = value;
}

