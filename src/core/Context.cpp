#include "Context.h"

void Context::init()
{
    _consoleInput = new ConsoleInput();
    _consoleInput->start();
}

Context::Context()
{
}

Context::~Context()
{
    _consoleInput->terminate();
}
