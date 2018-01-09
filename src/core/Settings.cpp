#include "Settings.h"
#include <QFile>

Settings::Settings() :
    _rpc_port(15698)
{

}

Settings::~Settings()
{

}

void Settings::load(QString filename)
{
    QFile file(filename);
    if (!file.exists())
    {
        //throw ContextException("Configuration file not found!");
        // creating default configuration file
        if (!file.open(QIODevice::WriteOnly))
        {
            throw ContextException("Configuration file access failed!");
        }
        _stream.setDevice(&file);
        save();
        file.close();
    }
    if (!file.open(QIODevice::ReadWrite))
    {
        throw ContextException("Configuration file access failed!");
    }
    _stream.setDevice(&file);
    deserialize(_stream);
}

void Settings::save()
{
    serialize(_stream);
}

void Settings::serialize(QDataStream &out)
{
    out << (quint16) _rpc_port;
}

void Settings::deserialize(QDataStream &in)
{
    in >> _rpc_port;
}
