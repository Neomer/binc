#include "Context.h"
#include <QDateTime>

void Context::load(QString settings)
{
    _sets.load(settings);
    _database = new Database();
    _database->open();

    _rpc_server = new RPCServer();
    _rpc_server->start();

    _consoleInput = new ConsoleInput();
    _consoleInput->start();
}

void Context::unload()
{
    _sets.save();
    _sets.close();
    _consoleInput->terminate();
    _rpc_server->stop();
    _database->close();
}

Context::Context()
{
    srand(QDateTime::currentDateTime().currentMSecsSinceEpoch());
}

Context::~Context()
{
    _consoleInput->terminate();
}
