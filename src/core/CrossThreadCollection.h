#ifndef CROSSTHREADCOLLECTION_H
#define CROSSTHREADCOLLECTION_H

#include <core/ICollection.h>
#include <QMutex>

///
/// \brief CrossThreadCollection класс реализующий потокобезопасное добавление и чтение данных из коллекции
///
template<class T> class CrossThreadCollection : public ICollection<T>
{
public:
    CrossThreadCollection();
    CrossThreadCollection(const CrossThreadCollection<T> &other);

    ///
    /// \brief getAll потокобезопасное получение копии коллекции
    /// \return
    ///
    ICollection<T> getAll();
    ///
    /// \brief add потокобезопасный вариант метода из ICollection
    /// \param item
    ///
    void add(T item);
    void add(ICollection<T> &collection);
    void add(T item, int after);

private:
    QMutex _mtx_lock;
};

#endif // CROSSTHREADCOLLECTION_H
