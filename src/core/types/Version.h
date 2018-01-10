#ifndef VERSION_H
#define VERSION_H

#include <QString>
#include <core/BaseException.h>

///
/// \brief The Version class класс для представления версии.
/// Поддерживаемые форматы версий:
///   - 1.3.24b
///   - 1.1
///   - 1.1.2-alpha
///   - 1.1.4 alpha
class Version
{
public:
    enum VersionStage
    {
        enVersionPreAlpha = 0,
        enVersionAlpha,
        enVersionBeta,
        enVersionReleaseCandidate,
        enVersionStageEmpty,
    };

    Version();
    Version(const Version &other);
    ///
    ///\brief Version создает экземпляр класса Version из текстового предаствления версии
    /// \param data
    ///
    Version(QString data);
    ///
    /// \brief Version создает экземпляр класса Version с указанными значенинями major, minor, maintance и stage
    /// \param major
    /// \param minor
    /// \param maintance
    /// \param stage
    ///
    Version(int major, int minor, int maintance = 0, VersionStage stage = enVersionStageEmpty);


    int major() { return _major; }
    void setMajor(int value) { _major = value; }

    int minor() { return _minor; }
    void setMinor(int value) { _minor = value; }

    int maintance() { return _maintenance; }
    void setMaintance(int value) { _maintenance = value; }

    void setStage(VersionStage value) { _stage = value; }

    QString stageShort();
    QString stageFull();


    ///
    /// \brief toString представляет значение номера версии в текстовом виде
    /// \return
    ///
    QString toString();
    ///
    /// \brief toString представляет значение номера версии в текстовом виде
    /// \param format формат:
    /// J - major версия
    /// N - minor версия
    /// T - maintance версия
    /// S - стадия выпуска в сокращенном виде (a, b, pre-a и т.д.)
    /// SS - стадия выпуска в полном виде (alpha, beta, pre-alpha и т.д.)
    /// \return
    ///
    QString toString(QString format);

    // Operators
    bool operator ==(const Version &other);
    Version &operator =(const Version &other);

    bool operator <(const Version &other);
    bool operator >(const Version &other);

    friend QDataStream &operator <<(QDataStream &stream, const Version &object);
    friend QDataStream &operator >>(QDataStream &stream, Version &object);



private:
    int _major, _minor, _maintenance;
    VersionStage _stage;
};

#endif // VERSION_H
