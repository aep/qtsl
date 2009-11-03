TEMPLATE = app
TARGET = 
LIBS+=../../lib/libqtsl.a
INCLUDEPATH += . \
    ../../lib/systems/session/ \
    ../../lib/systems/session/qxtxmlrpc/ \
    ../../lib/systems/simulator/ \
    ../../lib/systems/chat/  \
    ../../lib/systems/avatar/ 

DEPENDPATH = INCLUDEPATH

QT=core network

SOURCES += main.cpp
