TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

INCLUDEPATH += /usr/include/QxtCore/ /usr/include/QxtNetwork
LIBS +=  -lQxtCore -lQxtNetwork

OBJECTS_DIR=.obj
MOC_DIR=.obj

# Input
HEADERS +=          Session.hpp Circuit.hpp
SOURCES += main.cpp Session.cpp Circuit.cpp


QT=core network


CONFIG+=debug
