#include "Context.h"

void Context::load(QString settings)
{
    _sets.load(settings);
    _consoleInput = new ConsoleInput();
    _consoleInput->start();
    _database = new Database();
    _database->open();
}

void Context::unload()
{
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
