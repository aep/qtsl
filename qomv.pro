TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

INCLUDEPATH += /usr/include/QxtCore/
LIBS +=  -lQxtCore

# Input
HEADERS += RpcCallWriter.hpp Session.hpp
SOURCES += main.cpp RpcCallWriter.cpp Session.cpp


QT=core network


CONFIG+=debug
