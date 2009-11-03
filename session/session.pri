DEPENDPATH += session session/udp session/qxtxmlrpc
INCLUDEPATH += session session/udp session/qxtxmlrpc

HEADERS += session/Session.hpp \
	   session/Circuit.hpp \
	   session/udp/pkg.hpp \
           session/qxtxmlrpc/qxtglobal.h \
           session/qxtxmlrpc/qxtxmlrpc_p.h \
           session/qxtxmlrpc/qxtxmlrpccall.h \
           session/qxtxmlrpc/qxtxmlrpcclient.h 

SOURCES += session/Session.cpp \
	   session/Circuit.cpp \
           session/udp/pkg.cpp \
           session/qxtxmlrpc/qxtxmlrpc_p.cpp \
           session/qxtxmlrpc/qxtxmlrpccall.cpp \
           session/qxtxmlrpc/qxtxmlrpcclient.cpp 

