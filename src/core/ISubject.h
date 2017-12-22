#ifndef	_ISUBJECT_H_
#define	_ISUBJECT_H_

#include <QList>
#include <core/types/Guid.h>
#include "IObserver.h"

class ISubject
{
public:
	ISubject();
	~ISubject();
	void subscribe(IObserver *observer);
	void unsubscribe(IObserver *observer);
    void update(void *data);
    ///
    /// \brief guid уникальный идентификатор
    /// \return
    ///
    const Guid &guid() { return _guid; }

private:
	QList<IObserver *> _list;
    Guid _guid;
};

#endif
