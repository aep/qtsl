CONFIG+=debug
TEMPLATE = app
TARGET = 
DEPENDPATH += . 
INCLUDEPATH += . 
include (systems/session/session.pri)
include (systems/simulator/simulator.pri)
include (systems/avatar/avatar.pri)
SOURCES += main.cpp

OBJECTS_DIR=.obj
MOC_DIR=.obj

QT= network core
