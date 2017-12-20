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
    src/core/net/NetDataStreamException.cpp \
    src/core/net/HTTPClient.cpp \
    src/core/net/HTTPResponse.cpp \
    src/core/net/IHTTPRequest.cpp \
    src/core/net/HTTPgetRequest.cpp \
    src/core/net/HTTPParsingException.cpp \
    src/core/net/HTTPUdpClient.cpp \
    src/core/net/SSDPRequest.cpp \
    src/core/net/SSDPProvider.cpp \
    src/core/net/UdpStream.cpp \
    src/core/DataStreamException.cpp \
    src/core/net/UdpStreamException.cpp \
    src/core/IDataBlock.cpp

HEADERS += \
            src/core/IData.h \
            src/core/IObserver.h \
            src/core/ISubject.h \
    src/core/net/NetDataStream.h \
    src/core/net/PortMapping.h \
    src/core/IDataStream.h \
    src/core/net/NetDataStreamException.h \
    src/core/net/HTTPClient.h \
    src/core/net/HTTPResponse.h \
    src/core/net/IHTTPRequest.h \
    src/core/net/HTTPgetRequest.h \
    src/core/net/HTTPParsingException.h \
    src/core/net/HTTPUdpClient.h \
    src/core/net/SSDPRequest.h \
    src/core/net/SSDPProvider.h \
    src/core/net/UdpStream.h \
    src/core/DataStreamException.h \
    src/core/net/UdpStreamException.h \
    src/core/IDataBlock.h


INCLUDEPATH += $$PWD/src

OBJECTS_DIR = tmp
MOC_DIR = tmp
