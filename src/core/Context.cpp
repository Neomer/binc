#include "Context.h"
#include <database/DatabaseException.h>

void Context::init(QString filename)
{
    Q_UNUSED(filename);
    try
    {
        _database->open();
    }
    catch (DatabaseException &ex)
    {
        throw std::runtime_error(ex.what());
    }
    _isInit = true;
}

Context::Context() :
    _isInit(false)
{
    _database = new Database();
}

Context::~Context()
{
    delete _database;
}
