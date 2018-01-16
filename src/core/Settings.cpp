#include "Settings.h"
#include <QFile>

Settings::Settings() :
    _rpc_port(15698)
{

}

Settings::~Settings()
{
    _file.close();
}

void Settings::load(QString filename)
{
    QFile _file(filename);
    if (!_file.exists())
    {
        //throw ContextException("Configuration file not found!");
        // creating default configuration file
        if (!_file.open(QIODevice::WriteOnly))
        {
            throw ContextException("Configuration file access failed!");
        }
        save();
        _file.close();
    }
    if (!_file.open(QIODevice::ReadWrite))
    {
        throw ContextException("Configuration file access failed!");
    }
    try
    {
        IJsonSerializable::fromString(this, _file.readAll());
    }
    catch (BaseException &ex)
    {
        qDebug() << "Configuration file corrupted!" << ex.what();
    }
}

void Settings::save()
{
    QJsonObject obj;
    serialize(obj);
    _file.write(IJsonSerializable::toString(this).toUtf8());
    _file.flush();
}

void Settings::serialize(QJsonObject &out)
{
    out["rpc_port"] = _rpc_port;

    QJsonObject objNodes;
    _nodes.serialize(objNodes);
    out["nodes"] = objNodes;
}

void Settings::deserialize(QJsonObject &in)
{
    _rpc_port = in["rpc_port"].toInt(15698);

    QJsonObject objNodes = in["nodes"].toObject();
    _nodes.deserialize(objNodes);
}
