#ifndef	_ISUBJECT_H_
#define	_ISUBJECT_H_

#include <QList>
#include <QVariant>
#include "IObserver.h"

class ISubject
{
public:
	ISubject();
	~ISubject();
	void subscribe(IObserver *observer);
	void unsubscribe(IObserver *observer);
    void update(QVariant data);
	
private:
	QList<IObserver *> _list;
};

#endif
