#ifndef CONTEXT_H
#define CONTEXT_H

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

    void init();

private:
    Context();
    ~Context();
    Context& operator =(const Context&);
};

#endif // CONTEXT_H
