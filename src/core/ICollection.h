#ifndef ICOLLECTION_H
#define ICOLLECTION_H

template<class T>
class ICollection
{
public:
    virtual T first() = 0;
    virtual T last() = 0;
    virtual T get(int index) = 0;
    virtual void add(T item) = 0;
    virtual void add(T item, int after) = 0;
    virtual void remove(int index) = 0;
    virtual int count() = 0;
};

#endif // ICOLLECTION_H
