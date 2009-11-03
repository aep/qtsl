DEPENDPATH += systems/session systems/session/qxtxmlrpc
INCLUDEPATH += systems/session systems/session/qxtxmlrpc

HEADERS += systems/session/Session.hpp \
           systems/session/qxtxmlrpc/qxtglobal.h \
           systems/session/qxtxmlrpc/qxtxmlrpc_p.h \
           systems/session/qxtxmlrpc/qxtxmlrpccall.h \
           systems/session/qxtxmlrpc/qxtxmlrpcclient.h 

SOURCES += systems/session/Session.cpp \
           systems/session/qxtxmlrpc/qxtxmlrpc_p.cpp \
           systems/session/qxtxmlrpc/qxtxmlrpccall.cpp \
           systems/session/qxtxmlrpc/qxtxmlrpcclient.cpp 

