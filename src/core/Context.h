#ifndef CONTEXT_H
#define CONTEXT_H

#include <QMutex>

#include <core/ContextException.h>
#include <core/ConsoleInput.h>
#include <core/Settings.h>
#include <database/Database.h>
#include <model/RPCServerCollectionModel.h>

///
/// \brief The Context class хранит глобальные ресурсы используемые разными модулями программы.
/// Класс реализован в виде singleton'а. Чтобы получить экземпляр класса необходимо исопльзовать
/// метод Context::Instance()
class Context
{
public:
    ///
    /// \brief Instance возвращает статический экземпляр класса
    /// \return
    ///
    static Context& Instance()
    {
        static Context s;
        return s;
    }

    Database *database() { return _database; }
    ConsoleInput * consoleInput() const { return _consoleInput; }
    Settings *settings() { return &_sets; }

    ///
    /// \brief getNodes возвращает список известных узлов сети. Потокобезопасно.
    /// \return
    ///
    NodeCollectionModel getNodes();
    ///
    /// \brief updateNodes добавляет в список известных узлов сети новые. Потокобезопасно.
    /// \param nodes
    ///
    void updateNodes(NodeCollectionModel &nodes);
    ///
    /// \brief getRpcServers возвращает список известных RPC-серверов
    /// \return
    ///
    RPCServerCollectionModel &getRpcServers() { return _rpc_servers; }
    ///
    /// \brief load загружает среду выполнения приложения, настройки и пр.
    /// \param settings Файл конфигурации
    ///
    void load(QString settings);
    void unload();

private:
    Context();
    ~Context();
    Context & operator=(const Context &other);

    Database *_database;

    bool _isInit;
    ConsoleInput *_consoleInput;
    Settings _sets;
    RPCServerCollectionModel _rpc_servers;
    NodeCollectionModel _nodes;
    QMutex _mtx_lock_nodes;
};


#endif // CONTEXT_H
