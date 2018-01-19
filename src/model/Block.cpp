#include "Block.h"

Block::Block() :
    IIdentifyed(),
    SerializableEntity("Block"),
    _creation_time(QDateTime::currentDateTime()),
    _nonce(0)
{

}

void Block::serialize(QJsonObject &out)
{
    SerializableEntity::serialize(out);
    out["id"] = getId().toString();
    out["version"] = _version.toString();
    out["prev"] = _previous_block.toString();
    out["creationTime"] = _creation_time.toString("yyyy-MM-ddThh:mm:ss");
    out["nonce"] = _nonce;
}

void Block::deserialize(QJsonObject &in)
{
    SerializableEntity::deserialize(in);
    setId(Guid::fromString(in["id"].toString()));
    _version = Version(in["version"].toString());
    _previous_block = Guid::fromString(in["prev"].toString());
    _creation_time = QDateTime::fromString(in["creationTime"].toString(), "yyyy-MM-ddThh:mm:ss");
    _nonce = in["nonce"].toInt();
    //_hash = Hash::fromString(in["hash"].toString());
}
