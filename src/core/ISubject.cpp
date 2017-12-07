#include <core/ISubject.h>

ISubject::ISubject()
{
	_list.Clear();
}

ISubject::~ISubject()
{
	_list.Clear();
}

void ISubject::subscribe(IObserver *observer)
{
	_list << observer;
}

void ISubject::unsubscribe(IObserver *observer)
{
	_list.takeOne(observer);
}

