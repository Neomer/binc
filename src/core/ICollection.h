#ifndef ICOLLECTION_H
#define ICOLLECTION_H

///
/// ICollection<T> интерфейс, представляющий коллекцию данных неопределенного типа.
///
template<class  T>
class ICollection
{
public:
    ///
    /// \brief first возвращает первый элемент коллекции
    /// \return
    ///
    virtual T first() = 0;
    ///
    /// \brief last возвращает последний элемент коллекции
    /// \return
    ///
    virtual T last() = 0;
    ///
    /// \brief get возвращает элемент коллекции с позицией index (начинается с 0)
    /// \param index номер элемента коллекции
    /// \return
    ///
    virtual T get(int index) = 0;
    ///
    /// \brief add добавляет элемент в коллекцию
    /// \param item элемент коллекции
    ///
    virtual void add(T item) = 0;
    ///
    /// \brief add добавляет группу элементов в коллекцию
    /// \param items коллекция элементов
    ///
    virtual void add(ICollection<T> &items) = 0;
    ///
    /// \brief add добавляет элемент в коллекцию на позицию следующую за позицией after
    /// \param item элемент коллекции
    /// \param after
    ///
    virtual void add(T item, int after) = 0;
    ///
    /// \brief remove удаляет элемент коллекции с номером index
    /// \param index номер элемента коллекции
    ///
    virtual void remove(int index) = 0;
    ///
    /// \brief count количество элементов коллекции
    /// \return
    ///
    virtual int count() = 0;
};

#endif // ICOLLECTION_H
