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
    src/core/net/http/HTTPClient.cpp \
    src/core/net/http/HTTPResponse.cpp \
    src/core/net/http/HTTPParsingException.cpp \
    src/core/net/http/HTTPUdpClient.cpp \
    src/core/net/SSDPRequest.cpp \
    src/core/net/SSDPProvider.cpp \
    src/core/net/UdpStream.cpp \
    src/core/Context.cpp \
    src/core/DataStreamException.cpp \
    src/core/net/UdpStreamException.cpp \
    src/core/IDataBlock.cpp \
    src/core/IHashedDataBlock.cpp \
    src/core/ConsoleInput.cpp \
    src/core/ConsoleInputException.cpp \
    src/core/types/Guid.cpp \
    tests/chat/Chat.cpp \
    src/core/Settings.cpp \
    src/core/ContextException.cpp \
    src/core/net/rpc/RPCServer.cpp \
    src/core/net/rpc/RPCCommunicationThread.cpp \
    src/core/StringUtils.cpp \
    src/core/net/rpc/RPCRequest.cpp \
    src/core/types/Version.cpp \
    src/core/net/INetMessageWithHeaders.cpp \
    src/core/net/http/IHTTPMessage.cpp \
    src/core/net/http/HTTPRequest.cpp \
    src/core/net/rpc/RPCResponse.cpp \
    src/core/IJsonSerializable.cpp \
    src/model/NodeModel.cpp \
    src/model/NodeCollectionModel.cpp \
    src/core/BaseException.cpp \
    src/model/Deal.cpp \
    src/model/Block.cpp \
    src/core/types/Hash.cpp \
    src/miner/Worker.cpp \
    src/miner/Work.cpp \
    src/core/net/TransportProvider.cpp \
    src/model/IBlockData.cpp \
    src/core/net/Net.cpp \
    src/core/net/NodeConnection.cpp \
    src/core/types/ConnectionPoint.cpp \
    src/core/net/NetDataBlock.cpp \
    src/core/transport/TransportDataBlock.cpp \
    src/core/transport/TransportTransaction.cpp \
    src/core/ICache.cpp \
    src/core/MemoryCache.cpp \
    src/core/SerializableEntityFactory.cpp \
    src/core/IObservableDataStream.cpp \
    src/database/Database.cpp \
    src/database/DatabaseFile.cpp \
    src/model/DatabaseIndexRecord.cpp \
    src/model/DatabaseDataHeader.cpp \
    src/core/net/TcpStream.cpp \
    src/core/net/rpc/RPCClient.cpp \
    src/core/net/rpc/RPCRequestThread.cpp

HEADERS += \
    src/core/IData.h \
    src/core/IObserver.h \
    src/core/ISubject.h \
    src/core/net/NetDataStream.h \
    src/core/net/PortMapping.h \
    src/core/IDataStream.h \
    src/core/net/NetDataStreamException.h \
    src/core/net/http/HTTPClient.h \
    src/core/net/http/HTTPResponse.h \
    src/core/net/http/HTTPParsingException.h \
    src/core/net/http/HTTPUdpClient.h \
    src/core/net/SSDPRequest.h \
    src/core/net/SSDPProvider.h \
    src/core/net/UdpStream.h \
    src/core/DataStreamException.h \
    src/core/net/UdpStreamException.h \
    src/core/IDataBlock.h \
    src/core/IHashedDataBlock.h \
    src/core/Context.h \
    src/core/ConsoleInput.h \
    src/core/ConsoleInputException.h \
    src/core/types/Guid.h \
    tests/chat/Chat.h \
    src/core/IBinarySerializable.h \
    src/core/Settings.h \
    src/core/ContextException.h \
    src/core/net/rpc/RPCServer.h \
    src/core/net/rpc/RPCCommunicationThread.h \
    src/core/StringUtils.h \
    src/core/net/rpc/RPCRequest.h \
    src/core/types/Version.h \
    src/core/net/INetMessageWithHeaders.h \
    src/core/net/http/IHTTPMessage.h \
    src/core/net/http/HTTPRequest.h \
    src/core/net/rpc/RPCResponse.h \
    src/core/IJsonSerializable.h \
    src/model/NodeModel.h \
    src/model/NodeCollectionModel.h \
    src/core/BaseException.h \
    src/model/Deal.h \
    src/model/Block.h \
    src/core/types/Hash.h \
    src/miner/Worker.h \
    src/miner/Work.h \
    src/core/net/TransportProvider.h \
    src/model/IBlockData.h \
    src/core/net/Net.h \
    src/core/net/NodeConnection.h \
    src/core/types/ConnectionPoint.h \
    src/core/net/NetDataBlock.h \
    src/core/transport/TransportDataBlock.h \
    src/core/transport/TransportTransaction.h \
    src/core/IIdentifyed.h \
    src/core/ICache.h \
    src/core/MemoryCache.h \
    src/core/IEntityFactory.h \
    src/core/IEntity.h \
    src/core/SerializableEntityFactory.h \
    src/core/IObservableDataStream.h \
    src/database/IDatabaseWritable.h \
    src/core/JsonSerializableEntity.h \
    src/database/Database.h \
    src/core/StreamedBuffer.h \
    src/database/DatabaseFile.h \
    src/model/DatabaseIndexRecord.h \
    src/model/DatabaseDataHeader.h \
    src/core/StreamedFile.h \
    src/core/net/TcpStream.h \
    src/core/net/rpc/RPCClient.h \
    src/core/net/rpc/RPCRequestThread.h
    src/core/IFileWithStream.h


INCLUDEPATH += $$PWD/src

OBJECTS_DIR = tmp
MOC_DIR = tmp
