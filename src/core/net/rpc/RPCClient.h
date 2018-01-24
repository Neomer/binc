#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <model/NodeCollectionModel.h>
#include <core/ISubject.h>

///
/// \brief RPCClient класс осуществляет запрос с удаленных нодов с помощью RPC списка известных нодов.
/// При успешном получении списка отбрасывает ранее известные ноды. Список нодов сохраняется/читается из файла.
///
class RPCClient : public ISubject
{
public:
    RPCClient();

    void load(QString filename);
    void unload();

    NodeCollectionModel &getNodes() { return _nodes; }

private:
    NodeCollectionModel _nodes;
    QString _filename;
};

#endif // RPCCLIENT_H
