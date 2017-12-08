#include <core/ISubject.h>

ISubject::ISubject()
{
    _list.clear();
}

ISubject::~ISubject()
{
    _list.clear();
}

void ISubject::subscribe(IObserver *observer)
{
	_list << observer;
}

void ISubject::unsubscribe(IObserver *observer)
{
    _list.removeOne(observer);
}

void ISubject::update(QVariant data)
{
    foreach (IObserver *o, _list)
    {
        o->update(data);
    }
}

