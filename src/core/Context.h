#ifndef CONTEXT_H
#define CONTEXT_H

#include "ConsoleInput.h"

///
/// \brief The Context class класс предоставляет доступ к общим ресурсам
///
class Context
{
public:
    static Context& Instance()
    {
        static Context i;
        return i;
    }
    ConsoleInput * consoleInput() const { return _consoleInput; }

    void load();
    void unload();

private:
    Context();
    ~Context();
    Context& operator =(const Context&);

    ConsoleInput *_consoleInput;
};

#endif // CONTEXT_H
