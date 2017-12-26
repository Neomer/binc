#include <core/ISubject.h>

ISubject::ISubject()
{
    _guid = Guid::randomGuid();
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

void ISubject::update(void *data)
{
    foreach (IObserver *o, _list)
    {
        o->update(_guid, data);
    }
}

