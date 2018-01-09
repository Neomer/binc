QT += network

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/main.cpp \
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
    src/database/DatabaseException.cpp \
    src/database/IDatabaseIndex.cpp \
    src/database/DatabaseBinaryTreeIndex.cpp \
    src/database/DatabaseFile.cpp \
    src/database/DatabaseFileException.cpp \
    src/database/DatabaseDataFile.cpp \
    src/database/DatabaseIndexFile.cpp \
    src/database/IDatabaseFileCollection.cpp \
    src/database/IDatabaseDataBlock.cpp \
    src/database/DatabaseIndexHeader.cpp \
    src/database/DatabaseIndexRecord.cpp \
    src/database/DatabaseDataFileHeader.cpp \
    src/database/DatabaseDataFileRecord.cpp \
    src/database/IDatabaseFile.cpp \
    src/database/IDatabaseSequentialAccessFile.cpp \
    src/database/IDatabaseRandomAccessFile.cpp \
    src/database/HeaderDataBlock.cpp \
    src/core/net/UdpStream.cpp \
    src/core/Context.cpp \
    src/core/DataStreamException.cpp \
    src/core/net/UdpStreamException.cpp \
    src/core/IDataBlock.cpp \
    src/core/net/UdpDataBlock.cpp \
    src/core/IHashedDataBlock.cpp \
    src/core/ConsoleInput.cpp \
    src/core/ConsoleInputException.cpp \
    src/core/types/Guid.cpp \
    src/database/IDatabaseData.cpp \
    src/database/DatabaseIndexProvider.cpp \
    src/database/DatabaseDataProvider.cpp \
    tests/chat/Chat.cpp \
    src/core/IBinarySerializable.cpp \
    src/core/Settings.cpp \
    src/core/ContextException.cpp \
    src/core/net/RPCServer.cpp \
    src/core/net/RPCCommunicationThread.cpp \
    src/core/net/AbstractHTTPRequest.cpp \
    src/core/StringUtils.cpp \
    src/core/net/RPCRequest.cpp

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
    src/database/DatabaseException.h \
    src/database/IDatabaseIndex.h \
    src/database/DatabaseGeneral.h \
    src/database/DatabaseBinaryTreeIndex.h \
    src/database/DatabaseFile.h \
    src/database/DatabaseFileException.h \
    src/database/DatabaseDataFile.h \
    src/database/DatabaseIndexFile.h \
    src/database/IDatabaseFileCollection.h \
    src/database/IDatabaseDataBlock.h \
    src/database/DatabaseIndexHeader.h \
    src/database/DatabaseIndexRecord.h \
    src/database/DatabaseDataFileHeader.h \
    src/database/DatabaseDataFileRecord.h \
    src/database/IDatabaseFile.h \
    src/database/IDatabaseSequentialAccessFile.h \
    src/database/IDatabaseRandomAccessFile.h \
    src/database/HeaderDataBlock.h \
    src/core/net/UdpStream.h \
    src/core/DataStreamException.h \
    src/core/net/UdpStreamException.h \
    src/core/IDataBlock.h \
    src/core/net/UdpDataBlock.h \
    src/core/IHashedDataBlock.h \
    src/core/Context.h \
    src/core/ConsoleInput.h \
    src/core/ConsoleInputException.h \
    src/core/types/Guid.h \
    src/database/IDatabaseData.h \
    src/database/DatabaseIndexProvider.h \
    src/database/DatabaseDataProvider.h \
    tests/chat/Chat.h \
    src/core/IBinarySerializable.h \
    src/core/Settings.h \
    src/core/ContextException.h \
    src/core/net/RPCServer.h \
    src/core/net/RPCCommunicationThread.h \
    src/core/net/AbstractHTTPRequest.h \
    src/core/StringUtils.h \
    src/core/net/RPCRequest.h


INCLUDEPATH += $$PWD/src

OBJECTS_DIR = tmp
MOC_DIR = tmp
