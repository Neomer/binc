#ifndef BLOCK_H
#define BLOCK_H

#include <QList>
#include <QDateTime>

#include "IModelWithId.h"
#include <core/types/Guid.h>
#include <core/types/Version.h>
#include <model/Deal.h>

///
/// \brief The Block модель данных, представляющая одиночный блок
///
class Block : public IModelWithId
{
public:
    Block();

    void addDeal(Deal *value) { _deals << value; }

    Version getVersion() { return _version; }
    void setVersion(Version value) { _version = value; }

    Guid getPreviousBlock() { return _previous_block; }
    void setPreviousBlock(Guid value) { _previous_block = value; }

    QDateTime getCreationTime() { return _creation_time; }
    void setCreationTime(QDateTime value) { _creation_time = value; }

    int getNonce() { return _nonce; }
    void setNonce(quint64 value) { _nonce = value; }

    Hash getHash() { return _hash; }

    // IJsonSerializable interface
public:
    void serialize(QJsonObject &out) override;
    void deserialize(QJsonObject &in) override;

private:
    Version _version;
    Guid _previous_block;
    QDateTime _creation_time;
    QList<Deal *> _deals;
    int _nonce;
    Hash _hash;
};

#endif // BLOCK_H
