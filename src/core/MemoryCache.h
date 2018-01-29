#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H

#include <QList>
#include <QDateTime>
#include <QTimer>

#include <core/ICache.h>

///
/// \brief MemoryCache класс представляющий самоочищающийся список, хранящийся в опреативной памяти.
///
class MemoryCache : public QObject, public ICache
{
    Q_OBJECT

public:
    MemoryCache(int limit = -1);
    ///
    /// \brief setClearInterval устанавливает интервал самоочистки
    /// \param interval
    ///
    void setClearInterval(int interval);
    ///
    /// \brief setTTL устанавливает максимальное время жизни записи в пуле в секундах
    /// \param time
    ///
    void setTTL(int time) { _ttl = time * 1000; }

    // ICache interface
public:
    void add(IIdentifyed *value);
    IIdentifyed *get(Guid id);
    IIdentifyed *first();
    int count();
    IIdentifyed *take(Guid id);
    IIdentifyed *takeFirst();
    void clear();
    bool contains(Guid id);

    MemoryCache &operator <<(IIdentifyed *value);

private slots:
    ///
    /// \brief clearTick очистка кэша
    ///
    void clearTick();

private:
    struct MemoryCacheItem
    {
        QDateTime CreationDate;
        IIdentifyed * Data;
    };
    QList<MemoryCacheItem> _list;
    QTimer _timer;
    int _ttl;
};

#endif // MEMORYCACHE_H
