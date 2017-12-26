#ifndef CONTEXT_H
#define CONTEXT_H

#include <database/Database.h>
#include "ConsoleInput.h"

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

    void load();
    void unload();

private:
    Context();
    ~Context();
    Context & operator=(const Context &other);

    Database *_database;
    bool _isInit;
    ConsoleInput *_consoleInput;
};

#endif // CONTEXT_H
