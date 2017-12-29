#ifndef CONTEXT_H
#define CONTEXT_H

#include "ContextException.h"

#include <database/Database.h>
#include "ConsoleInput.h"
#include "Settings.h"

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
};


#endif // CONTEXT_H
