#ifndef CONTEXT_H
#define CONTEXT_H

#include <database/Database.h>


///
/// \brief The Context class хранит глобальные ресурсы используемые разными модулями программы.
/// Класс реализован в виде singleton'а. Чтобы получить экземпляр класса необходимо исопльзовать
/// метод Context::Instance()
///
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

    ///
    /// \brief init инициализирует контекст, загружает файл настроек
    /// \param filename имя файла конфигурации
    ///
    void init(QString filename);

    bool isInit() { return _isInit; }

    Database *database() { return _database; }

private:
    Context();
    ~Context();
    Context & operator=(const Context &other);

    Database *_database;
    bool _isInit;
};

#endif // CONTEXT_H
