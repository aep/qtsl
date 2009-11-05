DEPENDPATH += $$PWD $$PWD/qxtxmlrpc
INCLUDEPATH += $$PWD $$PWD/qxtxmlrpc

HEADERS += $$PWD/Session.hpp \
           $$PWD/qxtxmlrpc/qxtglobal.h \
           $$PWD/qxtxmlrpc/qxtxmlrpc_p.h \
           $$PWD/qxtxmlrpc/qxtxmlrpccall.h \
           $$PWD/qxtxmlrpc/qxtxmlrpcclient.h 

SOURCES += $$PWD/Session.cpp \
           $$PWD/qxtxmlrpc/qxtxmlrpc_p.cpp \
           $$PWD/qxtxmlrpc/qxtxmlrpccall.cpp \
           $$PWD/qxtxmlrpc/qxtxmlrpcclient.cpp 

