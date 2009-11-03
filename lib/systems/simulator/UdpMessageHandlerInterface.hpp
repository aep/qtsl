#ifndef QTSL_UdpMessageHandlerInterface_H
#define QTSL_UdpMessageHandlerInterface_H

namespace qtsl{
    namespace udp{
        struct UdpMessage;
    };
    class UdpMessageHandlerInterface{
    public:
        virtual void udpMessageHandler(qtsl::udp::UdpMessage * message)=0;
    };
};

#endif
