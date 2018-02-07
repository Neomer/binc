#include "NodeListRpcController.h"
#include <model/NodeCollectionModel.h>
#include <core/Context.h>

NodeListRpcController::NodeListRpcController()
{

}

void NodeListRpcController::exec(HTTPResponse *response)
{
    NodeCollectionModel nodes = Context::Instance().getNodes();
    static_cast<RPCResponse *>(response)->setContent(IJsonSerializable::toString(&nodes));
}
