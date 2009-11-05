CONFIG+=debug
TEMPLATE = lib
CONFIG+=staticlib
TARGET = qtsl
DEPENDPATH += . 
INCLUDEPATH += . 
include (systems/session/session.pri)
include (systems/simulator/simulator.pri)
include (systems/avatar/avatar.pri)
include (systems/chat/chat.pri)
include (systems/inventory/inventory.pri)

OBJECTS_DIR=.obj
MOC_DIR=.obj

QT= network core
