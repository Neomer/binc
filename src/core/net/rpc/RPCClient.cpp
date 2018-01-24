#include "RPCClient.h"
#include <core/StringUtils.h>

RPCClient::RPCClient()
{
}

void RPCClient::load(QString filename)
{
    _filename = filename;
    IJsonSerializable::fromFile(&_nodes, filename);
}

void RPCClient::unload()
{
    if (!StringUtils::IsNullOrEmpty(_filename))
    {
        IJsonSerializable::toFile(&_nodes, _filename);
    }
}
