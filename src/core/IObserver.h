#ifndef	_IOBSERVER_H_
#define	_IOBSERVER_H_

#include "IData.h"
#include <core/types/Guid.h>

class IObserver
{
public:
    virtual void update(const Guid &subject, void *data) = 0;
};

#endif
