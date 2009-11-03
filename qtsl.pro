TEMPLATE = app
TARGET = 
DEPENDPATH += . session session/udp
INCLUDEPATH += . session session/udp
include (session/session.pri)
SOURCES += main.cpp

OBJECTS_DIR=.obj
MOC_DIR=.obj


QT= network core
