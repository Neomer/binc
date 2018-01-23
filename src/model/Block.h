#ifndef BLOCK_H
#define BLOCK_H

#include <QList>
#include <QDateTime>

#include <core/SerializableEntity.h>
#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/types/Version.h>
#include <model/Deal.h>
#include <model/IBlockData.h>

///
/// \brief The Block модель данных, представляющая одиночный блок
///
class Block : public IIdentifyed, public SerializableEntity
{
private:
    Version _version;
    Guid _previous_block;
    QDateTime _creation_time;
    int _nonce;
    Hash _hash;
    QList<IBlockData *> _data;

public:
    Block();

    void addData(IBlockData *value) { _data << value; }

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
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;
};

#endif // BLOCK_H
