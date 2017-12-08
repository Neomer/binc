QT += network

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += src/main.cpp \
            src/core/IObserver.cpp \
            src/core/ISubject.cpp \
    src/core/net/NetDataStream.cpp \
    src/core/net/PortMapping.cpp \
    src/core/IDataStream.cpp \
    src/core/net/NetDataStreamException.cpp

HEADERS += \
            src/core/IData.h \
            src/core/IObserver.h \
            src/core/ISubject.h \
    src/core/net/NetDataStream.h \
    src/core/net/PortMapping.h \
    src/core/IDataStream.h \
    src/core/net/NetDataStreamException.h


INCLUDEPATH += $$PWD/src

OBJECTS_DIR = tmp
MOC_DIR = tmp
