#include "Block.h"

Block::Block()
{

}

void Block::serialize(QJsonObject &out)
{
    out["id"] = _block_id.toString();
    out["version"] = _version.toString();
    out["prev"] = _previous_block.toString();
    QJsonArray a;
    foreach (Deal *n, _deals)
    {
        QJsonObject o;
        n->serialize(o);
        a << o;
    }
    out["deals"] = a;
}

void Block::deserialize(QJsonObject &in)
{
    _block_id.fromString(in["id"].toString());
    _version = Version(in["version"].toString());
    _previous_block.fromString(in["prev"].toString());
}
