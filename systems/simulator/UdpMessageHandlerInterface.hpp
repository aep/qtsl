namespace qtsl{
    namespace udp{
        struct UdpMessage;
    };
    class UdpMessageHandlerInterface{
    public:
        virtual void udpMessageHandler(qtsl::udp::UdpMessage * message)=0;
    };
};
