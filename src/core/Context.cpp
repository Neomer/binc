#include "Context.h"

void Context::load()
{
    _consoleInput = new ConsoleInput();
    _consoleInput->start();
}

void Context::unload()
{
    _consoleInput->terminate();
}

Context::Context()
{

}

Context::~Context()
{
    _consoleInput->terminate();
}
