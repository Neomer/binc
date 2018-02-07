#include "RPCRequest.h"
#include <core/StringUtils.h>

RPCRequest::RPCRequest()
{

}

QString RPCRequest::getAction()
{
    QString path = getUrl().path();
    if (StringUtils::IsNullOrEmpty(path))
    {
        return path;
    }
    int l = qMin(path.indexOf('/', 1), path.length());
    return path.mid(1, l - 1);
}
