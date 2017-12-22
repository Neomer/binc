#ifndef	_IOBSERVER_H_
#define	_IOBSERVER_H_

#include "IData.h"
#include <QVariant>

class IObserver
{
public:
    virtual void update(void *subject, void *data) = 0;
};

#endif
