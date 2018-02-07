#ifndef NODELISTRPCCONTROLLER_H
#define NODELISTRPCCONTROLLER_H

#include <core/net/rpc/controllers/IAbstractRpcController.h>

class NodeListRpcController : public IAbstractRpcController
{
public:
    NodeListRpcController();

    // IAbstractRpcController interface
public:
    void exec(HTTPResponse *response) override;
    QString getControllerName() override { return "nodes"; }
};

#endif // NODELISTRPCCONTROLLER_H
