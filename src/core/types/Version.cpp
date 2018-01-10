#include "Version.h"
#include <core/StringUtils.h>
#include <QRegExp>

Version::Version() :
    _major(0),
    _minor(0),
    _maintenance(0),
    _stage(enVersionStageEmpty)
{

}

Version::Version(const Version &other) :
    _major(other._major),
    _minor(other._minor),
    _maintenance(other._maintenance),
    _stage(other._stage)
{

}

Version::Version(QString data) :
    _major(0),
    _minor(0),
    _maintenance(0),
    _stage(enVersionStageEmpty)
{
    data = StringUtils::TrimEx(data);
    if (!StringUtils::IsVersion(data))
    {
        throw std::runtime_error("Unsupported version format!");
    }
    bool ok = true;
    int s = data.indexOf(QRegExp("[\\.\\s\\-]")), s1;
    if (s < 0) s = data.length();
    _major = data.left(s).toInt(&ok);
    if (!ok) throw std::runtime_error("Unsupported version format!");
    s1 = s; s = data.indexOf(QRegExp("[\\.\\s\\-]"), s + 1);
    if (s < 0) s = data.length();
    if (s != s1) _minor = data.mid(s1 + 1, s - s1 - 1).toInt(&ok);
    if (!ok) throw std::runtime_error("Unsupported version format!");
    s1 = s; s = data.indexOf(QRegExp("[\\.\\s\\-]"), s + 1);
    if (s < 0) s = data.length();
    if (s != s1) _maintenance = data.mid(s1 + 1, s - s1 - 1).toInt(&ok);
    if (!ok) throw std::runtime_error("Unsupported version format!");
    if (s < data.length())
    {
        QRegExp stageExp("pre-alpha|alpha|beta|rc|pre-a|a|b");
        int idx = stageExp.indexIn(data, s);
        if (idx > 0)
        {
            QString sStage = data.mid(idx, stageExp.matchedLength());
            if (sStage == "pre-alpha" || sStage == "pre-a") _stage = enVersionPreAlpha;
            else if (sStage == "alpha" || sStage == "a") _stage = enVersionAlpha;
            else if (sStage == "beta" || sStage == "b") _stage = enVersionBeta;
            else if (sStage == "rc") _stage = enVersionReleaseCandidate;
        }
    }
}

Version::Version(int major, int minor, int maintance, Version::VersionStage stage) :
    _major(major), _minor(minor), _maintenance(maintance), _stage(stage)
{

}

QString Version::stageShort()
{
    switch (_stage)
    {
        case enVersionPreAlpha: return "pre-a";
        case enVersionAlpha: return "a";
        case enVersionBeta: return "b";
        case enVersionReleaseCandidate: return "rc";
        default: return StringUtils::EmptyString();
    }
}

QString Version::stageFull()
{
    switch (_stage)
    {
        case enVersionPreAlpha: return "pre-alpha";
        case enVersionAlpha: return "alpha";
        case enVersionBeta: return "beta";
        case enVersionReleaseCandidate: return "rc";
        default: return StringUtils::EmptyString();
    }
}

QString Version::toString()
{
    return QString::number(_major) + "." + QString::number(_minor) + "." + QString::number(_maintenance) + "-" + stageFull();
}

QString Version::toString(QString format)
{
    return format.replace(QRegExp("J"), QString::number(_major))
                    .replace(QRegExp("N"), QString::number(_minor))
                    .replace(QRegExp("T"), QString::number(_maintenance))
                    .replace(QRegExp("SS"), stageFull())
            .replace(QRegExp("S"), stageShort());
}

bool Version::operator ==(const Version &other)
{
    return _major == other._major && _minor == other._minor && _maintenance == other._maintenance && _stage == other._stage;
}

Version &Version::operator =(const Version &other)
{
    _major = other._major;
    _minor = other._minor;
    _maintenance = other._maintenance;
    _stage = other._stage;
    return *this;
}

bool Version::operator <(const Version &other)
{
    if (_major < other._major) return true; else if (_major > other._major) return false;
    if (_minor < other._minor) return true; else if (_minor > other._minor) return false;
    if (_maintenance < other._maintenance) return true; else if (_maintenance > other._maintenance) return false;
    if (_stage < other._stage) return true; else if (_stage > other._stage) return false;
    return false;
}

bool Version::operator >(const Version &other)
{
    if (_major > other._major) return true; else if (_major < other._major) return false;
    if (_minor > other._minor) return true; else if (_minor < other._minor) return false;
    if (_maintenance > other._maintenance) return true; else if (_maintenance < other._maintenance) return false;
    if (_stage > other._stage) return true; else if (_stage < other._stage) return false;
    return false;
}
