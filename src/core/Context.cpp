#include "Context.h"
#include <QDateTime>

void Context::load(QString settings)
{
    // Настройки должны грузиться раньше всего остального!
    _sets.load(settings);

    _database = new Database();
    _database->open();

    _consoleInput = new ConsoleInput();
    _consoleInput->start();

    _net.connect();

    _rpc_servers.servers().append(new RPCServerModel(ConnectionPoint(QHostAddress("127.0.0.1"), 15698)));
}

void Context::unload()
{
    _sets.save();
    _sets.close();
    _consoleInput->terminate();
    _database->close();
}

Context::Context()
{

}

Context::~Context()
{
    _consoleInput->terminate();
}
