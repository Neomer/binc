QT -= gui

SOURCES = src/main.cpp \
            src/core/IObserver.cpp \
            src/core/ISubject.cpp

HEADERS = \
            src/core/IData.h \
            src/core/IObserver.h \
            src/core/ISubject.h


INCLUDEPATH += $$PWD/src
