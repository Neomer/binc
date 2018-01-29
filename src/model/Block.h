#ifndef BLOCK_H
#define BLOCK_H

#include <QList>
#include <QDateTime>

#include <core/JsonSerializableIdentifyedEntity.h>
#include <core/IIdentifyed.h>
#include <core/types/Guid.h>
#include <core/types/Version.h>
#include <model/Deal.h>
#include <model/IBlockData.h>
#include <database/IDatabaseWritable.h>

///
/// \brief The Block модель данных, представляющая одиночный блок.
///
class Block : public JsonSerializableIdentifyedEntity, public IDatabaseWritable
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
    ///
    /// \brief addData Добавляет данные в блок
    /// \param value
    ///
    void addData(IBlockData *value) { _data << value; }
    ///
    /// \brief getVersion возвращает версию протокола блока
    /// \return
    ///
    Version getVersion() { return _version; }
    ///
    /// \brief setVersion устанавливает версию протокола блока
    /// \param value
    ///
    void setVersion(Version value) { _version = value; }
    ///
    /// \brief getPreviousBlock возвращает идентификатор предыдущего блока
    /// \return
    ///
    Guid getPreviousBlock() { return _previous_block; }
    ///
    /// \brief setPreviousBlock устанавливает идентификатор предыдущего блока
    /// \param value
    ///
    void setPreviousBlock(Guid value) { _previous_block = value; }
    ///
    /// \brief getCreationTime возвращает дату/время создания блока
    /// \return
    ///
    QDateTime getCreationTime() { return _creation_time; }
    ///
    /// \brief setCreationTime устанавливает дату/время создания блока
    /// \param value
    ///
    void setCreationTime(QDateTime value) { _creation_time = value; }
    ///
    /// \brief getNonce возвращает
    /// \return
    ///
    int getNonce() { return _nonce; }
    ///
    /// \brief setNonce устанавливает
    /// \param value
    ///
    void setNonce(quint64 value) { _nonce = value; }

    Hash getHash() { return _hash; }

    // IJsonSerializable interface
public:
    void toJsonObject(QJsonObject &out) override;
    void fromJsonObject(QJsonObject &in) override;

    // IBinarySerializable interface
public:
    void toDataStream(QDataStream &out) override;
    void fromDataStream(QDataStream &in) override;
};

#endif // BLOCK_H
