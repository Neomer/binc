#include "Block.h"

Block::Block() :
    JsonSerializableEntity("Block"),
    _creation_time(QDateTime::currentDateTime()),
    _nonce(0)
{

}

void Block::toJsonObject(QJsonObject &out)
{
    JsonSerializableEntity::toJsonObject(out);
    out["id"] = getId().toString();
    out["version"] = _version.toString();
    out["prev"] = _previous_block.toString();
    out["creationTime"] = _creation_time.toString("yyyy-MM-ddThh:mm:ss");
    out["nonce"] = _nonce;
}

void Block::fromJsonObject(QJsonObject &in)
{
    JsonSerializableEntity::fromJsonObject(in);
    setId(Guid::fromString(in["id"].toString()));
    _version = Version(in["version"].toString());
    _previous_block = Guid::fromString(in["prev"].toString());
    _creation_time = QDateTime::fromString(in["creationTime"].toString(), "yyyy-MM-ddThh:mm:ss");
    _nonce = in["nonce"].toInt();
    //_hash = Hash::fromString(in["hash"].toString());
}

void Block::toDataStream(QDataStream &out)
{
    out << getId();
    out << _version;
    out << _previous_block;
    out << _creation_time;
    out << _nonce;
}

void Block::fromDataStream(QDataStream &in)
{
    Guid id;

    in >> id;
    in >> _version;
    in >> _previous_block;
    in >> _creation_time;
    in >> _nonce;

    setId(id);
}
