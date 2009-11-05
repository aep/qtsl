#include "Avatar.hpp"
#include "Simulator.hpp"
#include "pkg/pkg.hpp"

using namespace qtsl;

Avatar::Avatar(Session & s)
    :QObject()
    ,session(s){
    connect(&session,SIGNAL(teleportComplete(Simulator*)),this,SLOT(d_teleportComplete(Simulator*)));
}

void Avatar::d_teleportComplete(Simulator *  target){
    udp::CompleteAgentMovementMessage c;
    c.AgentData.CircuitCode=target->circuitCode();
    c.AgentData.SessionID=session.sessionId();
    c.AgentData.AgentID=session.agentId();
    target->sendMessage(c,true);
}

