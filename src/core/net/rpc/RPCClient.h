#ifndef RPCCLIENT_H
#define RPCCLIENT_H

#include <QThread>
#include <model/NodeCollectionModel.h>

///
/// \brief RPCClient класс осуществляет запрос с удаленных нодов с помощью RPC списка известных нодов.
/// При успешном получении списка отбрасывает ранее известные ноды. Список нодов сохраняется/читается из файла.
///
class RPCClient : public QThread
{
    Q_OBJECT

public:
    RPCClient();

    ///
    /// \brief updateNodes обновляет список известных нодов
    ///
    void updateNodes();

    // QThread interface
protected:
    void run() override;
};

#endif // RPCCLIENT_H
