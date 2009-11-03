INCLUDEPATH += /usr/include/QxtCore/ /usr/include/QxtNetwork
LIBS +=  -lQxtCore -lQxtNetwork

HEADERS += session/Session.hpp \
	   session/Circuit.hpp \
	   session/udp/pkg.hpp \
           session/qxtrpc/qxtglobal.h \
           session/qxtrpc/qxtxmlrpc_p.h \
           session/qxtrpc/qxtxmlrpccall.h \
           session/qxtrpc/qxtxmlrpcclient.h 

SOURCES += session/Session.cpp \
	   session/Circuit.cpp \
           session/udp/pkg.cpp \
           session/qxtrpc/qxtxmlrpc_p.cpp \
           session/qxtrpc/qxtxmlrpccall.cpp \
           session/qxtrpc/qxtxmlrpcclient.cpp 

