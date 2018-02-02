#include "CrossThreadCollection.h"

template<class T>
CrossThreadCollection<T>::CrossThreadCollection()
{

}

template<class T>
CrossThreadCollection<T>::CrossThreadCollection(const CrossThreadCollection<T> &other)
{

}

template<class T>
ICollection<T> CrossThreadCollection<T>::getAll()
{
    _mtx_lock.lock();
    ICollection<T> ret(*this);
    _mtx_lock.unlock();
    return ret;
}

template<class T>
void CrossThreadCollection<T>::add(T item)
{
    _mtx_lock.lock();
    ICollection<T>::add(item);
    _mtx_lock.unlock();
}

template<class T>
void CrossThreadCollection<T>::add(ICollection<T> &collection)
{
    _mtx_lock.lock();
    ICollection<T>::add(collection);
    _mtx_lock.unlock();
}

template<class T>
void CrossThreadCollection<T>::add(T item, int after)
{
    _mtx_lock.lock();
    ICollection<T>::add(item, after);
    _mtx_lock.unlock();
}
