TEMPLATE = app
TARGET = 
DEPENDPATH += . 
INCLUDEPATH += . 
include (session/session.pri)
include (chat/chat.pri)
SOURCES += main.cpp

OBJECTS_DIR=.obj
MOC_DIR=.obj


QT= network core
