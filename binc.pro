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
    src/database/Database.cpp \
    src/database/IDatabaseObject.cpp \
    src/database/DatabaseException.cpp \
    src/database/IDatabaseIndex.cpp \
    src/database/IDatabaseIndexResult.cpp \
    src/database/DatabaseBinaryTreeIndex.cpp \
    src/core/Context.cpp \
    src/database/DatabaseBinaryTreeIndexRoot.cpp \
    src/database/DatabaseFile.cpp \
    src/database/DatabaseFileException.cpp \
    src/database/DatabaseDataFile.cpp \
    src/database/DatabaseIndexFile.cpp \
    src/database/IDatabaseData.cpp \
    src/database/IDatabaseFileCollection.cpp \
    src/database/IDatabaseDataBlock.cpp \
    src/database/DatabaseIndexHeader.cpp \
    src/database/DatabaseIndexRecord.cpp \
    src/database/DatabaseDataFileHeader.cpp \
    src/database/DatabaseDataFileRecord.cpp

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
    src/database/Database.h \
    src/database/IDatabaseObject.h \
    src/database/DatabaseException.h \
    src/database/IDatabaseIndex.h \
    src/database/DatabaseGeneral.h \
    src/database/IDatabaseIndexResult.h \
    src/database/DatabaseBinaryTreeIndex.h \
    src/core/Context.h \
    src/database/DatabaseBinaryTreeIndexRoot.h \
    src/database/DatabaseFile.h \
    src/database/DatabaseFileException.h \
    src/database/DatabaseDataFile.h \
    src/database/DatabaseIndexFile.h \
    src/database/IDatabaseData.h \
    src/database/IDatabaseFileCollection.h \
    src/database/IDatabaseDataBlock.h \
    src/database/DatabaseIndexHeader.h \
    src/database/DatabaseIndexRecord.h \
    src/database/DatabaseDataFileHeader.h \
    src/database/DatabaseDataFileRecord.h


INCLUDEPATH += $$PWD/src

OBJECTS_DIR = tmp
MOC_DIR = tmp
