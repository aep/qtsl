#include "pkg.hpp"
using namespace qtsl;
using namespace udp;

TestMessageMessage::TestMessageMessage (){
    type=TestMessageType;
    for(int i=0;i<4;i++)
        NeighborBlock<< NeighborBlockBlock();
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TestMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TestBlock1.Test1;

    for(int i=0;i<4;i++){
         out << o.NeighborBlock[i].Test0;
         out << o.NeighborBlock[i].Test1;
         out << o.NeighborBlock[i].Test2;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TestMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TestBlock1.Test1;

    for(int i=0;i<4;i++){
         in >> o.NeighborBlock[i].Test0;
         in >> o.NeighborBlock[i].Test1;
         in >> o.NeighborBlock[i].Test2;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PacketAckMessage::PacketAckMessage (){
    type=PacketAckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PacketAckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.Packets.size();
    for(int i=0;i<o.Packets.size();i++){
         out << o.Packets[i].ID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PacketAckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.Packets.clear();
    lltypes::U8 countPackets;
    in >> countPackets;
    for(int i=0;i<countPackets;i++){
        PacketAckMessage::PacketsBlock y;
        in >> y.ID;
        o.Packets << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


OpenCircuitMessage::OpenCircuitMessage (){
    type=OpenCircuitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const OpenCircuitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.CircuitInfo.IP;
    out << o.CircuitInfo.Port;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  OpenCircuitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.CircuitInfo.IP;
    in >> o.CircuitInfo.Port;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CloseCircuitMessage::CloseCircuitMessage (){
    type=CloseCircuitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CloseCircuitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CloseCircuitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


StartPingCheckMessage::StartPingCheckMessage (){
    type=StartPingCheckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const StartPingCheckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.PingID.PingID;
    out << o.PingID.OldestUnacked;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  StartPingCheckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.PingID.PingID;
    in >> o.PingID.OldestUnacked;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CompletePingCheckMessage::CompletePingCheckMessage (){
    type=CompletePingCheckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CompletePingCheckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.PingID.PingID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CompletePingCheckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.PingID.PingID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AddCircuitCodeMessage::AddCircuitCodeMessage (){
    type=AddCircuitCodeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AddCircuitCodeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.CircuitCode.Code;
    out << o.CircuitCode.SessionID;
    out << o.CircuitCode.AgentID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AddCircuitCodeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.CircuitCode.Code;
    in >> o.CircuitCode.SessionID;
    in >> o.CircuitCode.AgentID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UseCircuitCodeMessage::UseCircuitCodeMessage (){
    type=UseCircuitCodeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UseCircuitCodeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.CircuitCode.Code;
    out << o.CircuitCode.SessionID;
    out << o.CircuitCode.ID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UseCircuitCodeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.CircuitCode.Code;
    in >> o.CircuitCode.SessionID;
    in >> o.CircuitCode.ID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NeighborListMessage::NeighborListMessage (){
    type=NeighborListType;
    for(int i=0;i<4;i++)
        NeighborBlock<< NeighborBlockBlock();
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NeighborListMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    for(int i=0;i<4;i++){
         out << o.NeighborBlock[i].IP;
         out << o.NeighborBlock[i].Port;
         out << o.NeighborBlock[i].PublicIP;
         out << o.NeighborBlock[i].PublicPort;
         out << o.NeighborBlock[i].RegionID;
         out << o.NeighborBlock[i].Name;
         out << o.NeighborBlock[i].SimAccess;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NeighborListMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    for(int i=0;i<4;i++){
         in >> o.NeighborBlock[i].IP;
         in >> o.NeighborBlock[i].Port;
         in >> o.NeighborBlock[i].PublicIP;
         in >> o.NeighborBlock[i].PublicPort;
         in >> o.NeighborBlock[i].RegionID;
         in >> o.NeighborBlock[i].Name;
         in >> o.NeighborBlock[i].SimAccess;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarTextureUpdateMessage::AvatarTextureUpdateMessage (){
    type=AvatarTextureUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarTextureUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.TexturesChanged;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].CacheID;
         out << o.WearableData[i].TextureIndex;
         out << o.WearableData[i].HostName;
    }

    out << (lltypes::U8)o.TextureData.size();
    for(int i=0;i<o.TextureData.size();i++){
         out << o.TextureData[i].TextureID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarTextureUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.TexturesChanged;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AvatarTextureUpdateMessage::WearableDataBlock y;
        in >> y.CacheID;
        in >> y.TextureIndex;
        in >> y.HostName;
        o.WearableData << y;
    }

    o.TextureData.clear();
    lltypes::U8 countTextureData;
    in >> countTextureData;
    for(int i=0;i<countTextureData;i++){
        AvatarTextureUpdateMessage::TextureDataBlock y;
        in >> y.TextureID;
        o.TextureData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorMapUpdateMessage::SimulatorMapUpdateMessage (){
    type=SimulatorMapUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorMapUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MapData.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorMapUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MapData.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorSetMapMessage::SimulatorSetMapMessage (){
    type=SimulatorSetMapType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorSetMapMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MapData.RegionHandle;
    out << o.MapData.Type;
    out << o.MapData.MapImage;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorSetMapMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MapData.RegionHandle;
    in >> o.MapData.Type;
    in >> o.MapData.MapImage;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SubscribeLoadMessage::SubscribeLoadMessage (){
    type=SubscribeLoadType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SubscribeLoadMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SubscribeLoadMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UnsubscribeLoadMessage::UnsubscribeLoadMessage (){
    type=UnsubscribeLoadType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UnsubscribeLoadMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UnsubscribeLoadMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorReadyMessage::SimulatorReadyMessage (){
    type=SimulatorReadyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorReadyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimulatorBlock.SimName;
    out << o.SimulatorBlock.SimAccess;
    out << o.SimulatorBlock.RegionFlags;
    out << o.SimulatorBlock.RegionID;
    out << o.SimulatorBlock.EstateID;
    out << o.SimulatorBlock.ParentEstateID;

    out << o.TelehubBlock.HasTelehub;
    out << o.TelehubBlock.TelehubPos;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorReadyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimulatorBlock.SimName;
    in >> o.SimulatorBlock.SimAccess;
    in >> o.SimulatorBlock.RegionFlags;
    in >> o.SimulatorBlock.RegionID;
    in >> o.SimulatorBlock.EstateID;
    in >> o.SimulatorBlock.ParentEstateID;

    in >> o.TelehubBlock.HasTelehub;
    in >> o.TelehubBlock.TelehubPos;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TelehubInfoMessage::TelehubInfoMessage (){
    type=TelehubInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TelehubInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TelehubBlock.ObjectID;
    out << o.TelehubBlock.ObjectName;
    out << o.TelehubBlock.TelehubPos;
    out << o.TelehubBlock.TelehubRot;

    out << (lltypes::U8)o.SpawnPointBlock.size();
    for(int i=0;i<o.SpawnPointBlock.size();i++){
         out << o.SpawnPointBlock[i].SpawnPointPos;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TelehubInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TelehubBlock.ObjectID;
    in >> o.TelehubBlock.ObjectName;
    in >> o.TelehubBlock.TelehubPos;
    in >> o.TelehubBlock.TelehubRot;

    o.SpawnPointBlock.clear();
    lltypes::U8 countSpawnPointBlock;
    in >> countSpawnPointBlock;
    for(int i=0;i<countSpawnPointBlock;i++){
        TelehubInfoMessage::SpawnPointBlockBlock y;
        in >> y.SpawnPointPos;
        o.SpawnPointBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorPresentAtLocationMessage::SimulatorPresentAtLocationMessage (){
    type=SimulatorPresentAtLocationType;
    for(int i=0;i<4;i++)
        NeighborBlock<< NeighborBlockBlock();
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorPresentAtLocationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimulatorPublicHostBlock.Port;
    out << o.SimulatorPublicHostBlock.SimulatorIP;
    out << o.SimulatorPublicHostBlock.GridX;
    out << o.SimulatorPublicHostBlock.GridY;

    for(int i=0;i<4;i++){
         out << o.NeighborBlock[i].IP;
         out << o.NeighborBlock[i].Port;
    }

    out << o.SimulatorBlock.SimName;
    out << o.SimulatorBlock.SimAccess;
    out << o.SimulatorBlock.RegionFlags;
    out << o.SimulatorBlock.RegionID;
    out << o.SimulatorBlock.EstateID;
    out << o.SimulatorBlock.ParentEstateID;

    out << (lltypes::U8)o.TelehubBlock.size();
    for(int i=0;i<o.TelehubBlock.size();i++){
         out << o.TelehubBlock[i].HasTelehub;
         out << o.TelehubBlock[i].TelehubPos;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorPresentAtLocationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimulatorPublicHostBlock.Port;
    in >> o.SimulatorPublicHostBlock.SimulatorIP;
    in >> o.SimulatorPublicHostBlock.GridX;
    in >> o.SimulatorPublicHostBlock.GridY;

    for(int i=0;i<4;i++){
         in >> o.NeighborBlock[i].IP;
         in >> o.NeighborBlock[i].Port;
    }

    in >> o.SimulatorBlock.SimName;
    in >> o.SimulatorBlock.SimAccess;
    in >> o.SimulatorBlock.RegionFlags;
    in >> o.SimulatorBlock.RegionID;
    in >> o.SimulatorBlock.EstateID;
    in >> o.SimulatorBlock.ParentEstateID;

    o.TelehubBlock.clear();
    lltypes::U8 countTelehubBlock;
    in >> countTelehubBlock;
    for(int i=0;i<countTelehubBlock;i++){
        SimulatorPresentAtLocationMessage::TelehubBlockBlock y;
        in >> y.HasTelehub;
        in >> y.TelehubPos;
        o.TelehubBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorLoadMessage::SimulatorLoadMessage (){
    type=SimulatorLoadType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorLoadMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimulatorLoad.TimeDilation;
    out << o.SimulatorLoad.AgentCount;
    out << o.SimulatorLoad.CanAcceptAgents;

    out << (lltypes::U8)o.AgentList.size();
    for(int i=0;i<o.AgentList.size();i++){
         out << o.AgentList[i].CircuitCode;
         out << o.AgentList[i].X;
         out << o.AgentList[i].Y;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorLoadMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimulatorLoad.TimeDilation;
    in >> o.SimulatorLoad.AgentCount;
    in >> o.SimulatorLoad.CanAcceptAgents;

    o.AgentList.clear();
    lltypes::U8 countAgentList;
    in >> countAgentList;
    for(int i=0;i<countAgentList;i++){
        SimulatorLoadMessage::AgentListBlock y;
        in >> y.CircuitCode;
        in >> y.X;
        in >> y.Y;
        o.AgentList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorShutdownRequestMessage::SimulatorShutdownRequestMessage (){
    type=SimulatorShutdownRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorShutdownRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorShutdownRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionPresenceRequestByRegionIDMessage::RegionPresenceRequestByRegionIDMessage (){
    type=RegionPresenceRequestByRegionIDType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionPresenceRequestByRegionIDMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.RegionData.size();
    for(int i=0;i<o.RegionData.size();i++){
         out << o.RegionData[i].RegionID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionPresenceRequestByRegionIDMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.RegionData.clear();
    lltypes::U8 countRegionData;
    in >> countRegionData;
    for(int i=0;i<countRegionData;i++){
        RegionPresenceRequestByRegionIDMessage::RegionDataBlock y;
        in >> y.RegionID;
        o.RegionData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionPresenceRequestByHandleMessage::RegionPresenceRequestByHandleMessage (){
    type=RegionPresenceRequestByHandleType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionPresenceRequestByHandleMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.RegionData.size();
    for(int i=0;i<o.RegionData.size();i++){
         out << o.RegionData[i].RegionHandle;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionPresenceRequestByHandleMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.RegionData.clear();
    lltypes::U8 countRegionData;
    in >> countRegionData;
    for(int i=0;i<countRegionData;i++){
        RegionPresenceRequestByHandleMessage::RegionDataBlock y;
        in >> y.RegionHandle;
        o.RegionData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionPresenceResponseMessage::RegionPresenceResponseMessage (){
    type=RegionPresenceResponseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionPresenceResponseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.RegionData.size();
    for(int i=0;i<o.RegionData.size();i++){
         out << o.RegionData[i].RegionID;
         out << o.RegionData[i].RegionHandle;
         out << o.RegionData[i].InternalRegionIP;
         out << o.RegionData[i].ExternalRegionIP;
         out << o.RegionData[i].RegionPort;
         out << o.RegionData[i].ValidUntil;
         out << o.RegionData[i].Message;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionPresenceResponseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.RegionData.clear();
    lltypes::U8 countRegionData;
    in >> countRegionData;
    for(int i=0;i<countRegionData;i++){
        RegionPresenceResponseMessage::RegionDataBlock y;
        in >> y.RegionID;
        in >> y.RegionHandle;
        in >> y.InternalRegionIP;
        in >> y.ExternalRegionIP;
        in >> y.RegionPort;
        in >> y.ValidUntil;
        in >> y.Message;
        o.RegionData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateSimulatorMessage::UpdateSimulatorMessage (){
    type=UpdateSimulatorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateSimulatorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimulatorInfo.RegionID;
    out << o.SimulatorInfo.SimName;
    out << o.SimulatorInfo.EstateID;
    out << o.SimulatorInfo.SimAccess;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateSimulatorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimulatorInfo.RegionID;
    in >> o.SimulatorInfo.SimName;
    in >> o.SimulatorInfo.EstateID;
    in >> o.SimulatorInfo.SimAccess;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogDwellTimeMessage::LogDwellTimeMessage (){
    type=LogDwellTimeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogDwellTimeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DwellInfo.AgentID;
    out << o.DwellInfo.SessionID;
    out << o.DwellInfo.Duration;
    out << o.DwellInfo.SimName;
    out << o.DwellInfo.RegionX;
    out << o.DwellInfo.RegionY;
    out << o.DwellInfo.AvgAgentsInView;
    out << o.DwellInfo.AvgViewerFPS;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogDwellTimeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DwellInfo.AgentID;
    in >> o.DwellInfo.SessionID;
    in >> o.DwellInfo.Duration;
    in >> o.DwellInfo.SimName;
    in >> o.DwellInfo.RegionX;
    in >> o.DwellInfo.RegionY;
    in >> o.DwellInfo.AvgAgentsInView;
    in >> o.DwellInfo.AvgViewerFPS;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FeatureDisabledMessage::FeatureDisabledMessage (){
    type=FeatureDisabledType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FeatureDisabledMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.FailureInfo.ErrorMessage;
    out << o.FailureInfo.AgentID;
    out << o.FailureInfo.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FeatureDisabledMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.FailureInfo.ErrorMessage;
    in >> o.FailureInfo.AgentID;
    in >> o.FailureInfo.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogFailedMoneyTransactionMessage::LogFailedMoneyTransactionMessage (){
    type=LogFailedMoneyTransactionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogFailedMoneyTransactionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransactionData.TransactionID;
    out << o.TransactionData.TransactionTime;
    out << o.TransactionData.TransactionType;
    out << o.TransactionData.SourceID;
    out << o.TransactionData.DestID;
    out << o.TransactionData.Flags;
    out << o.TransactionData.Amount;
    out << o.TransactionData.SimulatorIP;
    out << o.TransactionData.GridX;
    out << o.TransactionData.GridY;
    out << o.TransactionData.FailureType;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogFailedMoneyTransactionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransactionData.TransactionID;
    in >> o.TransactionData.TransactionTime;
    in >> o.TransactionData.TransactionType;
    in >> o.TransactionData.SourceID;
    in >> o.TransactionData.DestID;
    in >> o.TransactionData.Flags;
    in >> o.TransactionData.Amount;
    in >> o.TransactionData.SimulatorIP;
    in >> o.TransactionData.GridX;
    in >> o.TransactionData.GridY;
    in >> o.TransactionData.FailureType;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UserReportInternalMessage::UserReportInternalMessage (){
    type=UserReportInternalType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UserReportInternalMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ReportData.ReportType;
    out << o.ReportData.Category;
    out << o.ReportData.ReporterID;
    out << o.ReportData.ViewerPosition;
    out << o.ReportData.AgentPosition;
    out << o.ReportData.ScreenshotID;
    out << o.ReportData.ObjectID;
    out << o.ReportData.OwnerID;
    out << o.ReportData.LastOwnerID;
    out << o.ReportData.CreatorID;
    out << o.ReportData.RegionID;
    out << o.ReportData.AbuserID;
    out << o.ReportData.AbuseRegionName;
    out << o.ReportData.AbuseRegionID;
    out << o.ReportData.Summary;
    out << o.ReportData.Details;
    out << o.ReportData.VersionString;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UserReportInternalMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ReportData.ReportType;
    in >> o.ReportData.Category;
    in >> o.ReportData.ReporterID;
    in >> o.ReportData.ViewerPosition;
    in >> o.ReportData.AgentPosition;
    in >> o.ReportData.ScreenshotID;
    in >> o.ReportData.ObjectID;
    in >> o.ReportData.OwnerID;
    in >> o.ReportData.LastOwnerID;
    in >> o.ReportData.CreatorID;
    in >> o.ReportData.RegionID;
    in >> o.ReportData.AbuserID;
    in >> o.ReportData.AbuseRegionName;
    in >> o.ReportData.AbuseRegionID;
    in >> o.ReportData.Summary;
    in >> o.ReportData.Details;
    in >> o.ReportData.VersionString;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetSimStatusInDatabaseMessage::SetSimStatusInDatabaseMessage (){
    type=SetSimStatusInDatabaseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetSimStatusInDatabaseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.RegionID;
    out << o.Data.HostName;
    out << o.Data.X;
    out << o.Data.Y;
    out << o.Data.PID;
    out << o.Data.AgentCount;
    out << o.Data.TimeToLive;
    out << o.Data.Status;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetSimStatusInDatabaseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.RegionID;
    in >> o.Data.HostName;
    in >> o.Data.X;
    in >> o.Data.Y;
    in >> o.Data.PID;
    in >> o.Data.AgentCount;
    in >> o.Data.TimeToLive;
    in >> o.Data.Status;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetSimPresenceInDatabaseMessage::SetSimPresenceInDatabaseMessage (){
    type=SetSimPresenceInDatabaseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetSimPresenceInDatabaseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimData.RegionID;
    out << o.SimData.HostName;
    out << o.SimData.GridX;
    out << o.SimData.GridY;
    out << o.SimData.PID;
    out << o.SimData.AgentCount;
    out << o.SimData.TimeToLive;
    out << o.SimData.Status;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetSimPresenceInDatabaseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimData.RegionID;
    in >> o.SimData.HostName;
    in >> o.SimData.GridX;
    in >> o.SimData.GridY;
    in >> o.SimData.PID;
    in >> o.SimData.AgentCount;
    in >> o.SimData.TimeToLive;
    in >> o.SimData.Status;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EconomyDataRequestMessage::EconomyDataRequestMessage (){
    type=EconomyDataRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EconomyDataRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EconomyDataRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EconomyDataMessage::EconomyDataMessage (){
    type=EconomyDataType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EconomyDataMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.ObjectCapacity;
    out << o.Info.ObjectCount;
    out << o.Info.PriceEnergyUnit;
    out << o.Info.PriceObjectClaim;
    out << o.Info.PricePublicObjectDecay;
    out << o.Info.PricePublicObjectDelete;
    out << o.Info.PriceParcelClaim;
    out << o.Info.PriceParcelClaimFactor;
    out << o.Info.PriceUpload;
    out << o.Info.PriceRentLight;
    out << o.Info.TeleportMinPrice;
    out << o.Info.TeleportPriceExponent;
    out << o.Info.EnergyEfficiency;
    out << o.Info.PriceObjectRent;
    out << o.Info.PriceObjectScaleFactor;
    out << o.Info.PriceParcelRent;
    out << o.Info.PriceGroupCreate;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EconomyDataMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.ObjectCapacity;
    in >> o.Info.ObjectCount;
    in >> o.Info.PriceEnergyUnit;
    in >> o.Info.PriceObjectClaim;
    in >> o.Info.PricePublicObjectDecay;
    in >> o.Info.PricePublicObjectDelete;
    in >> o.Info.PriceParcelClaim;
    in >> o.Info.PriceParcelClaimFactor;
    in >> o.Info.PriceUpload;
    in >> o.Info.PriceRentLight;
    in >> o.Info.TeleportMinPrice;
    in >> o.Info.TeleportPriceExponent;
    in >> o.Info.EnergyEfficiency;
    in >> o.Info.PriceObjectRent;
    in >> o.Info.PriceObjectScaleFactor;
    in >> o.Info.PriceParcelRent;
    in >> o.Info.PriceGroupCreate;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPickerRequestMessage::AvatarPickerRequestMessage (){
    type=AvatarPickerRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPickerRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.QueryID;

    out << o.Data.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPickerRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.QueryID;

    in >> o.Data.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPickerRequestBackendMessage::AvatarPickerRequestBackendMessage (){
    type=AvatarPickerRequestBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPickerRequestBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.QueryID;
    out << o.AgentData.GodLevel;

    out << o.Data.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPickerRequestBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.QueryID;
    in >> o.AgentData.GodLevel;

    in >> o.Data.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPickerReplyMessage::AvatarPickerReplyMessage (){
    type=AvatarPickerReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPickerReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.QueryID;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].AvatarID;
         out << o.Data[i].FirstName;
         out << o.Data[i].LastName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPickerReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.QueryID;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        AvatarPickerReplyMessage::DataBlock y;
        in >> y.AvatarID;
        in >> y.FirstName;
        in >> y.LastName;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PlacesQueryMessage::PlacesQueryMessage (){
    type=PlacesQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PlacesQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.QueryID;

    out << o.TransactionData.TransactionID;

    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.Category;
    out << o.QueryData.SimName;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PlacesQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.QueryID;

    in >> o.TransactionData.TransactionID;

    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.Category;
    in >> o.QueryData.SimName;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PlacesReplyMessage::PlacesReplyMessage (){
    type=PlacesReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PlacesReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.QueryID;

    out << o.TransactionData.TransactionID;

    out << (lltypes::U8)o.QueryData.size();
    for(int i=0;i<o.QueryData.size();i++){
         out << o.QueryData[i].OwnerID;
         out << o.QueryData[i].Name;
         out << o.QueryData[i].Desc;
         out << o.QueryData[i].ActualArea;
         out << o.QueryData[i].BillableArea;
         out << o.QueryData[i].Flags;
         out << o.QueryData[i].GlobalX;
         out << o.QueryData[i].GlobalY;
         out << o.QueryData[i].GlobalZ;
         out << o.QueryData[i].SimName;
         out << o.QueryData[i].SnapshotID;
         out << o.QueryData[i].Dwell;
         out << o.QueryData[i].Price;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PlacesReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.QueryID;

    in >> o.TransactionData.TransactionID;

    o.QueryData.clear();
    lltypes::U8 countQueryData;
    in >> countQueryData;
    for(int i=0;i<countQueryData;i++){
        PlacesReplyMessage::QueryDataBlock y;
        in >> y.OwnerID;
        in >> y.Name;
        in >> y.Desc;
        in >> y.ActualArea;
        in >> y.BillableArea;
        in >> y.Flags;
        in >> y.GlobalX;
        in >> y.GlobalY;
        in >> y.GlobalZ;
        in >> y.SimName;
        in >> y.SnapshotID;
        in >> y.Dwell;
        in >> y.Price;
        o.QueryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirFindQueryMessage::DirFindQueryMessage (){
    type=DirFindQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirFindQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirFindQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirFindQueryBackendMessage::DirFindQueryBackendMessage (){
    type=DirFindQueryBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirFindQueryBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.QueryStart;
    out << o.QueryData.EstateID;
    out << o.QueryData.Godlike;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirFindQueryBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.QueryStart;
    in >> o.QueryData.EstateID;
    in >> o.QueryData.Godlike;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPlacesQueryMessage::DirPlacesQueryMessage (){
    type=DirPlacesQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPlacesQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.Category;
    out << o.QueryData.SimName;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPlacesQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.Category;
    in >> o.QueryData.SimName;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPlacesQueryBackendMessage::DirPlacesQueryBackendMessage (){
    type=DirPlacesQueryBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPlacesQueryBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.Category;
    out << o.QueryData.SimName;
    out << o.QueryData.EstateID;
    out << o.QueryData.Godlike;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPlacesQueryBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.Category;
    in >> o.QueryData.SimName;
    in >> o.QueryData.EstateID;
    in >> o.QueryData.Godlike;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPlacesReplyMessage::DirPlacesReplyMessage (){
    type=DirPlacesReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPlacesReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << (lltypes::U8)o.QueryData.size();
    for(int i=0;i<o.QueryData.size();i++){
         out << o.QueryData[i].QueryID;
    }

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].ParcelID;
         out << o.QueryReplies[i].Name;
         out << o.QueryReplies[i].ForSale;
         out << o.QueryReplies[i].Auction;
         out << o.QueryReplies[i].Dwell;
    }

    out << (lltypes::U8)o.StatusData.size();
    for(int i=0;i<o.StatusData.size();i++){
         out << o.StatusData[i].Status;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPlacesReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    o.QueryData.clear();
    lltypes::U8 countQueryData;
    in >> countQueryData;
    for(int i=0;i<countQueryData;i++){
        DirPlacesReplyMessage::QueryDataBlock y;
        in >> y.QueryID;
        o.QueryData << y;
    }

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirPlacesReplyMessage::QueryRepliesBlock y;
        in >> y.ParcelID;
        in >> y.Name;
        in >> y.ForSale;
        in >> y.Auction;
        in >> y.Dwell;
        o.QueryReplies << y;
    }

    o.StatusData.clear();
    lltypes::U8 countStatusData;
    in >> countStatusData;
    for(int i=0;i<countStatusData;i++){
        DirPlacesReplyMessage::StatusDataBlock y;
        in >> y.Status;
        o.StatusData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPeopleReplyMessage::DirPeopleReplyMessage (){
    type=DirPeopleReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPeopleReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].AgentID;
         out << o.QueryReplies[i].FirstName;
         out << o.QueryReplies[i].LastName;
         out << o.QueryReplies[i].Group;
         out << o.QueryReplies[i].Online;
         out << o.QueryReplies[i].Reputation;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPeopleReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirPeopleReplyMessage::QueryRepliesBlock y;
        in >> y.AgentID;
        in >> y.FirstName;
        in >> y.LastName;
        in >> y.Group;
        in >> y.Online;
        in >> y.Reputation;
        o.QueryReplies << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirEventsReplyMessage::DirEventsReplyMessage (){
    type=DirEventsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirEventsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].OwnerID;
         out << o.QueryReplies[i].Name;
         out << o.QueryReplies[i].EventID;
         out << o.QueryReplies[i].Date;
         out << o.QueryReplies[i].UnixTime;
         out << o.QueryReplies[i].EventFlags;
    }

    out << (lltypes::U8)o.StatusData.size();
    for(int i=0;i<o.StatusData.size();i++){
         out << o.StatusData[i].Status;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirEventsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirEventsReplyMessage::QueryRepliesBlock y;
        in >> y.OwnerID;
        in >> y.Name;
        in >> y.EventID;
        in >> y.Date;
        in >> y.UnixTime;
        in >> y.EventFlags;
        o.QueryReplies << y;
    }

    o.StatusData.clear();
    lltypes::U8 countStatusData;
    in >> countStatusData;
    for(int i=0;i<countStatusData;i++){
        DirEventsReplyMessage::StatusDataBlock y;
        in >> y.Status;
        o.StatusData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirGroupsReplyMessage::DirGroupsReplyMessage (){
    type=DirGroupsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirGroupsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].GroupID;
         out << o.QueryReplies[i].GroupName;
         out << o.QueryReplies[i].Members;
         out << o.QueryReplies[i].SearchOrder;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirGroupsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirGroupsReplyMessage::QueryRepliesBlock y;
        in >> y.GroupID;
        in >> y.GroupName;
        in >> y.Members;
        in >> y.SearchOrder;
        o.QueryReplies << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirClassifiedQueryMessage::DirClassifiedQueryMessage (){
    type=DirClassifiedQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirClassifiedQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.Category;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirClassifiedQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.Category;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirClassifiedQueryBackendMessage::DirClassifiedQueryBackendMessage (){
    type=DirClassifiedQueryBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirClassifiedQueryBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.Category;
    out << o.QueryData.EstateID;
    out << o.QueryData.Godlike;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirClassifiedQueryBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.Category;
    in >> o.QueryData.EstateID;
    in >> o.QueryData.Godlike;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirClassifiedReplyMessage::DirClassifiedReplyMessage (){
    type=DirClassifiedReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirClassifiedReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].ClassifiedID;
         out << o.QueryReplies[i].Name;
         out << o.QueryReplies[i].ClassifiedFlags;
         out << o.QueryReplies[i].CreationDate;
         out << o.QueryReplies[i].ExpirationDate;
         out << o.QueryReplies[i].PriceForListing;
    }

    out << (lltypes::U8)o.StatusData.size();
    for(int i=0;i<o.StatusData.size();i++){
         out << o.StatusData[i].Status;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirClassifiedReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirClassifiedReplyMessage::QueryRepliesBlock y;
        in >> y.ClassifiedID;
        in >> y.Name;
        in >> y.ClassifiedFlags;
        in >> y.CreationDate;
        in >> y.ExpirationDate;
        in >> y.PriceForListing;
        o.QueryReplies << y;
    }

    o.StatusData.clear();
    lltypes::U8 countStatusData;
    in >> countStatusData;
    for(int i=0;i<countStatusData;i++){
        DirClassifiedReplyMessage::StatusDataBlock y;
        in >> y.Status;
        o.StatusData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarClassifiedReplyMessage::AvatarClassifiedReplyMessage (){
    type=AvatarClassifiedReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarClassifiedReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.TargetID;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].ClassifiedID;
         out << o.Data[i].Name;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarClassifiedReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.TargetID;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        AvatarClassifiedReplyMessage::DataBlock y;
        in >> y.ClassifiedID;
        in >> y.Name;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClassifiedInfoRequestMessage::ClassifiedInfoRequestMessage (){
    type=ClassifiedInfoRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClassifiedInfoRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ClassifiedID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClassifiedInfoRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ClassifiedID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClassifiedInfoReplyMessage::ClassifiedInfoReplyMessage (){
    type=ClassifiedInfoReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClassifiedInfoReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.ClassifiedID;
    out << o.Data.CreatorID;
    out << o.Data.CreationDate;
    out << o.Data.ExpirationDate;
    out << o.Data.Category;
    out << o.Data.Name;
    out << o.Data.Desc;
    out << o.Data.ParcelID;
    out << o.Data.ParentEstate;
    out << o.Data.SnapshotID;
    out << o.Data.SimName;
    out << o.Data.PosGlobal;
    out << o.Data.ParcelName;
    out << o.Data.ClassifiedFlags;
    out << o.Data.PriceForListing;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClassifiedInfoReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.ClassifiedID;
    in >> o.Data.CreatorID;
    in >> o.Data.CreationDate;
    in >> o.Data.ExpirationDate;
    in >> o.Data.Category;
    in >> o.Data.Name;
    in >> o.Data.Desc;
    in >> o.Data.ParcelID;
    in >> o.Data.ParentEstate;
    in >> o.Data.SnapshotID;
    in >> o.Data.SimName;
    in >> o.Data.PosGlobal;
    in >> o.Data.ParcelName;
    in >> o.Data.ClassifiedFlags;
    in >> o.Data.PriceForListing;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClassifiedInfoUpdateMessage::ClassifiedInfoUpdateMessage (){
    type=ClassifiedInfoUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClassifiedInfoUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ClassifiedID;
    out << o.Data.Category;
    out << o.Data.Name;
    out << o.Data.Desc;
    out << o.Data.ParcelID;
    out << o.Data.ParentEstate;
    out << o.Data.SnapshotID;
    out << o.Data.PosGlobal;
    out << o.Data.ClassifiedFlags;
    out << o.Data.PriceForListing;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClassifiedInfoUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ClassifiedID;
    in >> o.Data.Category;
    in >> o.Data.Name;
    in >> o.Data.Desc;
    in >> o.Data.ParcelID;
    in >> o.Data.ParentEstate;
    in >> o.Data.SnapshotID;
    in >> o.Data.PosGlobal;
    in >> o.Data.ClassifiedFlags;
    in >> o.Data.PriceForListing;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClassifiedDeleteMessage::ClassifiedDeleteMessage (){
    type=ClassifiedDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClassifiedDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ClassifiedID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClassifiedDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ClassifiedID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClassifiedGodDeleteMessage::ClassifiedGodDeleteMessage (){
    type=ClassifiedGodDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClassifiedGodDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ClassifiedID;
    out << o.Data.QueryID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClassifiedGodDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ClassifiedID;
    in >> o.Data.QueryID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirLandQueryMessage::DirLandQueryMessage (){
    type=DirLandQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirLandQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.SearchType;
    out << o.QueryData.Price;
    out << o.QueryData.Area;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirLandQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.SearchType;
    in >> o.QueryData.Price;
    in >> o.QueryData.Area;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirLandQueryBackendMessage::DirLandQueryBackendMessage (){
    type=DirLandQueryBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirLandQueryBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.SearchType;
    out << o.QueryData.Price;
    out << o.QueryData.Area;
    out << o.QueryData.QueryStart;
    out << o.QueryData.EstateID;
    out << o.QueryData.Godlike;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirLandQueryBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.SearchType;
    in >> o.QueryData.Price;
    in >> o.QueryData.Area;
    in >> o.QueryData.QueryStart;
    in >> o.QueryData.EstateID;
    in >> o.QueryData.Godlike;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirLandReplyMessage::DirLandReplyMessage (){
    type=DirLandReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirLandReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].ParcelID;
         out << o.QueryReplies[i].Name;
         out << o.QueryReplies[i].Auction;
         out << o.QueryReplies[i].ForSale;
         out << o.QueryReplies[i].SalePrice;
         out << o.QueryReplies[i].ActualArea;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirLandReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirLandReplyMessage::QueryRepliesBlock y;
        in >> y.ParcelID;
        in >> y.Name;
        in >> y.Auction;
        in >> y.ForSale;
        in >> y.SalePrice;
        in >> y.ActualArea;
        o.QueryReplies << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPopularQueryMessage::DirPopularQueryMessage (){
    type=DirPopularQueryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPopularQueryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPopularQueryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPopularQueryBackendMessage::DirPopularQueryBackendMessage (){
    type=DirPopularQueryBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPopularQueryBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.EstateID;
    out << o.QueryData.Godlike;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPopularQueryBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.EstateID;
    in >> o.QueryData.Godlike;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DirPopularReplyMessage::DirPopularReplyMessage (){
    type=DirPopularReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DirPopularReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.QueryData.QueryID;

    out << (lltypes::U8)o.QueryReplies.size();
    for(int i=0;i<o.QueryReplies.size();i++){
         out << o.QueryReplies[i].ParcelID;
         out << o.QueryReplies[i].Name;
         out << o.QueryReplies[i].Dwell;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DirPopularReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.QueryData.QueryID;

    o.QueryReplies.clear();
    lltypes::U8 countQueryReplies;
    in >> countQueryReplies;
    for(int i=0;i<countQueryReplies;i++){
        DirPopularReplyMessage::QueryRepliesBlock y;
        in >> y.ParcelID;
        in >> y.Name;
        in >> y.Dwell;
        o.QueryReplies << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelInfoRequestMessage::ParcelInfoRequestMessage (){
    type=ParcelInfoRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelInfoRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ParcelID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelInfoRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ParcelID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelInfoReplyMessage::ParcelInfoReplyMessage (){
    type=ParcelInfoReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelInfoReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.ParcelID;
    out << o.Data.OwnerID;
    out << o.Data.Name;
    out << o.Data.Desc;
    out << o.Data.ActualArea;
    out << o.Data.BillableArea;
    out << o.Data.Flags;
    out << o.Data.GlobalX;
    out << o.Data.GlobalY;
    out << o.Data.GlobalZ;
    out << o.Data.SimName;
    out << o.Data.SnapshotID;
    out << o.Data.Dwell;
    out << o.Data.SalePrice;
    out << o.Data.AuctionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelInfoReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.ParcelID;
    in >> o.Data.OwnerID;
    in >> o.Data.Name;
    in >> o.Data.Desc;
    in >> o.Data.ActualArea;
    in >> o.Data.BillableArea;
    in >> o.Data.Flags;
    in >> o.Data.GlobalX;
    in >> o.Data.GlobalY;
    in >> o.Data.GlobalZ;
    in >> o.Data.SimName;
    in >> o.Data.SnapshotID;
    in >> o.Data.Dwell;
    in >> o.Data.SalePrice;
    in >> o.Data.AuctionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelObjectOwnersRequestMessage::ParcelObjectOwnersRequestMessage (){
    type=ParcelObjectOwnersRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelObjectOwnersRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelObjectOwnersRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelObjectOwnersReplyMessage::ParcelObjectOwnersReplyMessage (){
    type=ParcelObjectOwnersReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelObjectOwnersReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].OwnerID;
         out << o.Data[i].IsGroupOwned;
         out << o.Data[i].Count;
         out << o.Data[i].OnlineStatus;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelObjectOwnersReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        ParcelObjectOwnersReplyMessage::DataBlock y;
        in >> y.OwnerID;
        in >> y.IsGroupOwned;
        in >> y.Count;
        in >> y.OnlineStatus;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupNoticesListRequestMessage::GroupNoticesListRequestMessage (){
    type=GroupNoticesListRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupNoticesListRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupNoticesListRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupNoticesListReplyMessage::GroupNoticesListReplyMessage (){
    type=GroupNoticesListReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupNoticesListReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].NoticeID;
         out << o.Data[i].Timestamp;
         out << o.Data[i].FromName;
         out << o.Data[i].Subject;
         out << o.Data[i].HasAttachment;
         out << o.Data[i].AssetType;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupNoticesListReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        GroupNoticesListReplyMessage::DataBlock y;
        in >> y.NoticeID;
        in >> y.Timestamp;
        in >> y.FromName;
        in >> y.Subject;
        in >> y.HasAttachment;
        in >> y.AssetType;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupNoticeRequestMessage::GroupNoticeRequestMessage (){
    type=GroupNoticeRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupNoticeRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupNoticeID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupNoticeRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupNoticeID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupNoticeAddMessage::GroupNoticeAddMessage (){
    type=GroupNoticeAddType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupNoticeAddMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.MessageBlock.ToGroupID;
    out << o.MessageBlock.ID;
    out << o.MessageBlock.Dialog;
    out << o.MessageBlock.FromAgentName;
    out << o.MessageBlock.Message;
    out << o.MessageBlock.BinaryBucket;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupNoticeAddMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.MessageBlock.ToGroupID;
    in >> o.MessageBlock.ID;
    in >> o.MessageBlock.Dialog;
    in >> o.MessageBlock.FromAgentName;
    in >> o.MessageBlock.Message;
    in >> o.MessageBlock.BinaryBucket;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportRequestMessage::TeleportRequestMessage (){
    type=TeleportRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Info.RegionID;
    out << o.Info.Position;
    out << o.Info.LookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Info.RegionID;
    in >> o.Info.Position;
    in >> o.Info.LookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportLocationRequestMessage::TeleportLocationRequestMessage (){
    type=TeleportLocationRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportLocationRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Info.RegionHandle;
    out << o.Info.Position;
    out << o.Info.LookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportLocationRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Info.RegionHandle;
    in >> o.Info.Position;
    in >> o.Info.LookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportLocalMessage::TeleportLocalMessage (){
    type=TeleportLocalType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportLocalMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.LocationID;
    out << o.Info.Position;
    out << o.Info.LookAt;
    out << o.Info.TeleportFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportLocalMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.LocationID;
    in >> o.Info.Position;
    in >> o.Info.LookAt;
    in >> o.Info.TeleportFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportLandmarkRequestMessage::TeleportLandmarkRequestMessage (){
    type=TeleportLandmarkRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportLandmarkRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.SessionID;
    out << o.Info.LandmarkID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportLandmarkRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.SessionID;
    in >> o.Info.LandmarkID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportProgressMessage::TeleportProgressMessage (){
    type=TeleportProgressType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportProgressMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Info.TeleportFlags;
    out << o.Info.Message;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportProgressMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Info.TeleportFlags;
    in >> o.Info.Message;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DataHomeLocationRequestMessage::DataHomeLocationRequestMessage (){
    type=DataHomeLocationRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DataHomeLocationRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.KickedFromEstateID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DataHomeLocationRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.KickedFromEstateID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DataHomeLocationReplyMessage::DataHomeLocationReplyMessage (){
    type=DataHomeLocationReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DataHomeLocationReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.RegionHandle;
    out << o.Info.Position;
    out << o.Info.LookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DataHomeLocationReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.RegionHandle;
    in >> o.Info.Position;
    in >> o.Info.LookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportFinishMessage::TeleportFinishMessage (){
    type=TeleportFinishType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportFinishMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.LocationID;
    out << o.Info.SimIP;
    out << o.Info.SimPort;
    out << o.Info.RegionHandle;
    out << o.Info.SeedCapability;
    out << o.Info.SimAccess;
    out << o.Info.TeleportFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportFinishMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.LocationID;
    in >> o.Info.SimIP;
    in >> o.Info.SimPort;
    in >> o.Info.RegionHandle;
    in >> o.Info.SeedCapability;
    in >> o.Info.SimAccess;
    in >> o.Info.TeleportFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


StartLureMessage::StartLureMessage (){
    type=StartLureType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const StartLureMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Info.LureType;
    out << o.Info.Message;

    out << (lltypes::U8)o.TargetData.size();
    for(int i=0;i<o.TargetData.size();i++){
         out << o.TargetData[i].TargetID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  StartLureMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Info.LureType;
    in >> o.Info.Message;

    o.TargetData.clear();
    lltypes::U8 countTargetData;
    in >> countTargetData;
    for(int i=0;i<countTargetData;i++){
        StartLureMessage::TargetDataBlock y;
        in >> y.TargetID;
        o.TargetData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportLureRequestMessage::TeleportLureRequestMessage (){
    type=TeleportLureRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportLureRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.SessionID;
    out << o.Info.LureID;
    out << o.Info.TeleportFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportLureRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.SessionID;
    in >> o.Info.LureID;
    in >> o.Info.TeleportFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportCancelMessage::TeleportCancelMessage (){
    type=TeleportCancelType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportCancelMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportCancelMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportStartMessage::TeleportStartMessage (){
    type=TeleportStartType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportStartMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.TeleportFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportStartMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.TeleportFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportFailedMessage::TeleportFailedMessage (){
    type=TeleportFailedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportFailedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Info.AgentID;
    out << o.Info.Reason;

    out << (lltypes::U8)o.AlertInfo.size();
    for(int i=0;i<o.AlertInfo.size();i++){
         out << o.AlertInfo[i].Message;
         out << o.AlertInfo[i].ExtraParams;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportFailedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Info.AgentID;
    in >> o.Info.Reason;

    o.AlertInfo.clear();
    lltypes::U8 countAlertInfo;
    in >> countAlertInfo;
    for(int i=0;i<countAlertInfo;i++){
        TeleportFailedMessage::AlertInfoBlock y;
        in >> y.Message;
        in >> y.ExtraParams;
        o.AlertInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UndoMessage::UndoMessage (){
    type=UndoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UndoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UndoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        UndoMessage::ObjectDataBlock y;
        in >> y.ObjectID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RedoMessage::RedoMessage (){
    type=RedoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RedoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RedoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        RedoMessage::ObjectDataBlock y;
        in >> y.ObjectID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UndoLandMessage::UndoLandMessage (){
    type=UndoLandType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UndoLandMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UndoLandMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentPauseMessage::AgentPauseMessage (){
    type=AgentPauseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentPauseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentPauseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentResumeMessage::AgentResumeMessage (){
    type=AgentResumeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentResumeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentResumeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentUpdateMessage::AgentUpdateMessage (){
    type=AgentUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.BodyRotation;
    out << o.AgentData.HeadRotation;
    out << o.AgentData.State;
    out << o.AgentData.CameraCenter;
    out << o.AgentData.CameraAtAxis;
    out << o.AgentData.CameraLeftAxis;
    out << o.AgentData.CameraUpAxis;
    out << o.AgentData.Far;
    out << o.AgentData.ControlFlags;
    out << o.AgentData.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.BodyRotation;
    in >> o.AgentData.HeadRotation;
    in >> o.AgentData.State;
    in >> o.AgentData.CameraCenter;
    in >> o.AgentData.CameraAtAxis;
    in >> o.AgentData.CameraLeftAxis;
    in >> o.AgentData.CameraUpAxis;
    in >> o.AgentData.Far;
    in >> o.AgentData.ControlFlags;
    in >> o.AgentData.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChatFromViewerMessage::ChatFromViewerMessage (){
    type=ChatFromViewerType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChatFromViewerMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ChatData.Message;
    out << o.ChatData.Type;
    out << o.ChatData.Channel;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChatFromViewerMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ChatData.Message;
    in >> o.ChatData.Type;
    in >> o.ChatData.Channel;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentThrottleMessage::AgentThrottleMessage (){
    type=AgentThrottleType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentThrottleMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.CircuitCode;

    out << o.Throttle.GenCounter;
    out << o.Throttle.Throttles;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentThrottleMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.CircuitCode;

    in >> o.Throttle.GenCounter;
    in >> o.Throttle.Throttles;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentFOVMessage::AgentFOVMessage (){
    type=AgentFOVType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentFOVMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.CircuitCode;

    out << o.FOVBlock.GenCounter;
    out << o.FOVBlock.VerticalAngle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentFOVMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.CircuitCode;

    in >> o.FOVBlock.GenCounter;
    in >> o.FOVBlock.VerticalAngle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentHeightWidthMessage::AgentHeightWidthMessage (){
    type=AgentHeightWidthType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentHeightWidthMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.CircuitCode;

    out << o.HeightWidthBlock.GenCounter;
    out << o.HeightWidthBlock.Height;
    out << o.HeightWidthBlock.Width;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentHeightWidthMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.CircuitCode;

    in >> o.HeightWidthBlock.GenCounter;
    in >> o.HeightWidthBlock.Height;
    in >> o.HeightWidthBlock.Width;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentSetAppearanceMessage::AgentSetAppearanceMessage (){
    type=AgentSetAppearanceType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentSetAppearanceMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;
    out << o.AgentData.Size;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].CacheID;
         out << o.WearableData[i].TextureIndex;
    }

    out << o.ObjectData.TextureEntry;

    out << (lltypes::U8)o.VisualParam.size();
    for(int i=0;i<o.VisualParam.size();i++){
         out << o.VisualParam[i].ParamValue;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentSetAppearanceMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;
    in >> o.AgentData.Size;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AgentSetAppearanceMessage::WearableDataBlock y;
        in >> y.CacheID;
        in >> y.TextureIndex;
        o.WearableData << y;
    }

    in >> o.ObjectData.TextureEntry;

    o.VisualParam.clear();
    lltypes::U8 countVisualParam;
    in >> countVisualParam;
    for(int i=0;i<countVisualParam;i++){
        AgentSetAppearanceMessage::VisualParamBlock y;
        in >> y.ParamValue;
        o.VisualParam << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentAnimationMessage::AgentAnimationMessage (){
    type=AgentAnimationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentAnimationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.AnimationList.size();
    for(int i=0;i<o.AnimationList.size();i++){
         out << o.AnimationList[i].AnimID;
         out << o.AnimationList[i].StartAnim;
    }

    out << (lltypes::U8)o.PhysicalAvatarEventList.size();
    for(int i=0;i<o.PhysicalAvatarEventList.size();i++){
         out << o.PhysicalAvatarEventList[i].TypeData;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentAnimationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.AnimationList.clear();
    lltypes::U8 countAnimationList;
    in >> countAnimationList;
    for(int i=0;i<countAnimationList;i++){
        AgentAnimationMessage::AnimationListBlock y;
        in >> y.AnimID;
        in >> y.StartAnim;
        o.AnimationList << y;
    }

    o.PhysicalAvatarEventList.clear();
    lltypes::U8 countPhysicalAvatarEventList;
    in >> countPhysicalAvatarEventList;
    for(int i=0;i<countPhysicalAvatarEventList;i++){
        AgentAnimationMessage::PhysicalAvatarEventListBlock y;
        in >> y.TypeData;
        o.PhysicalAvatarEventList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentRequestSitMessage::AgentRequestSitMessage (){
    type=AgentRequestSitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentRequestSitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TargetObject.TargetID;
    out << o.TargetObject.Offset;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentRequestSitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TargetObject.TargetID;
    in >> o.TargetObject.Offset;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentSitMessage::AgentSitMessage (){
    type=AgentSitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentSitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentSitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentQuitCopyMessage::AgentQuitCopyMessage (){
    type=AgentQuitCopyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentQuitCopyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.FuseBlock.ViewerCircuitCode;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentQuitCopyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.FuseBlock.ViewerCircuitCode;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestImageMessage::RequestImageMessage (){
    type=RequestImageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestImageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.RequestImage.size();
    for(int i=0;i<o.RequestImage.size();i++){
         out << o.RequestImage[i].Image;
         out << o.RequestImage[i].DiscardLevel;
         out << o.RequestImage[i].DownloadPriority;
         out << o.RequestImage[i].Packet;
         out << o.RequestImage[i].Type;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestImageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.RequestImage.clear();
    lltypes::U8 countRequestImage;
    in >> countRequestImage;
    for(int i=0;i<countRequestImage;i++){
        RequestImageMessage::RequestImageBlock y;
        in >> y.Image;
        in >> y.DiscardLevel;
        in >> y.DownloadPriority;
        in >> y.Packet;
        in >> y.Type;
        o.RequestImage << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ImageNotInDatabaseMessage::ImageNotInDatabaseMessage (){
    type=ImageNotInDatabaseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ImageNotInDatabaseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ImageID.ID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ImageNotInDatabaseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ImageID.ID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RebakeAvatarTexturesMessage::RebakeAvatarTexturesMessage (){
    type=RebakeAvatarTexturesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RebakeAvatarTexturesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TextureData.TextureID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RebakeAvatarTexturesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TextureData.TextureID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetAlwaysRunMessage::SetAlwaysRunMessage (){
    type=SetAlwaysRunType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetAlwaysRunMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AlwaysRun;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetAlwaysRunMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AlwaysRun;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectAddMessage::ObjectAddMessage (){
    type=ObjectAddType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectAddMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.ObjectData.PCode;
    out << o.ObjectData.Material;
    out << o.ObjectData.AddFlags;
    out << o.ObjectData.PathCurve;
    out << o.ObjectData.ProfileCurve;
    out << o.ObjectData.PathBegin;
    out << o.ObjectData.PathEnd;
    out << o.ObjectData.PathScaleX;
    out << o.ObjectData.PathScaleY;
    out << o.ObjectData.PathShearX;
    out << o.ObjectData.PathShearY;
    out << o.ObjectData.PathTwist;
    out << o.ObjectData.PathTwistBegin;
    out << o.ObjectData.PathRadiusOffset;
    out << o.ObjectData.PathTaperX;
    out << o.ObjectData.PathTaperY;
    out << o.ObjectData.PathRevolutions;
    out << o.ObjectData.PathSkew;
    out << o.ObjectData.ProfileBegin;
    out << o.ObjectData.ProfileEnd;
    out << o.ObjectData.ProfileHollow;
    out << o.ObjectData.BypassRaycast;
    out << o.ObjectData.RayStart;
    out << o.ObjectData.RayEnd;
    out << o.ObjectData.RayTargetID;
    out << o.ObjectData.RayEndIsIntersection;
    out << o.ObjectData.Scale;
    out << o.ObjectData.Rotation;
    out << o.ObjectData.State;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectAddMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.ObjectData.PCode;
    in >> o.ObjectData.Material;
    in >> o.ObjectData.AddFlags;
    in >> o.ObjectData.PathCurve;
    in >> o.ObjectData.ProfileCurve;
    in >> o.ObjectData.PathBegin;
    in >> o.ObjectData.PathEnd;
    in >> o.ObjectData.PathScaleX;
    in >> o.ObjectData.PathScaleY;
    in >> o.ObjectData.PathShearX;
    in >> o.ObjectData.PathShearY;
    in >> o.ObjectData.PathTwist;
    in >> o.ObjectData.PathTwistBegin;
    in >> o.ObjectData.PathRadiusOffset;
    in >> o.ObjectData.PathTaperX;
    in >> o.ObjectData.PathTaperY;
    in >> o.ObjectData.PathRevolutions;
    in >> o.ObjectData.PathSkew;
    in >> o.ObjectData.ProfileBegin;
    in >> o.ObjectData.ProfileEnd;
    in >> o.ObjectData.ProfileHollow;
    in >> o.ObjectData.BypassRaycast;
    in >> o.ObjectData.RayStart;
    in >> o.ObjectData.RayEnd;
    in >> o.ObjectData.RayTargetID;
    in >> o.ObjectData.RayEndIsIntersection;
    in >> o.ObjectData.Scale;
    in >> o.ObjectData.Rotation;
    in >> o.ObjectData.State;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDeleteMessage::ObjectDeleteMessage (){
    type=ObjectDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Force;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Force;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDeleteMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDuplicateMessage::ObjectDuplicateMessage (){
    type=ObjectDuplicateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDuplicateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.SharedData.Offset;
    out << o.SharedData.DuplicateFlags;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDuplicateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.SharedData.Offset;
    in >> o.SharedData.DuplicateFlags;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDuplicateMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDuplicateOnRayMessage::ObjectDuplicateOnRayMessage (){
    type=ObjectDuplicateOnRayType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDuplicateOnRayMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;
    out << o.AgentData.RayStart;
    out << o.AgentData.RayEnd;
    out << o.AgentData.BypassRaycast;
    out << o.AgentData.RayEndIsIntersection;
    out << o.AgentData.CopyCenters;
    out << o.AgentData.CopyRotates;
    out << o.AgentData.RayTargetID;
    out << o.AgentData.DuplicateFlags;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDuplicateOnRayMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.RayStart;
    in >> o.AgentData.RayEnd;
    in >> o.AgentData.BypassRaycast;
    in >> o.AgentData.RayEndIsIntersection;
    in >> o.AgentData.CopyCenters;
    in >> o.AgentData.CopyRotates;
    in >> o.AgentData.RayTargetID;
    in >> o.AgentData.DuplicateFlags;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDuplicateOnRayMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MultipleObjectUpdateMessage::MultipleObjectUpdateMessage (){
    type=MultipleObjectUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MultipleObjectUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Type;
         out << o.ObjectData[i].Data;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MultipleObjectUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        MultipleObjectUpdateMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Type;
        in >> y.Data;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestMultipleObjectsMessage::RequestMultipleObjectsMessage (){
    type=RequestMultipleObjectsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestMultipleObjectsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].CacheMissType;
         out << o.ObjectData[i].ID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestMultipleObjectsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        RequestMultipleObjectsMessage::ObjectDataBlock y;
        in >> y.CacheMissType;
        in >> y.ID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectPositionMessage::ObjectPositionMessage (){
    type=ObjectPositionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectPositionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Position;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectPositionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectPositionMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Position;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectScaleMessage::ObjectScaleMessage (){
    type=ObjectScaleType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectScaleMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Scale;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectScaleMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectScaleMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Scale;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectRotationMessage::ObjectRotationMessage (){
    type=ObjectRotationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectRotationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Rotation;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectRotationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectRotationMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Rotation;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectFlagUpdateMessage::ObjectFlagUpdateMessage (){
    type=ObjectFlagUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectFlagUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.ObjectLocalID;
    out << o.AgentData.UsePhysics;
    out << o.AgentData.IsTemporary;
    out << o.AgentData.IsPhantom;
    out << o.AgentData.CastsShadows;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectFlagUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.ObjectLocalID;
    in >> o.AgentData.UsePhysics;
    in >> o.AgentData.IsTemporary;
    in >> o.AgentData.IsPhantom;
    in >> o.AgentData.CastsShadows;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectClickActionMessage::ObjectClickActionMessage (){
    type=ObjectClickActionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectClickActionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].ClickAction;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectClickActionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectClickActionMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.ClickAction;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectImageMessage::ObjectImageMessage (){
    type=ObjectImageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectImageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].MediaURL;
         out << o.ObjectData[i].TextureEntry;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectImageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectImageMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.MediaURL;
        in >> y.TextureEntry;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectMaterialMessage::ObjectMaterialMessage (){
    type=ObjectMaterialType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectMaterialMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Material;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectMaterialMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectMaterialMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Material;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectShapeMessage::ObjectShapeMessage (){
    type=ObjectShapeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectShapeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].PathCurve;
         out << o.ObjectData[i].ProfileCurve;
         out << o.ObjectData[i].PathBegin;
         out << o.ObjectData[i].PathEnd;
         out << o.ObjectData[i].PathScaleX;
         out << o.ObjectData[i].PathScaleY;
         out << o.ObjectData[i].PathShearX;
         out << o.ObjectData[i].PathShearY;
         out << o.ObjectData[i].PathTwist;
         out << o.ObjectData[i].PathTwistBegin;
         out << o.ObjectData[i].PathRadiusOffset;
         out << o.ObjectData[i].PathTaperX;
         out << o.ObjectData[i].PathTaperY;
         out << o.ObjectData[i].PathRevolutions;
         out << o.ObjectData[i].PathSkew;
         out << o.ObjectData[i].ProfileBegin;
         out << o.ObjectData[i].ProfileEnd;
         out << o.ObjectData[i].ProfileHollow;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectShapeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectShapeMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.PathCurve;
        in >> y.ProfileCurve;
        in >> y.PathBegin;
        in >> y.PathEnd;
        in >> y.PathScaleX;
        in >> y.PathScaleY;
        in >> y.PathShearX;
        in >> y.PathShearY;
        in >> y.PathTwist;
        in >> y.PathTwistBegin;
        in >> y.PathRadiusOffset;
        in >> y.PathTaperX;
        in >> y.PathTaperY;
        in >> y.PathRevolutions;
        in >> y.PathSkew;
        in >> y.ProfileBegin;
        in >> y.ProfileEnd;
        in >> y.ProfileHollow;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectExtraParamsMessage::ObjectExtraParamsMessage (){
    type=ObjectExtraParamsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectExtraParamsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].ParamType;
         out << o.ObjectData[i].ParamInUse;
         out << o.ObjectData[i].ParamSize;
         out << o.ObjectData[i].ParamData;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectExtraParamsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectExtraParamsMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.ParamType;
        in >> y.ParamInUse;
        in >> y.ParamSize;
        in >> y.ParamData;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectOwnerMessage::ObjectOwnerMessage (){
    type=ObjectOwnerType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectOwnerMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.HeaderData.Override;
    out << o.HeaderData.OwnerID;
    out << o.HeaderData.GroupID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectOwnerMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.HeaderData.Override;
    in >> o.HeaderData.OwnerID;
    in >> o.HeaderData.GroupID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectOwnerMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectGroupMessage::ObjectGroupMessage (){
    type=ObjectGroupType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectGroupMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectGroupMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectGroupMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectBuyMessage::ObjectBuyMessage (){
    type=ObjectBuyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectBuyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;
    out << o.AgentData.CategoryID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].SaleType;
         out << o.ObjectData[i].SalePrice;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectBuyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.CategoryID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectBuyMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.SaleType;
        in >> y.SalePrice;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


BuyObjectInventoryMessage::BuyObjectInventoryMessage (){
    type=BuyObjectInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const BuyObjectInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ObjectID;
    out << o.Data.ItemID;
    out << o.Data.FolderID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  BuyObjectInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ObjectID;
    in >> o.Data.ItemID;
    in >> o.Data.FolderID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DerezContainerMessage::DerezContainerMessage (){
    type=DerezContainerType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DerezContainerMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.ObjectID;
    out << o.Data.Delete;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DerezContainerMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.ObjectID;
    in >> o.Data.Delete;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectPermissionsMessage::ObjectPermissionsMessage (){
    type=ObjectPermissionsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectPermissionsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.HeaderData.Override;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Field;
         out << o.ObjectData[i].Set;
         out << o.ObjectData[i].Mask;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectPermissionsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.HeaderData.Override;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectPermissionsMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Field;
        in >> y.Set;
        in >> y.Mask;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectSaleInfoMessage::ObjectSaleInfoMessage (){
    type=ObjectSaleInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectSaleInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].LocalID;
         out << o.ObjectData[i].SaleType;
         out << o.ObjectData[i].SalePrice;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectSaleInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectSaleInfoMessage::ObjectDataBlock y;
        in >> y.LocalID;
        in >> y.SaleType;
        in >> y.SalePrice;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectNameMessage::ObjectNameMessage (){
    type=ObjectNameType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectNameMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].LocalID;
         out << o.ObjectData[i].Name;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectNameMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectNameMessage::ObjectDataBlock y;
        in >> y.LocalID;
        in >> y.Name;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDescriptionMessage::ObjectDescriptionMessage (){
    type=ObjectDescriptionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDescriptionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].LocalID;
         out << o.ObjectData[i].Description;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDescriptionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDescriptionMessage::ObjectDataBlock y;
        in >> y.LocalID;
        in >> y.Description;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectCategoryMessage::ObjectCategoryMessage (){
    type=ObjectCategoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectCategoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].LocalID;
         out << o.ObjectData[i].Category;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectCategoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectCategoryMessage::ObjectDataBlock y;
        in >> y.LocalID;
        in >> y.Category;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectSelectMessage::ObjectSelectMessage (){
    type=ObjectSelectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectSelectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectSelectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectSelectMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDeselectMessage::ObjectDeselectMessage (){
    type=ObjectDeselectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDeselectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDeselectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDeselectMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectAttachMessage::ObjectAttachMessage (){
    type=ObjectAttachType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectAttachMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AttachmentPoint;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].Rotation;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectAttachMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AttachmentPoint;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectAttachMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.Rotation;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDetachMessage::ObjectDetachMessage (){
    type=ObjectDetachType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDetachMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDetachMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDetachMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDropMessage::ObjectDropMessage (){
    type=ObjectDropType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDropMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDropMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDropMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectLinkMessage::ObjectLinkMessage (){
    type=ObjectLinkType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectLinkMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectLinkMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectLinkMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDelinkMessage::ObjectDelinkMessage (){
    type=ObjectDelinkType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDelinkMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDelinkMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectDelinkMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectGrabMessage::ObjectGrabMessage (){
    type=ObjectGrabType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectGrabMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.LocalID;
    out << o.ObjectData.GrabOffset;

    out << (lltypes::U8)o.SurfaceInfo.size();
    for(int i=0;i<o.SurfaceInfo.size();i++){
         out << o.SurfaceInfo[i].UVCoord;
         out << o.SurfaceInfo[i].STCoord;
         out << o.SurfaceInfo[i].FaceIndex;
         out << o.SurfaceInfo[i].Position;
         out << o.SurfaceInfo[i].Normal;
         out << o.SurfaceInfo[i].Binormal;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectGrabMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.LocalID;
    in >> o.ObjectData.GrabOffset;

    o.SurfaceInfo.clear();
    lltypes::U8 countSurfaceInfo;
    in >> countSurfaceInfo;
    for(int i=0;i<countSurfaceInfo;i++){
        ObjectGrabMessage::SurfaceInfoBlock y;
        in >> y.UVCoord;
        in >> y.STCoord;
        in >> y.FaceIndex;
        in >> y.Position;
        in >> y.Normal;
        in >> y.Binormal;
        o.SurfaceInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectGrabUpdateMessage::ObjectGrabUpdateMessage (){
    type=ObjectGrabUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectGrabUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.ObjectID;
    out << o.ObjectData.GrabOffsetInitial;
    out << o.ObjectData.GrabPosition;
    out << o.ObjectData.TimeSinceLast;

    out << (lltypes::U8)o.SurfaceInfo.size();
    for(int i=0;i<o.SurfaceInfo.size();i++){
         out << o.SurfaceInfo[i].UVCoord;
         out << o.SurfaceInfo[i].STCoord;
         out << o.SurfaceInfo[i].FaceIndex;
         out << o.SurfaceInfo[i].Position;
         out << o.SurfaceInfo[i].Normal;
         out << o.SurfaceInfo[i].Binormal;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectGrabUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.ObjectID;
    in >> o.ObjectData.GrabOffsetInitial;
    in >> o.ObjectData.GrabPosition;
    in >> o.ObjectData.TimeSinceLast;

    o.SurfaceInfo.clear();
    lltypes::U8 countSurfaceInfo;
    in >> countSurfaceInfo;
    for(int i=0;i<countSurfaceInfo;i++){
        ObjectGrabUpdateMessage::SurfaceInfoBlock y;
        in >> y.UVCoord;
        in >> y.STCoord;
        in >> y.FaceIndex;
        in >> y.Position;
        in >> y.Normal;
        in >> y.Binormal;
        o.SurfaceInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectDeGrabMessage::ObjectDeGrabMessage (){
    type=ObjectDeGrabType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectDeGrabMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.LocalID;

    out << (lltypes::U8)o.SurfaceInfo.size();
    for(int i=0;i<o.SurfaceInfo.size();i++){
         out << o.SurfaceInfo[i].UVCoord;
         out << o.SurfaceInfo[i].STCoord;
         out << o.SurfaceInfo[i].FaceIndex;
         out << o.SurfaceInfo[i].Position;
         out << o.SurfaceInfo[i].Normal;
         out << o.SurfaceInfo[i].Binormal;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectDeGrabMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.LocalID;

    o.SurfaceInfo.clear();
    lltypes::U8 countSurfaceInfo;
    in >> countSurfaceInfo;
    for(int i=0;i<countSurfaceInfo;i++){
        ObjectDeGrabMessage::SurfaceInfoBlock y;
        in >> y.UVCoord;
        in >> y.STCoord;
        in >> y.FaceIndex;
        in >> y.Position;
        in >> y.Normal;
        in >> y.Binormal;
        o.SurfaceInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectSpinStartMessage::ObjectSpinStartMessage (){
    type=ObjectSpinStartType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectSpinStartMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.ObjectID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectSpinStartMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.ObjectID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectSpinUpdateMessage::ObjectSpinUpdateMessage (){
    type=ObjectSpinUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectSpinUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.ObjectID;
    out << o.ObjectData.Rotation;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectSpinUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.ObjectID;
    in >> o.ObjectData.Rotation;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectSpinStopMessage::ObjectSpinStopMessage (){
    type=ObjectSpinStopType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectSpinStopMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.ObjectID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectSpinStopMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.ObjectID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectExportSelectedMessage::ObjectExportSelectedMessage (){
    type=ObjectExportSelectedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectExportSelectedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.RequestID;
    out << o.AgentData.VolumeDetail;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectExportSelectedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.RequestID;
    in >> o.AgentData.VolumeDetail;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectExportSelectedMessage::ObjectDataBlock y;
        in >> y.ObjectID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ModifyLandMessage::ModifyLandMessage (){
    type=ModifyLandType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ModifyLandMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ModifyBlock.Action;
    out << o.ModifyBlock.BrushSize;
    out << o.ModifyBlock.Seconds;
    out << o.ModifyBlock.Height;

    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].LocalID;
         out << o.ParcelData[i].West;
         out << o.ParcelData[i].South;
         out << o.ParcelData[i].East;
         out << o.ParcelData[i].North;
    }

    out << (lltypes::U8)o.ModifyBlockExtended.size();
    for(int i=0;i<o.ModifyBlockExtended.size();i++){
         out << o.ModifyBlockExtended[i].BrushSize;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ModifyLandMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ModifyBlock.Action;
    in >> o.ModifyBlock.BrushSize;
    in >> o.ModifyBlock.Seconds;
    in >> o.ModifyBlock.Height;

    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        ModifyLandMessage::ParcelDataBlock y;
        in >> y.LocalID;
        in >> y.West;
        in >> y.South;
        in >> y.East;
        in >> y.North;
        o.ParcelData << y;
    }

    o.ModifyBlockExtended.clear();
    lltypes::U8 countModifyBlockExtended;
    in >> countModifyBlockExtended;
    for(int i=0;i<countModifyBlockExtended;i++){
        ModifyLandMessage::ModifyBlockExtendedBlock y;
        in >> y.BrushSize;
        o.ModifyBlockExtended << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


VelocityInterpolateOnMessage::VelocityInterpolateOnMessage (){
    type=VelocityInterpolateOnType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const VelocityInterpolateOnMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  VelocityInterpolateOnMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


VelocityInterpolateOffMessage::VelocityInterpolateOffMessage (){
    type=VelocityInterpolateOffType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const VelocityInterpolateOffMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  VelocityInterpolateOffMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


StateSaveMessage::StateSaveMessage (){
    type=StateSaveType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const StateSaveMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.DataBlock.Filename;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  StateSaveMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.DataBlock.Filename;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ReportAutosaveCrashMessage::ReportAutosaveCrashMessage (){
    type=ReportAutosaveCrashType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ReportAutosaveCrashMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AutosaveData.PID;
    out << o.AutosaveData.Status;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ReportAutosaveCrashMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AutosaveData.PID;
    in >> o.AutosaveData.Status;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimWideDeletesMessage::SimWideDeletesMessage (){
    type=SimWideDeletesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimWideDeletesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.DataBlock.TargetID;
    out << o.DataBlock.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimWideDeletesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.DataBlock.TargetID;
    in >> o.DataBlock.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestObjectPropertiesFamilyMessage::RequestObjectPropertiesFamilyMessage (){
    type=RequestObjectPropertiesFamilyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestObjectPropertiesFamilyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.RequestFlags;
    out << o.ObjectData.ObjectID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestObjectPropertiesFamilyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.RequestFlags;
    in >> o.ObjectData.ObjectID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TrackAgentMessage::TrackAgentMessage (){
    type=TrackAgentType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TrackAgentMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TargetData.PreyID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TrackAgentMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TargetData.PreyID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ViewerStatsMessage::ViewerStatsMessage (){
    type=ViewerStatsType;
    for(int i=0;i<2;i++)
        NetStats<< NetStatsBlock();
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ViewerStatsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.IP;
    out << o.AgentData.StartTime;
    out << o.AgentData.RunTime;
    out << o.AgentData.SimFPS;
    out << o.AgentData.FPS;
    out << o.AgentData.AgentsInView;
    out << o.AgentData.Ping;
    out << o.AgentData.MetersTraveled;
    out << o.AgentData.RegionsVisited;
    out << o.AgentData.SysRAM;
    out << o.AgentData.SysOS;
    out << o.AgentData.SysCPU;
    out << o.AgentData.SysGPU;

    out << o.DownloadTotals.World;
    out << o.DownloadTotals.Objects;
    out << o.DownloadTotals.Textures;

    for(int i=0;i<2;i++){
         out << o.NetStats[i].Bytes;
         out << o.NetStats[i].Packets;
         out << o.NetStats[i].Compressed;
         out << o.NetStats[i].Savings;
    }

    out << o.FailStats.SendPacket;
    out << o.FailStats.Dropped;
    out << o.FailStats.Resent;
    out << o.FailStats.FailedResends;
    out << o.FailStats.OffCircuit;
    out << o.FailStats.Invalid;

    out << (lltypes::U8)o.MiscStats.size();
    for(int i=0;i<o.MiscStats.size();i++){
         out << o.MiscStats[i].Type;
         out << o.MiscStats[i].Value;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ViewerStatsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.IP;
    in >> o.AgentData.StartTime;
    in >> o.AgentData.RunTime;
    in >> o.AgentData.SimFPS;
    in >> o.AgentData.FPS;
    in >> o.AgentData.AgentsInView;
    in >> o.AgentData.Ping;
    in >> o.AgentData.MetersTraveled;
    in >> o.AgentData.RegionsVisited;
    in >> o.AgentData.SysRAM;
    in >> o.AgentData.SysOS;
    in >> o.AgentData.SysCPU;
    in >> o.AgentData.SysGPU;

    in >> o.DownloadTotals.World;
    in >> o.DownloadTotals.Objects;
    in >> o.DownloadTotals.Textures;

    for(int i=0;i<2;i++){
         in >> o.NetStats[i].Bytes;
         in >> o.NetStats[i].Packets;
         in >> o.NetStats[i].Compressed;
         in >> o.NetStats[i].Savings;
    }

    in >> o.FailStats.SendPacket;
    in >> o.FailStats.Dropped;
    in >> o.FailStats.Resent;
    in >> o.FailStats.FailedResends;
    in >> o.FailStats.OffCircuit;
    in >> o.FailStats.Invalid;

    o.MiscStats.clear();
    lltypes::U8 countMiscStats;
    in >> countMiscStats;
    for(int i=0;i<countMiscStats;i++){
        ViewerStatsMessage::MiscStatsBlock y;
        in >> y.Type;
        in >> y.Value;
        o.MiscStats << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptAnswerYesMessage::ScriptAnswerYesMessage (){
    type=ScriptAnswerYesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptAnswerYesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.TaskID;
    out << o.Data.ItemID;
    out << o.Data.Questions;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptAnswerYesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.TaskID;
    in >> o.Data.ItemID;
    in >> o.Data.Questions;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UserReportMessage::UserReportMessage (){
    type=UserReportType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UserReportMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ReportData.ReportType;
    out << o.ReportData.Category;
    out << o.ReportData.Position;
    out << o.ReportData.CheckFlags;
    out << o.ReportData.ScreenshotID;
    out << o.ReportData.ObjectID;
    out << o.ReportData.AbuserID;
    out << o.ReportData.AbuseRegionName;
    out << o.ReportData.AbuseRegionID;
    out << o.ReportData.Summary;
    out << o.ReportData.Details;
    out << o.ReportData.VersionString;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UserReportMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ReportData.ReportType;
    in >> o.ReportData.Category;
    in >> o.ReportData.Position;
    in >> o.ReportData.CheckFlags;
    in >> o.ReportData.ScreenshotID;
    in >> o.ReportData.ObjectID;
    in >> o.ReportData.AbuserID;
    in >> o.ReportData.AbuseRegionName;
    in >> o.ReportData.AbuseRegionID;
    in >> o.ReportData.Summary;
    in >> o.ReportData.Details;
    in >> o.ReportData.VersionString;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AlertMessageMessage::AlertMessageMessage (){
    type=AlertMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AlertMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AlertData.Message;

    out << (lltypes::U8)o.AlertInfo.size();
    for(int i=0;i<o.AlertInfo.size();i++){
         out << o.AlertInfo[i].Message;
         out << o.AlertInfo[i].ExtraParams;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AlertMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AlertData.Message;

    o.AlertInfo.clear();
    lltypes::U8 countAlertInfo;
    in >> countAlertInfo;
    for(int i=0;i<countAlertInfo;i++){
        AlertMessageMessage::AlertInfoBlock y;
        in >> y.Message;
        in >> y.ExtraParams;
        o.AlertInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentAlertMessageMessage::AgentAlertMessageMessage (){
    type=AgentAlertMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentAlertMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.AlertData.Modal;
    out << o.AlertData.Message;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentAlertMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.AlertData.Modal;
    in >> o.AlertData.Message;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MeanCollisionAlertMessage::MeanCollisionAlertMessage (){
    type=MeanCollisionAlertType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MeanCollisionAlertMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.MeanCollision.size();
    for(int i=0;i<o.MeanCollision.size();i++){
         out << o.MeanCollision[i].Victim;
         out << o.MeanCollision[i].Perp;
         out << o.MeanCollision[i].Time;
         out << o.MeanCollision[i].Mag;
         out << o.MeanCollision[i].Type;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MeanCollisionAlertMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.MeanCollision.clear();
    lltypes::U8 countMeanCollision;
    in >> countMeanCollision;
    for(int i=0;i<countMeanCollision;i++){
        MeanCollisionAlertMessage::MeanCollisionBlock y;
        in >> y.Victim;
        in >> y.Perp;
        in >> y.Time;
        in >> y.Mag;
        in >> y.Type;
        o.MeanCollision << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ViewerFrozenMessageMessage::ViewerFrozenMessageMessage (){
    type=ViewerFrozenMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ViewerFrozenMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.FrozenData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ViewerFrozenMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.FrozenData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


HealthMessageMessage::HealthMessageMessage (){
    type=HealthMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const HealthMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.HealthData.Health;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  HealthMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.HealthData.Health;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChatFromSimulatorMessage::ChatFromSimulatorMessage (){
    type=ChatFromSimulatorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChatFromSimulatorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ChatData.FromName;
    out << o.ChatData.SourceID;
    out << o.ChatData.OwnerID;
    out << o.ChatData.SourceType;
    out << o.ChatData.ChatType;
    out << o.ChatData.Audible;
    out << o.ChatData.Position;
    out << o.ChatData.Message;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChatFromSimulatorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ChatData.FromName;
    in >> o.ChatData.SourceID;
    in >> o.ChatData.OwnerID;
    in >> o.ChatData.SourceType;
    in >> o.ChatData.ChatType;
    in >> o.ChatData.Audible;
    in >> o.ChatData.Position;
    in >> o.ChatData.Message;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimStatsMessage::SimStatsMessage (){
    type=SimStatsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimStatsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Region.RegionX;
    out << o.Region.RegionY;
    out << o.Region.RegionFlags;
    out << o.Region.ObjectCapacity;

    out << (lltypes::U8)o.Stat.size();
    for(int i=0;i<o.Stat.size();i++){
         out << o.Stat[i].StatID;
         out << o.Stat[i].StatValue;
    }

    out << o.PidStat.PID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimStatsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Region.RegionX;
    in >> o.Region.RegionY;
    in >> o.Region.RegionFlags;
    in >> o.Region.ObjectCapacity;

    o.Stat.clear();
    lltypes::U8 countStat;
    in >> countStat;
    for(int i=0;i<countStat;i++){
        SimStatsMessage::StatBlock y;
        in >> y.StatID;
        in >> y.StatValue;
        o.Stat << y;
    }

    in >> o.PidStat.PID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestRegionInfoMessage::RequestRegionInfoMessage (){
    type=RequestRegionInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestRegionInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestRegionInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionInfoMessage::RegionInfoMessage (){
    type=RegionInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RegionInfo.SimName;
    out << o.RegionInfo.EstateID;
    out << o.RegionInfo.ParentEstateID;
    out << o.RegionInfo.RegionFlags;
    out << o.RegionInfo.SimAccess;
    out << o.RegionInfo.MaxAgents;
    out << o.RegionInfo.BillableFactor;
    out << o.RegionInfo.ObjectBonusFactor;
    out << o.RegionInfo.WaterHeight;
    out << o.RegionInfo.TerrainRaiseLimit;
    out << o.RegionInfo.TerrainLowerLimit;
    out << o.RegionInfo.PricePerMeter;
    out << o.RegionInfo.RedirectGridX;
    out << o.RegionInfo.RedirectGridY;
    out << o.RegionInfo.UseEstateSun;
    out << o.RegionInfo.SunHour;

    out << o.RegionInfo2.ProductSKU;
    out << o.RegionInfo2.ProductName;
    out << o.RegionInfo2.MaxAgents32;
    out << o.RegionInfo2.HardMaxAgents;
    out << o.RegionInfo2.HardMaxObjects;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RegionInfo.SimName;
    in >> o.RegionInfo.EstateID;
    in >> o.RegionInfo.ParentEstateID;
    in >> o.RegionInfo.RegionFlags;
    in >> o.RegionInfo.SimAccess;
    in >> o.RegionInfo.MaxAgents;
    in >> o.RegionInfo.BillableFactor;
    in >> o.RegionInfo.ObjectBonusFactor;
    in >> o.RegionInfo.WaterHeight;
    in >> o.RegionInfo.TerrainRaiseLimit;
    in >> o.RegionInfo.TerrainLowerLimit;
    in >> o.RegionInfo.PricePerMeter;
    in >> o.RegionInfo.RedirectGridX;
    in >> o.RegionInfo.RedirectGridY;
    in >> o.RegionInfo.UseEstateSun;
    in >> o.RegionInfo.SunHour;

    in >> o.RegionInfo2.ProductSKU;
    in >> o.RegionInfo2.ProductName;
    in >> o.RegionInfo2.MaxAgents32;
    in >> o.RegionInfo2.HardMaxAgents;
    in >> o.RegionInfo2.HardMaxObjects;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GodUpdateRegionInfoMessage::GodUpdateRegionInfoMessage (){
    type=GodUpdateRegionInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GodUpdateRegionInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RegionInfo.SimName;
    out << o.RegionInfo.EstateID;
    out << o.RegionInfo.ParentEstateID;
    out << o.RegionInfo.RegionFlags;
    out << o.RegionInfo.BillableFactor;
    out << o.RegionInfo.PricePerMeter;
    out << o.RegionInfo.RedirectGridX;
    out << o.RegionInfo.RedirectGridY;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GodUpdateRegionInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RegionInfo.SimName;
    in >> o.RegionInfo.EstateID;
    in >> o.RegionInfo.ParentEstateID;
    in >> o.RegionInfo.RegionFlags;
    in >> o.RegionInfo.BillableFactor;
    in >> o.RegionInfo.PricePerMeter;
    in >> o.RegionInfo.RedirectGridX;
    in >> o.RegionInfo.RedirectGridY;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NearestLandingRegionRequestMessage::NearestLandingRegionRequestMessage (){
    type=NearestLandingRegionRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NearestLandingRegionRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RequestingRegionData.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NearestLandingRegionRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RequestingRegionData.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NearestLandingRegionReplyMessage::NearestLandingRegionReplyMessage (){
    type=NearestLandingRegionReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NearestLandingRegionReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.LandingRegionData.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NearestLandingRegionReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.LandingRegionData.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NearestLandingRegionUpdatedMessage::NearestLandingRegionUpdatedMessage (){
    type=NearestLandingRegionUpdatedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NearestLandingRegionUpdatedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NearestLandingRegionUpdatedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TeleportLandingStatusChangedMessage::TeleportLandingStatusChangedMessage (){
    type=TeleportLandingStatusChangedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TeleportLandingStatusChangedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TeleportLandingStatusChangedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionHandshakeMessage::RegionHandshakeMessage (){
    type=RegionHandshakeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionHandshakeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionInfo.RegionFlags;
    out << o.RegionInfo.SimAccess;
    out << o.RegionInfo.SimName;
    out << o.RegionInfo.SimOwner;
    out << o.RegionInfo.IsEstateManager;
    out << o.RegionInfo.WaterHeight;
    out << o.RegionInfo.BillableFactor;
    out << o.RegionInfo.CacheID;
    out << o.RegionInfo.TerrainBase0;
    out << o.RegionInfo.TerrainBase1;
    out << o.RegionInfo.TerrainBase2;
    out << o.RegionInfo.TerrainBase3;
    out << o.RegionInfo.TerrainDetail0;
    out << o.RegionInfo.TerrainDetail1;
    out << o.RegionInfo.TerrainDetail2;
    out << o.RegionInfo.TerrainDetail3;
    out << o.RegionInfo.TerrainStartHeight00;
    out << o.RegionInfo.TerrainStartHeight01;
    out << o.RegionInfo.TerrainStartHeight10;
    out << o.RegionInfo.TerrainStartHeight11;
    out << o.RegionInfo.TerrainHeightRange00;
    out << o.RegionInfo.TerrainHeightRange01;
    out << o.RegionInfo.TerrainHeightRange10;
    out << o.RegionInfo.TerrainHeightRange11;

    out << o.RegionInfo2.RegionID;

    out << o.RegionInfo3.CPUClassID;
    out << o.RegionInfo3.CPURatio;
    out << o.RegionInfo3.ColoName;
    out << o.RegionInfo3.ProductSKU;
    out << o.RegionInfo3.ProductName;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionHandshakeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionInfo.RegionFlags;
    in >> o.RegionInfo.SimAccess;
    in >> o.RegionInfo.SimName;
    in >> o.RegionInfo.SimOwner;
    in >> o.RegionInfo.IsEstateManager;
    in >> o.RegionInfo.WaterHeight;
    in >> o.RegionInfo.BillableFactor;
    in >> o.RegionInfo.CacheID;
    in >> o.RegionInfo.TerrainBase0;
    in >> o.RegionInfo.TerrainBase1;
    in >> o.RegionInfo.TerrainBase2;
    in >> o.RegionInfo.TerrainBase3;
    in >> o.RegionInfo.TerrainDetail0;
    in >> o.RegionInfo.TerrainDetail1;
    in >> o.RegionInfo.TerrainDetail2;
    in >> o.RegionInfo.TerrainDetail3;
    in >> o.RegionInfo.TerrainStartHeight00;
    in >> o.RegionInfo.TerrainStartHeight01;
    in >> o.RegionInfo.TerrainStartHeight10;
    in >> o.RegionInfo.TerrainStartHeight11;
    in >> o.RegionInfo.TerrainHeightRange00;
    in >> o.RegionInfo.TerrainHeightRange01;
    in >> o.RegionInfo.TerrainHeightRange10;
    in >> o.RegionInfo.TerrainHeightRange11;

    in >> o.RegionInfo2.RegionID;

    in >> o.RegionInfo3.CPUClassID;
    in >> o.RegionInfo3.CPURatio;
    in >> o.RegionInfo3.ColoName;
    in >> o.RegionInfo3.ProductSKU;
    in >> o.RegionInfo3.ProductName;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionHandshakeReplyMessage::RegionHandshakeReplyMessage (){
    type=RegionHandshakeReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionHandshakeReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RegionInfo.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionHandshakeReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RegionInfo.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CoarseLocationUpdateMessage::CoarseLocationUpdateMessage (){
    type=CoarseLocationUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CoarseLocationUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.Location.size();
    for(int i=0;i<o.Location.size();i++){
         out << o.Location[i].X;
         out << o.Location[i].Y;
         out << o.Location[i].Z;
    }

    out << o.Index.You;
    out << o.Index.Prey;

    out << (lltypes::U8)o.AgentData.size();
    for(int i=0;i<o.AgentData.size();i++){
         out << o.AgentData[i].AgentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CoarseLocationUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.Location.clear();
    lltypes::U8 countLocation;
    in >> countLocation;
    for(int i=0;i<countLocation;i++){
        CoarseLocationUpdateMessage::LocationBlock y;
        in >> y.X;
        in >> y.Y;
        in >> y.Z;
        o.Location << y;
    }

    in >> o.Index.You;
    in >> o.Index.Prey;

    o.AgentData.clear();
    lltypes::U8 countAgentData;
    in >> countAgentData;
    for(int i=0;i<countAgentData;i++){
        CoarseLocationUpdateMessage::AgentDataBlock y;
        in >> y.AgentID;
        o.AgentData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ImageDataMessage::ImageDataMessage (){
    type=ImageDataType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ImageDataMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ImageID.ID;
    out << o.ImageID.Codec;
    out << o.ImageID.Size;
    out << o.ImageID.Packets;

    out << o.ImageData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ImageDataMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ImageID.ID;
    in >> o.ImageID.Codec;
    in >> o.ImageID.Size;
    in >> o.ImageID.Packets;

    in >> o.ImageData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ImagePacketMessage::ImagePacketMessage (){
    type=ImagePacketType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ImagePacketMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ImageID.ID;
    out << o.ImageID.Packet;

    out << o.ImageData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ImagePacketMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ImageID.ID;
    in >> o.ImageID.Packet;

    in >> o.ImageData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LayerDataMessage::LayerDataMessage (){
    type=LayerDataType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LayerDataMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.LayerID.Type;

    out << o.LayerData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LayerDataMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.LayerID.Type;

    in >> o.LayerData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectUpdateMessage::ObjectUpdateMessage (){
    type=ObjectUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;
    out << o.RegionData.TimeDilation;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ID;
         out << o.ObjectData[i].State;
         out << o.ObjectData[i].FullID;
         out << o.ObjectData[i].CRC;
         out << o.ObjectData[i].PCode;
         out << o.ObjectData[i].Material;
         out << o.ObjectData[i].ClickAction;
         out << o.ObjectData[i].Scale;
         out << o.ObjectData[i].ObjectData;
         out << o.ObjectData[i].ParentID;
         out << o.ObjectData[i].UpdateFlags;
         out << o.ObjectData[i].PathCurve;
         out << o.ObjectData[i].ProfileCurve;
         out << o.ObjectData[i].PathBegin;
         out << o.ObjectData[i].PathEnd;
         out << o.ObjectData[i].PathScaleX;
         out << o.ObjectData[i].PathScaleY;
         out << o.ObjectData[i].PathShearX;
         out << o.ObjectData[i].PathShearY;
         out << o.ObjectData[i].PathTwist;
         out << o.ObjectData[i].PathTwistBegin;
         out << o.ObjectData[i].PathRadiusOffset;
         out << o.ObjectData[i].PathTaperX;
         out << o.ObjectData[i].PathTaperY;
         out << o.ObjectData[i].PathRevolutions;
         out << o.ObjectData[i].PathSkew;
         out << o.ObjectData[i].ProfileBegin;
         out << o.ObjectData[i].ProfileEnd;
         out << o.ObjectData[i].ProfileHollow;
         out << o.ObjectData[i].TextureEntry;
         out << o.ObjectData[i].TextureAnim;
         out << o.ObjectData[i].NameValue;
         out << o.ObjectData[i].Data;
         out << o.ObjectData[i].Text;
         out << o.ObjectData[i].TextColor;
         out << o.ObjectData[i].MediaURL;
         out << o.ObjectData[i].PSBlock;
         out << o.ObjectData[i].ExtraParams;
         out << o.ObjectData[i].Sound;
         out << o.ObjectData[i].OwnerID;
         out << o.ObjectData[i].Gain;
         out << o.ObjectData[i].Flags;
         out << o.ObjectData[i].Radius;
         out << o.ObjectData[i].JointType;
         out << o.ObjectData[i].JointPivot;
         out << o.ObjectData[i].JointAxisOrAnchor;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;
    in >> o.RegionData.TimeDilation;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectUpdateMessage::ObjectDataBlock y;
        in >> y.ID;
        in >> y.State;
        in >> y.FullID;
        in >> y.CRC;
        in >> y.PCode;
        in >> y.Material;
        in >> y.ClickAction;
        in >> y.Scale;
        in >> y.ObjectData;
        in >> y.ParentID;
        in >> y.UpdateFlags;
        in >> y.PathCurve;
        in >> y.ProfileCurve;
        in >> y.PathBegin;
        in >> y.PathEnd;
        in >> y.PathScaleX;
        in >> y.PathScaleY;
        in >> y.PathShearX;
        in >> y.PathShearY;
        in >> y.PathTwist;
        in >> y.PathTwistBegin;
        in >> y.PathRadiusOffset;
        in >> y.PathTaperX;
        in >> y.PathTaperY;
        in >> y.PathRevolutions;
        in >> y.PathSkew;
        in >> y.ProfileBegin;
        in >> y.ProfileEnd;
        in >> y.ProfileHollow;
        in >> y.TextureEntry;
        in >> y.TextureAnim;
        in >> y.NameValue;
        in >> y.Data;
        in >> y.Text;
        in >> y.TextColor;
        in >> y.MediaURL;
        in >> y.PSBlock;
        in >> y.ExtraParams;
        in >> y.Sound;
        in >> y.OwnerID;
        in >> y.Gain;
        in >> y.Flags;
        in >> y.Radius;
        in >> y.JointType;
        in >> y.JointPivot;
        in >> y.JointAxisOrAnchor;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectUpdateCompressedMessage::ObjectUpdateCompressedMessage (){
    type=ObjectUpdateCompressedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectUpdateCompressedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;
    out << o.RegionData.TimeDilation;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].UpdateFlags;
         out << o.ObjectData[i].Data;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectUpdateCompressedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;
    in >> o.RegionData.TimeDilation;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectUpdateCompressedMessage::ObjectDataBlock y;
        in >> y.UpdateFlags;
        in >> y.Data;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectUpdateCachedMessage::ObjectUpdateCachedMessage (){
    type=ObjectUpdateCachedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectUpdateCachedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;
    out << o.RegionData.TimeDilation;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ID;
         out << o.ObjectData[i].CRC;
         out << o.ObjectData[i].UpdateFlags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectUpdateCachedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;
    in >> o.RegionData.TimeDilation;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectUpdateCachedMessage::ObjectDataBlock y;
        in >> y.ID;
        in >> y.CRC;
        in >> y.UpdateFlags;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ImprovedTerseObjectUpdateMessage::ImprovedTerseObjectUpdateMessage (){
    type=ImprovedTerseObjectUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ImprovedTerseObjectUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RegionData.RegionHandle;
    out << o.RegionData.TimeDilation;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].Data;
         out << o.ObjectData[i].TextureEntry;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ImprovedTerseObjectUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RegionData.RegionHandle;
    in >> o.RegionData.TimeDilation;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ImprovedTerseObjectUpdateMessage::ObjectDataBlock y;
        in >> y.Data;
        in >> y.TextureEntry;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


KillObjectMessage::KillObjectMessage (){
    type=KillObjectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const KillObjectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  KillObjectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        KillObjectMessage::ObjectDataBlock y;
        in >> y.ID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CrossedRegionMessage::CrossedRegionMessage (){
    type=CrossedRegionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CrossedRegionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RegionData.SimIP;
    out << o.RegionData.SimPort;
    out << o.RegionData.RegionHandle;
    out << o.RegionData.SeedCapability;

    out << o.Info.Position;
    out << o.Info.LookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CrossedRegionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RegionData.SimIP;
    in >> o.RegionData.SimPort;
    in >> o.RegionData.RegionHandle;
    in >> o.RegionData.SeedCapability;

    in >> o.Info.Position;
    in >> o.Info.LookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimulatorViewerTimeMessageMessage::SimulatorViewerTimeMessageMessage (){
    type=SimulatorViewerTimeMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimulatorViewerTimeMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TimeInfo.UsecSinceStart;
    out << o.TimeInfo.SecPerDay;
    out << o.TimeInfo.SecPerYear;
    out << o.TimeInfo.SunDirection;
    out << o.TimeInfo.SunPhase;
    out << o.TimeInfo.SunAngVelocity;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimulatorViewerTimeMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TimeInfo.UsecSinceStart;
    in >> o.TimeInfo.SecPerDay;
    in >> o.TimeInfo.SecPerYear;
    in >> o.TimeInfo.SunDirection;
    in >> o.TimeInfo.SunPhase;
    in >> o.TimeInfo.SunAngVelocity;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EnableSimulatorMessage::EnableSimulatorMessage (){
    type=EnableSimulatorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EnableSimulatorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimulatorInfo.Handle;
    out << o.SimulatorInfo.IP;
    out << o.SimulatorInfo.Port;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EnableSimulatorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimulatorInfo.Handle;
    in >> o.SimulatorInfo.IP;
    in >> o.SimulatorInfo.Port;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DisableSimulatorMessage::DisableSimulatorMessage (){
    type=DisableSimulatorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DisableSimulatorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DisableSimulatorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ConfirmEnableSimulatorMessage::ConfirmEnableSimulatorMessage (){
    type=ConfirmEnableSimulatorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ConfirmEnableSimulatorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ConfirmEnableSimulatorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferRequestMessage::TransferRequestMessage (){
    type=TransferRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransferInfo.TransferID;
    out << o.TransferInfo.ChannelType;
    out << o.TransferInfo.SourceType;
    out << o.TransferInfo.Priority;
    out << o.TransferInfo.Params;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransferInfo.TransferID;
    in >> o.TransferInfo.ChannelType;
    in >> o.TransferInfo.SourceType;
    in >> o.TransferInfo.Priority;
    in >> o.TransferInfo.Params;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferInfoMessage::TransferInfoMessage (){
    type=TransferInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransferInfo.TransferID;
    out << o.TransferInfo.ChannelType;
    out << o.TransferInfo.TargetType;
    out << o.TransferInfo.Status;
    out << o.TransferInfo.Size;
    out << o.TransferInfo.Params;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransferInfo.TransferID;
    in >> o.TransferInfo.ChannelType;
    in >> o.TransferInfo.TargetType;
    in >> o.TransferInfo.Status;
    in >> o.TransferInfo.Size;
    in >> o.TransferInfo.Params;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferPacketMessage::TransferPacketMessage (){
    type=TransferPacketType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferPacketMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransferData.TransferID;
    out << o.TransferData.ChannelType;
    out << o.TransferData.Packet;
    out << o.TransferData.Status;
    out << o.TransferData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferPacketMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransferData.TransferID;
    in >> o.TransferData.ChannelType;
    in >> o.TransferData.Packet;
    in >> o.TransferData.Status;
    in >> o.TransferData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferAbortMessage::TransferAbortMessage (){
    type=TransferAbortType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferAbortMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransferInfo.TransferID;
    out << o.TransferInfo.ChannelType;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferAbortMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransferInfo.TransferID;
    in >> o.TransferInfo.ChannelType;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestXferMessage::RequestXferMessage (){
    type=RequestXferType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestXferMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.XferID.ID;
    out << o.XferID.Filename;
    out << o.XferID.FilePath;
    out << o.XferID.DeleteOnCompletion;
    out << o.XferID.UseBigPackets;
    out << o.XferID.VFileID;
    out << o.XferID.VFileType;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestXferMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.XferID.ID;
    in >> o.XferID.Filename;
    in >> o.XferID.FilePath;
    in >> o.XferID.DeleteOnCompletion;
    in >> o.XferID.UseBigPackets;
    in >> o.XferID.VFileID;
    in >> o.XferID.VFileType;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SendXferPacketMessage::SendXferPacketMessage (){
    type=SendXferPacketType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SendXferPacketMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.XferID.ID;
    out << o.XferID.Packet;

    out << o.DataPacket.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SendXferPacketMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.XferID.ID;
    in >> o.XferID.Packet;

    in >> o.DataPacket.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ConfirmXferPacketMessage::ConfirmXferPacketMessage (){
    type=ConfirmXferPacketType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ConfirmXferPacketMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.XferID.ID;
    out << o.XferID.Packet;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ConfirmXferPacketMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.XferID.ID;
    in >> o.XferID.Packet;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AbortXferMessage::AbortXferMessage (){
    type=AbortXferType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AbortXferMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.XferID.ID;
    out << o.XferID.Result;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AbortXferMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.XferID.ID;
    in >> o.XferID.Result;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarAnimationMessage::AvatarAnimationMessage (){
    type=AvatarAnimationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarAnimationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Sender.ID;

    out << (lltypes::U8)o.AnimationList.size();
    for(int i=0;i<o.AnimationList.size();i++){
         out << o.AnimationList[i].AnimID;
         out << o.AnimationList[i].AnimSequenceID;
    }

    out << (lltypes::U8)o.AnimationSourceList.size();
    for(int i=0;i<o.AnimationSourceList.size();i++){
         out << o.AnimationSourceList[i].ObjectID;
    }

    out << (lltypes::U8)o.PhysicalAvatarEventList.size();
    for(int i=0;i<o.PhysicalAvatarEventList.size();i++){
         out << o.PhysicalAvatarEventList[i].TypeData;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarAnimationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Sender.ID;

    o.AnimationList.clear();
    lltypes::U8 countAnimationList;
    in >> countAnimationList;
    for(int i=0;i<countAnimationList;i++){
        AvatarAnimationMessage::AnimationListBlock y;
        in >> y.AnimID;
        in >> y.AnimSequenceID;
        o.AnimationList << y;
    }

    o.AnimationSourceList.clear();
    lltypes::U8 countAnimationSourceList;
    in >> countAnimationSourceList;
    for(int i=0;i<countAnimationSourceList;i++){
        AvatarAnimationMessage::AnimationSourceListBlock y;
        in >> y.ObjectID;
        o.AnimationSourceList << y;
    }

    o.PhysicalAvatarEventList.clear();
    lltypes::U8 countPhysicalAvatarEventList;
    in >> countPhysicalAvatarEventList;
    for(int i=0;i<countPhysicalAvatarEventList;i++){
        AvatarAnimationMessage::PhysicalAvatarEventListBlock y;
        in >> y.TypeData;
        o.PhysicalAvatarEventList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarAppearanceMessage::AvatarAppearanceMessage (){
    type=AvatarAppearanceType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarAppearanceMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Sender.ID;
    out << o.Sender.IsTrial;

    out << o.ObjectData.TextureEntry;

    out << (lltypes::U8)o.VisualParam.size();
    for(int i=0;i<o.VisualParam.size();i++){
         out << o.VisualParam[i].ParamValue;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarAppearanceMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Sender.ID;
    in >> o.Sender.IsTrial;

    in >> o.ObjectData.TextureEntry;

    o.VisualParam.clear();
    lltypes::U8 countVisualParam;
    in >> countVisualParam;
    for(int i=0;i<countVisualParam;i++){
        AvatarAppearanceMessage::VisualParamBlock y;
        in >> y.ParamValue;
        o.VisualParam << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarSitResponseMessage::AvatarSitResponseMessage (){
    type=AvatarSitResponseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarSitResponseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SitObject.ID;

    out << o.SitTransform.AutoPilot;
    out << o.SitTransform.SitPosition;
    out << o.SitTransform.SitRotation;
    out << o.SitTransform.CameraEyeOffset;
    out << o.SitTransform.CameraAtOffset;
    out << o.SitTransform.ForceMouselook;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarSitResponseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SitObject.ID;

    in >> o.SitTransform.AutoPilot;
    in >> o.SitTransform.SitPosition;
    in >> o.SitTransform.SitRotation;
    in >> o.SitTransform.CameraEyeOffset;
    in >> o.SitTransform.CameraAtOffset;
    in >> o.SitTransform.ForceMouselook;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetFollowCamPropertiesMessage::SetFollowCamPropertiesMessage (){
    type=SetFollowCamPropertiesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetFollowCamPropertiesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.ObjectID;

    out << (lltypes::U8)o.CameraProperty.size();
    for(int i=0;i<o.CameraProperty.size();i++){
         out << o.CameraProperty[i].Type;
         out << o.CameraProperty[i].Value;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetFollowCamPropertiesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.ObjectID;

    o.CameraProperty.clear();
    lltypes::U8 countCameraProperty;
    in >> countCameraProperty;
    for(int i=0;i<countCameraProperty;i++){
        SetFollowCamPropertiesMessage::CameraPropertyBlock y;
        in >> y.Type;
        in >> y.Value;
        o.CameraProperty << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ClearFollowCamPropertiesMessage::ClearFollowCamPropertiesMessage (){
    type=ClearFollowCamPropertiesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ClearFollowCamPropertiesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.ObjectID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ClearFollowCamPropertiesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.ObjectID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CameraConstraintMessage::CameraConstraintMessage (){
    type=CameraConstraintType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CameraConstraintMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.CameraCollidePlane.Plane;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CameraConstraintMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.CameraCollidePlane.Plane;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectPropertiesMessage::ObjectPropertiesMessage (){
    type=ObjectPropertiesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectPropertiesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectID;
         out << o.ObjectData[i].CreatorID;
         out << o.ObjectData[i].OwnerID;
         out << o.ObjectData[i].GroupID;
         out << o.ObjectData[i].CreationDate;
         out << o.ObjectData[i].BaseMask;
         out << o.ObjectData[i].OwnerMask;
         out << o.ObjectData[i].GroupMask;
         out << o.ObjectData[i].EveryoneMask;
         out << o.ObjectData[i].NextOwnerMask;
         out << o.ObjectData[i].OwnershipCost;
         out << o.ObjectData[i].SaleType;
         out << o.ObjectData[i].SalePrice;
         out << o.ObjectData[i].AggregatePerms;
         out << o.ObjectData[i].AggregatePermTextures;
         out << o.ObjectData[i].AggregatePermTexturesOwner;
         out << o.ObjectData[i].Category;
         out << o.ObjectData[i].InventorySerial;
         out << o.ObjectData[i].ItemID;
         out << o.ObjectData[i].FolderID;
         out << o.ObjectData[i].FromTaskID;
         out << o.ObjectData[i].LastOwnerID;
         out << o.ObjectData[i].Name;
         out << o.ObjectData[i].Description;
         out << o.ObjectData[i].TouchName;
         out << o.ObjectData[i].SitName;
         out << o.ObjectData[i].TextureID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectPropertiesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectPropertiesMessage::ObjectDataBlock y;
        in >> y.ObjectID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.CreationDate;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.OwnershipCost;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.AggregatePerms;
        in >> y.AggregatePermTextures;
        in >> y.AggregatePermTexturesOwner;
        in >> y.Category;
        in >> y.InventorySerial;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.FromTaskID;
        in >> y.LastOwnerID;
        in >> y.Name;
        in >> y.Description;
        in >> y.TouchName;
        in >> y.SitName;
        in >> y.TextureID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectPropertiesFamilyMessage::ObjectPropertiesFamilyMessage (){
    type=ObjectPropertiesFamilyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectPropertiesFamilyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.RequestFlags;
    out << o.ObjectData.ObjectID;
    out << o.ObjectData.OwnerID;
    out << o.ObjectData.GroupID;
    out << o.ObjectData.BaseMask;
    out << o.ObjectData.OwnerMask;
    out << o.ObjectData.GroupMask;
    out << o.ObjectData.EveryoneMask;
    out << o.ObjectData.NextOwnerMask;
    out << o.ObjectData.OwnershipCost;
    out << o.ObjectData.SaleType;
    out << o.ObjectData.SalePrice;
    out << o.ObjectData.Category;
    out << o.ObjectData.LastOwnerID;
    out << o.ObjectData.Name;
    out << o.ObjectData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectPropertiesFamilyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.RequestFlags;
    in >> o.ObjectData.ObjectID;
    in >> o.ObjectData.OwnerID;
    in >> o.ObjectData.GroupID;
    in >> o.ObjectData.BaseMask;
    in >> o.ObjectData.OwnerMask;
    in >> o.ObjectData.GroupMask;
    in >> o.ObjectData.EveryoneMask;
    in >> o.ObjectData.NextOwnerMask;
    in >> o.ObjectData.OwnershipCost;
    in >> o.ObjectData.SaleType;
    in >> o.ObjectData.SalePrice;
    in >> o.ObjectData.Category;
    in >> o.ObjectData.LastOwnerID;
    in >> o.ObjectData.Name;
    in >> o.ObjectData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestPayPriceMessage::RequestPayPriceMessage (){
    type=RequestPayPriceType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestPayPriceMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.ObjectID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestPayPriceMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.ObjectID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PayPriceReplyMessage::PayPriceReplyMessage (){
    type=PayPriceReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PayPriceReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.ObjectID;
    out << o.ObjectData.DefaultPayPrice;

    out << (lltypes::U8)o.ButtonData.size();
    for(int i=0;i<o.ButtonData.size();i++){
         out << o.ButtonData[i].PayButton;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PayPriceReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.ObjectID;
    in >> o.ObjectData.DefaultPayPrice;

    o.ButtonData.clear();
    lltypes::U8 countButtonData;
    in >> countButtonData;
    for(int i=0;i<countButtonData;i++){
        PayPriceReplyMessage::ButtonDataBlock y;
        in >> y.PayButton;
        o.ButtonData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


KickUserMessage::KickUserMessage (){
    type=KickUserType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const KickUserMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TargetBlock.TargetIP;
    out << o.TargetBlock.TargetPort;

    out << o.UserInfo.AgentID;
    out << o.UserInfo.SessionID;
    out << o.UserInfo.Reason;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  KickUserMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TargetBlock.TargetIP;
    in >> o.TargetBlock.TargetPort;

    in >> o.UserInfo.AgentID;
    in >> o.UserInfo.SessionID;
    in >> o.UserInfo.Reason;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


KickUserAckMessage::KickUserAckMessage (){
    type=KickUserAckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const KickUserAckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.UserInfo.SessionID;
    out << o.UserInfo.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  KickUserAckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.UserInfo.SessionID;
    in >> o.UserInfo.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GodKickUserMessage::GodKickUserMessage (){
    type=GodKickUserType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GodKickUserMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.UserInfo.GodID;
    out << o.UserInfo.GodSessionID;
    out << o.UserInfo.AgentID;
    out << o.UserInfo.KickFlags;
    out << o.UserInfo.Reason;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GodKickUserMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.UserInfo.GodID;
    in >> o.UserInfo.GodSessionID;
    in >> o.UserInfo.AgentID;
    in >> o.UserInfo.KickFlags;
    in >> o.UserInfo.Reason;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SystemKickUserMessage::SystemKickUserMessage (){
    type=SystemKickUserType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SystemKickUserMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.AgentInfo.size();
    for(int i=0;i<o.AgentInfo.size();i++){
         out << o.AgentInfo[i].AgentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SystemKickUserMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.AgentInfo.clear();
    lltypes::U8 countAgentInfo;
    in >> countAgentInfo;
    for(int i=0;i<countAgentInfo;i++){
        SystemKickUserMessage::AgentInfoBlock y;
        in >> y.AgentID;
        o.AgentInfo << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EjectUserMessage::EjectUserMessage (){
    type=EjectUserType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EjectUserMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.TargetID;
    out << o.Data.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EjectUserMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.TargetID;
    in >> o.Data.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FreezeUserMessage::FreezeUserMessage (){
    type=FreezeUserType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FreezeUserMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.TargetID;
    out << o.Data.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FreezeUserMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.TargetID;
    in >> o.Data.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPropertiesRequestMessage::AvatarPropertiesRequestMessage (){
    type=AvatarPropertiesRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPropertiesRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AvatarID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPropertiesRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AvatarID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPropertiesRequestBackendMessage::AvatarPropertiesRequestBackendMessage (){
    type=AvatarPropertiesRequestBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPropertiesRequestBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.AvatarID;
    out << o.AgentData.GodLevel;
    out << o.AgentData.WebProfilesDisabled;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPropertiesRequestBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.AvatarID;
    in >> o.AgentData.GodLevel;
    in >> o.AgentData.WebProfilesDisabled;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPropertiesReplyMessage::AvatarPropertiesReplyMessage (){
    type=AvatarPropertiesReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPropertiesReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.AvatarID;

    out << o.PropertiesData.ImageID;
    out << o.PropertiesData.FLImageID;
    out << o.PropertiesData.PartnerID;
    out << o.PropertiesData.AboutText;
    out << o.PropertiesData.FLAboutText;
    out << o.PropertiesData.BornOn;
    out << o.PropertiesData.ProfileURL;
    out << o.PropertiesData.CharterMember;
    out << o.PropertiesData.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPropertiesReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.AvatarID;

    in >> o.PropertiesData.ImageID;
    in >> o.PropertiesData.FLImageID;
    in >> o.PropertiesData.PartnerID;
    in >> o.PropertiesData.AboutText;
    in >> o.PropertiesData.FLAboutText;
    in >> o.PropertiesData.BornOn;
    in >> o.PropertiesData.ProfileURL;
    in >> o.PropertiesData.CharterMember;
    in >> o.PropertiesData.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarInterestsReplyMessage::AvatarInterestsReplyMessage (){
    type=AvatarInterestsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarInterestsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.AvatarID;

    out << o.PropertiesData.WantToMask;
    out << o.PropertiesData.WantToText;
    out << o.PropertiesData.SkillsMask;
    out << o.PropertiesData.SkillsText;
    out << o.PropertiesData.LanguagesText;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarInterestsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.AvatarID;

    in >> o.PropertiesData.WantToMask;
    in >> o.PropertiesData.WantToText;
    in >> o.PropertiesData.SkillsMask;
    in >> o.PropertiesData.SkillsText;
    in >> o.PropertiesData.LanguagesText;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarGroupsReplyMessage::AvatarGroupsReplyMessage (){
    type=AvatarGroupsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarGroupsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.AvatarID;

    out << (lltypes::U8)o.GroupData.size();
    for(int i=0;i<o.GroupData.size();i++){
         out << o.GroupData[i].GroupPowers;
         out << o.GroupData[i].AcceptNotices;
         out << o.GroupData[i].GroupTitle;
         out << o.GroupData[i].GroupID;
         out << o.GroupData[i].GroupName;
         out << o.GroupData[i].GroupInsigniaID;
    }

    out << o.NewGroupData.ListInProfile;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarGroupsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.AvatarID;

    o.GroupData.clear();
    lltypes::U8 countGroupData;
    in >> countGroupData;
    for(int i=0;i<countGroupData;i++){
        AvatarGroupsReplyMessage::GroupDataBlock y;
        in >> y.GroupPowers;
        in >> y.AcceptNotices;
        in >> y.GroupTitle;
        in >> y.GroupID;
        in >> y.GroupName;
        in >> y.GroupInsigniaID;
        o.GroupData << y;
    }

    in >> o.NewGroupData.ListInProfile;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPropertiesUpdateMessage::AvatarPropertiesUpdateMessage (){
    type=AvatarPropertiesUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPropertiesUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.PropertiesData.ImageID;
    out << o.PropertiesData.FLImageID;
    out << o.PropertiesData.AboutText;
    out << o.PropertiesData.FLAboutText;
    out << o.PropertiesData.AllowPublish;
    out << o.PropertiesData.MaturePublish;
    out << o.PropertiesData.ProfileURL;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPropertiesUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.PropertiesData.ImageID;
    in >> o.PropertiesData.FLImageID;
    in >> o.PropertiesData.AboutText;
    in >> o.PropertiesData.FLAboutText;
    in >> o.PropertiesData.AllowPublish;
    in >> o.PropertiesData.MaturePublish;
    in >> o.PropertiesData.ProfileURL;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarInterestsUpdateMessage::AvatarInterestsUpdateMessage (){
    type=AvatarInterestsUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarInterestsUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.PropertiesData.WantToMask;
    out << o.PropertiesData.WantToText;
    out << o.PropertiesData.SkillsMask;
    out << o.PropertiesData.SkillsText;
    out << o.PropertiesData.LanguagesText;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarInterestsUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.PropertiesData.WantToMask;
    in >> o.PropertiesData.WantToText;
    in >> o.PropertiesData.SkillsMask;
    in >> o.PropertiesData.SkillsText;
    in >> o.PropertiesData.LanguagesText;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarNotesReplyMessage::AvatarNotesReplyMessage (){
    type=AvatarNotesReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarNotesReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.TargetID;
    out << o.Data.Notes;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarNotesReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.TargetID;
    in >> o.Data.Notes;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarNotesUpdateMessage::AvatarNotesUpdateMessage (){
    type=AvatarNotesUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarNotesUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.TargetID;
    out << o.Data.Notes;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarNotesUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.TargetID;
    in >> o.Data.Notes;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AvatarPicksReplyMessage::AvatarPicksReplyMessage (){
    type=AvatarPicksReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AvatarPicksReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.TargetID;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].PickID;
         out << o.Data[i].PickName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AvatarPicksReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.TargetID;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        AvatarPicksReplyMessage::DataBlock y;
        in >> y.PickID;
        in >> y.PickName;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventInfoRequestMessage::EventInfoRequestMessage (){
    type=EventInfoRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventInfoRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.EventData.EventID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventInfoRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.EventData.EventID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventInfoReplyMessage::EventInfoReplyMessage (){
    type=EventInfoReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventInfoReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.EventData.EventID;
    out << o.EventData.Creator;
    out << o.EventData.Name;
    out << o.EventData.Category;
    out << o.EventData.Desc;
    out << o.EventData.Date;
    out << o.EventData.DateUTC;
    out << o.EventData.Duration;
    out << o.EventData.Cover;
    out << o.EventData.Amount;
    out << o.EventData.SimName;
    out << o.EventData.GlobalPos;
    out << o.EventData.EventFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventInfoReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.EventData.EventID;
    in >> o.EventData.Creator;
    in >> o.EventData.Name;
    in >> o.EventData.Category;
    in >> o.EventData.Desc;
    in >> o.EventData.Date;
    in >> o.EventData.DateUTC;
    in >> o.EventData.Duration;
    in >> o.EventData.Cover;
    in >> o.EventData.Amount;
    in >> o.EventData.SimName;
    in >> o.EventData.GlobalPos;
    in >> o.EventData.EventFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventNotificationAddRequestMessage::EventNotificationAddRequestMessage (){
    type=EventNotificationAddRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventNotificationAddRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.EventData.EventID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventNotificationAddRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.EventData.EventID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventNotificationRemoveRequestMessage::EventNotificationRemoveRequestMessage (){
    type=EventNotificationRemoveRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventNotificationRemoveRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.EventData.EventID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventNotificationRemoveRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.EventData.EventID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventGodDeleteMessage::EventGodDeleteMessage (){
    type=EventGodDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventGodDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.EventData.EventID;

    out << o.QueryData.QueryID;
    out << o.QueryData.QueryText;
    out << o.QueryData.QueryFlags;
    out << o.QueryData.QueryStart;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventGodDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.EventData.EventID;

    in >> o.QueryData.QueryID;
    in >> o.QueryData.QueryText;
    in >> o.QueryData.QueryFlags;
    in >> o.QueryData.QueryStart;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PickInfoReplyMessage::PickInfoReplyMessage (){
    type=PickInfoReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PickInfoReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.PickID;
    out << o.Data.CreatorID;
    out << o.Data.TopPick;
    out << o.Data.ParcelID;
    out << o.Data.Name;
    out << o.Data.Desc;
    out << o.Data.SnapshotID;
    out << o.Data.User;
    out << o.Data.OriginalName;
    out << o.Data.SimName;
    out << o.Data.PosGlobal;
    out << o.Data.SortOrder;
    out << o.Data.Enabled;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PickInfoReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.PickID;
    in >> o.Data.CreatorID;
    in >> o.Data.TopPick;
    in >> o.Data.ParcelID;
    in >> o.Data.Name;
    in >> o.Data.Desc;
    in >> o.Data.SnapshotID;
    in >> o.Data.User;
    in >> o.Data.OriginalName;
    in >> o.Data.SimName;
    in >> o.Data.PosGlobal;
    in >> o.Data.SortOrder;
    in >> o.Data.Enabled;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PickInfoUpdateMessage::PickInfoUpdateMessage (){
    type=PickInfoUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PickInfoUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.PickID;
    out << o.Data.CreatorID;
    out << o.Data.TopPick;
    out << o.Data.ParcelID;
    out << o.Data.Name;
    out << o.Data.Desc;
    out << o.Data.SnapshotID;
    out << o.Data.PosGlobal;
    out << o.Data.SortOrder;
    out << o.Data.Enabled;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PickInfoUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.PickID;
    in >> o.Data.CreatorID;
    in >> o.Data.TopPick;
    in >> o.Data.ParcelID;
    in >> o.Data.Name;
    in >> o.Data.Desc;
    in >> o.Data.SnapshotID;
    in >> o.Data.PosGlobal;
    in >> o.Data.SortOrder;
    in >> o.Data.Enabled;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PickDeleteMessage::PickDeleteMessage (){
    type=PickDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PickDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.PickID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PickDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.PickID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PickGodDeleteMessage::PickGodDeleteMessage (){
    type=PickGodDeleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PickGodDeleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.PickID;
    out << o.Data.QueryID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PickGodDeleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.PickID;
    in >> o.Data.QueryID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptQuestionMessage::ScriptQuestionMessage (){
    type=ScriptQuestionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptQuestionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.TaskID;
    out << o.Data.ItemID;
    out << o.Data.ObjectName;
    out << o.Data.ObjectOwner;
    out << o.Data.Questions;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptQuestionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.TaskID;
    in >> o.Data.ItemID;
    in >> o.Data.ObjectName;
    in >> o.Data.ObjectOwner;
    in >> o.Data.Questions;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptControlChangeMessage::ScriptControlChangeMessage (){
    type=ScriptControlChangeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptControlChangeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].TakeControls;
         out << o.Data[i].Controls;
         out << o.Data[i].PassToAgent;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptControlChangeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        ScriptControlChangeMessage::DataBlock y;
        in >> y.TakeControls;
        in >> y.Controls;
        in >> y.PassToAgent;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptDialogMessage::ScriptDialogMessage (){
    type=ScriptDialogType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptDialogMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.ObjectID;
    out << o.Data.FirstName;
    out << o.Data.LastName;
    out << o.Data.ObjectName;
    out << o.Data.Message;
    out << o.Data.ChatChannel;
    out << o.Data.ImageID;

    out << (lltypes::U8)o.Buttons.size();
    for(int i=0;i<o.Buttons.size();i++){
         out << o.Buttons[i].ButtonLabel;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptDialogMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.ObjectID;
    in >> o.Data.FirstName;
    in >> o.Data.LastName;
    in >> o.Data.ObjectName;
    in >> o.Data.Message;
    in >> o.Data.ChatChannel;
    in >> o.Data.ImageID;

    o.Buttons.clear();
    lltypes::U8 countButtons;
    in >> countButtons;
    for(int i=0;i<countButtons;i++){
        ScriptDialogMessage::ButtonsBlock y;
        in >> y.ButtonLabel;
        o.Buttons << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptDialogReplyMessage::ScriptDialogReplyMessage (){
    type=ScriptDialogReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptDialogReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ObjectID;
    out << o.Data.ChatChannel;
    out << o.Data.ButtonIndex;
    out << o.Data.ButtonLabel;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptDialogReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ObjectID;
    in >> o.Data.ChatChannel;
    in >> o.Data.ButtonIndex;
    in >> o.Data.ButtonLabel;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ForceScriptControlReleaseMessage::ForceScriptControlReleaseMessage (){
    type=ForceScriptControlReleaseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ForceScriptControlReleaseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ForceScriptControlReleaseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RevokePermissionsMessage::RevokePermissionsMessage (){
    type=RevokePermissionsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RevokePermissionsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.ObjectID;
    out << o.Data.ObjectPermissions;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RevokePermissionsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.ObjectID;
    in >> o.Data.ObjectPermissions;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LoadURLMessage::LoadURLMessage (){
    type=LoadURLType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LoadURLMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.ObjectName;
    out << o.Data.ObjectID;
    out << o.Data.OwnerID;
    out << o.Data.OwnerIsGroup;
    out << o.Data.Message;
    out << o.Data.URL;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LoadURLMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.ObjectName;
    in >> o.Data.ObjectID;
    in >> o.Data.OwnerID;
    in >> o.Data.OwnerIsGroup;
    in >> o.Data.Message;
    in >> o.Data.URL;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptTeleportRequestMessage::ScriptTeleportRequestMessage (){
    type=ScriptTeleportRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptTeleportRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.ObjectName;
    out << o.Data.SimName;
    out << o.Data.SimPosition;
    out << o.Data.LookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptTeleportRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.ObjectName;
    in >> o.Data.SimName;
    in >> o.Data.SimPosition;
    in >> o.Data.LookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelOverlayMessage::ParcelOverlayMessage (){
    type=ParcelOverlayType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelOverlayMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ParcelData.SequenceID;
    out << o.ParcelData.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelOverlayMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ParcelData.SequenceID;
    in >> o.ParcelData.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelPropertiesRequestMessage::ParcelPropertiesRequestMessage (){
    type=ParcelPropertiesRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelPropertiesRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.SequenceID;
    out << o.ParcelData.West;
    out << o.ParcelData.South;
    out << o.ParcelData.East;
    out << o.ParcelData.North;
    out << o.ParcelData.SnapSelection;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelPropertiesRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.SequenceID;
    in >> o.ParcelData.West;
    in >> o.ParcelData.South;
    in >> o.ParcelData.East;
    in >> o.ParcelData.North;
    in >> o.ParcelData.SnapSelection;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelPropertiesRequestByIDMessage::ParcelPropertiesRequestByIDMessage (){
    type=ParcelPropertiesRequestByIDType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelPropertiesRequestByIDMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.SequenceID;
    out << o.ParcelData.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelPropertiesRequestByIDMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.SequenceID;
    in >> o.ParcelData.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelPropertiesMessage::ParcelPropertiesMessage (){
    type=ParcelPropertiesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelPropertiesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ParcelData.RequestResult;
    out << o.ParcelData.SequenceID;
    out << o.ParcelData.SnapSelection;
    out << o.ParcelData.SelfCount;
    out << o.ParcelData.OtherCount;
    out << o.ParcelData.PublicCount;
    out << o.ParcelData.LocalID;
    out << o.ParcelData.OwnerID;
    out << o.ParcelData.IsGroupOwned;
    out << o.ParcelData.AuctionID;
    out << o.ParcelData.ClaimDate;
    out << o.ParcelData.ClaimPrice;
    out << o.ParcelData.RentPrice;
    out << o.ParcelData.AABBMin;
    out << o.ParcelData.AABBMax;
    out << o.ParcelData.Bitmap;
    out << o.ParcelData.Area;
    out << o.ParcelData.Status;
    out << o.ParcelData.SimWideMaxPrims;
    out << o.ParcelData.SimWideTotalPrims;
    out << o.ParcelData.MaxPrims;
    out << o.ParcelData.TotalPrims;
    out << o.ParcelData.OwnerPrims;
    out << o.ParcelData.GroupPrims;
    out << o.ParcelData.OtherPrims;
    out << o.ParcelData.SelectedPrims;
    out << o.ParcelData.ParcelPrimBonus;
    out << o.ParcelData.OtherCleanTime;
    out << o.ParcelData.ParcelFlags;
    out << o.ParcelData.SalePrice;
    out << o.ParcelData.Name;
    out << o.ParcelData.Desc;
    out << o.ParcelData.MusicURL;
    out << o.ParcelData.MediaURL;
    out << o.ParcelData.MediaID;
    out << o.ParcelData.MediaAutoScale;
    out << o.ParcelData.GroupID;
    out << o.ParcelData.PassPrice;
    out << o.ParcelData.PassHours;
    out << o.ParcelData.Category;
    out << o.ParcelData.AuthBuyerID;
    out << o.ParcelData.SnapshotID;
    out << o.ParcelData.UserLocation;
    out << o.ParcelData.UserLookAt;
    out << o.ParcelData.LandingType;
    out << o.ParcelData.RegionPushOverride;
    out << o.ParcelData.RegionDenyAnonymous;
    out << o.ParcelData.RegionDenyIdentified;
    out << o.ParcelData.RegionDenyTransacted;

    out << o.AgeVerificationBlock.RegionDenyAgeUnverified;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelPropertiesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ParcelData.RequestResult;
    in >> o.ParcelData.SequenceID;
    in >> o.ParcelData.SnapSelection;
    in >> o.ParcelData.SelfCount;
    in >> o.ParcelData.OtherCount;
    in >> o.ParcelData.PublicCount;
    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.OwnerID;
    in >> o.ParcelData.IsGroupOwned;
    in >> o.ParcelData.AuctionID;
    in >> o.ParcelData.ClaimDate;
    in >> o.ParcelData.ClaimPrice;
    in >> o.ParcelData.RentPrice;
    in >> o.ParcelData.AABBMin;
    in >> o.ParcelData.AABBMax;
    in >> o.ParcelData.Bitmap;
    in >> o.ParcelData.Area;
    in >> o.ParcelData.Status;
    in >> o.ParcelData.SimWideMaxPrims;
    in >> o.ParcelData.SimWideTotalPrims;
    in >> o.ParcelData.MaxPrims;
    in >> o.ParcelData.TotalPrims;
    in >> o.ParcelData.OwnerPrims;
    in >> o.ParcelData.GroupPrims;
    in >> o.ParcelData.OtherPrims;
    in >> o.ParcelData.SelectedPrims;
    in >> o.ParcelData.ParcelPrimBonus;
    in >> o.ParcelData.OtherCleanTime;
    in >> o.ParcelData.ParcelFlags;
    in >> o.ParcelData.SalePrice;
    in >> o.ParcelData.Name;
    in >> o.ParcelData.Desc;
    in >> o.ParcelData.MusicURL;
    in >> o.ParcelData.MediaURL;
    in >> o.ParcelData.MediaID;
    in >> o.ParcelData.MediaAutoScale;
    in >> o.ParcelData.GroupID;
    in >> o.ParcelData.PassPrice;
    in >> o.ParcelData.PassHours;
    in >> o.ParcelData.Category;
    in >> o.ParcelData.AuthBuyerID;
    in >> o.ParcelData.SnapshotID;
    in >> o.ParcelData.UserLocation;
    in >> o.ParcelData.UserLookAt;
    in >> o.ParcelData.LandingType;
    in >> o.ParcelData.RegionPushOverride;
    in >> o.ParcelData.RegionDenyAnonymous;
    in >> o.ParcelData.RegionDenyIdentified;
    in >> o.ParcelData.RegionDenyTransacted;

    in >> o.AgeVerificationBlock.RegionDenyAgeUnverified;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelPropertiesUpdateMessage::ParcelPropertiesUpdateMessage (){
    type=ParcelPropertiesUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelPropertiesUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.Flags;
    out << o.ParcelData.ParcelFlags;
    out << o.ParcelData.SalePrice;
    out << o.ParcelData.Name;
    out << o.ParcelData.Desc;
    out << o.ParcelData.MusicURL;
    out << o.ParcelData.MediaURL;
    out << o.ParcelData.MediaID;
    out << o.ParcelData.MediaAutoScale;
    out << o.ParcelData.GroupID;
    out << o.ParcelData.PassPrice;
    out << o.ParcelData.PassHours;
    out << o.ParcelData.Category;
    out << o.ParcelData.AuthBuyerID;
    out << o.ParcelData.SnapshotID;
    out << o.ParcelData.UserLocation;
    out << o.ParcelData.UserLookAt;
    out << o.ParcelData.LandingType;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelPropertiesUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.Flags;
    in >> o.ParcelData.ParcelFlags;
    in >> o.ParcelData.SalePrice;
    in >> o.ParcelData.Name;
    in >> o.ParcelData.Desc;
    in >> o.ParcelData.MusicURL;
    in >> o.ParcelData.MediaURL;
    in >> o.ParcelData.MediaID;
    in >> o.ParcelData.MediaAutoScale;
    in >> o.ParcelData.GroupID;
    in >> o.ParcelData.PassPrice;
    in >> o.ParcelData.PassHours;
    in >> o.ParcelData.Category;
    in >> o.ParcelData.AuthBuyerID;
    in >> o.ParcelData.SnapshotID;
    in >> o.ParcelData.UserLocation;
    in >> o.ParcelData.UserLookAt;
    in >> o.ParcelData.LandingType;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelReturnObjectsMessage::ParcelReturnObjectsMessage (){
    type=ParcelReturnObjectsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelReturnObjectsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.ReturnType;

    out << (lltypes::U8)o.TaskIDs.size();
    for(int i=0;i<o.TaskIDs.size();i++){
         out << o.TaskIDs[i].TaskID;
    }

    out << (lltypes::U8)o.OwnerIDs.size();
    for(int i=0;i<o.OwnerIDs.size();i++){
         out << o.OwnerIDs[i].OwnerID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelReturnObjectsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.ReturnType;

    o.TaskIDs.clear();
    lltypes::U8 countTaskIDs;
    in >> countTaskIDs;
    for(int i=0;i<countTaskIDs;i++){
        ParcelReturnObjectsMessage::TaskIDsBlock y;
        in >> y.TaskID;
        o.TaskIDs << y;
    }

    o.OwnerIDs.clear();
    lltypes::U8 countOwnerIDs;
    in >> countOwnerIDs;
    for(int i=0;i<countOwnerIDs;i++){
        ParcelReturnObjectsMessage::OwnerIDsBlock y;
        in >> y.OwnerID;
        o.OwnerIDs << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelSetOtherCleanTimeMessage::ParcelSetOtherCleanTimeMessage (){
    type=ParcelSetOtherCleanTimeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelSetOtherCleanTimeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.OtherCleanTime;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelSetOtherCleanTimeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.OtherCleanTime;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelDisableObjectsMessage::ParcelDisableObjectsMessage (){
    type=ParcelDisableObjectsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelDisableObjectsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.ReturnType;

    out << (lltypes::U8)o.TaskIDs.size();
    for(int i=0;i<o.TaskIDs.size();i++){
         out << o.TaskIDs[i].TaskID;
    }

    out << (lltypes::U8)o.OwnerIDs.size();
    for(int i=0;i<o.OwnerIDs.size();i++){
         out << o.OwnerIDs[i].OwnerID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelDisableObjectsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.ReturnType;

    o.TaskIDs.clear();
    lltypes::U8 countTaskIDs;
    in >> countTaskIDs;
    for(int i=0;i<countTaskIDs;i++){
        ParcelDisableObjectsMessage::TaskIDsBlock y;
        in >> y.TaskID;
        o.TaskIDs << y;
    }

    o.OwnerIDs.clear();
    lltypes::U8 countOwnerIDs;
    in >> countOwnerIDs;
    for(int i=0;i<countOwnerIDs;i++){
        ParcelDisableObjectsMessage::OwnerIDsBlock y;
        in >> y.OwnerID;
        o.OwnerIDs << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelSelectObjectsMessage::ParcelSelectObjectsMessage (){
    type=ParcelSelectObjectsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelSelectObjectsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.ReturnType;

    out << (lltypes::U8)o.ReturnIDs.size();
    for(int i=0;i<o.ReturnIDs.size();i++){
         out << o.ReturnIDs[i].ReturnID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelSelectObjectsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.ReturnType;

    o.ReturnIDs.clear();
    lltypes::U8 countReturnIDs;
    in >> countReturnIDs;
    for(int i=0;i<countReturnIDs;i++){
        ParcelSelectObjectsMessage::ReturnIDsBlock y;
        in >> y.ReturnID;
        o.ReturnIDs << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EstateCovenantRequestMessage::EstateCovenantRequestMessage (){
    type=EstateCovenantRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EstateCovenantRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EstateCovenantRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EstateCovenantReplyMessage::EstateCovenantReplyMessage (){
    type=EstateCovenantReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EstateCovenantReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.CovenantID;
    out << o.Data.CovenantTimestamp;
    out << o.Data.EstateName;
    out << o.Data.EstateOwnerID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EstateCovenantReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.CovenantID;
    in >> o.Data.CovenantTimestamp;
    in >> o.Data.EstateName;
    in >> o.Data.EstateOwnerID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ForceObjectSelectMessage::ForceObjectSelectMessage (){
    type=ForceObjectSelectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ForceObjectSelectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Header.ResetList;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].LocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ForceObjectSelectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Header.ResetList;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        ForceObjectSelectMessage::DataBlock y;
        in >> y.LocalID;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelBuyPassMessage::ParcelBuyPassMessage (){
    type=ParcelBuyPassType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelBuyPassMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelBuyPassMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelDeedToGroupMessage::ParcelDeedToGroupMessage (){
    type=ParcelDeedToGroupType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelDeedToGroupMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;
    out << o.Data.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelDeedToGroupMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;
    in >> o.Data.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelReclaimMessage::ParcelReclaimMessage (){
    type=ParcelReclaimType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelReclaimMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelReclaimMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelClaimMessage::ParcelClaimMessage (){
    type=ParcelClaimType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelClaimMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;
    out << o.Data.IsGroupOwned;
    out << o.Data.Final;

    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].West;
         out << o.ParcelData[i].South;
         out << o.ParcelData[i].East;
         out << o.ParcelData[i].North;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelClaimMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;
    in >> o.Data.IsGroupOwned;
    in >> o.Data.Final;

    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        ParcelClaimMessage::ParcelDataBlock y;
        in >> y.West;
        in >> y.South;
        in >> y.East;
        in >> y.North;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelJoinMessage::ParcelJoinMessage (){
    type=ParcelJoinType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelJoinMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.West;
    out << o.ParcelData.South;
    out << o.ParcelData.East;
    out << o.ParcelData.North;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelJoinMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.West;
    in >> o.ParcelData.South;
    in >> o.ParcelData.East;
    in >> o.ParcelData.North;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelDivideMessage::ParcelDivideMessage (){
    type=ParcelDivideType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelDivideMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.West;
    out << o.ParcelData.South;
    out << o.ParcelData.East;
    out << o.ParcelData.North;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelDivideMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.West;
    in >> o.ParcelData.South;
    in >> o.ParcelData.East;
    in >> o.ParcelData.North;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelReleaseMessage::ParcelReleaseMessage (){
    type=ParcelReleaseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelReleaseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelReleaseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelBuyMessage::ParcelBuyMessage (){
    type=ParcelBuyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelBuyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;
    out << o.Data.IsGroupOwned;
    out << o.Data.RemoveContribution;
    out << o.Data.LocalID;
    out << o.Data.Final;

    out << o.ParcelData.Price;
    out << o.ParcelData.Area;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelBuyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;
    in >> o.Data.IsGroupOwned;
    in >> o.Data.RemoveContribution;
    in >> o.Data.LocalID;
    in >> o.Data.Final;

    in >> o.ParcelData.Price;
    in >> o.ParcelData.Area;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelGodForceOwnerMessage::ParcelGodForceOwnerMessage (){
    type=ParcelGodForceOwnerType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelGodForceOwnerMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.OwnerID;
    out << o.Data.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelGodForceOwnerMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.OwnerID;
    in >> o.Data.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelAccessListRequestMessage::ParcelAccessListRequestMessage (){
    type=ParcelAccessListRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelAccessListRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.SequenceID;
    out << o.Data.Flags;
    out << o.Data.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelAccessListRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.SequenceID;
    in >> o.Data.Flags;
    in >> o.Data.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelAccessListReplyMessage::ParcelAccessListReplyMessage (){
    type=ParcelAccessListReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelAccessListReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.AgentID;
    out << o.Data.SequenceID;
    out << o.Data.Flags;
    out << o.Data.LocalID;

    out << (lltypes::U8)o.List.size();
    for(int i=0;i<o.List.size();i++){
         out << o.List[i].ID;
         out << o.List[i].Time;
         out << o.List[i].Flags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelAccessListReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.AgentID;
    in >> o.Data.SequenceID;
    in >> o.Data.Flags;
    in >> o.Data.LocalID;

    o.List.clear();
    lltypes::U8 countList;
    in >> countList;
    for(int i=0;i<countList;i++){
        ParcelAccessListReplyMessage::ListBlock y;
        in >> y.ID;
        in >> y.Time;
        in >> y.Flags;
        o.List << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelAccessListUpdateMessage::ParcelAccessListUpdateMessage (){
    type=ParcelAccessListUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelAccessListUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.Flags;
    out << o.Data.LocalID;
    out << o.Data.TransactionID;
    out << o.Data.SequenceID;
    out << o.Data.Sections;

    out << (lltypes::U8)o.List.size();
    for(int i=0;i<o.List.size();i++){
         out << o.List[i].ID;
         out << o.List[i].Time;
         out << o.List[i].Flags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelAccessListUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.Flags;
    in >> o.Data.LocalID;
    in >> o.Data.TransactionID;
    in >> o.Data.SequenceID;
    in >> o.Data.Sections;

    o.List.clear();
    lltypes::U8 countList;
    in >> countList;
    for(int i=0;i<countList;i++){
        ParcelAccessListUpdateMessage::ListBlock y;
        in >> y.ID;
        in >> y.Time;
        in >> y.Flags;
        o.List << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelDwellRequestMessage::ParcelDwellRequestMessage (){
    type=ParcelDwellRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelDwellRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.LocalID;
    out << o.Data.ParcelID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelDwellRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.LocalID;
    in >> o.Data.ParcelID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelDwellReplyMessage::ParcelDwellReplyMessage (){
    type=ParcelDwellReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelDwellReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.LocalID;
    out << o.Data.ParcelID;
    out << o.Data.Dwell;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelDwellReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.LocalID;
    in >> o.Data.ParcelID;
    in >> o.Data.Dwell;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestParcelTransferMessage::RequestParcelTransferMessage (){
    type=RequestParcelTransferType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestParcelTransferMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.TransactionID;
    out << o.Data.TransactionTime;
    out << o.Data.SourceID;
    out << o.Data.DestID;
    out << o.Data.OwnerID;
    out << o.Data.Flags;
    out << o.Data.TransactionType;
    out << o.Data.Amount;
    out << o.Data.BillableArea;
    out << o.Data.ActualArea;
    out << o.Data.Final;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestParcelTransferMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.TransactionID;
    in >> o.Data.TransactionTime;
    in >> o.Data.SourceID;
    in >> o.Data.DestID;
    in >> o.Data.OwnerID;
    in >> o.Data.Flags;
    in >> o.Data.TransactionType;
    in >> o.Data.Amount;
    in >> o.Data.BillableArea;
    in >> o.Data.ActualArea;
    in >> o.Data.Final;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateParcelMessage::UpdateParcelMessage (){
    type=UpdateParcelType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateParcelMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ParcelData.ParcelID;
    out << o.ParcelData.RegionHandle;
    out << o.ParcelData.OwnerID;
    out << o.ParcelData.GroupOwned;
    out << o.ParcelData.Status;
    out << o.ParcelData.Name;
    out << o.ParcelData.Description;
    out << o.ParcelData.MusicURL;
    out << o.ParcelData.RegionX;
    out << o.ParcelData.RegionY;
    out << o.ParcelData.ActualArea;
    out << o.ParcelData.BillableArea;
    out << o.ParcelData.ShowDir;
    out << o.ParcelData.IsForSale;
    out << o.ParcelData.Category;
    out << o.ParcelData.SnapshotID;
    out << o.ParcelData.UserLocation;
    out << o.ParcelData.SalePrice;
    out << o.ParcelData.AuthorizedBuyerID;
    out << o.ParcelData.AllowPublish;
    out << o.ParcelData.MaturePublish;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateParcelMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ParcelData.ParcelID;
    in >> o.ParcelData.RegionHandle;
    in >> o.ParcelData.OwnerID;
    in >> o.ParcelData.GroupOwned;
    in >> o.ParcelData.Status;
    in >> o.ParcelData.Name;
    in >> o.ParcelData.Description;
    in >> o.ParcelData.MusicURL;
    in >> o.ParcelData.RegionX;
    in >> o.ParcelData.RegionY;
    in >> o.ParcelData.ActualArea;
    in >> o.ParcelData.BillableArea;
    in >> o.ParcelData.ShowDir;
    in >> o.ParcelData.IsForSale;
    in >> o.ParcelData.Category;
    in >> o.ParcelData.SnapshotID;
    in >> o.ParcelData.UserLocation;
    in >> o.ParcelData.SalePrice;
    in >> o.ParcelData.AuthorizedBuyerID;
    in >> o.ParcelData.AllowPublish;
    in >> o.ParcelData.MaturePublish;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveParcelMessage::RemoveParcelMessage (){
    type=RemoveParcelType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveParcelMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveParcelMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        RemoveParcelMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MergeParcelMessage::MergeParcelMessage (){
    type=MergeParcelType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MergeParcelMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MasterParcelData.MasterID;

    out << (lltypes::U8)o.SlaveParcelData.size();
    for(int i=0;i<o.SlaveParcelData.size();i++){
         out << o.SlaveParcelData[i].SlaveID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MergeParcelMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MasterParcelData.MasterID;

    o.SlaveParcelData.clear();
    lltypes::U8 countSlaveParcelData;
    in >> countSlaveParcelData;
    for(int i=0;i<countSlaveParcelData;i++){
        MergeParcelMessage::SlaveParcelDataBlock y;
        in >> y.SlaveID;
        o.SlaveParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogParcelChangesMessage::LogParcelChangesMessage (){
    type=LogParcelChangesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogParcelChangesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.RegionData.RegionHandle;

    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
         out << o.ParcelData[i].OwnerID;
         out << o.ParcelData[i].IsOwnerGroup;
         out << o.ParcelData[i].ActualArea;
         out << o.ParcelData[i].Action;
         out << o.ParcelData[i].TransactionID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogParcelChangesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.RegionData.RegionHandle;

    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        LogParcelChangesMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        in >> y.OwnerID;
        in >> y.IsOwnerGroup;
        in >> y.ActualArea;
        in >> y.Action;
        in >> y.TransactionID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CheckParcelSalesMessage::CheckParcelSalesMessage (){
    type=CheckParcelSalesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CheckParcelSalesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.RegionData.size();
    for(int i=0;i<o.RegionData.size();i++){
         out << o.RegionData[i].RegionHandle;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CheckParcelSalesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.RegionData.clear();
    lltypes::U8 countRegionData;
    in >> countRegionData;
    for(int i=0;i<countRegionData;i++){
        CheckParcelSalesMessage::RegionDataBlock y;
        in >> y.RegionHandle;
        o.RegionData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelSalesMessage::ParcelSalesMessage (){
    type=ParcelSalesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelSalesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
         out << o.ParcelData[i].BuyerID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelSalesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        ParcelSalesMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        in >> y.BuyerID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelGodMarkAsContentMessage::ParcelGodMarkAsContentMessage (){
    type=ParcelGodMarkAsContentType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelGodMarkAsContentMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelGodMarkAsContentMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ViewerStartAuctionMessage::ViewerStartAuctionMessage (){
    type=ViewerStartAuctionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ViewerStartAuctionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ParcelData.LocalID;
    out << o.ParcelData.SnapshotID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ViewerStartAuctionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ParcelData.LocalID;
    in >> o.ParcelData.SnapshotID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


StartAuctionMessage::StartAuctionMessage (){
    type=StartAuctionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const StartAuctionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.ParcelData.ParcelID;
    out << o.ParcelData.SnapshotID;
    out << o.ParcelData.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  StartAuctionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.ParcelData.ParcelID;
    in >> o.ParcelData.SnapshotID;
    in >> o.ParcelData.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ConfirmAuctionStartMessage::ConfirmAuctionStartMessage (){
    type=ConfirmAuctionStartType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ConfirmAuctionStartMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AuctionData.ParcelID;
    out << o.AuctionData.AuctionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ConfirmAuctionStartMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AuctionData.ParcelID;
    in >> o.AuctionData.AuctionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CompleteAuctionMessage::CompleteAuctionMessage (){
    type=CompleteAuctionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CompleteAuctionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CompleteAuctionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        CompleteAuctionMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CancelAuctionMessage::CancelAuctionMessage (){
    type=CancelAuctionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CancelAuctionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CancelAuctionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        CancelAuctionMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CheckParcelAuctionsMessage::CheckParcelAuctionsMessage (){
    type=CheckParcelAuctionsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CheckParcelAuctionsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.RegionData.size();
    for(int i=0;i<o.RegionData.size();i++){
         out << o.RegionData[i].RegionHandle;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CheckParcelAuctionsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.RegionData.clear();
    lltypes::U8 countRegionData;
    in >> countRegionData;
    for(int i=0;i<countRegionData;i++){
        CheckParcelAuctionsMessage::RegionDataBlock y;
        in >> y.RegionHandle;
        o.RegionData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelAuctionsMessage::ParcelAuctionsMessage (){
    type=ParcelAuctionsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelAuctionsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
         out << o.ParcelData[i].WinnerID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelAuctionsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        ParcelAuctionsMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        in >> y.WinnerID;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UUIDNameRequestMessage::UUIDNameRequestMessage (){
    type=UUIDNameRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UUIDNameRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.UUIDNameBlock.size();
    for(int i=0;i<o.UUIDNameBlock.size();i++){
         out << o.UUIDNameBlock[i].ID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UUIDNameRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.UUIDNameBlock.clear();
    lltypes::U8 countUUIDNameBlock;
    in >> countUUIDNameBlock;
    for(int i=0;i<countUUIDNameBlock;i++){
        UUIDNameRequestMessage::UUIDNameBlockBlock y;
        in >> y.ID;
        o.UUIDNameBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UUIDNameReplyMessage::UUIDNameReplyMessage (){
    type=UUIDNameReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UUIDNameReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.UUIDNameBlock.size();
    for(int i=0;i<o.UUIDNameBlock.size();i++){
         out << o.UUIDNameBlock[i].ID;
         out << o.UUIDNameBlock[i].FirstName;
         out << o.UUIDNameBlock[i].LastName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UUIDNameReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.UUIDNameBlock.clear();
    lltypes::U8 countUUIDNameBlock;
    in >> countUUIDNameBlock;
    for(int i=0;i<countUUIDNameBlock;i++){
        UUIDNameReplyMessage::UUIDNameBlockBlock y;
        in >> y.ID;
        in >> y.FirstName;
        in >> y.LastName;
        o.UUIDNameBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UUIDGroupNameRequestMessage::UUIDGroupNameRequestMessage (){
    type=UUIDGroupNameRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UUIDGroupNameRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.UUIDNameBlock.size();
    for(int i=0;i<o.UUIDNameBlock.size();i++){
         out << o.UUIDNameBlock[i].ID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UUIDGroupNameRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.UUIDNameBlock.clear();
    lltypes::U8 countUUIDNameBlock;
    in >> countUUIDNameBlock;
    for(int i=0;i<countUUIDNameBlock;i++){
        UUIDGroupNameRequestMessage::UUIDNameBlockBlock y;
        in >> y.ID;
        o.UUIDNameBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UUIDGroupNameReplyMessage::UUIDGroupNameReplyMessage (){
    type=UUIDGroupNameReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UUIDGroupNameReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.UUIDNameBlock.size();
    for(int i=0;i<o.UUIDNameBlock.size();i++){
         out << o.UUIDNameBlock[i].ID;
         out << o.UUIDNameBlock[i].GroupName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UUIDGroupNameReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.UUIDNameBlock.clear();
    lltypes::U8 countUUIDNameBlock;
    in >> countUUIDNameBlock;
    for(int i=0;i<countUUIDNameBlock;i++){
        UUIDGroupNameReplyMessage::UUIDNameBlockBlock y;
        in >> y.ID;
        in >> y.GroupName;
        o.UUIDNameBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChatPassMessage::ChatPassMessage (){
    type=ChatPassType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChatPassMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ChatData.Channel;
    out << o.ChatData.Position;
    out << o.ChatData.ID;
    out << o.ChatData.OwnerID;
    out << o.ChatData.Name;
    out << o.ChatData.SourceType;
    out << o.ChatData.Type;
    out << o.ChatData.Radius;
    out << o.ChatData.SimAccess;
    out << o.ChatData.Message;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChatPassMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ChatData.Channel;
    in >> o.ChatData.Position;
    in >> o.ChatData.ID;
    in >> o.ChatData.OwnerID;
    in >> o.ChatData.Name;
    in >> o.ChatData.SourceType;
    in >> o.ChatData.Type;
    in >> o.ChatData.Radius;
    in >> o.ChatData.SimAccess;
    in >> o.ChatData.Message;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EdgeDataPacketMessage::EdgeDataPacketMessage (){
    type=EdgeDataPacketType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EdgeDataPacketMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.EdgeData.LayerType;
    out << o.EdgeData.Direction;
    out << o.EdgeData.LayerData;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EdgeDataPacketMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.EdgeData.LayerType;
    in >> o.EdgeData.Direction;
    in >> o.EdgeData.LayerData;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimStatusMessage::SimStatusMessage (){
    type=SimStatusType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimStatusMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SimStatus.CanAcceptAgents;
    out << o.SimStatus.CanAcceptTasks;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimStatusMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SimStatus.CanAcceptAgents;
    in >> o.SimStatus.CanAcceptTasks;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChildAgentUpdateMessage::ChildAgentUpdateMessage (){
    type=ChildAgentUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChildAgentUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.RegionHandle;
    out << o.AgentData.ViewerCircuitCode;
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AgentPos;
    out << o.AgentData.AgentVel;
    out << o.AgentData.Center;
    out << o.AgentData.Size;
    out << o.AgentData.AtAxis;
    out << o.AgentData.LeftAxis;
    out << o.AgentData.UpAxis;
    out << o.AgentData.ChangedGrid;
    out << o.AgentData.Far;
    out << o.AgentData.Aspect;
    out << o.AgentData.Throttles;
    out << o.AgentData.LocomotionState;
    out << o.AgentData.HeadRotation;
    out << o.AgentData.BodyRotation;
    out << o.AgentData.ControlFlags;
    out << o.AgentData.EnergyLevel;
    out << o.AgentData.GodLevel;
    out << o.AgentData.AlwaysRun;
    out << o.AgentData.PreyAgent;
    out << o.AgentData.AgentAccess;
    out << o.AgentData.AgentTextures;
    out << o.AgentData.ActiveGroupID;

    out << (lltypes::U8)o.GroupData.size();
    for(int i=0;i<o.GroupData.size();i++){
         out << o.GroupData[i].GroupID;
         out << o.GroupData[i].GroupPowers;
         out << o.GroupData[i].AcceptNotices;
    }

    out << (lltypes::U8)o.AnimationData.size();
    for(int i=0;i<o.AnimationData.size();i++){
         out << o.AnimationData[i].Animation;
         out << o.AnimationData[i].ObjectID;
    }

    out << (lltypes::U8)o.GranterBlock.size();
    for(int i=0;i<o.GranterBlock.size();i++){
         out << o.GranterBlock[i].GranterID;
    }

    out << (lltypes::U8)o.NVPairData.size();
    for(int i=0;i<o.NVPairData.size();i++){
         out << o.NVPairData[i].NVPairs;
    }

    out << (lltypes::U8)o.VisualParam.size();
    for(int i=0;i<o.VisualParam.size();i++){
         out << o.VisualParam[i].ParamValue;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChildAgentUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.RegionHandle;
    in >> o.AgentData.ViewerCircuitCode;
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AgentPos;
    in >> o.AgentData.AgentVel;
    in >> o.AgentData.Center;
    in >> o.AgentData.Size;
    in >> o.AgentData.AtAxis;
    in >> o.AgentData.LeftAxis;
    in >> o.AgentData.UpAxis;
    in >> o.AgentData.ChangedGrid;
    in >> o.AgentData.Far;
    in >> o.AgentData.Aspect;
    in >> o.AgentData.Throttles;
    in >> o.AgentData.LocomotionState;
    in >> o.AgentData.HeadRotation;
    in >> o.AgentData.BodyRotation;
    in >> o.AgentData.ControlFlags;
    in >> o.AgentData.EnergyLevel;
    in >> o.AgentData.GodLevel;
    in >> o.AgentData.AlwaysRun;
    in >> o.AgentData.PreyAgent;
    in >> o.AgentData.AgentAccess;
    in >> o.AgentData.AgentTextures;
    in >> o.AgentData.ActiveGroupID;

    o.GroupData.clear();
    lltypes::U8 countGroupData;
    in >> countGroupData;
    for(int i=0;i<countGroupData;i++){
        ChildAgentUpdateMessage::GroupDataBlock y;
        in >> y.GroupID;
        in >> y.GroupPowers;
        in >> y.AcceptNotices;
        o.GroupData << y;
    }

    o.AnimationData.clear();
    lltypes::U8 countAnimationData;
    in >> countAnimationData;
    for(int i=0;i<countAnimationData;i++){
        ChildAgentUpdateMessage::AnimationDataBlock y;
        in >> y.Animation;
        in >> y.ObjectID;
        o.AnimationData << y;
    }

    o.GranterBlock.clear();
    lltypes::U8 countGranterBlock;
    in >> countGranterBlock;
    for(int i=0;i<countGranterBlock;i++){
        ChildAgentUpdateMessage::GranterBlockBlock y;
        in >> y.GranterID;
        o.GranterBlock << y;
    }

    o.NVPairData.clear();
    lltypes::U8 countNVPairData;
    in >> countNVPairData;
    for(int i=0;i<countNVPairData;i++){
        ChildAgentUpdateMessage::NVPairDataBlock y;
        in >> y.NVPairs;
        o.NVPairData << y;
    }

    o.VisualParam.clear();
    lltypes::U8 countVisualParam;
    in >> countVisualParam;
    for(int i=0;i<countVisualParam;i++){
        ChildAgentUpdateMessage::VisualParamBlock y;
        in >> y.ParamValue;
        o.VisualParam << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChildAgentAliveMessage::ChildAgentAliveMessage (){
    type=ChildAgentAliveType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChildAgentAliveMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.RegionHandle;
    out << o.AgentData.ViewerCircuitCode;
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChildAgentAliveMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.RegionHandle;
    in >> o.AgentData.ViewerCircuitCode;
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChildAgentPositionUpdateMessage::ChildAgentPositionUpdateMessage (){
    type=ChildAgentPositionUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChildAgentPositionUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.RegionHandle;
    out << o.AgentData.ViewerCircuitCode;
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AgentPos;
    out << o.AgentData.AgentVel;
    out << o.AgentData.Center;
    out << o.AgentData.Size;
    out << o.AgentData.AtAxis;
    out << o.AgentData.LeftAxis;
    out << o.AgentData.UpAxis;
    out << o.AgentData.ChangedGrid;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChildAgentPositionUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.RegionHandle;
    in >> o.AgentData.ViewerCircuitCode;
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AgentPos;
    in >> o.AgentData.AgentVel;
    in >> o.AgentData.Center;
    in >> o.AgentData.Size;
    in >> o.AgentData.AtAxis;
    in >> o.AgentData.LeftAxis;
    in >> o.AgentData.UpAxis;
    in >> o.AgentData.ChangedGrid;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChildAgentDyingMessage::ChildAgentDyingMessage (){
    type=ChildAgentDyingType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChildAgentDyingMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChildAgentDyingMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChildAgentUnknownMessage::ChildAgentUnknownMessage (){
    type=ChildAgentUnknownType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChildAgentUnknownMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChildAgentUnknownMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AtomicPassObjectMessage::AtomicPassObjectMessage (){
    type=AtomicPassObjectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AtomicPassObjectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TaskData.TaskID;
    out << o.TaskData.AttachmentNeedsSave;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AtomicPassObjectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TaskData.TaskID;
    in >> o.TaskData.AttachmentNeedsSave;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


KillChildAgentsMessage::KillChildAgentsMessage (){
    type=KillChildAgentsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const KillChildAgentsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.IDBlock.AgentID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  KillChildAgentsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.IDBlock.AgentID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GetScriptRunningMessage::GetScriptRunningMessage (){
    type=GetScriptRunningType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GetScriptRunningMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Script.ObjectID;
    out << o.Script.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GetScriptRunningMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Script.ObjectID;
    in >> o.Script.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptRunningReplyMessage::ScriptRunningReplyMessage (){
    type=ScriptRunningReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptRunningReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Script.ObjectID;
    out << o.Script.ItemID;
    out << o.Script.Running;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptRunningReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Script.ObjectID;
    in >> o.Script.ItemID;
    in >> o.Script.Running;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetScriptRunningMessage::SetScriptRunningMessage (){
    type=SetScriptRunningType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetScriptRunningMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Script.ObjectID;
    out << o.Script.ItemID;
    out << o.Script.Running;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetScriptRunningMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Script.ObjectID;
    in >> o.Script.ItemID;
    in >> o.Script.Running;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptResetMessage::ScriptResetMessage (){
    type=ScriptResetType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptResetMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Script.ObjectID;
    out << o.Script.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptResetMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Script.ObjectID;
    in >> o.Script.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptSensorRequestMessage::ScriptSensorRequestMessage (){
    type=ScriptSensorRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptSensorRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Requester.SourceID;
    out << o.Requester.RequestID;
    out << o.Requester.SearchID;
    out << o.Requester.SearchPos;
    out << o.Requester.SearchDir;
    out << o.Requester.SearchName;
    out << o.Requester.Type;
    out << o.Requester.Range;
    out << o.Requester.Arc;
    out << o.Requester.RegionHandle;
    out << o.Requester.SearchRegions;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptSensorRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Requester.SourceID;
    in >> o.Requester.RequestID;
    in >> o.Requester.SearchID;
    in >> o.Requester.SearchPos;
    in >> o.Requester.SearchDir;
    in >> o.Requester.SearchName;
    in >> o.Requester.Type;
    in >> o.Requester.Range;
    in >> o.Requester.Arc;
    in >> o.Requester.RegionHandle;
    in >> o.Requester.SearchRegions;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptSensorReplyMessage::ScriptSensorReplyMessage (){
    type=ScriptSensorReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptSensorReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Requester.SourceID;

    out << (lltypes::U8)o.SensedData.size();
    for(int i=0;i<o.SensedData.size();i++){
         out << o.SensedData[i].ObjectID;
         out << o.SensedData[i].OwnerID;
         out << o.SensedData[i].GroupID;
         out << o.SensedData[i].Position;
         out << o.SensedData[i].Velocity;
         out << o.SensedData[i].Rotation;
         out << o.SensedData[i].Name;
         out << o.SensedData[i].Type;
         out << o.SensedData[i].Range;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptSensorReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Requester.SourceID;

    o.SensedData.clear();
    lltypes::U8 countSensedData;
    in >> countSensedData;
    for(int i=0;i<countSensedData;i++){
        ScriptSensorReplyMessage::SensedDataBlock y;
        in >> y.ObjectID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.Position;
        in >> y.Velocity;
        in >> y.Rotation;
        in >> y.Name;
        in >> y.Type;
        in >> y.Range;
        o.SensedData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CompleteAgentMovementMessage::CompleteAgentMovementMessage (){
    type=CompleteAgentMovementType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CompleteAgentMovementMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.CircuitCode;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CompleteAgentMovementMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.CircuitCode;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentMovementCompleteMessage::AgentMovementCompleteMessage (){
    type=AgentMovementCompleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentMovementCompleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.Position;
    out << o.Data.LookAt;
    out << o.Data.RegionHandle;
    out << o.Data.Timestamp;

    out << o.SimData.ChannelVersion;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentMovementCompleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.Position;
    in >> o.Data.LookAt;
    in >> o.Data.RegionHandle;
    in >> o.Data.Timestamp;

    in >> o.SimData.ChannelVersion;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DataServerLogoutMessage::DataServerLogoutMessage (){
    type=DataServerLogoutType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DataServerLogoutMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.UserData.AgentID;
    out << o.UserData.ViewerIP;
    out << o.UserData.Disconnect;
    out << o.UserData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DataServerLogoutMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.UserData.AgentID;
    in >> o.UserData.ViewerIP;
    in >> o.UserData.Disconnect;
    in >> o.UserData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogoutRequestMessage::LogoutRequestMessage (){
    type=LogoutRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogoutRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogoutRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogoutReplyMessage::LogoutReplyMessage (){
    type=LogoutReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogoutReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogoutReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        LogoutReplyMessage::InventoryDataBlock y;
        in >> y.ItemID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ImprovedInstantMessageMessage::ImprovedInstantMessageMessage (){
    type=ImprovedInstantMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ImprovedInstantMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MessageBlock.FromGroup;
    out << o.MessageBlock.ToAgentID;
    out << o.MessageBlock.ParentEstateID;
    out << o.MessageBlock.RegionID;
    out << o.MessageBlock.Position;
    out << o.MessageBlock.Offline;
    out << o.MessageBlock.Dialog;
    out << o.MessageBlock.ID;
    out << o.MessageBlock.Timestamp;
    out << o.MessageBlock.FromAgentName;
    out << o.MessageBlock.Message;
    out << o.MessageBlock.BinaryBucket;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ImprovedInstantMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MessageBlock.FromGroup;
    in >> o.MessageBlock.ToAgentID;
    in >> o.MessageBlock.ParentEstateID;
    in >> o.MessageBlock.RegionID;
    in >> o.MessageBlock.Position;
    in >> o.MessageBlock.Offline;
    in >> o.MessageBlock.Dialog;
    in >> o.MessageBlock.ID;
    in >> o.MessageBlock.Timestamp;
    in >> o.MessageBlock.FromAgentName;
    in >> o.MessageBlock.Message;
    in >> o.MessageBlock.BinaryBucket;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RetrieveInstantMessagesMessage::RetrieveInstantMessagesMessage (){
    type=RetrieveInstantMessagesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RetrieveInstantMessagesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RetrieveInstantMessagesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FindAgentMessage::FindAgentMessage (){
    type=FindAgentType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FindAgentMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentBlock.Hunter;
    out << o.AgentBlock.Prey;
    out << o.AgentBlock.SpaceIP;

    out << (lltypes::U8)o.LocationBlock.size();
    for(int i=0;i<o.LocationBlock.size();i++){
         out << o.LocationBlock[i].GlobalX;
         out << o.LocationBlock[i].GlobalY;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FindAgentMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentBlock.Hunter;
    in >> o.AgentBlock.Prey;
    in >> o.AgentBlock.SpaceIP;

    o.LocationBlock.clear();
    lltypes::U8 countLocationBlock;
    in >> countLocationBlock;
    for(int i=0;i<countLocationBlock;i++){
        FindAgentMessage::LocationBlockBlock y;
        in >> y.GlobalX;
        in >> y.GlobalY;
        o.LocationBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestGodlikePowersMessage::RequestGodlikePowersMessage (){
    type=RequestGodlikePowersType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestGodlikePowersMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RequestBlock.Godlike;
    out << o.RequestBlock.Token;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestGodlikePowersMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RequestBlock.Godlike;
    in >> o.RequestBlock.Token;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GrantGodlikePowersMessage::GrantGodlikePowersMessage (){
    type=GrantGodlikePowersType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GrantGodlikePowersMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GrantData.GodLevel;
    out << o.GrantData.Token;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GrantGodlikePowersMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GrantData.GodLevel;
    in >> o.GrantData.Token;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GodlikeMessageMessage::GodlikeMessageMessage (){
    type=GodlikeMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GodlikeMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.TransactionID;

    out << o.MethodData.Method;
    out << o.MethodData.Invoice;

    out << (lltypes::U8)o.ParamList.size();
    for(int i=0;i<o.ParamList.size();i++){
         out << o.ParamList[i].Parameter;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GodlikeMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.TransactionID;

    in >> o.MethodData.Method;
    in >> o.MethodData.Invoice;

    o.ParamList.clear();
    lltypes::U8 countParamList;
    in >> countParamList;
    for(int i=0;i<countParamList;i++){
        GodlikeMessageMessage::ParamListBlock y;
        in >> y.Parameter;
        o.ParamList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EstateOwnerMessageMessage::EstateOwnerMessageMessage (){
    type=EstateOwnerMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EstateOwnerMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.TransactionID;

    out << o.MethodData.Method;
    out << o.MethodData.Invoice;

    out << (lltypes::U8)o.ParamList.size();
    for(int i=0;i<o.ParamList.size();i++){
         out << o.ParamList[i].Parameter;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EstateOwnerMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.TransactionID;

    in >> o.MethodData.Method;
    in >> o.MethodData.Invoice;

    o.ParamList.clear();
    lltypes::U8 countParamList;
    in >> countParamList;
    for(int i=0;i<countParamList;i++){
        EstateOwnerMessageMessage::ParamListBlock y;
        in >> y.Parameter;
        o.ParamList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GenericMessageMessage::GenericMessageMessage (){
    type=GenericMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GenericMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.TransactionID;

    out << o.MethodData.Method;
    out << o.MethodData.Invoice;

    out << (lltypes::U8)o.ParamList.size();
    for(int i=0;i<o.ParamList.size();i++){
         out << o.ParamList[i].Parameter;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GenericMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.TransactionID;

    in >> o.MethodData.Method;
    in >> o.MethodData.Invoice;

    o.ParamList.clear();
    lltypes::U8 countParamList;
    in >> countParamList;
    for(int i=0;i<countParamList;i++){
        GenericMessageMessage::ParamListBlock y;
        in >> y.Parameter;
        o.ParamList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MuteListRequestMessage::MuteListRequestMessage (){
    type=MuteListRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MuteListRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MuteData.MuteCRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MuteListRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MuteData.MuteCRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateMuteListEntryMessage::UpdateMuteListEntryMessage (){
    type=UpdateMuteListEntryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateMuteListEntryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MuteData.MuteID;
    out << o.MuteData.MuteName;
    out << o.MuteData.MuteType;
    out << o.MuteData.MuteFlags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateMuteListEntryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MuteData.MuteID;
    in >> o.MuteData.MuteName;
    in >> o.MuteData.MuteType;
    in >> o.MuteData.MuteFlags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveMuteListEntryMessage::RemoveMuteListEntryMessage (){
    type=RemoveMuteListEntryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveMuteListEntryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MuteData.MuteID;
    out << o.MuteData.MuteName;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveMuteListEntryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MuteData.MuteID;
    in >> o.MuteData.MuteName;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CopyInventoryFromNotecardMessage::CopyInventoryFromNotecardMessage (){
    type=CopyInventoryFromNotecardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CopyInventoryFromNotecardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.NotecardData.NotecardItemID;
    out << o.NotecardData.ObjectID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].FolderID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CopyInventoryFromNotecardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.NotecardData.NotecardItemID;
    in >> o.NotecardData.ObjectID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        CopyInventoryFromNotecardMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateInventoryItemMessage::UpdateInventoryItemMessage (){
    type=UpdateInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.TransactionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].FolderID;
         out << o.InventoryData[i].CallbackID;
         out << o.InventoryData[i].CreatorID;
         out << o.InventoryData[i].OwnerID;
         out << o.InventoryData[i].GroupID;
         out << o.InventoryData[i].BaseMask;
         out << o.InventoryData[i].OwnerMask;
         out << o.InventoryData[i].GroupMask;
         out << o.InventoryData[i].EveryoneMask;
         out << o.InventoryData[i].NextOwnerMask;
         out << o.InventoryData[i].GroupOwned;
         out << o.InventoryData[i].TransactionID;
         out << o.InventoryData[i].Type;
         out << o.InventoryData[i].InvType;
         out << o.InventoryData[i].Flags;
         out << o.InventoryData[i].SaleType;
         out << o.InventoryData[i].SalePrice;
         out << o.InventoryData[i].Name;
         out << o.InventoryData[i].Description;
         out << o.InventoryData[i].CreationDate;
         out << o.InventoryData[i].CRC;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.TransactionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        UpdateInventoryItemMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.CallbackID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.GroupOwned;
        in >> y.TransactionID;
        in >> y.Type;
        in >> y.InvType;
        in >> y.Flags;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.Name;
        in >> y.Description;
        in >> y.CreationDate;
        in >> y.CRC;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateCreateInventoryItemMessage::UpdateCreateInventoryItemMessage (){
    type=UpdateCreateInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateCreateInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SimApproved;
    out << o.AgentData.TransactionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].FolderID;
         out << o.InventoryData[i].CallbackID;
         out << o.InventoryData[i].CreatorID;
         out << o.InventoryData[i].OwnerID;
         out << o.InventoryData[i].GroupID;
         out << o.InventoryData[i].BaseMask;
         out << o.InventoryData[i].OwnerMask;
         out << o.InventoryData[i].GroupMask;
         out << o.InventoryData[i].EveryoneMask;
         out << o.InventoryData[i].NextOwnerMask;
         out << o.InventoryData[i].GroupOwned;
         out << o.InventoryData[i].AssetID;
         out << o.InventoryData[i].Type;
         out << o.InventoryData[i].InvType;
         out << o.InventoryData[i].Flags;
         out << o.InventoryData[i].SaleType;
         out << o.InventoryData[i].SalePrice;
         out << o.InventoryData[i].Name;
         out << o.InventoryData[i].Description;
         out << o.InventoryData[i].CreationDate;
         out << o.InventoryData[i].CRC;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateCreateInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SimApproved;
    in >> o.AgentData.TransactionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        UpdateCreateInventoryItemMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.CallbackID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.GroupOwned;
        in >> y.AssetID;
        in >> y.Type;
        in >> y.InvType;
        in >> y.Flags;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.Name;
        in >> y.Description;
        in >> y.CreationDate;
        in >> y.CRC;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoveInventoryItemMessage::MoveInventoryItemMessage (){
    type=MoveInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoveInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Stamp;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].FolderID;
         out << o.InventoryData[i].NewName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoveInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Stamp;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        MoveInventoryItemMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.NewName;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CopyInventoryItemMessage::CopyInventoryItemMessage (){
    type=CopyInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CopyInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].CallbackID;
         out << o.InventoryData[i].OldAgentID;
         out << o.InventoryData[i].OldItemID;
         out << o.InventoryData[i].NewFolderID;
         out << o.InventoryData[i].NewName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CopyInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        CopyInventoryItemMessage::InventoryDataBlock y;
        in >> y.CallbackID;
        in >> y.OldAgentID;
        in >> y.OldItemID;
        in >> y.NewFolderID;
        in >> y.NewName;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveInventoryItemMessage::RemoveInventoryItemMessage (){
    type=RemoveInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        RemoveInventoryItemMessage::InventoryDataBlock y;
        in >> y.ItemID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChangeInventoryItemFlagsMessage::ChangeInventoryItemFlagsMessage (){
    type=ChangeInventoryItemFlagsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChangeInventoryItemFlagsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].Flags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChangeInventoryItemFlagsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        ChangeInventoryItemFlagsMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.Flags;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SaveAssetIntoInventoryMessage::SaveAssetIntoInventoryMessage (){
    type=SaveAssetIntoInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SaveAssetIntoInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.InventoryData.ItemID;
    out << o.InventoryData.NewAssetID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SaveAssetIntoInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.InventoryData.ItemID;
    in >> o.InventoryData.NewAssetID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateInventoryFolderMessage::CreateInventoryFolderMessage (){
    type=CreateInventoryFolderType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateInventoryFolderMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.FolderData.FolderID;
    out << o.FolderData.ParentID;
    out << o.FolderData.Type;
    out << o.FolderData.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateInventoryFolderMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.FolderData.FolderID;
    in >> o.FolderData.ParentID;
    in >> o.FolderData.Type;
    in >> o.FolderData.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateInventoryFolderMessage::UpdateInventoryFolderMessage (){
    type=UpdateInventoryFolderType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateInventoryFolderMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
         out << o.FolderData[i].ParentID;
         out << o.FolderData[i].Type;
         out << o.FolderData[i].Name;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateInventoryFolderMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        UpdateInventoryFolderMessage::FolderDataBlock y;
        in >> y.FolderID;
        in >> y.ParentID;
        in >> y.Type;
        in >> y.Name;
        o.FolderData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoveInventoryFolderMessage::MoveInventoryFolderMessage (){
    type=MoveInventoryFolderType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoveInventoryFolderMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Stamp;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].FolderID;
         out << o.InventoryData[i].ParentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoveInventoryFolderMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Stamp;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        MoveInventoryFolderMessage::InventoryDataBlock y;
        in >> y.FolderID;
        in >> y.ParentID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveInventoryFolderMessage::RemoveInventoryFolderMessage (){
    type=RemoveInventoryFolderType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveInventoryFolderMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveInventoryFolderMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        RemoveInventoryFolderMessage::FolderDataBlock y;
        in >> y.FolderID;
        o.FolderData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FetchInventoryDescendentsMessage::FetchInventoryDescendentsMessage (){
    type=FetchInventoryDescendentsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FetchInventoryDescendentsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryData.FolderID;
    out << o.InventoryData.OwnerID;
    out << o.InventoryData.SortOrder;
    out << o.InventoryData.FetchFolders;
    out << o.InventoryData.FetchItems;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FetchInventoryDescendentsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryData.FolderID;
    in >> o.InventoryData.OwnerID;
    in >> o.InventoryData.SortOrder;
    in >> o.InventoryData.FetchFolders;
    in >> o.InventoryData.FetchItems;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InventoryDescendentsMessage::InventoryDescendentsMessage (){
    type=InventoryDescendentsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InventoryDescendentsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.FolderID;
    out << o.AgentData.OwnerID;
    out << o.AgentData.Version;
    out << o.AgentData.Descendents;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
         out << o.FolderData[i].ParentID;
         out << o.FolderData[i].Type;
         out << o.FolderData[i].Name;
    }

    out << (lltypes::U8)o.ItemData.size();
    for(int i=0;i<o.ItemData.size();i++){
         out << o.ItemData[i].ItemID;
         out << o.ItemData[i].FolderID;
         out << o.ItemData[i].CreatorID;
         out << o.ItemData[i].OwnerID;
         out << o.ItemData[i].GroupID;
         out << o.ItemData[i].BaseMask;
         out << o.ItemData[i].OwnerMask;
         out << o.ItemData[i].GroupMask;
         out << o.ItemData[i].EveryoneMask;
         out << o.ItemData[i].NextOwnerMask;
         out << o.ItemData[i].GroupOwned;
         out << o.ItemData[i].AssetID;
         out << o.ItemData[i].Type;
         out << o.ItemData[i].InvType;
         out << o.ItemData[i].Flags;
         out << o.ItemData[i].SaleType;
         out << o.ItemData[i].SalePrice;
         out << o.ItemData[i].Name;
         out << o.ItemData[i].Description;
         out << o.ItemData[i].CreationDate;
         out << o.ItemData[i].CRC;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InventoryDescendentsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.FolderID;
    in >> o.AgentData.OwnerID;
    in >> o.AgentData.Version;
    in >> o.AgentData.Descendents;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        InventoryDescendentsMessage::FolderDataBlock y;
        in >> y.FolderID;
        in >> y.ParentID;
        in >> y.Type;
        in >> y.Name;
        o.FolderData << y;
    }

    o.ItemData.clear();
    lltypes::U8 countItemData;
    in >> countItemData;
    for(int i=0;i<countItemData;i++){
        InventoryDescendentsMessage::ItemDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.GroupOwned;
        in >> y.AssetID;
        in >> y.Type;
        in >> y.InvType;
        in >> y.Flags;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.Name;
        in >> y.Description;
        in >> y.CreationDate;
        in >> y.CRC;
        o.ItemData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FetchInventoryMessage::FetchInventoryMessage (){
    type=FetchInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FetchInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].OwnerID;
         out << o.InventoryData[i].ItemID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FetchInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        FetchInventoryMessage::InventoryDataBlock y;
        in >> y.OwnerID;
        in >> y.ItemID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FetchInventoryReplyMessage::FetchInventoryReplyMessage (){
    type=FetchInventoryReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FetchInventoryReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
         out << o.InventoryData[i].FolderID;
         out << o.InventoryData[i].CreatorID;
         out << o.InventoryData[i].OwnerID;
         out << o.InventoryData[i].GroupID;
         out << o.InventoryData[i].BaseMask;
         out << o.InventoryData[i].OwnerMask;
         out << o.InventoryData[i].GroupMask;
         out << o.InventoryData[i].EveryoneMask;
         out << o.InventoryData[i].NextOwnerMask;
         out << o.InventoryData[i].GroupOwned;
         out << o.InventoryData[i].AssetID;
         out << o.InventoryData[i].Type;
         out << o.InventoryData[i].InvType;
         out << o.InventoryData[i].Flags;
         out << o.InventoryData[i].SaleType;
         out << o.InventoryData[i].SalePrice;
         out << o.InventoryData[i].Name;
         out << o.InventoryData[i].Description;
         out << o.InventoryData[i].CreationDate;
         out << o.InventoryData[i].CRC;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FetchInventoryReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        FetchInventoryReplyMessage::InventoryDataBlock y;
        in >> y.ItemID;
        in >> y.FolderID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.GroupOwned;
        in >> y.AssetID;
        in >> y.Type;
        in >> y.InvType;
        in >> y.Flags;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.Name;
        in >> y.Description;
        in >> y.CreationDate;
        in >> y.CRC;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


BulkUpdateInventoryMessage::BulkUpdateInventoryMessage (){
    type=BulkUpdateInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const BulkUpdateInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.TransactionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
         out << o.FolderData[i].ParentID;
         out << o.FolderData[i].Type;
         out << o.FolderData[i].Name;
    }

    out << (lltypes::U8)o.ItemData.size();
    for(int i=0;i<o.ItemData.size();i++){
         out << o.ItemData[i].ItemID;
         out << o.ItemData[i].CallbackID;
         out << o.ItemData[i].FolderID;
         out << o.ItemData[i].CreatorID;
         out << o.ItemData[i].OwnerID;
         out << o.ItemData[i].GroupID;
         out << o.ItemData[i].BaseMask;
         out << o.ItemData[i].OwnerMask;
         out << o.ItemData[i].GroupMask;
         out << o.ItemData[i].EveryoneMask;
         out << o.ItemData[i].NextOwnerMask;
         out << o.ItemData[i].GroupOwned;
         out << o.ItemData[i].AssetID;
         out << o.ItemData[i].Type;
         out << o.ItemData[i].InvType;
         out << o.ItemData[i].Flags;
         out << o.ItemData[i].SaleType;
         out << o.ItemData[i].SalePrice;
         out << o.ItemData[i].Name;
         out << o.ItemData[i].Description;
         out << o.ItemData[i].CreationDate;
         out << o.ItemData[i].CRC;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  BulkUpdateInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.TransactionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        BulkUpdateInventoryMessage::FolderDataBlock y;
        in >> y.FolderID;
        in >> y.ParentID;
        in >> y.Type;
        in >> y.Name;
        o.FolderData << y;
    }

    o.ItemData.clear();
    lltypes::U8 countItemData;
    in >> countItemData;
    for(int i=0;i<countItemData;i++){
        BulkUpdateInventoryMessage::ItemDataBlock y;
        in >> y.ItemID;
        in >> y.CallbackID;
        in >> y.FolderID;
        in >> y.CreatorID;
        in >> y.OwnerID;
        in >> y.GroupID;
        in >> y.BaseMask;
        in >> y.OwnerMask;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.GroupOwned;
        in >> y.AssetID;
        in >> y.Type;
        in >> y.InvType;
        in >> y.Flags;
        in >> y.SaleType;
        in >> y.SalePrice;
        in >> y.Name;
        in >> y.Description;
        in >> y.CreationDate;
        in >> y.CRC;
        o.ItemData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestInventoryAssetMessage::RequestInventoryAssetMessage (){
    type=RequestInventoryAssetType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestInventoryAssetMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.QueryData.QueryID;
    out << o.QueryData.AgentID;
    out << o.QueryData.OwnerID;
    out << o.QueryData.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestInventoryAssetMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.QueryData.QueryID;
    in >> o.QueryData.AgentID;
    in >> o.QueryData.OwnerID;
    in >> o.QueryData.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InventoryAssetResponseMessage::InventoryAssetResponseMessage (){
    type=InventoryAssetResponseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InventoryAssetResponseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.QueryData.QueryID;
    out << o.QueryData.AssetID;
    out << o.QueryData.IsReadable;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InventoryAssetResponseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.QueryData.QueryID;
    in >> o.QueryData.AssetID;
    in >> o.QueryData.IsReadable;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveInventoryObjectsMessage::RemoveInventoryObjectsMessage (){
    type=RemoveInventoryObjectsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveInventoryObjectsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
    }

    out << (lltypes::U8)o.ItemData.size();
    for(int i=0;i<o.ItemData.size();i++){
         out << o.ItemData[i].ItemID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveInventoryObjectsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        RemoveInventoryObjectsMessage::FolderDataBlock y;
        in >> y.FolderID;
        o.FolderData << y;
    }

    o.ItemData.clear();
    lltypes::U8 countItemData;
    in >> countItemData;
    for(int i=0;i<countItemData;i++){
        RemoveInventoryObjectsMessage::ItemDataBlock y;
        in >> y.ItemID;
        o.ItemData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PurgeInventoryDescendentsMessage::PurgeInventoryDescendentsMessage (){
    type=PurgeInventoryDescendentsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PurgeInventoryDescendentsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryData.FolderID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PurgeInventoryDescendentsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryData.FolderID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateTaskInventoryMessage::UpdateTaskInventoryMessage (){
    type=UpdateTaskInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateTaskInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.UpdateData.LocalID;
    out << o.UpdateData.Key;

    out << o.InventoryData.ItemID;
    out << o.InventoryData.FolderID;
    out << o.InventoryData.CreatorID;
    out << o.InventoryData.OwnerID;
    out << o.InventoryData.GroupID;
    out << o.InventoryData.BaseMask;
    out << o.InventoryData.OwnerMask;
    out << o.InventoryData.GroupMask;
    out << o.InventoryData.EveryoneMask;
    out << o.InventoryData.NextOwnerMask;
    out << o.InventoryData.GroupOwned;
    out << o.InventoryData.TransactionID;
    out << o.InventoryData.Type;
    out << o.InventoryData.InvType;
    out << o.InventoryData.Flags;
    out << o.InventoryData.SaleType;
    out << o.InventoryData.SalePrice;
    out << o.InventoryData.Name;
    out << o.InventoryData.Description;
    out << o.InventoryData.CreationDate;
    out << o.InventoryData.CRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateTaskInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.UpdateData.LocalID;
    in >> o.UpdateData.Key;

    in >> o.InventoryData.ItemID;
    in >> o.InventoryData.FolderID;
    in >> o.InventoryData.CreatorID;
    in >> o.InventoryData.OwnerID;
    in >> o.InventoryData.GroupID;
    in >> o.InventoryData.BaseMask;
    in >> o.InventoryData.OwnerMask;
    in >> o.InventoryData.GroupMask;
    in >> o.InventoryData.EveryoneMask;
    in >> o.InventoryData.NextOwnerMask;
    in >> o.InventoryData.GroupOwned;
    in >> o.InventoryData.TransactionID;
    in >> o.InventoryData.Type;
    in >> o.InventoryData.InvType;
    in >> o.InventoryData.Flags;
    in >> o.InventoryData.SaleType;
    in >> o.InventoryData.SalePrice;
    in >> o.InventoryData.Name;
    in >> o.InventoryData.Description;
    in >> o.InventoryData.CreationDate;
    in >> o.InventoryData.CRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveTaskInventoryMessage::RemoveTaskInventoryMessage (){
    type=RemoveTaskInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveTaskInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryData.LocalID;
    out << o.InventoryData.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveTaskInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryData.LocalID;
    in >> o.InventoryData.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoveTaskInventoryMessage::MoveTaskInventoryMessage (){
    type=MoveTaskInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoveTaskInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.FolderID;

    out << o.InventoryData.LocalID;
    out << o.InventoryData.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoveTaskInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.FolderID;

    in >> o.InventoryData.LocalID;
    in >> o.InventoryData.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestTaskInventoryMessage::RequestTaskInventoryMessage (){
    type=RequestTaskInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestTaskInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryData.LocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestTaskInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryData.LocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ReplyTaskInventoryMessage::ReplyTaskInventoryMessage (){
    type=ReplyTaskInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ReplyTaskInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.InventoryData.TaskID;
    out << o.InventoryData.Serial;
    out << o.InventoryData.Filename;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ReplyTaskInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.InventoryData.TaskID;
    in >> o.InventoryData.Serial;
    in >> o.InventoryData.Filename;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DeRezObjectMessage::DeRezObjectMessage (){
    type=DeRezObjectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DeRezObjectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.AgentBlock.GroupID;
    out << o.AgentBlock.Destination;
    out << o.AgentBlock.DestinationID;
    out << o.AgentBlock.TransactionID;
    out << o.AgentBlock.PacketCount;
    out << o.AgentBlock.PacketNumber;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DeRezObjectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.AgentBlock.GroupID;
    in >> o.AgentBlock.Destination;
    in >> o.AgentBlock.DestinationID;
    in >> o.AgentBlock.TransactionID;
    in >> o.AgentBlock.PacketCount;
    in >> o.AgentBlock.PacketNumber;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        DeRezObjectMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DeRezAckMessage::DeRezAckMessage (){
    type=DeRezAckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DeRezAckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TransactionData.TransactionID;
    out << o.TransactionData.Success;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DeRezAckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TransactionData.TransactionID;
    in >> o.TransactionData.Success;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezObjectMessage::RezObjectMessage (){
    type=RezObjectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezObjectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.RezData.FromTaskID;
    out << o.RezData.BypassRaycast;
    out << o.RezData.RayStart;
    out << o.RezData.RayEnd;
    out << o.RezData.RayTargetID;
    out << o.RezData.RayEndIsIntersection;
    out << o.RezData.RezSelected;
    out << o.RezData.RemoveItem;
    out << o.RezData.ItemFlags;
    out << o.RezData.GroupMask;
    out << o.RezData.EveryoneMask;
    out << o.RezData.NextOwnerMask;

    out << o.InventoryData.ItemID;
    out << o.InventoryData.FolderID;
    out << o.InventoryData.CreatorID;
    out << o.InventoryData.OwnerID;
    out << o.InventoryData.GroupID;
    out << o.InventoryData.BaseMask;
    out << o.InventoryData.OwnerMask;
    out << o.InventoryData.GroupMask;
    out << o.InventoryData.EveryoneMask;
    out << o.InventoryData.NextOwnerMask;
    out << o.InventoryData.GroupOwned;
    out << o.InventoryData.TransactionID;
    out << o.InventoryData.Type;
    out << o.InventoryData.InvType;
    out << o.InventoryData.Flags;
    out << o.InventoryData.SaleType;
    out << o.InventoryData.SalePrice;
    out << o.InventoryData.Name;
    out << o.InventoryData.Description;
    out << o.InventoryData.CreationDate;
    out << o.InventoryData.CRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezObjectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.RezData.FromTaskID;
    in >> o.RezData.BypassRaycast;
    in >> o.RezData.RayStart;
    in >> o.RezData.RayEnd;
    in >> o.RezData.RayTargetID;
    in >> o.RezData.RayEndIsIntersection;
    in >> o.RezData.RezSelected;
    in >> o.RezData.RemoveItem;
    in >> o.RezData.ItemFlags;
    in >> o.RezData.GroupMask;
    in >> o.RezData.EveryoneMask;
    in >> o.RezData.NextOwnerMask;

    in >> o.InventoryData.ItemID;
    in >> o.InventoryData.FolderID;
    in >> o.InventoryData.CreatorID;
    in >> o.InventoryData.OwnerID;
    in >> o.InventoryData.GroupID;
    in >> o.InventoryData.BaseMask;
    in >> o.InventoryData.OwnerMask;
    in >> o.InventoryData.GroupMask;
    in >> o.InventoryData.EveryoneMask;
    in >> o.InventoryData.NextOwnerMask;
    in >> o.InventoryData.GroupOwned;
    in >> o.InventoryData.TransactionID;
    in >> o.InventoryData.Type;
    in >> o.InventoryData.InvType;
    in >> o.InventoryData.Flags;
    in >> o.InventoryData.SaleType;
    in >> o.InventoryData.SalePrice;
    in >> o.InventoryData.Name;
    in >> o.InventoryData.Description;
    in >> o.InventoryData.CreationDate;
    in >> o.InventoryData.CRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezObjectFromNotecardMessage::RezObjectFromNotecardMessage (){
    type=RezObjectFromNotecardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezObjectFromNotecardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.RezData.FromTaskID;
    out << o.RezData.BypassRaycast;
    out << o.RezData.RayStart;
    out << o.RezData.RayEnd;
    out << o.RezData.RayTargetID;
    out << o.RezData.RayEndIsIntersection;
    out << o.RezData.RezSelected;
    out << o.RezData.RemoveItem;
    out << o.RezData.ItemFlags;
    out << o.RezData.GroupMask;
    out << o.RezData.EveryoneMask;
    out << o.RezData.NextOwnerMask;

    out << o.NotecardData.NotecardItemID;
    out << o.NotecardData.ObjectID;

    out << (lltypes::U8)o.InventoryData.size();
    for(int i=0;i<o.InventoryData.size();i++){
         out << o.InventoryData[i].ItemID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezObjectFromNotecardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.RezData.FromTaskID;
    in >> o.RezData.BypassRaycast;
    in >> o.RezData.RayStart;
    in >> o.RezData.RayEnd;
    in >> o.RezData.RayTargetID;
    in >> o.RezData.RayEndIsIntersection;
    in >> o.RezData.RezSelected;
    in >> o.RezData.RemoveItem;
    in >> o.RezData.ItemFlags;
    in >> o.RezData.GroupMask;
    in >> o.RezData.EveryoneMask;
    in >> o.RezData.NextOwnerMask;

    in >> o.NotecardData.NotecardItemID;
    in >> o.NotecardData.ObjectID;

    o.InventoryData.clear();
    lltypes::U8 countInventoryData;
    in >> countInventoryData;
    for(int i=0;i<countInventoryData;i++){
        RezObjectFromNotecardMessage::InventoryDataBlock y;
        in >> y.ItemID;
        o.InventoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferInventoryMessage::TransferInventoryMessage (){
    type=TransferInventoryType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferInventoryMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.InfoBlock.SourceID;
    out << o.InfoBlock.DestID;
    out << o.InfoBlock.TransactionID;

    out << (lltypes::U8)o.InventoryBlock.size();
    for(int i=0;i<o.InventoryBlock.size();i++){
         out << o.InventoryBlock[i].InventoryID;
         out << o.InventoryBlock[i].Type;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferInventoryMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.InfoBlock.SourceID;
    in >> o.InfoBlock.DestID;
    in >> o.InfoBlock.TransactionID;

    o.InventoryBlock.clear();
    lltypes::U8 countInventoryBlock;
    in >> countInventoryBlock;
    for(int i=0;i<countInventoryBlock;i++){
        TransferInventoryMessage::InventoryBlockBlock y;
        in >> y.InventoryID;
        in >> y.Type;
        o.InventoryBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TransferInventoryAckMessage::TransferInventoryAckMessage (){
    type=TransferInventoryAckType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TransferInventoryAckMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.InfoBlock.TransactionID;
    out << o.InfoBlock.InventoryID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TransferInventoryAckMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.InfoBlock.TransactionID;
    in >> o.InfoBlock.InventoryID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AcceptFriendshipMessage::AcceptFriendshipMessage (){
    type=AcceptFriendshipType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AcceptFriendshipMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TransactionBlock.TransactionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AcceptFriendshipMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TransactionBlock.TransactionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        AcceptFriendshipMessage::FolderDataBlock y;
        in >> y.FolderID;
        o.FolderData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DeclineFriendshipMessage::DeclineFriendshipMessage (){
    type=DeclineFriendshipType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DeclineFriendshipMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TransactionBlock.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DeclineFriendshipMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TransactionBlock.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


FormFriendshipMessage::FormFriendshipMessage (){
    type=FormFriendshipType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const FormFriendshipMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentBlock.SourceID;
    out << o.AgentBlock.DestID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  FormFriendshipMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentBlock.SourceID;
    in >> o.AgentBlock.DestID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TerminateFriendshipMessage::TerminateFriendshipMessage (){
    type=TerminateFriendshipType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TerminateFriendshipMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ExBlock.OtherID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TerminateFriendshipMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ExBlock.OtherID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


OfferCallingCardMessage::OfferCallingCardMessage (){
    type=OfferCallingCardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const OfferCallingCardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.AgentBlock.DestID;
    out << o.AgentBlock.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  OfferCallingCardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.AgentBlock.DestID;
    in >> o.AgentBlock.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AcceptCallingCardMessage::AcceptCallingCardMessage (){
    type=AcceptCallingCardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AcceptCallingCardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TransactionBlock.TransactionID;

    out << (lltypes::U8)o.FolderData.size();
    for(int i=0;i<o.FolderData.size();i++){
         out << o.FolderData[i].FolderID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AcceptCallingCardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TransactionBlock.TransactionID;

    o.FolderData.clear();
    lltypes::U8 countFolderData;
    in >> countFolderData;
    for(int i=0;i<countFolderData;i++){
        AcceptCallingCardMessage::FolderDataBlock y;
        in >> y.FolderID;
        o.FolderData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DeclineCallingCardMessage::DeclineCallingCardMessage (){
    type=DeclineCallingCardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DeclineCallingCardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.TransactionBlock.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DeclineCallingCardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.TransactionBlock.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezScriptMessage::RezScriptMessage (){
    type=RezScriptType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezScriptMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.UpdateBlock.ObjectLocalID;
    out << o.UpdateBlock.Enabled;

    out << o.InventoryBlock.ItemID;
    out << o.InventoryBlock.FolderID;
    out << o.InventoryBlock.CreatorID;
    out << o.InventoryBlock.OwnerID;
    out << o.InventoryBlock.GroupID;
    out << o.InventoryBlock.BaseMask;
    out << o.InventoryBlock.OwnerMask;
    out << o.InventoryBlock.GroupMask;
    out << o.InventoryBlock.EveryoneMask;
    out << o.InventoryBlock.NextOwnerMask;
    out << o.InventoryBlock.GroupOwned;
    out << o.InventoryBlock.TransactionID;
    out << o.InventoryBlock.Type;
    out << o.InventoryBlock.InvType;
    out << o.InventoryBlock.Flags;
    out << o.InventoryBlock.SaleType;
    out << o.InventoryBlock.SalePrice;
    out << o.InventoryBlock.Name;
    out << o.InventoryBlock.Description;
    out << o.InventoryBlock.CreationDate;
    out << o.InventoryBlock.CRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezScriptMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.UpdateBlock.ObjectLocalID;
    in >> o.UpdateBlock.Enabled;

    in >> o.InventoryBlock.ItemID;
    in >> o.InventoryBlock.FolderID;
    in >> o.InventoryBlock.CreatorID;
    in >> o.InventoryBlock.OwnerID;
    in >> o.InventoryBlock.GroupID;
    in >> o.InventoryBlock.BaseMask;
    in >> o.InventoryBlock.OwnerMask;
    in >> o.InventoryBlock.GroupMask;
    in >> o.InventoryBlock.EveryoneMask;
    in >> o.InventoryBlock.NextOwnerMask;
    in >> o.InventoryBlock.GroupOwned;
    in >> o.InventoryBlock.TransactionID;
    in >> o.InventoryBlock.Type;
    in >> o.InventoryBlock.InvType;
    in >> o.InventoryBlock.Flags;
    in >> o.InventoryBlock.SaleType;
    in >> o.InventoryBlock.SalePrice;
    in >> o.InventoryBlock.Name;
    in >> o.InventoryBlock.Description;
    in >> o.InventoryBlock.CreationDate;
    in >> o.InventoryBlock.CRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateInventoryItemMessage::CreateInventoryItemMessage (){
    type=CreateInventoryItemType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateInventoryItemMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryBlock.CallbackID;
    out << o.InventoryBlock.FolderID;
    out << o.InventoryBlock.TransactionID;
    out << o.InventoryBlock.NextOwnerMask;
    out << o.InventoryBlock.Type;
    out << o.InventoryBlock.InvType;
    out << o.InventoryBlock.WearableType;
    out << o.InventoryBlock.Name;
    out << o.InventoryBlock.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateInventoryItemMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryBlock.CallbackID;
    in >> o.InventoryBlock.FolderID;
    in >> o.InventoryBlock.TransactionID;
    in >> o.InventoryBlock.NextOwnerMask;
    in >> o.InventoryBlock.Type;
    in >> o.InventoryBlock.InvType;
    in >> o.InventoryBlock.WearableType;
    in >> o.InventoryBlock.Name;
    in >> o.InventoryBlock.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateLandmarkForEventMessage::CreateLandmarkForEventMessage (){
    type=CreateLandmarkForEventType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateLandmarkForEventMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.EventData.EventID;

    out << o.InventoryBlock.FolderID;
    out << o.InventoryBlock.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateLandmarkForEventMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.EventData.EventID;

    in >> o.InventoryBlock.FolderID;
    in >> o.InventoryBlock.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventLocationRequestMessage::EventLocationRequestMessage (){
    type=EventLocationRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventLocationRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.QueryData.QueryID;

    out << o.EventData.EventID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventLocationRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.QueryData.QueryID;

    in >> o.EventData.EventID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EventLocationReplyMessage::EventLocationReplyMessage (){
    type=EventLocationReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EventLocationReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.QueryData.QueryID;

    out << o.EventData.Success;
    out << o.EventData.RegionID;
    out << o.EventData.RegionPos;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EventLocationReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.QueryData.QueryID;

    in >> o.EventData.Success;
    in >> o.EventData.RegionID;
    in >> o.EventData.RegionPos;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionHandleRequestMessage::RegionHandleRequestMessage (){
    type=RegionHandleRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionHandleRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RequestBlock.RegionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionHandleRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RequestBlock.RegionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RegionIDAndHandleReplyMessage::RegionIDAndHandleReplyMessage (){
    type=RegionIDAndHandleReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RegionIDAndHandleReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ReplyBlock.RegionID;
    out << o.ReplyBlock.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RegionIDAndHandleReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ReplyBlock.RegionID;
    in >> o.ReplyBlock.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoneyTransferRequestMessage::MoneyTransferRequestMessage (){
    type=MoneyTransferRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoneyTransferRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MoneyData.SourceID;
    out << o.MoneyData.DestID;
    out << o.MoneyData.Flags;
    out << o.MoneyData.Amount;
    out << o.MoneyData.AggregatePermNextOwner;
    out << o.MoneyData.AggregatePermInventory;
    out << o.MoneyData.TransactionType;
    out << o.MoneyData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoneyTransferRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MoneyData.SourceID;
    in >> o.MoneyData.DestID;
    in >> o.MoneyData.Flags;
    in >> o.MoneyData.Amount;
    in >> o.MoneyData.AggregatePermNextOwner;
    in >> o.MoneyData.AggregatePermInventory;
    in >> o.MoneyData.TransactionType;
    in >> o.MoneyData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoneyTransferBackendMessage::MoneyTransferBackendMessage (){
    type=MoneyTransferBackendType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoneyTransferBackendMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MoneyData.TransactionID;
    out << o.MoneyData.TransactionTime;
    out << o.MoneyData.SourceID;
    out << o.MoneyData.DestID;
    out << o.MoneyData.Flags;
    out << o.MoneyData.Amount;
    out << o.MoneyData.AggregatePermNextOwner;
    out << o.MoneyData.AggregatePermInventory;
    out << o.MoneyData.TransactionType;
    out << o.MoneyData.RegionID;
    out << o.MoneyData.GridX;
    out << o.MoneyData.GridY;
    out << o.MoneyData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoneyTransferBackendMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MoneyData.TransactionID;
    in >> o.MoneyData.TransactionTime;
    in >> o.MoneyData.SourceID;
    in >> o.MoneyData.DestID;
    in >> o.MoneyData.Flags;
    in >> o.MoneyData.Amount;
    in >> o.MoneyData.AggregatePermNextOwner;
    in >> o.MoneyData.AggregatePermInventory;
    in >> o.MoneyData.TransactionType;
    in >> o.MoneyData.RegionID;
    in >> o.MoneyData.GridX;
    in >> o.MoneyData.GridY;
    in >> o.MoneyData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoneyBalanceRequestMessage::MoneyBalanceRequestMessage (){
    type=MoneyBalanceRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoneyBalanceRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.MoneyData.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoneyBalanceRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.MoneyData.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MoneyBalanceReplyMessage::MoneyBalanceReplyMessage (){
    type=MoneyBalanceReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MoneyBalanceReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MoneyData.AgentID;
    out << o.MoneyData.TransactionID;
    out << o.MoneyData.TransactionSuccess;
    out << o.MoneyData.MoneyBalance;
    out << o.MoneyData.SquareMetersCredit;
    out << o.MoneyData.SquareMetersCommitted;
    out << o.MoneyData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MoneyBalanceReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MoneyData.AgentID;
    in >> o.MoneyData.TransactionID;
    in >> o.MoneyData.TransactionSuccess;
    in >> o.MoneyData.MoneyBalance;
    in >> o.MoneyData.SquareMetersCredit;
    in >> o.MoneyData.SquareMetersCommitted;
    in >> o.MoneyData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RoutedMoneyBalanceReplyMessage::RoutedMoneyBalanceReplyMessage (){
    type=RoutedMoneyBalanceReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RoutedMoneyBalanceReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TargetBlock.TargetIP;
    out << o.TargetBlock.TargetPort;

    out << o.MoneyData.AgentID;
    out << o.MoneyData.TransactionID;
    out << o.MoneyData.TransactionSuccess;
    out << o.MoneyData.MoneyBalance;
    out << o.MoneyData.SquareMetersCredit;
    out << o.MoneyData.SquareMetersCommitted;
    out << o.MoneyData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RoutedMoneyBalanceReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TargetBlock.TargetIP;
    in >> o.TargetBlock.TargetPort;

    in >> o.MoneyData.AgentID;
    in >> o.MoneyData.TransactionID;
    in >> o.MoneyData.TransactionSuccess;
    in >> o.MoneyData.MoneyBalance;
    in >> o.MoneyData.SquareMetersCredit;
    in >> o.MoneyData.SquareMetersCommitted;
    in >> o.MoneyData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ActivateGesturesMessage::ActivateGesturesMessage (){
    type=ActivateGesturesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ActivateGesturesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].ItemID;
         out << o.Data[i].AssetID;
         out << o.Data[i].GestureFlags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ActivateGesturesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        ActivateGesturesMessage::DataBlock y;
        in >> y.ItemID;
        in >> y.AssetID;
        in >> y.GestureFlags;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DeactivateGesturesMessage::DeactivateGesturesMessage (){
    type=DeactivateGesturesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DeactivateGesturesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].ItemID;
         out << o.Data[i].GestureFlags;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DeactivateGesturesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        DeactivateGesturesMessage::DataBlock y;
        in >> y.ItemID;
        in >> y.GestureFlags;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MuteListUpdateMessage::MuteListUpdateMessage (){
    type=MuteListUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MuteListUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MuteData.AgentID;
    out << o.MuteData.Filename;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MuteListUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MuteData.AgentID;
    in >> o.MuteData.Filename;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UseCachedMuteListMessage::UseCachedMuteListMessage (){
    type=UseCachedMuteListType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UseCachedMuteListMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UseCachedMuteListMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GrantUserRightsMessage::GrantUserRightsMessage (){
    type=GrantUserRightsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GrantUserRightsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.Rights.size();
    for(int i=0;i<o.Rights.size();i++){
         out << o.Rights[i].AgentRelated;
         out << o.Rights[i].RelatedRights;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GrantUserRightsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.Rights.clear();
    lltypes::U8 countRights;
    in >> countRights;
    for(int i=0;i<countRights;i++){
        GrantUserRightsMessage::RightsBlock y;
        in >> y.AgentRelated;
        in >> y.RelatedRights;
        o.Rights << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ChangeUserRightsMessage::ChangeUserRightsMessage (){
    type=ChangeUserRightsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ChangeUserRightsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << (lltypes::U8)o.Rights.size();
    for(int i=0;i<o.Rights.size();i++){
         out << o.Rights[i].AgentRelated;
         out << o.Rights[i].RelatedRights;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ChangeUserRightsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    o.Rights.clear();
    lltypes::U8 countRights;
    in >> countRights;
    for(int i=0;i<countRights;i++){
        ChangeUserRightsMessage::RightsBlock y;
        in >> y.AgentRelated;
        in >> y.RelatedRights;
        o.Rights << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


OnlineNotificationMessage::OnlineNotificationMessage (){
    type=OnlineNotificationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const OnlineNotificationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.AgentBlock.size();
    for(int i=0;i<o.AgentBlock.size();i++){
         out << o.AgentBlock[i].AgentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  OnlineNotificationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.AgentBlock.clear();
    lltypes::U8 countAgentBlock;
    in >> countAgentBlock;
    for(int i=0;i<countAgentBlock;i++){
        OnlineNotificationMessage::AgentBlockBlock y;
        in >> y.AgentID;
        o.AgentBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


OfflineNotificationMessage::OfflineNotificationMessage (){
    type=OfflineNotificationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const OfflineNotificationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.AgentBlock.size();
    for(int i=0;i<o.AgentBlock.size();i++){
         out << o.AgentBlock[i].AgentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  OfflineNotificationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.AgentBlock.clear();
    lltypes::U8 countAgentBlock;
    in >> countAgentBlock;
    for(int i=0;i<countAgentBlock;i++){
        OfflineNotificationMessage::AgentBlockBlock y;
        in >> y.AgentID;
        o.AgentBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetStartLocationRequestMessage::SetStartLocationRequestMessage (){
    type=SetStartLocationRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetStartLocationRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.StartLocationData.SimName;
    out << o.StartLocationData.LocationID;
    out << o.StartLocationData.LocationPos;
    out << o.StartLocationData.LocationLookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetStartLocationRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.StartLocationData.SimName;
    in >> o.StartLocationData.LocationID;
    in >> o.StartLocationData.LocationPos;
    in >> o.StartLocationData.LocationLookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetStartLocationMessage::SetStartLocationMessage (){
    type=SetStartLocationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetStartLocationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.StartLocationData.AgentID;
    out << o.StartLocationData.RegionID;
    out << o.StartLocationData.LocationID;
    out << o.StartLocationData.RegionHandle;
    out << o.StartLocationData.LocationPos;
    out << o.StartLocationData.LocationLookAt;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetStartLocationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.StartLocationData.AgentID;
    in >> o.StartLocationData.RegionID;
    in >> o.StartLocationData.LocationID;
    in >> o.StartLocationData.RegionHandle;
    in >> o.StartLocationData.LocationPos;
    in >> o.StartLocationData.LocationLookAt;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NetTestMessage::NetTestMessage (){
    type=NetTestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NetTestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.NetBlock.Port;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NetTestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.NetBlock.Port;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetCPURatioMessage::SetCPURatioMessage (){
    type=SetCPURatioType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetCPURatioMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.Ratio;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetCPURatioMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.Ratio;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SimCrashedMessage::SimCrashedMessage (){
    type=SimCrashedType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SimCrashedMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.Data.RegionX;
    out << o.Data.RegionY;

    out << (lltypes::U8)o.Users.size();
    for(int i=0;i<o.Users.size();i++){
         out << o.Users[i].AgentID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SimCrashedMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.Data.RegionX;
    in >> o.Data.RegionY;

    o.Users.clear();
    lltypes::U8 countUsers;
    in >> countUsers;
    for(int i=0;i<countUsers;i++){
        SimCrashedMessage::UsersBlock y;
        in >> y.AgentID;
        o.Users << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


NameValuePairMessage::NameValuePairMessage (){
    type=NameValuePairType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const NameValuePairMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TaskData.ID;

    out << (lltypes::U8)o.NameValueData.size();
    for(int i=0;i<o.NameValueData.size();i++){
         out << o.NameValueData[i].NVPair;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  NameValuePairMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TaskData.ID;

    o.NameValueData.clear();
    lltypes::U8 countNameValueData;
    in >> countNameValueData;
    for(int i=0;i<countNameValueData;i++){
        NameValuePairMessage::NameValueDataBlock y;
        in >> y.NVPair;
        o.NameValueData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveNameValuePairMessage::RemoveNameValuePairMessage (){
    type=RemoveNameValuePairType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveNameValuePairMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TaskData.ID;

    out << (lltypes::U8)o.NameValueData.size();
    for(int i=0;i<o.NameValueData.size();i++){
         out << o.NameValueData[i].NVPair;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveNameValuePairMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TaskData.ID;

    o.NameValueData.clear();
    lltypes::U8 countNameValueData;
    in >> countNameValueData;
    for(int i=0;i<countNameValueData;i++){
        RemoveNameValuePairMessage::NameValueDataBlock y;
        in >> y.NVPair;
        o.NameValueData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateAttachmentMessage::UpdateAttachmentMessage (){
    type=UpdateAttachmentType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateAttachmentMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.AttachmentBlock.AttachmentPoint;

    out << o.OperationData.AddItem;
    out << o.OperationData.UseExistingAsset;

    out << o.InventoryData.ItemID;
    out << o.InventoryData.FolderID;
    out << o.InventoryData.CreatorID;
    out << o.InventoryData.OwnerID;
    out << o.InventoryData.GroupID;
    out << o.InventoryData.BaseMask;
    out << o.InventoryData.OwnerMask;
    out << o.InventoryData.GroupMask;
    out << o.InventoryData.EveryoneMask;
    out << o.InventoryData.NextOwnerMask;
    out << o.InventoryData.GroupOwned;
    out << o.InventoryData.AssetID;
    out << o.InventoryData.Type;
    out << o.InventoryData.InvType;
    out << o.InventoryData.Flags;
    out << o.InventoryData.SaleType;
    out << o.InventoryData.SalePrice;
    out << o.InventoryData.Name;
    out << o.InventoryData.Description;
    out << o.InventoryData.CreationDate;
    out << o.InventoryData.CRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateAttachmentMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.AttachmentBlock.AttachmentPoint;

    in >> o.OperationData.AddItem;
    in >> o.OperationData.UseExistingAsset;

    in >> o.InventoryData.ItemID;
    in >> o.InventoryData.FolderID;
    in >> o.InventoryData.CreatorID;
    in >> o.InventoryData.OwnerID;
    in >> o.InventoryData.GroupID;
    in >> o.InventoryData.BaseMask;
    in >> o.InventoryData.OwnerMask;
    in >> o.InventoryData.GroupMask;
    in >> o.InventoryData.EveryoneMask;
    in >> o.InventoryData.NextOwnerMask;
    in >> o.InventoryData.GroupOwned;
    in >> o.InventoryData.AssetID;
    in >> o.InventoryData.Type;
    in >> o.InventoryData.InvType;
    in >> o.InventoryData.Flags;
    in >> o.InventoryData.SaleType;
    in >> o.InventoryData.SalePrice;
    in >> o.InventoryData.Name;
    in >> o.InventoryData.Description;
    in >> o.InventoryData.CreationDate;
    in >> o.InventoryData.CRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RemoveAttachmentMessage::RemoveAttachmentMessage (){
    type=RemoveAttachmentType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RemoveAttachmentMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.AttachmentBlock.AttachmentPoint;
    out << o.AttachmentBlock.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RemoveAttachmentMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.AttachmentBlock.AttachmentPoint;
    in >> o.AttachmentBlock.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SoundTriggerMessage::SoundTriggerMessage (){
    type=SoundTriggerType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SoundTriggerMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.SoundData.SoundID;
    out << o.SoundData.OwnerID;
    out << o.SoundData.ObjectID;
    out << o.SoundData.ParentID;
    out << o.SoundData.Handle;
    out << o.SoundData.Position;
    out << o.SoundData.Gain;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SoundTriggerMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.SoundData.SoundID;
    in >> o.SoundData.OwnerID;
    in >> o.SoundData.ObjectID;
    in >> o.SoundData.ParentID;
    in >> o.SoundData.Handle;
    in >> o.SoundData.Position;
    in >> o.SoundData.Gain;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AttachedSoundMessage::AttachedSoundMessage (){
    type=AttachedSoundType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AttachedSoundMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.SoundID;
    out << o.DataBlock.ObjectID;
    out << o.DataBlock.OwnerID;
    out << o.DataBlock.Gain;
    out << o.DataBlock.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AttachedSoundMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.SoundID;
    in >> o.DataBlock.ObjectID;
    in >> o.DataBlock.OwnerID;
    in >> o.DataBlock.Gain;
    in >> o.DataBlock.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AttachedSoundGainChangeMessage::AttachedSoundGainChangeMessage (){
    type=AttachedSoundGainChangeType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AttachedSoundGainChangeMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.ObjectID;
    out << o.DataBlock.Gain;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AttachedSoundGainChangeMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.ObjectID;
    in >> o.DataBlock.Gain;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


PreloadSoundMessage::PreloadSoundMessage (){
    type=PreloadSoundType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const PreloadSoundMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.DataBlock.size();
    for(int i=0;i<o.DataBlock.size();i++){
         out << o.DataBlock[i].ObjectID;
         out << o.DataBlock[i].OwnerID;
         out << o.DataBlock[i].SoundID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  PreloadSoundMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.DataBlock.clear();
    lltypes::U8 countDataBlock;
    in >> countDataBlock;
    for(int i=0;i<countDataBlock;i++){
        PreloadSoundMessage::DataBlockBlock y;
        in >> y.ObjectID;
        in >> y.OwnerID;
        in >> y.SoundID;
        o.DataBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AssetUploadRequestMessage::AssetUploadRequestMessage (){
    type=AssetUploadRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AssetUploadRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AssetBlock.TransactionID;
    out << o.AssetBlock.Type;
    out << o.AssetBlock.Tempfile;
    out << o.AssetBlock.StoreLocal;
    out << o.AssetBlock.AssetData;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AssetUploadRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AssetBlock.TransactionID;
    in >> o.AssetBlock.Type;
    in >> o.AssetBlock.Tempfile;
    in >> o.AssetBlock.StoreLocal;
    in >> o.AssetBlock.AssetData;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AssetUploadCompleteMessage::AssetUploadCompleteMessage (){
    type=AssetUploadCompleteType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AssetUploadCompleteMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AssetBlock.UUID;
    out << o.AssetBlock.Type;
    out << o.AssetBlock.Success;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AssetUploadCompleteMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AssetBlock.UUID;
    in >> o.AssetBlock.Type;
    in >> o.AssetBlock.Success;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EmailMessageRequestMessage::EmailMessageRequestMessage (){
    type=EmailMessageRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EmailMessageRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.ObjectID;
    out << o.DataBlock.FromAddress;
    out << o.DataBlock.Subject;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EmailMessageRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.ObjectID;
    in >> o.DataBlock.FromAddress;
    in >> o.DataBlock.Subject;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EmailMessageReplyMessage::EmailMessageReplyMessage (){
    type=EmailMessageReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EmailMessageReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.ObjectID;
    out << o.DataBlock.More;
    out << o.DataBlock.Time;
    out << o.DataBlock.FromAddress;
    out << o.DataBlock.Subject;
    out << o.DataBlock.Data;
    out << o.DataBlock.MailFilter;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EmailMessageReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.ObjectID;
    in >> o.DataBlock.More;
    in >> o.DataBlock.Time;
    in >> o.DataBlock.FromAddress;
    in >> o.DataBlock.Subject;
    in >> o.DataBlock.Data;
    in >> o.DataBlock.MailFilter;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InternalScriptMailMessage::InternalScriptMailMessage (){
    type=InternalScriptMailType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InternalScriptMailMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.From;
    out << o.DataBlock.To;
    out << o.DataBlock.Subject;
    out << o.DataBlock.Body;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InternalScriptMailMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.From;
    in >> o.DataBlock.To;
    in >> o.DataBlock.Subject;
    in >> o.DataBlock.Body;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptDataRequestMessage::ScriptDataRequestMessage (){
    type=ScriptDataRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptDataRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.DataBlock.size();
    for(int i=0;i<o.DataBlock.size();i++){
         out << o.DataBlock[i].Hash;
         out << o.DataBlock[i].RequestType;
         out << o.DataBlock[i].Request;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptDataRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.DataBlock.clear();
    lltypes::U8 countDataBlock;
    in >> countDataBlock;
    for(int i=0;i<countDataBlock;i++){
        ScriptDataRequestMessage::DataBlockBlock y;
        in >> y.Hash;
        in >> y.RequestType;
        in >> y.Request;
        o.DataBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptDataReplyMessage::ScriptDataReplyMessage (){
    type=ScriptDataReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptDataReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.DataBlock.size();
    for(int i=0;i<o.DataBlock.size();i++){
         out << o.DataBlock[i].Hash;
         out << o.DataBlock[i].Reply;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptDataReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.DataBlock.clear();
    lltypes::U8 countDataBlock;
    in >> countDataBlock;
    for(int i=0;i<countDataBlock;i++){
        ScriptDataReplyMessage::DataBlockBlock y;
        in >> y.Hash;
        in >> y.Reply;
        o.DataBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateGroupRequestMessage::CreateGroupRequestMessage (){
    type=CreateGroupRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateGroupRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.Name;
    out << o.GroupData.Charter;
    out << o.GroupData.ShowInList;
    out << o.GroupData.InsigniaID;
    out << o.GroupData.MembershipFee;
    out << o.GroupData.OpenEnrollment;
    out << o.GroupData.AllowPublish;
    out << o.GroupData.MaturePublish;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateGroupRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.Name;
    in >> o.GroupData.Charter;
    in >> o.GroupData.ShowInList;
    in >> o.GroupData.InsigniaID;
    in >> o.GroupData.MembershipFee;
    in >> o.GroupData.OpenEnrollment;
    in >> o.GroupData.AllowPublish;
    in >> o.GroupData.MaturePublish;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateGroupReplyMessage::CreateGroupReplyMessage (){
    type=CreateGroupReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateGroupReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.ReplyData.GroupID;
    out << o.ReplyData.Success;
    out << o.ReplyData.Message;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateGroupReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.ReplyData.GroupID;
    in >> o.ReplyData.Success;
    in >> o.ReplyData.Message;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateGroupInfoMessage::UpdateGroupInfoMessage (){
    type=UpdateGroupInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateGroupInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;
    out << o.GroupData.Charter;
    out << o.GroupData.ShowInList;
    out << o.GroupData.InsigniaID;
    out << o.GroupData.MembershipFee;
    out << o.GroupData.OpenEnrollment;
    out << o.GroupData.AllowPublish;
    out << o.GroupData.MaturePublish;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateGroupInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.Charter;
    in >> o.GroupData.ShowInList;
    in >> o.GroupData.InsigniaID;
    in >> o.GroupData.MembershipFee;
    in >> o.GroupData.OpenEnrollment;
    in >> o.GroupData.AllowPublish;
    in >> o.GroupData.MaturePublish;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleChangesMessage::GroupRoleChangesMessage (){
    type=GroupRoleChangesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleChangesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.RoleChange.size();
    for(int i=0;i<o.RoleChange.size();i++){
         out << o.RoleChange[i].RoleID;
         out << o.RoleChange[i].MemberID;
         out << o.RoleChange[i].Change;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleChangesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    o.RoleChange.clear();
    lltypes::U8 countRoleChange;
    in >> countRoleChange;
    for(int i=0;i<countRoleChange;i++){
        GroupRoleChangesMessage::RoleChangeBlock y;
        in >> y.RoleID;
        in >> y.MemberID;
        in >> y.Change;
        o.RoleChange << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


JoinGroupRequestMessage::JoinGroupRequestMessage (){
    type=JoinGroupRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const JoinGroupRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  JoinGroupRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


JoinGroupReplyMessage::JoinGroupReplyMessage (){
    type=JoinGroupReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const JoinGroupReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;
    out << o.GroupData.Success;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  JoinGroupReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.Success;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EjectGroupMemberRequestMessage::EjectGroupMemberRequestMessage (){
    type=EjectGroupMemberRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EjectGroupMemberRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out << (lltypes::U8)o.EjectData.size();
    for(int i=0;i<o.EjectData.size();i++){
         out << o.EjectData[i].EjecteeID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EjectGroupMemberRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    o.EjectData.clear();
    lltypes::U8 countEjectData;
    in >> countEjectData;
    for(int i=0;i<countEjectData;i++){
        EjectGroupMemberRequestMessage::EjectDataBlock y;
        in >> y.EjecteeID;
        o.EjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


EjectGroupMemberReplyMessage::EjectGroupMemberReplyMessage (){
    type=EjectGroupMemberReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const EjectGroupMemberReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;

    out << o.EjectData.Success;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  EjectGroupMemberReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;

    in >> o.EjectData.Success;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LeaveGroupRequestMessage::LeaveGroupRequestMessage (){
    type=LeaveGroupRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LeaveGroupRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LeaveGroupRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LeaveGroupReplyMessage::LeaveGroupReplyMessage (){
    type=LeaveGroupReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LeaveGroupReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;
    out << o.GroupData.Success;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LeaveGroupReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.Success;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InviteGroupRequestMessage::InviteGroupRequestMessage (){
    type=InviteGroupRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InviteGroupRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out << (lltypes::U8)o.InviteData.size();
    for(int i=0;i<o.InviteData.size();i++){
         out << o.InviteData[i].InviteeID;
         out << o.InviteData[i].RoleID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InviteGroupRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    o.InviteData.clear();
    lltypes::U8 countInviteData;
    in >> countInviteData;
    for(int i=0;i<countInviteData;i++){
        InviteGroupRequestMessage::InviteDataBlock y;
        in >> y.InviteeID;
        in >> y.RoleID;
        o.InviteData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InviteGroupResponseMessage::InviteGroupResponseMessage (){
    type=InviteGroupResponseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InviteGroupResponseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.InviteData.AgentID;
    out << o.InviteData.InviteeID;
    out << o.InviteData.GroupID;
    out << o.InviteData.RoleID;
    out << o.InviteData.MembershipFee;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InviteGroupResponseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.InviteData.AgentID;
    in >> o.InviteData.InviteeID;
    in >> o.InviteData.GroupID;
    in >> o.InviteData.RoleID;
    in >> o.InviteData.MembershipFee;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupProfileRequestMessage::GroupProfileRequestMessage (){
    type=GroupProfileRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupProfileRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupProfileRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupProfileReplyMessage::GroupProfileReplyMessage (){
    type=GroupProfileReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupProfileReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;
    out << o.GroupData.Name;
    out << o.GroupData.Charter;
    out << o.GroupData.ShowInList;
    out << o.GroupData.MemberTitle;
    out << o.GroupData.PowersMask;
    out << o.GroupData.InsigniaID;
    out << o.GroupData.FounderID;
    out << o.GroupData.MembershipFee;
    out << o.GroupData.OpenEnrollment;
    out << o.GroupData.Money;
    out << o.GroupData.GroupMembershipCount;
    out << o.GroupData.GroupRolesCount;
    out << o.GroupData.AllowPublish;
    out << o.GroupData.MaturePublish;
    out << o.GroupData.OwnerRole;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupProfileReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.Name;
    in >> o.GroupData.Charter;
    in >> o.GroupData.ShowInList;
    in >> o.GroupData.MemberTitle;
    in >> o.GroupData.PowersMask;
    in >> o.GroupData.InsigniaID;
    in >> o.GroupData.FounderID;
    in >> o.GroupData.MembershipFee;
    in >> o.GroupData.OpenEnrollment;
    in >> o.GroupData.Money;
    in >> o.GroupData.GroupMembershipCount;
    in >> o.GroupData.GroupRolesCount;
    in >> o.GroupData.AllowPublish;
    in >> o.GroupData.MaturePublish;
    in >> o.GroupData.OwnerRole;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountSummaryRequestMessage::GroupAccountSummaryRequestMessage (){
    type=GroupAccountSummaryRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountSummaryRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountSummaryRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountSummaryReplyMessage::GroupAccountSummaryReplyMessage (){
    type=GroupAccountSummaryReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountSummaryReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;
    out << o.MoneyData.StartDate;
    out << o.MoneyData.Balance;
    out << o.MoneyData.TotalCredits;
    out << o.MoneyData.TotalDebits;
    out << o.MoneyData.ObjectTaxCurrent;
    out << o.MoneyData.LightTaxCurrent;
    out << o.MoneyData.LandTaxCurrent;
    out << o.MoneyData.GroupTaxCurrent;
    out << o.MoneyData.ParcelDirFeeCurrent;
    out << o.MoneyData.ObjectTaxEstimate;
    out << o.MoneyData.LightTaxEstimate;
    out << o.MoneyData.LandTaxEstimate;
    out << o.MoneyData.GroupTaxEstimate;
    out << o.MoneyData.ParcelDirFeeEstimate;
    out << o.MoneyData.NonExemptMembers;
    out << o.MoneyData.LastTaxDate;
    out << o.MoneyData.TaxDate;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountSummaryReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;
    in >> o.MoneyData.StartDate;
    in >> o.MoneyData.Balance;
    in >> o.MoneyData.TotalCredits;
    in >> o.MoneyData.TotalDebits;
    in >> o.MoneyData.ObjectTaxCurrent;
    in >> o.MoneyData.LightTaxCurrent;
    in >> o.MoneyData.LandTaxCurrent;
    in >> o.MoneyData.GroupTaxCurrent;
    in >> o.MoneyData.ParcelDirFeeCurrent;
    in >> o.MoneyData.ObjectTaxEstimate;
    in >> o.MoneyData.LightTaxEstimate;
    in >> o.MoneyData.LandTaxEstimate;
    in >> o.MoneyData.GroupTaxEstimate;
    in >> o.MoneyData.ParcelDirFeeEstimate;
    in >> o.MoneyData.NonExemptMembers;
    in >> o.MoneyData.LastTaxDate;
    in >> o.MoneyData.TaxDate;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountDetailsRequestMessage::GroupAccountDetailsRequestMessage (){
    type=GroupAccountDetailsRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountDetailsRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountDetailsRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountDetailsReplyMessage::GroupAccountDetailsReplyMessage (){
    type=GroupAccountDetailsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountDetailsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;
    out << o.MoneyData.StartDate;

    out << (lltypes::U8)o.HistoryData.size();
    for(int i=0;i<o.HistoryData.size();i++){
         out << o.HistoryData[i].Description;
         out << o.HistoryData[i].Amount;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountDetailsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;
    in >> o.MoneyData.StartDate;

    o.HistoryData.clear();
    lltypes::U8 countHistoryData;
    in >> countHistoryData;
    for(int i=0;i<countHistoryData;i++){
        GroupAccountDetailsReplyMessage::HistoryDataBlock y;
        in >> y.Description;
        in >> y.Amount;
        o.HistoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountTransactionsRequestMessage::GroupAccountTransactionsRequestMessage (){
    type=GroupAccountTransactionsRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountTransactionsRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountTransactionsRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupAccountTransactionsReplyMessage::GroupAccountTransactionsReplyMessage (){
    type=GroupAccountTransactionsReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupAccountTransactionsReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << o.MoneyData.RequestID;
    out << o.MoneyData.IntervalDays;
    out << o.MoneyData.CurrentInterval;
    out << o.MoneyData.StartDate;

    out << (lltypes::U8)o.HistoryData.size();
    for(int i=0;i<o.HistoryData.size();i++){
         out << o.HistoryData[i].Time;
         out << o.HistoryData[i].User;
         out << o.HistoryData[i].Type;
         out << o.HistoryData[i].Item;
         out << o.HistoryData[i].Amount;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupAccountTransactionsReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in >> o.MoneyData.RequestID;
    in >> o.MoneyData.IntervalDays;
    in >> o.MoneyData.CurrentInterval;
    in >> o.MoneyData.StartDate;

    o.HistoryData.clear();
    lltypes::U8 countHistoryData;
    in >> countHistoryData;
    for(int i=0;i<countHistoryData;i++){
        GroupAccountTransactionsReplyMessage::HistoryDataBlock y;
        in >> y.Time;
        in >> y.User;
        in >> y.Type;
        in >> y.Item;
        in >> y.Amount;
        o.HistoryData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupActiveProposalsRequestMessage::GroupActiveProposalsRequestMessage (){
    type=GroupActiveProposalsRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupActiveProposalsRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out << o.TransactionData.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupActiveProposalsRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    in >> o.TransactionData.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupActiveProposalItemReplyMessage::GroupActiveProposalItemReplyMessage (){
    type=GroupActiveProposalItemReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupActiveProposalItemReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << o.TransactionData.TransactionID;
    out << o.TransactionData.TotalNumItems;

    out << (lltypes::U8)o.ProposalData.size();
    for(int i=0;i<o.ProposalData.size();i++){
         out << o.ProposalData[i].VoteID;
         out << o.ProposalData[i].VoteInitiator;
         out << o.ProposalData[i].TerseDateID;
         out << o.ProposalData[i].StartDateTime;
         out << o.ProposalData[i].EndDateTime;
         out << o.ProposalData[i].AlreadyVoted;
         out << o.ProposalData[i].VoteCast;
         out << o.ProposalData[i].Majority;
         out << o.ProposalData[i].Quorum;
         out << o.ProposalData[i].ProposalText;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupActiveProposalItemReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in >> o.TransactionData.TransactionID;
    in >> o.TransactionData.TotalNumItems;

    o.ProposalData.clear();
    lltypes::U8 countProposalData;
    in >> countProposalData;
    for(int i=0;i<countProposalData;i++){
        GroupActiveProposalItemReplyMessage::ProposalDataBlock y;
        in >> y.VoteID;
        in >> y.VoteInitiator;
        in >> y.TerseDateID;
        in >> y.StartDateTime;
        in >> y.EndDateTime;
        in >> y.AlreadyVoted;
        in >> y.VoteCast;
        in >> y.Majority;
        in >> y.Quorum;
        in >> y.ProposalText;
        o.ProposalData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupVoteHistoryRequestMessage::GroupVoteHistoryRequestMessage (){
    type=GroupVoteHistoryRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupVoteHistoryRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;

    out << o.TransactionData.TransactionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupVoteHistoryRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;

    in >> o.TransactionData.TransactionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupVoteHistoryItemReplyMessage::GroupVoteHistoryItemReplyMessage (){
    type=GroupVoteHistoryItemReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupVoteHistoryItemReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out << o.TransactionData.TransactionID;
    out << o.TransactionData.TotalNumItems;

    out << o.HistoryItemData.VoteID;
    out << o.HistoryItemData.TerseDateID;
    out << o.HistoryItemData.StartDateTime;
    out << o.HistoryItemData.EndDateTime;
    out << o.HistoryItemData.VoteInitiator;
    out << o.HistoryItemData.VoteType;
    out << o.HistoryItemData.VoteResult;
    out << o.HistoryItemData.Majority;
    out << o.HistoryItemData.Quorum;
    out << o.HistoryItemData.ProposalText;

    out << (lltypes::U8)o.VoteItem.size();
    for(int i=0;i<o.VoteItem.size();i++){
         out << o.VoteItem[i].CandidateID;
         out << o.VoteItem[i].VoteCast;
         out << o.VoteItem[i].NumVotes;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupVoteHistoryItemReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in >> o.TransactionData.TransactionID;
    in >> o.TransactionData.TotalNumItems;

    in >> o.HistoryItemData.VoteID;
    in >> o.HistoryItemData.TerseDateID;
    in >> o.HistoryItemData.StartDateTime;
    in >> o.HistoryItemData.EndDateTime;
    in >> o.HistoryItemData.VoteInitiator;
    in >> o.HistoryItemData.VoteType;
    in >> o.HistoryItemData.VoteResult;
    in >> o.HistoryItemData.Majority;
    in >> o.HistoryItemData.Quorum;
    in >> o.HistoryItemData.ProposalText;

    o.VoteItem.clear();
    lltypes::U8 countVoteItem;
    in >> countVoteItem;
    for(int i=0;i<countVoteItem;i++){
        GroupVoteHistoryItemReplyMessage::VoteItemBlock y;
        in >> y.CandidateID;
        in >> y.VoteCast;
        in >> y.NumVotes;
        o.VoteItem << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


StartGroupProposalMessage::StartGroupProposalMessage (){
    type=StartGroupProposalType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const StartGroupProposalMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ProposalData.GroupID;
    out << o.ProposalData.Quorum;
    out << o.ProposalData.Majority;
    out << o.ProposalData.Duration;
    out << o.ProposalData.ProposalText;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  StartGroupProposalMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ProposalData.GroupID;
    in >> o.ProposalData.Quorum;
    in >> o.ProposalData.Majority;
    in >> o.ProposalData.Duration;
    in >> o.ProposalData.ProposalText;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupProposalBallotMessage::GroupProposalBallotMessage (){
    type=GroupProposalBallotType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupProposalBallotMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ProposalData.ProposalID;
    out << o.ProposalData.GroupID;
    out << o.ProposalData.VoteCast;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupProposalBallotMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ProposalData.ProposalID;
    in >> o.ProposalData.GroupID;
    in >> o.ProposalData.VoteCast;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


TallyVotesMessage::TallyVotesMessage (){
    type=TallyVotesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const TallyVotesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  TallyVotesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupMembersRequestMessage::GroupMembersRequestMessage (){
    type=GroupMembersRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupMembersRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;
    out << o.GroupData.RequestID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupMembersRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.RequestID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupMembersReplyMessage::GroupMembersReplyMessage (){
    type=GroupMembersReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupMembersReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;
    out << o.GroupData.RequestID;
    out << o.GroupData.MemberCount;

    out << (lltypes::U8)o.MemberData.size();
    for(int i=0;i<o.MemberData.size();i++){
         out << o.MemberData[i].AgentID;
         out << o.MemberData[i].Contribution;
         out << o.MemberData[i].OnlineStatus;
         out << o.MemberData[i].AgentPowers;
         out << o.MemberData[i].Title;
         out << o.MemberData[i].IsOwner;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupMembersReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.RequestID;
    in >> o.GroupData.MemberCount;

    o.MemberData.clear();
    lltypes::U8 countMemberData;
    in >> countMemberData;
    for(int i=0;i<countMemberData;i++){
        GroupMembersReplyMessage::MemberDataBlock y;
        in >> y.AgentID;
        in >> y.Contribution;
        in >> y.OnlineStatus;
        in >> y.AgentPowers;
        in >> y.Title;
        in >> y.IsOwner;
        o.MemberData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ActivateGroupMessage::ActivateGroupMessage (){
    type=ActivateGroupType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ActivateGroupMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ActivateGroupMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetGroupContributionMessage::SetGroupContributionMessage (){
    type=SetGroupContributionType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetGroupContributionMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;
    out << o.Data.Contribution;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetGroupContributionMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;
    in >> o.Data.Contribution;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SetGroupAcceptNoticesMessage::SetGroupAcceptNoticesMessage (){
    type=SetGroupAcceptNoticesType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SetGroupAcceptNoticesMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.Data.GroupID;
    out << o.Data.AcceptNotices;

    out << o.NewData.ListInProfile;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SetGroupAcceptNoticesMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.Data.GroupID;
    in >> o.Data.AcceptNotices;

    in >> o.NewData.ListInProfile;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleDataRequestMessage::GroupRoleDataRequestMessage (){
    type=GroupRoleDataRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleDataRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;
    out << o.GroupData.RequestID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleDataRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.RequestID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleDataReplyMessage::GroupRoleDataReplyMessage (){
    type=GroupRoleDataReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleDataReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.GroupData.GroupID;
    out << o.GroupData.RequestID;
    out << o.GroupData.RoleCount;

    out << (lltypes::U8)o.RoleData.size();
    for(int i=0;i<o.RoleData.size();i++){
         out << o.RoleData[i].RoleID;
         out << o.RoleData[i].Name;
         out << o.RoleData[i].Title;
         out << o.RoleData[i].Description;
         out << o.RoleData[i].Powers;
         out << o.RoleData[i].Members;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleDataReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.RequestID;
    in >> o.GroupData.RoleCount;

    o.RoleData.clear();
    lltypes::U8 countRoleData;
    in >> countRoleData;
    for(int i=0;i<countRoleData;i++){
        GroupRoleDataReplyMessage::RoleDataBlock y;
        in >> y.RoleID;
        in >> y.Name;
        in >> y.Title;
        in >> y.Description;
        in >> y.Powers;
        in >> y.Members;
        o.RoleData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleMembersRequestMessage::GroupRoleMembersRequestMessage (){
    type=GroupRoleMembersRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleMembersRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.GroupData.GroupID;
    out << o.GroupData.RequestID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleMembersRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.GroupData.GroupID;
    in >> o.GroupData.RequestID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleMembersReplyMessage::GroupRoleMembersReplyMessage (){
    type=GroupRoleMembersReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleMembersReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;
    out << o.AgentData.RequestID;
    out << o.AgentData.TotalPairs;

    out << (lltypes::U8)o.MemberData.size();
    for(int i=0;i<o.MemberData.size();i++){
         out << o.MemberData[i].RoleID;
         out << o.MemberData[i].MemberID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleMembersReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.RequestID;
    in >> o.AgentData.TotalPairs;

    o.MemberData.clear();
    lltypes::U8 countMemberData;
    in >> countMemberData;
    for(int i=0;i<countMemberData;i++){
        GroupRoleMembersReplyMessage::MemberDataBlock y;
        in >> y.RoleID;
        in >> y.MemberID;
        o.MemberData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupTitlesRequestMessage::GroupTitlesRequestMessage (){
    type=GroupTitlesRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupTitlesRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;
    out << o.AgentData.RequestID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupTitlesRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.RequestID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupTitlesReplyMessage::GroupTitlesReplyMessage (){
    type=GroupTitlesReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupTitlesReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;
    out << o.AgentData.RequestID;

    out << (lltypes::U8)o.GroupData.size();
    for(int i=0;i<o.GroupData.size();i++){
         out << o.GroupData[i].Title;
         out << o.GroupData[i].RoleID;
         out << o.GroupData[i].Selected;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupTitlesReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.RequestID;

    o.GroupData.clear();
    lltypes::U8 countGroupData;
    in >> countGroupData;
    for(int i=0;i<countGroupData;i++){
        GroupTitlesReplyMessage::GroupDataBlock y;
        in >> y.Title;
        in >> y.RoleID;
        in >> y.Selected;
        o.GroupData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupTitleUpdateMessage::GroupTitleUpdateMessage (){
    type=GroupTitleUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupTitleUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;
    out << o.AgentData.TitleRoleID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupTitleUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;
    in >> o.AgentData.TitleRoleID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupRoleUpdateMessage::GroupRoleUpdateMessage (){
    type=GroupRoleUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupRoleUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.GroupID;

    out << (lltypes::U8)o.RoleData.size();
    for(int i=0;i<o.RoleData.size();i++){
         out << o.RoleData[i].RoleID;
         out << o.RoleData[i].Name;
         out << o.RoleData[i].Description;
         out << o.RoleData[i].Title;
         out << o.RoleData[i].Powers;
         out << o.RoleData[i].UpdateType;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupRoleUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.GroupID;

    o.RoleData.clear();
    lltypes::U8 countRoleData;
    in >> countRoleData;
    for(int i=0;i<countRoleData;i++){
        GroupRoleUpdateMessage::RoleDataBlock y;
        in >> y.RoleID;
        in >> y.Name;
        in >> y.Description;
        in >> y.Title;
        in >> y.Powers;
        in >> y.UpdateType;
        o.RoleData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LiveHelpGroupRequestMessage::LiveHelpGroupRequestMessage (){
    type=LiveHelpGroupRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LiveHelpGroupRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RequestData.RequestID;
    out << o.RequestData.AgentID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LiveHelpGroupRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RequestData.RequestID;
    in >> o.RequestData.AgentID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LiveHelpGroupReplyMessage::LiveHelpGroupReplyMessage (){
    type=LiveHelpGroupReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LiveHelpGroupReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ReplyData.RequestID;
    out << o.ReplyData.GroupID;
    out << o.ReplyData.Selection;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LiveHelpGroupReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ReplyData.RequestID;
    in >> o.ReplyData.GroupID;
    in >> o.ReplyData.Selection;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentWearablesRequestMessage::AgentWearablesRequestMessage (){
    type=AgentWearablesRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentWearablesRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentWearablesRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentWearablesUpdateMessage::AgentWearablesUpdateMessage (){
    type=AgentWearablesUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentWearablesUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].ItemID;
         out << o.WearableData[i].AssetID;
         out << o.WearableData[i].WearableType;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentWearablesUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AgentWearablesUpdateMessage::WearableDataBlock y;
        in >> y.ItemID;
        in >> y.AssetID;
        in >> y.WearableType;
        o.WearableData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentIsNowWearingMessage::AgentIsNowWearingMessage (){
    type=AgentIsNowWearingType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentIsNowWearingMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].ItemID;
         out << o.WearableData[i].WearableType;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentIsNowWearingMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AgentIsNowWearingMessage::WearableDataBlock y;
        in >> y.ItemID;
        in >> y.WearableType;
        o.WearableData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentCachedTextureMessage::AgentCachedTextureMessage (){
    type=AgentCachedTextureType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentCachedTextureMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].ID;
         out << o.WearableData[i].TextureIndex;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentCachedTextureMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AgentCachedTextureMessage::WearableDataBlock y;
        in >> y.ID;
        in >> y.TextureIndex;
        o.WearableData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentCachedTextureResponseMessage::AgentCachedTextureResponseMessage (){
    type=AgentCachedTextureResponseType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentCachedTextureResponseMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.SerialNum;

    out << (lltypes::U8)o.WearableData.size();
    for(int i=0;i<o.WearableData.size();i++){
         out << o.WearableData[i].TextureID;
         out << o.WearableData[i].TextureIndex;
         out << o.WearableData[i].HostName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentCachedTextureResponseMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.SerialNum;

    o.WearableData.clear();
    lltypes::U8 countWearableData;
    in >> countWearableData;
    for(int i=0;i<countWearableData;i++){
        AgentCachedTextureResponseMessage::WearableDataBlock y;
        in >> y.TextureID;
        in >> y.TextureIndex;
        in >> y.HostName;
        o.WearableData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentDataUpdateRequestMessage::AgentDataUpdateRequestMessage (){
    type=AgentDataUpdateRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentDataUpdateRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentDataUpdateRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentDataUpdateMessage::AgentDataUpdateMessage (){
    type=AgentDataUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentDataUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.FirstName;
    out << o.AgentData.LastName;
    out << o.AgentData.GroupTitle;
    out << o.AgentData.ActiveGroupID;
    out << o.AgentData.GroupPowers;
    out << o.AgentData.GroupName;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentDataUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.FirstName;
    in >> o.AgentData.LastName;
    in >> o.AgentData.GroupTitle;
    in >> o.AgentData.ActiveGroupID;
    in >> o.AgentData.GroupPowers;
    in >> o.AgentData.GroupName;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


GroupDataUpdateMessage::GroupDataUpdateMessage (){
    type=GroupDataUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const GroupDataUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.AgentGroupData.size();
    for(int i=0;i<o.AgentGroupData.size();i++){
         out << o.AgentGroupData[i].AgentID;
         out << o.AgentGroupData[i].GroupID;
         out << o.AgentGroupData[i].AgentPowers;
         out << o.AgentGroupData[i].GroupTitle;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  GroupDataUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.AgentGroupData.clear();
    lltypes::U8 countAgentGroupData;
    in >> countAgentGroupData;
    for(int i=0;i<countAgentGroupData;i++){
        GroupDataUpdateMessage::AgentGroupDataBlock y;
        in >> y.AgentID;
        in >> y.GroupID;
        in >> y.AgentPowers;
        in >> y.GroupTitle;
        o.AgentGroupData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentGroupDataUpdateMessage::AgentGroupDataUpdateMessage (){
    type=AgentGroupDataUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentGroupDataUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << (lltypes::U8)o.GroupData.size();
    for(int i=0;i<o.GroupData.size();i++){
         out << o.GroupData[i].GroupID;
         out << o.GroupData[i].GroupPowers;
         out << o.GroupData[i].AcceptNotices;
         out << o.GroupData[i].GroupInsigniaID;
         out << o.GroupData[i].Contribution;
         out << o.GroupData[i].GroupName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentGroupDataUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    o.GroupData.clear();
    lltypes::U8 countGroupData;
    in >> countGroupData;
    for(int i=0;i<countGroupData;i++){
        AgentGroupDataUpdateMessage::GroupDataBlock y;
        in >> y.GroupID;
        in >> y.GroupPowers;
        in >> y.AcceptNotices;
        in >> y.GroupInsigniaID;
        in >> y.Contribution;
        in >> y.GroupName;
        o.GroupData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


AgentDropGroupMessage::AgentDropGroupMessage (){
    type=AgentDropGroupType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const AgentDropGroupMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.GroupID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  AgentDropGroupMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.GroupID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LogTextMessageMessage::LogTextMessageMessage (){
    type=LogTextMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LogTextMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.DataBlock.size();
    for(int i=0;i<o.DataBlock.size();i++){
         out << o.DataBlock[i].FromAgentId;
         out << o.DataBlock[i].ToAgentId;
         out << o.DataBlock[i].GlobalX;
         out << o.DataBlock[i].GlobalY;
         out << o.DataBlock[i].Time;
         out << o.DataBlock[i].Message;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LogTextMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.DataBlock.clear();
    lltypes::U8 countDataBlock;
    in >> countDataBlock;
    for(int i=0;i<countDataBlock;i++){
        LogTextMessageMessage::DataBlockBlock y;
        in >> y.FromAgentId;
        in >> y.ToAgentId;
        in >> y.GlobalX;
        in >> y.GlobalY;
        in >> y.Time;
        in >> y.Message;
        o.DataBlock << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ViewerEffectMessage::ViewerEffectMessage (){
    type=ViewerEffectType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ViewerEffectMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.Effect.size();
    for(int i=0;i<o.Effect.size();i++){
         out << o.Effect[i].ID;
         out << o.Effect[i].AgentID;
         out << o.Effect[i].Type;
         out << o.Effect[i].Duration;
         out << o.Effect[i].Color;
         out << o.Effect[i].TypeData;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ViewerEffectMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.Effect.clear();
    lltypes::U8 countEffect;
    in >> countEffect;
    for(int i=0;i<countEffect;i++){
        ViewerEffectMessage::EffectBlock y;
        in >> y.ID;
        in >> y.AgentID;
        in >> y.Type;
        in >> y.Duration;
        in >> y.Color;
        in >> y.TypeData;
        o.Effect << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateTrustedCircuitMessage::CreateTrustedCircuitMessage (){
    type=CreateTrustedCircuitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateTrustedCircuitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.EndPointID;
    out << o.DataBlock.Digest;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateTrustedCircuitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.EndPointID;
    in >> o.DataBlock.Digest;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DenyTrustedCircuitMessage::DenyTrustedCircuitMessage (){
    type=DenyTrustedCircuitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DenyTrustedCircuitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.EndPointID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DenyTrustedCircuitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.EndPointID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RequestTrustedCircuitMessage::RequestTrustedCircuitMessage (){
    type=RequestTrustedCircuitType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RequestTrustedCircuitMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RequestTrustedCircuitMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezSingleAttachmentFromInvMessage::RezSingleAttachmentFromInvMessage (){
    type=RezSingleAttachmentFromInvType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezSingleAttachmentFromInvMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.ObjectData.ItemID;
    out << o.ObjectData.OwnerID;
    out << o.ObjectData.AttachmentPt;
    out << o.ObjectData.ItemFlags;
    out << o.ObjectData.GroupMask;
    out << o.ObjectData.EveryoneMask;
    out << o.ObjectData.NextOwnerMask;
    out << o.ObjectData.Name;
    out << o.ObjectData.Description;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezSingleAttachmentFromInvMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.ObjectData.ItemID;
    in >> o.ObjectData.OwnerID;
    in >> o.ObjectData.AttachmentPt;
    in >> o.ObjectData.ItemFlags;
    in >> o.ObjectData.GroupMask;
    in >> o.ObjectData.EveryoneMask;
    in >> o.ObjectData.NextOwnerMask;
    in >> o.ObjectData.Name;
    in >> o.ObjectData.Description;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezMultipleAttachmentsFromInvMessage::RezMultipleAttachmentsFromInvMessage (){
    type=RezMultipleAttachmentsFromInvType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezMultipleAttachmentsFromInvMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.HeaderData.CompoundMsgID;
    out << o.HeaderData.TotalObjects;
    out << o.HeaderData.FirstDetachAll;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ItemID;
         out << o.ObjectData[i].OwnerID;
         out << o.ObjectData[i].AttachmentPt;
         out << o.ObjectData[i].ItemFlags;
         out << o.ObjectData[i].GroupMask;
         out << o.ObjectData[i].EveryoneMask;
         out << o.ObjectData[i].NextOwnerMask;
         out << o.ObjectData[i].Name;
         out << o.ObjectData[i].Description;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezMultipleAttachmentsFromInvMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.HeaderData.CompoundMsgID;
    in >> o.HeaderData.TotalObjects;
    in >> o.HeaderData.FirstDetachAll;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        RezMultipleAttachmentsFromInvMessage::ObjectDataBlock y;
        in >> y.ItemID;
        in >> y.OwnerID;
        in >> y.AttachmentPt;
        in >> y.ItemFlags;
        in >> y.GroupMask;
        in >> y.EveryoneMask;
        in >> y.NextOwnerMask;
        in >> y.Name;
        in >> y.Description;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


DetachAttachmentIntoInvMessage::DetachAttachmentIntoInvMessage (){
    type=DetachAttachmentIntoInvType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const DetachAttachmentIntoInvMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.ObjectData.AgentID;
    out << o.ObjectData.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  DetachAttachmentIntoInvMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.ObjectData.AgentID;
    in >> o.ObjectData.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


CreateNewOutfitAttachmentsMessage::CreateNewOutfitAttachmentsMessage (){
    type=CreateNewOutfitAttachmentsType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const CreateNewOutfitAttachmentsMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.HeaderData.NewFolderID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].OldItemID;
         out << o.ObjectData[i].OldFolderID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  CreateNewOutfitAttachmentsMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.HeaderData.NewFolderID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        CreateNewOutfitAttachmentsMessage::ObjectDataBlock y;
        in >> y.OldItemID;
        in >> y.OldFolderID;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UserInfoRequestMessage::UserInfoRequestMessage (){
    type=UserInfoRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UserInfoRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UserInfoRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UserInfoReplyMessage::UserInfoReplyMessage (){
    type=UserInfoReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UserInfoReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.UserData.IMViaEMail;
    out << o.UserData.DirectoryVisibility;
    out << o.UserData.EMail;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UserInfoReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.UserData.IMViaEMail;
    in >> o.UserData.DirectoryVisibility;
    in >> o.UserData.EMail;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UpdateUserInfoMessage::UpdateUserInfoMessage (){
    type=UpdateUserInfoType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const UpdateUserInfoMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.UserData.IMViaEMail;
    out << o.UserData.DirectoryVisibility;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  UpdateUserInfoMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.UserData.IMViaEMail;
    in >> o.UserData.DirectoryVisibility;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelRenameMessage::ParcelRenameMessage (){
    type=ParcelRenameType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelRenameMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << (lltypes::U8)o.ParcelData.size();
    for(int i=0;i<o.ParcelData.size();i++){
         out << o.ParcelData[i].ParcelID;
         out << o.ParcelData[i].NewName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelRenameMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    o.ParcelData.clear();
    lltypes::U8 countParcelData;
    in >> countParcelData;
    for(int i=0;i<countParcelData;i++){
        ParcelRenameMessage::ParcelDataBlock y;
        in >> y.ParcelID;
        in >> y.NewName;
        o.ParcelData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


InitiateDownloadMessage::InitiateDownloadMessage (){
    type=InitiateDownloadType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const InitiateDownloadMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.FileData.SimFilename;
    out << o.FileData.ViewerFilename;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  InitiateDownloadMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.FileData.SimFilename;
    in >> o.FileData.ViewerFilename;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SystemMessageMessage::SystemMessageMessage (){
    type=SystemMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SystemMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.MethodData.Method;
    out << o.MethodData.Invoice;
    out << o.MethodData.Digest;

    out << (lltypes::U8)o.ParamList.size();
    for(int i=0;i<o.ParamList.size();i++){
         out << o.ParamList[i].Parameter;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SystemMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.MethodData.Method;
    in >> o.MethodData.Invoice;
    in >> o.MethodData.Digest;

    o.ParamList.clear();
    lltypes::U8 countParamList;
    in >> countParamList;
    for(int i=0;i<countParamList;i++){
        SystemMessageMessage::ParamListBlock y;
        in >> y.Parameter;
        o.ParamList << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapLayerRequestMessage::MapLayerRequestMessage (){
    type=MapLayerRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapLayerRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;
    out << o.AgentData.EstateID;
    out << o.AgentData.Godlike;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapLayerRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;
    in >> o.AgentData.EstateID;
    in >> o.AgentData.Godlike;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapLayerReplyMessage::MapLayerReplyMessage (){
    type=MapLayerReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapLayerReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.Flags;

    out << (lltypes::U8)o.LayerData.size();
    for(int i=0;i<o.LayerData.size();i++){
         out << o.LayerData[i].Left;
         out << o.LayerData[i].Right;
         out << o.LayerData[i].Top;
         out << o.LayerData[i].Bottom;
         out << o.LayerData[i].ImageID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapLayerReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.Flags;

    o.LayerData.clear();
    lltypes::U8 countLayerData;
    in >> countLayerData;
    for(int i=0;i<countLayerData;i++){
        MapLayerReplyMessage::LayerDataBlock y;
        in >> y.Left;
        in >> y.Right;
        in >> y.Top;
        in >> y.Bottom;
        in >> y.ImageID;
        o.LayerData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapBlockRequestMessage::MapBlockRequestMessage (){
    type=MapBlockRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapBlockRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;
    out << o.AgentData.EstateID;
    out << o.AgentData.Godlike;

    out << o.PositionData.MinX;
    out << o.PositionData.MaxX;
    out << o.PositionData.MinY;
    out << o.PositionData.MaxY;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapBlockRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;
    in >> o.AgentData.EstateID;
    in >> o.AgentData.Godlike;

    in >> o.PositionData.MinX;
    in >> o.PositionData.MaxX;
    in >> o.PositionData.MinY;
    in >> o.PositionData.MaxY;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapNameRequestMessage::MapNameRequestMessage (){
    type=MapNameRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapNameRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;
    out << o.AgentData.EstateID;
    out << o.AgentData.Godlike;

    out << o.NameData.Name;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapNameRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;
    in >> o.AgentData.EstateID;
    in >> o.AgentData.Godlike;

    in >> o.NameData.Name;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapBlockReplyMessage::MapBlockReplyMessage (){
    type=MapBlockReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapBlockReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.Flags;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].X;
         out << o.Data[i].Y;
         out << o.Data[i].Name;
         out << o.Data[i].Access;
         out << o.Data[i].RegionFlags;
         out << o.Data[i].WaterHeight;
         out << o.Data[i].Agents;
         out << o.Data[i].MapImageID;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapBlockReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.Flags;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        MapBlockReplyMessage::DataBlock y;
        in >> y.X;
        in >> y.Y;
        in >> y.Name;
        in >> y.Access;
        in >> y.RegionFlags;
        in >> y.WaterHeight;
        in >> y.Agents;
        in >> y.MapImageID;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapItemRequestMessage::MapItemRequestMessage (){
    type=MapItemRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapItemRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.Flags;
    out << o.AgentData.EstateID;
    out << o.AgentData.Godlike;

    out << o.RequestData.ItemType;
    out << o.RequestData.RegionHandle;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapItemRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.Flags;
    in >> o.AgentData.EstateID;
    in >> o.AgentData.Godlike;

    in >> o.RequestData.ItemType;
    in >> o.RequestData.RegionHandle;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


MapItemReplyMessage::MapItemReplyMessage (){
    type=MapItemReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const MapItemReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.Flags;

    out << o.RequestData.ItemType;

    out << (lltypes::U8)o.Data.size();
    for(int i=0;i<o.Data.size();i++){
         out << o.Data[i].X;
         out << o.Data[i].Y;
         out << o.Data[i].ID;
         out << o.Data[i].Extra;
         out << o.Data[i].Extra2;
         out << o.Data[i].Name;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  MapItemReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.Flags;

    in >> o.RequestData.ItemType;

    o.Data.clear();
    lltypes::U8 countData;
    in >> countData;
    for(int i=0;i<countData;i++){
        MapItemReplyMessage::DataBlock y;
        in >> y.X;
        in >> y.Y;
        in >> y.ID;
        in >> y.Extra;
        in >> y.Extra2;
        in >> y.Name;
        o.Data << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


SendPostcardMessage::SendPostcardMessage (){
    type=SendPostcardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const SendPostcardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;
    out << o.AgentData.AssetID;
    out << o.AgentData.PosGlobal;
    out << o.AgentData.To;
    out << o.AgentData.From;
    out << o.AgentData.Name;
    out << o.AgentData.Subject;
    out << o.AgentData.Msg;
    out << o.AgentData.AllowPublish;
    out << o.AgentData.MaturePublish;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  SendPostcardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;
    in >> o.AgentData.AssetID;
    in >> o.AgentData.PosGlobal;
    in >> o.AgentData.To;
    in >> o.AgentData.From;
    in >> o.AgentData.Name;
    in >> o.AgentData.Subject;
    in >> o.AgentData.Msg;
    in >> o.AgentData.AllowPublish;
    in >> o.AgentData.MaturePublish;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RpcChannelRequestMessage::RpcChannelRequestMessage (){
    type=RpcChannelRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RpcChannelRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.GridX;
    out << o.DataBlock.GridY;
    out << o.DataBlock.TaskID;
    out << o.DataBlock.ItemID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RpcChannelRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.GridX;
    in >> o.DataBlock.GridY;
    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.ItemID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RpcChannelReplyMessage::RpcChannelReplyMessage (){
    type=RpcChannelReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RpcChannelReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.TaskID;
    out << o.DataBlock.ItemID;
    out << o.DataBlock.ChannelID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RpcChannelReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.ItemID;
    in >> o.DataBlock.ChannelID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RpcScriptRequestInboundMessage::RpcScriptRequestInboundMessage (){
    type=RpcScriptRequestInboundType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RpcScriptRequestInboundMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.TargetBlock.GridX;
    out << o.TargetBlock.GridY;

    out << o.DataBlock.TaskID;
    out << o.DataBlock.ItemID;
    out << o.DataBlock.ChannelID;
    out << o.DataBlock.IntValue;
    out << o.DataBlock.StringValue;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RpcScriptRequestInboundMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.TargetBlock.GridX;
    in >> o.TargetBlock.GridY;

    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.ItemID;
    in >> o.DataBlock.ChannelID;
    in >> o.DataBlock.IntValue;
    in >> o.DataBlock.StringValue;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RpcScriptRequestInboundForwardMessage::RpcScriptRequestInboundForwardMessage (){
    type=RpcScriptRequestInboundForwardType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RpcScriptRequestInboundForwardMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.RPCServerIP;
    out << o.DataBlock.RPCServerPort;
    out << o.DataBlock.TaskID;
    out << o.DataBlock.ItemID;
    out << o.DataBlock.ChannelID;
    out << o.DataBlock.IntValue;
    out << o.DataBlock.StringValue;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RpcScriptRequestInboundForwardMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.RPCServerIP;
    in >> o.DataBlock.RPCServerPort;
    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.ItemID;
    in >> o.DataBlock.ChannelID;
    in >> o.DataBlock.IntValue;
    in >> o.DataBlock.StringValue;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RpcScriptReplyInboundMessage::RpcScriptReplyInboundMessage (){
    type=RpcScriptReplyInboundType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RpcScriptReplyInboundMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.TaskID;
    out << o.DataBlock.ItemID;
    out << o.DataBlock.ChannelID;
    out << o.DataBlock.IntValue;
    out << o.DataBlock.StringValue;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RpcScriptReplyInboundMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.ItemID;
    in >> o.DataBlock.ChannelID;
    in >> o.DataBlock.IntValue;
    in >> o.DataBlock.StringValue;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ScriptMailRegistrationMessage::ScriptMailRegistrationMessage (){
    type=ScriptMailRegistrationType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ScriptMailRegistrationMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.TargetIP;
    out << o.DataBlock.TargetPort;
    out << o.DataBlock.TaskID;
    out << o.DataBlock.Flags;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ScriptMailRegistrationMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.TargetIP;
    in >> o.DataBlock.TargetPort;
    in >> o.DataBlock.TaskID;
    in >> o.DataBlock.Flags;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelMediaCommandMessageMessage::ParcelMediaCommandMessageMessage (){
    type=ParcelMediaCommandMessageType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelMediaCommandMessageMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.CommandBlock.Flags;
    out << o.CommandBlock.Command;
    out << o.CommandBlock.Time;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelMediaCommandMessageMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.CommandBlock.Flags;
    in >> o.CommandBlock.Command;
    in >> o.CommandBlock.Time;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ParcelMediaUpdateMessage::ParcelMediaUpdateMessage (){
    type=ParcelMediaUpdateType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ParcelMediaUpdateMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.DataBlock.MediaURL;
    out << o.DataBlock.MediaID;
    out << o.DataBlock.MediaAutoScale;

    out << o.DataBlockExtended.MediaType;
    out << o.DataBlockExtended.MediaDesc;
    out << o.DataBlockExtended.MediaWidth;
    out << o.DataBlockExtended.MediaHeight;
    out << o.DataBlockExtended.MediaLoop;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ParcelMediaUpdateMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.DataBlock.MediaURL;
    in >> o.DataBlock.MediaID;
    in >> o.DataBlock.MediaAutoScale;

    in >> o.DataBlockExtended.MediaType;
    in >> o.DataBlockExtended.MediaDesc;
    in >> o.DataBlockExtended.MediaWidth;
    in >> o.DataBlockExtended.MediaHeight;
    in >> o.DataBlockExtended.MediaLoop;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LandStatRequestMessage::LandStatRequestMessage (){
    type=LandStatRequestType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LandStatRequestMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.RequestData.ReportType;
    out << o.RequestData.RequestFlags;
    out << o.RequestData.Filter;
    out << o.RequestData.ParcelLocalID;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LandStatRequestMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.RequestData.ReportType;
    in >> o.RequestData.RequestFlags;
    in >> o.RequestData.Filter;
    in >> o.RequestData.ParcelLocalID;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


LandStatReplyMessage::LandStatReplyMessage (){
    type=LandStatReplyType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const LandStatReplyMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.RequestData.ReportType;
    out << o.RequestData.RequestFlags;
    out << o.RequestData.TotalObjectCount;

    out << (lltypes::U8)o.ReportData.size();
    for(int i=0;i<o.ReportData.size();i++){
         out << o.ReportData[i].TaskLocalID;
         out << o.ReportData[i].TaskID;
         out << o.ReportData[i].LocationX;
         out << o.ReportData[i].LocationY;
         out << o.ReportData[i].LocationZ;
         out << o.ReportData[i].Score;
         out << o.ReportData[i].TaskName;
         out << o.ReportData[i].OwnerName;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  LandStatReplyMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.RequestData.ReportType;
    in >> o.RequestData.RequestFlags;
    in >> o.RequestData.TotalObjectCount;

    o.ReportData.clear();
    lltypes::U8 countReportData;
    in >> countReportData;
    for(int i=0;i<countReportData;i++){
        LandStatReplyMessage::ReportDataBlock y;
        in >> y.TaskLocalID;
        in >> y.TaskID;
        in >> y.LocationX;
        in >> y.LocationY;
        in >> y.LocationZ;
        in >> y.Score;
        in >> y.TaskName;
        in >> y.OwnerName;
        o.ReportData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ErrorMessage::ErrorMessage (){
    type=ErrorType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ErrorMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;

    out << o.Data.Code;
    out << o.Data.Token;
    out << o.Data.ID;
    out << o.Data.System;
    out << o.Data.Message;
    out << o.Data.Data;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ErrorMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;

    in >> o.Data.Code;
    in >> o.Data.Token;
    in >> o.Data.ID;
    in >> o.Data.System;
    in >> o.Data.Message;
    in >> o.Data.Data;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


ObjectIncludeInSearchMessage::ObjectIncludeInSearchMessage (){
    type=ObjectIncludeInSearchType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const ObjectIncludeInSearchMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << (lltypes::U8)o.ObjectData.size();
    for(int i=0;i<o.ObjectData.size();i++){
         out << o.ObjectData[i].ObjectLocalID;
         out << o.ObjectData[i].IncludeInSearch;
    }

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  ObjectIncludeInSearchMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    o.ObjectData.clear();
    lltypes::U8 countObjectData;
    in >> countObjectData;
    for(int i=0;i<countObjectData;i++){
        ObjectIncludeInSearchMessage::ObjectDataBlock y;
        in >> y.ObjectLocalID;
        in >> y.IncludeInSearch;
        o.ObjectData << y;
    }

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


RezRestoreToWorldMessage::RezRestoreToWorldMessage (){
    type=RezRestoreToWorldType;
}

QDataStream &qtsl::udp::operator<<(QDataStream & out, const RezRestoreToWorldMessage & o) {
    out.setByteOrder(QDataStream::LittleEndian);
    out << o.AgentData.AgentID;
    out << o.AgentData.SessionID;

    out << o.InventoryData.ItemID;
    out << o.InventoryData.FolderID;
    out << o.InventoryData.CreatorID;
    out << o.InventoryData.OwnerID;
    out << o.InventoryData.GroupID;
    out << o.InventoryData.BaseMask;
    out << o.InventoryData.OwnerMask;
    out << o.InventoryData.GroupMask;
    out << o.InventoryData.EveryoneMask;
    out << o.InventoryData.NextOwnerMask;
    out << o.InventoryData.GroupOwned;
    out << o.InventoryData.TransactionID;
    out << o.InventoryData.Type;
    out << o.InventoryData.InvType;
    out << o.InventoryData.Flags;
    out << o.InventoryData.SaleType;
    out << o.InventoryData.SalePrice;
    out << o.InventoryData.Name;
    out << o.InventoryData.Description;
    out << o.InventoryData.CreationDate;
    out << o.InventoryData.CRC;

    out.setByteOrder(QDataStream::BigEndian);
    return out;
}
QDataStream &qtsl::udp::operator>>(QDataStream & in,  RezRestoreToWorldMessage & o) {
    in.setByteOrder(QDataStream::LittleEndian);
    in >> o.AgentData.AgentID;
    in >> o.AgentData.SessionID;

    in >> o.InventoryData.ItemID;
    in >> o.InventoryData.FolderID;
    in >> o.InventoryData.CreatorID;
    in >> o.InventoryData.OwnerID;
    in >> o.InventoryData.GroupID;
    in >> o.InventoryData.BaseMask;
    in >> o.InventoryData.OwnerMask;
    in >> o.InventoryData.GroupMask;
    in >> o.InventoryData.EveryoneMask;
    in >> o.InventoryData.NextOwnerMask;
    in >> o.InventoryData.GroupOwned;
    in >> o.InventoryData.TransactionID;
    in >> o.InventoryData.Type;
    in >> o.InventoryData.InvType;
    in >> o.InventoryData.Flags;
    in >> o.InventoryData.SaleType;
    in >> o.InventoryData.SalePrice;
    in >> o.InventoryData.Name;
    in >> o.InventoryData.Description;
    in >> o.InventoryData.CreationDate;
    in >> o.InventoryData.CRC;

    in.setByteOrder(QDataStream::BigEndian);
    return in;
}


UdpMessage * qtsl::udp::fromBytes(QByteArray &bytes){
    if((quint8)bytes[0]==255){
        if((quint8)bytes[1]==255){
            if((quint8)bytes[2]==255){
                quint32 bb=qFromBigEndian(((quint32*)bytes.data())[0]);
                bytes=bytes.mid(4);
                QBuffer buff(&bytes);
                buff.open(QIODevice::ReadOnly);
                QDataStream s(&buff); 
                switch(bb){
                    case 4294967291U: {
                        PacketAckMessage * m = new PacketAckMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 4294967292U: {
                        OpenCircuitMessage * m = new OpenCircuitMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 4294967293U: {
                        CloseCircuitMessage * m = new CloseCircuitMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                }
            }else{
                quint16 bb=qFromBigEndian(((quint16*)bytes.data())[1]);
                bytes=bytes.mid(4);
                QBuffer buff(&bytes);
                buff.open(QIODevice::ReadOnly);
                QDataStream s(&buff); 
                switch(bb){
                    case 1U: {
                        TestMessageMessage * m = new TestMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 2U: {
                        AddCircuitCodeMessage * m = new AddCircuitCodeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 3U: {
                        UseCircuitCodeMessage * m = new UseCircuitCodeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 4U: {
                        AvatarTextureUpdateMessage * m = new AvatarTextureUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 5U: {
                        SimulatorMapUpdateMessage * m = new SimulatorMapUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 6U: {
                        SimulatorSetMapMessage * m = new SimulatorSetMapMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 7U: {
                        SubscribeLoadMessage * m = new SubscribeLoadMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 8U: {
                        UnsubscribeLoadMessage * m = new UnsubscribeLoadMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 9U: {
                        SimulatorReadyMessage * m = new SimulatorReadyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 10U: {
                        TelehubInfoMessage * m = new TelehubInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 11U: {
                        SimulatorPresentAtLocationMessage * m = new SimulatorPresentAtLocationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 12U: {
                        SimulatorLoadMessage * m = new SimulatorLoadMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 13U: {
                        SimulatorShutdownRequestMessage * m = new SimulatorShutdownRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 14U: {
                        RegionPresenceRequestByRegionIDMessage * m = new RegionPresenceRequestByRegionIDMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 15U: {
                        RegionPresenceRequestByHandleMessage * m = new RegionPresenceRequestByHandleMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 16U: {
                        RegionPresenceResponseMessage * m = new RegionPresenceResponseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 17U: {
                        UpdateSimulatorMessage * m = new UpdateSimulatorMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 18U: {
                        LogDwellTimeMessage * m = new LogDwellTimeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 19U: {
                        FeatureDisabledMessage * m = new FeatureDisabledMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 20U: {
                        LogFailedMoneyTransactionMessage * m = new LogFailedMoneyTransactionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 21U: {
                        UserReportInternalMessage * m = new UserReportInternalMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 22U: {
                        SetSimStatusInDatabaseMessage * m = new SetSimStatusInDatabaseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 23U: {
                        SetSimPresenceInDatabaseMessage * m = new SetSimPresenceInDatabaseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 24U: {
                        EconomyDataRequestMessage * m = new EconomyDataRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 25U: {
                        EconomyDataMessage * m = new EconomyDataMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 26U: {
                        AvatarPickerRequestMessage * m = new AvatarPickerRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 27U: {
                        AvatarPickerRequestBackendMessage * m = new AvatarPickerRequestBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 28U: {
                        AvatarPickerReplyMessage * m = new AvatarPickerReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 29U: {
                        PlacesQueryMessage * m = new PlacesQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 30U: {
                        PlacesReplyMessage * m = new PlacesReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 31U: {
                        DirFindQueryMessage * m = new DirFindQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 32U: {
                        DirFindQueryBackendMessage * m = new DirFindQueryBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 33U: {
                        DirPlacesQueryMessage * m = new DirPlacesQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 34U: {
                        DirPlacesQueryBackendMessage * m = new DirPlacesQueryBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 35U: {
                        DirPlacesReplyMessage * m = new DirPlacesReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 36U: {
                        DirPeopleReplyMessage * m = new DirPeopleReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 37U: {
                        DirEventsReplyMessage * m = new DirEventsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 38U: {
                        DirGroupsReplyMessage * m = new DirGroupsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 39U: {
                        DirClassifiedQueryMessage * m = new DirClassifiedQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 40U: {
                        DirClassifiedQueryBackendMessage * m = new DirClassifiedQueryBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 41U: {
                        DirClassifiedReplyMessage * m = new DirClassifiedReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 42U: {
                        AvatarClassifiedReplyMessage * m = new AvatarClassifiedReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 43U: {
                        ClassifiedInfoRequestMessage * m = new ClassifiedInfoRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 44U: {
                        ClassifiedInfoReplyMessage * m = new ClassifiedInfoReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 45U: {
                        ClassifiedInfoUpdateMessage * m = new ClassifiedInfoUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 46U: {
                        ClassifiedDeleteMessage * m = new ClassifiedDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 47U: {
                        ClassifiedGodDeleteMessage * m = new ClassifiedGodDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 48U: {
                        DirLandQueryMessage * m = new DirLandQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 49U: {
                        DirLandQueryBackendMessage * m = new DirLandQueryBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 50U: {
                        DirLandReplyMessage * m = new DirLandReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 51U: {
                        DirPopularQueryMessage * m = new DirPopularQueryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 52U: {
                        DirPopularQueryBackendMessage * m = new DirPopularQueryBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 53U: {
                        DirPopularReplyMessage * m = new DirPopularReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 54U: {
                        ParcelInfoRequestMessage * m = new ParcelInfoRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 55U: {
                        ParcelInfoReplyMessage * m = new ParcelInfoReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 56U: {
                        ParcelObjectOwnersRequestMessage * m = new ParcelObjectOwnersRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 57U: {
                        ParcelObjectOwnersReplyMessage * m = new ParcelObjectOwnersReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 58U: {
                        GroupNoticesListRequestMessage * m = new GroupNoticesListRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 59U: {
                        GroupNoticesListReplyMessage * m = new GroupNoticesListReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 60U: {
                        GroupNoticeRequestMessage * m = new GroupNoticeRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 61U: {
                        GroupNoticeAddMessage * m = new GroupNoticeAddMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 62U: {
                        TeleportRequestMessage * m = new TeleportRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 63U: {
                        TeleportLocationRequestMessage * m = new TeleportLocationRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 64U: {
                        TeleportLocalMessage * m = new TeleportLocalMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 65U: {
                        TeleportLandmarkRequestMessage * m = new TeleportLandmarkRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 66U: {
                        TeleportProgressMessage * m = new TeleportProgressMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 67U: {
                        DataHomeLocationRequestMessage * m = new DataHomeLocationRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 68U: {
                        DataHomeLocationReplyMessage * m = new DataHomeLocationReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 69U: {
                        TeleportFinishMessage * m = new TeleportFinishMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 70U: {
                        StartLureMessage * m = new StartLureMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 71U: {
                        TeleportLureRequestMessage * m = new TeleportLureRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 72U: {
                        TeleportCancelMessage * m = new TeleportCancelMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 73U: {
                        TeleportStartMessage * m = new TeleportStartMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 74U: {
                        TeleportFailedMessage * m = new TeleportFailedMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 75U: {
                        UndoMessage * m = new UndoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 76U: {
                        RedoMessage * m = new RedoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 77U: {
                        UndoLandMessage * m = new UndoLandMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 78U: {
                        AgentPauseMessage * m = new AgentPauseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 79U: {
                        AgentResumeMessage * m = new AgentResumeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 80U: {
                        ChatFromViewerMessage * m = new ChatFromViewerMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 81U: {
                        AgentThrottleMessage * m = new AgentThrottleMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 82U: {
                        AgentFOVMessage * m = new AgentFOVMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 83U: {
                        AgentHeightWidthMessage * m = new AgentHeightWidthMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 84U: {
                        AgentSetAppearanceMessage * m = new AgentSetAppearanceMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 85U: {
                        AgentQuitCopyMessage * m = new AgentQuitCopyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 86U: {
                        ImageNotInDatabaseMessage * m = new ImageNotInDatabaseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 87U: {
                        RebakeAvatarTexturesMessage * m = new RebakeAvatarTexturesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 88U: {
                        SetAlwaysRunMessage * m = new SetAlwaysRunMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 89U: {
                        ObjectDeleteMessage * m = new ObjectDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 90U: {
                        ObjectDuplicateMessage * m = new ObjectDuplicateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 91U: {
                        ObjectDuplicateOnRayMessage * m = new ObjectDuplicateOnRayMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 92U: {
                        ObjectScaleMessage * m = new ObjectScaleMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 93U: {
                        ObjectRotationMessage * m = new ObjectRotationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 94U: {
                        ObjectFlagUpdateMessage * m = new ObjectFlagUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 95U: {
                        ObjectClickActionMessage * m = new ObjectClickActionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 96U: {
                        ObjectImageMessage * m = new ObjectImageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 97U: {
                        ObjectMaterialMessage * m = new ObjectMaterialMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 98U: {
                        ObjectShapeMessage * m = new ObjectShapeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 99U: {
                        ObjectExtraParamsMessage * m = new ObjectExtraParamsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 100U: {
                        ObjectOwnerMessage * m = new ObjectOwnerMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 101U: {
                        ObjectGroupMessage * m = new ObjectGroupMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 102U: {
                        ObjectBuyMessage * m = new ObjectBuyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 103U: {
                        BuyObjectInventoryMessage * m = new BuyObjectInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 104U: {
                        DerezContainerMessage * m = new DerezContainerMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 105U: {
                        ObjectPermissionsMessage * m = new ObjectPermissionsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 106U: {
                        ObjectSaleInfoMessage * m = new ObjectSaleInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 107U: {
                        ObjectNameMessage * m = new ObjectNameMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 108U: {
                        ObjectDescriptionMessage * m = new ObjectDescriptionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 109U: {
                        ObjectCategoryMessage * m = new ObjectCategoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 110U: {
                        ObjectSelectMessage * m = new ObjectSelectMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 111U: {
                        ObjectDeselectMessage * m = new ObjectDeselectMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 112U: {
                        ObjectAttachMessage * m = new ObjectAttachMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 113U: {
                        ObjectDetachMessage * m = new ObjectDetachMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 114U: {
                        ObjectDropMessage * m = new ObjectDropMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 115U: {
                        ObjectLinkMessage * m = new ObjectLinkMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 116U: {
                        ObjectDelinkMessage * m = new ObjectDelinkMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 117U: {
                        ObjectGrabMessage * m = new ObjectGrabMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 118U: {
                        ObjectGrabUpdateMessage * m = new ObjectGrabUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 119U: {
                        ObjectDeGrabMessage * m = new ObjectDeGrabMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 120U: {
                        ObjectSpinStartMessage * m = new ObjectSpinStartMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 121U: {
                        ObjectSpinUpdateMessage * m = new ObjectSpinUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 122U: {
                        ObjectSpinStopMessage * m = new ObjectSpinStopMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 123U: {
                        ObjectExportSelectedMessage * m = new ObjectExportSelectedMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 124U: {
                        ModifyLandMessage * m = new ModifyLandMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 125U: {
                        VelocityInterpolateOnMessage * m = new VelocityInterpolateOnMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 126U: {
                        VelocityInterpolateOffMessage * m = new VelocityInterpolateOffMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 127U: {
                        StateSaveMessage * m = new StateSaveMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 128U: {
                        ReportAutosaveCrashMessage * m = new ReportAutosaveCrashMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 129U: {
                        SimWideDeletesMessage * m = new SimWideDeletesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 130U: {
                        TrackAgentMessage * m = new TrackAgentMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 131U: {
                        ViewerStatsMessage * m = new ViewerStatsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 132U: {
                        ScriptAnswerYesMessage * m = new ScriptAnswerYesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 133U: {
                        UserReportMessage * m = new UserReportMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 134U: {
                        AlertMessageMessage * m = new AlertMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 135U: {
                        AgentAlertMessageMessage * m = new AgentAlertMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 136U: {
                        MeanCollisionAlertMessage * m = new MeanCollisionAlertMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 137U: {
                        ViewerFrozenMessageMessage * m = new ViewerFrozenMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 138U: {
                        HealthMessageMessage * m = new HealthMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 139U: {
                        ChatFromSimulatorMessage * m = new ChatFromSimulatorMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 140U: {
                        SimStatsMessage * m = new SimStatsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 141U: {
                        RequestRegionInfoMessage * m = new RequestRegionInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 142U: {
                        RegionInfoMessage * m = new RegionInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 143U: {
                        GodUpdateRegionInfoMessage * m = new GodUpdateRegionInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 144U: {
                        NearestLandingRegionRequestMessage * m = new NearestLandingRegionRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 145U: {
                        NearestLandingRegionReplyMessage * m = new NearestLandingRegionReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 146U: {
                        NearestLandingRegionUpdatedMessage * m = new NearestLandingRegionUpdatedMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 147U: {
                        TeleportLandingStatusChangedMessage * m = new TeleportLandingStatusChangedMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 148U: {
                        RegionHandshakeMessage * m = new RegionHandshakeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 149U: {
                        RegionHandshakeReplyMessage * m = new RegionHandshakeReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 150U: {
                        SimulatorViewerTimeMessageMessage * m = new SimulatorViewerTimeMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 151U: {
                        EnableSimulatorMessage * m = new EnableSimulatorMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 152U: {
                        DisableSimulatorMessage * m = new DisableSimulatorMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 153U: {
                        TransferRequestMessage * m = new TransferRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 154U: {
                        TransferInfoMessage * m = new TransferInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 155U: {
                        TransferAbortMessage * m = new TransferAbortMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 156U: {
                        RequestXferMessage * m = new RequestXferMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 157U: {
                        AbortXferMessage * m = new AbortXferMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 158U: {
                        AvatarAppearanceMessage * m = new AvatarAppearanceMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 159U: {
                        SetFollowCamPropertiesMessage * m = new SetFollowCamPropertiesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 160U: {
                        ClearFollowCamPropertiesMessage * m = new ClearFollowCamPropertiesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 161U: {
                        RequestPayPriceMessage * m = new RequestPayPriceMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 162U: {
                        PayPriceReplyMessage * m = new PayPriceReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 163U: {
                        KickUserMessage * m = new KickUserMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 164U: {
                        KickUserAckMessage * m = new KickUserAckMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 165U: {
                        GodKickUserMessage * m = new GodKickUserMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 166U: {
                        SystemKickUserMessage * m = new SystemKickUserMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 167U: {
                        EjectUserMessage * m = new EjectUserMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 168U: {
                        FreezeUserMessage * m = new FreezeUserMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 169U: {
                        AvatarPropertiesRequestMessage * m = new AvatarPropertiesRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 170U: {
                        AvatarPropertiesRequestBackendMessage * m = new AvatarPropertiesRequestBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 171U: {
                        AvatarPropertiesReplyMessage * m = new AvatarPropertiesReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 172U: {
                        AvatarInterestsReplyMessage * m = new AvatarInterestsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 173U: {
                        AvatarGroupsReplyMessage * m = new AvatarGroupsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 174U: {
                        AvatarPropertiesUpdateMessage * m = new AvatarPropertiesUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 175U: {
                        AvatarInterestsUpdateMessage * m = new AvatarInterestsUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 176U: {
                        AvatarNotesReplyMessage * m = new AvatarNotesReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 177U: {
                        AvatarNotesUpdateMessage * m = new AvatarNotesUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 178U: {
                        AvatarPicksReplyMessage * m = new AvatarPicksReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 179U: {
                        EventInfoRequestMessage * m = new EventInfoRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 180U: {
                        EventInfoReplyMessage * m = new EventInfoReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 181U: {
                        EventNotificationAddRequestMessage * m = new EventNotificationAddRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 182U: {
                        EventNotificationRemoveRequestMessage * m = new EventNotificationRemoveRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 183U: {
                        EventGodDeleteMessage * m = new EventGodDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 184U: {
                        PickInfoReplyMessage * m = new PickInfoReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 185U: {
                        PickInfoUpdateMessage * m = new PickInfoUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 186U: {
                        PickDeleteMessage * m = new PickDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 187U: {
                        PickGodDeleteMessage * m = new PickGodDeleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 188U: {
                        ScriptQuestionMessage * m = new ScriptQuestionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 189U: {
                        ScriptControlChangeMessage * m = new ScriptControlChangeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 190U: {
                        ScriptDialogMessage * m = new ScriptDialogMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 191U: {
                        ScriptDialogReplyMessage * m = new ScriptDialogReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 192U: {
                        ForceScriptControlReleaseMessage * m = new ForceScriptControlReleaseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 193U: {
                        RevokePermissionsMessage * m = new RevokePermissionsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 194U: {
                        LoadURLMessage * m = new LoadURLMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 195U: {
                        ScriptTeleportRequestMessage * m = new ScriptTeleportRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 196U: {
                        ParcelOverlayMessage * m = new ParcelOverlayMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 197U: {
                        ParcelPropertiesRequestByIDMessage * m = new ParcelPropertiesRequestByIDMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 198U: {
                        ParcelPropertiesUpdateMessage * m = new ParcelPropertiesUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 199U: {
                        ParcelReturnObjectsMessage * m = new ParcelReturnObjectsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 200U: {
                        ParcelSetOtherCleanTimeMessage * m = new ParcelSetOtherCleanTimeMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 201U: {
                        ParcelDisableObjectsMessage * m = new ParcelDisableObjectsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 202U: {
                        ParcelSelectObjectsMessage * m = new ParcelSelectObjectsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 203U: {
                        EstateCovenantRequestMessage * m = new EstateCovenantRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 204U: {
                        EstateCovenantReplyMessage * m = new EstateCovenantReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 205U: {
                        ForceObjectSelectMessage * m = new ForceObjectSelectMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 206U: {
                        ParcelBuyPassMessage * m = new ParcelBuyPassMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 207U: {
                        ParcelDeedToGroupMessage * m = new ParcelDeedToGroupMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 208U: {
                        ParcelReclaimMessage * m = new ParcelReclaimMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 209U: {
                        ParcelClaimMessage * m = new ParcelClaimMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 210U: {
                        ParcelJoinMessage * m = new ParcelJoinMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 211U: {
                        ParcelDivideMessage * m = new ParcelDivideMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 212U: {
                        ParcelReleaseMessage * m = new ParcelReleaseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 213U: {
                        ParcelBuyMessage * m = new ParcelBuyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 214U: {
                        ParcelGodForceOwnerMessage * m = new ParcelGodForceOwnerMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 215U: {
                        ParcelAccessListRequestMessage * m = new ParcelAccessListRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 216U: {
                        ParcelAccessListReplyMessage * m = new ParcelAccessListReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 217U: {
                        ParcelAccessListUpdateMessage * m = new ParcelAccessListUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 218U: {
                        ParcelDwellRequestMessage * m = new ParcelDwellRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 219U: {
                        ParcelDwellReplyMessage * m = new ParcelDwellReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 220U: {
                        RequestParcelTransferMessage * m = new RequestParcelTransferMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 221U: {
                        UpdateParcelMessage * m = new UpdateParcelMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 222U: {
                        RemoveParcelMessage * m = new RemoveParcelMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 223U: {
                        MergeParcelMessage * m = new MergeParcelMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 224U: {
                        LogParcelChangesMessage * m = new LogParcelChangesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 225U: {
                        CheckParcelSalesMessage * m = new CheckParcelSalesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 226U: {
                        ParcelSalesMessage * m = new ParcelSalesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 227U: {
                        ParcelGodMarkAsContentMessage * m = new ParcelGodMarkAsContentMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 228U: {
                        ViewerStartAuctionMessage * m = new ViewerStartAuctionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 229U: {
                        StartAuctionMessage * m = new StartAuctionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 230U: {
                        ConfirmAuctionStartMessage * m = new ConfirmAuctionStartMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 231U: {
                        CompleteAuctionMessage * m = new CompleteAuctionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 232U: {
                        CancelAuctionMessage * m = new CancelAuctionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 233U: {
                        CheckParcelAuctionsMessage * m = new CheckParcelAuctionsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 234U: {
                        ParcelAuctionsMessage * m = new ParcelAuctionsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 235U: {
                        UUIDNameRequestMessage * m = new UUIDNameRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 236U: {
                        UUIDNameReplyMessage * m = new UUIDNameReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 237U: {
                        UUIDGroupNameRequestMessage * m = new UUIDGroupNameRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 238U: {
                        UUIDGroupNameReplyMessage * m = new UUIDGroupNameReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 239U: {
                        ChatPassMessage * m = new ChatPassMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 240U: {
                        ChildAgentDyingMessage * m = new ChildAgentDyingMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 241U: {
                        ChildAgentUnknownMessage * m = new ChildAgentUnknownMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 242U: {
                        KillChildAgentsMessage * m = new KillChildAgentsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 243U: {
                        GetScriptRunningMessage * m = new GetScriptRunningMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 244U: {
                        ScriptRunningReplyMessage * m = new ScriptRunningReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 245U: {
                        SetScriptRunningMessage * m = new SetScriptRunningMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 246U: {
                        ScriptResetMessage * m = new ScriptResetMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 247U: {
                        ScriptSensorRequestMessage * m = new ScriptSensorRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 248U: {
                        ScriptSensorReplyMessage * m = new ScriptSensorReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 249U: {
                        CompleteAgentMovementMessage * m = new CompleteAgentMovementMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 250U: {
                        AgentMovementCompleteMessage * m = new AgentMovementCompleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 251U: {
                        DataServerLogoutMessage * m = new DataServerLogoutMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 252U: {
                        LogoutRequestMessage * m = new LogoutRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 253U: {
                        LogoutReplyMessage * m = new LogoutReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 254U: {
                        ImprovedInstantMessageMessage * m = new ImprovedInstantMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 255U: {
                        RetrieveInstantMessagesMessage * m = new RetrieveInstantMessagesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 256U: {
                        FindAgentMessage * m = new FindAgentMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 257U: {
                        RequestGodlikePowersMessage * m = new RequestGodlikePowersMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 258U: {
                        GrantGodlikePowersMessage * m = new GrantGodlikePowersMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 259U: {
                        GodlikeMessageMessage * m = new GodlikeMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 260U: {
                        EstateOwnerMessageMessage * m = new EstateOwnerMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 261U: {
                        GenericMessageMessage * m = new GenericMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 262U: {
                        MuteListRequestMessage * m = new MuteListRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 263U: {
                        UpdateMuteListEntryMessage * m = new UpdateMuteListEntryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 264U: {
                        RemoveMuteListEntryMessage * m = new RemoveMuteListEntryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 265U: {
                        CopyInventoryFromNotecardMessage * m = new CopyInventoryFromNotecardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 266U: {
                        UpdateInventoryItemMessage * m = new UpdateInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 267U: {
                        UpdateCreateInventoryItemMessage * m = new UpdateCreateInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 268U: {
                        MoveInventoryItemMessage * m = new MoveInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 269U: {
                        CopyInventoryItemMessage * m = new CopyInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 270U: {
                        RemoveInventoryItemMessage * m = new RemoveInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 271U: {
                        ChangeInventoryItemFlagsMessage * m = new ChangeInventoryItemFlagsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 272U: {
                        SaveAssetIntoInventoryMessage * m = new SaveAssetIntoInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 273U: {
                        CreateInventoryFolderMessage * m = new CreateInventoryFolderMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 274U: {
                        UpdateInventoryFolderMessage * m = new UpdateInventoryFolderMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 275U: {
                        MoveInventoryFolderMessage * m = new MoveInventoryFolderMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 276U: {
                        RemoveInventoryFolderMessage * m = new RemoveInventoryFolderMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 277U: {
                        FetchInventoryDescendentsMessage * m = new FetchInventoryDescendentsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 278U: {
                        InventoryDescendentsMessage * m = new InventoryDescendentsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 279U: {
                        FetchInventoryMessage * m = new FetchInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 280U: {
                        FetchInventoryReplyMessage * m = new FetchInventoryReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 281U: {
                        BulkUpdateInventoryMessage * m = new BulkUpdateInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 282U: {
                        RequestInventoryAssetMessage * m = new RequestInventoryAssetMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 283U: {
                        InventoryAssetResponseMessage * m = new InventoryAssetResponseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 284U: {
                        RemoveInventoryObjectsMessage * m = new RemoveInventoryObjectsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 285U: {
                        PurgeInventoryDescendentsMessage * m = new PurgeInventoryDescendentsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 286U: {
                        UpdateTaskInventoryMessage * m = new UpdateTaskInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 287U: {
                        RemoveTaskInventoryMessage * m = new RemoveTaskInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 288U: {
                        MoveTaskInventoryMessage * m = new MoveTaskInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 289U: {
                        RequestTaskInventoryMessage * m = new RequestTaskInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 290U: {
                        ReplyTaskInventoryMessage * m = new ReplyTaskInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 291U: {
                        DeRezObjectMessage * m = new DeRezObjectMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 292U: {
                        DeRezAckMessage * m = new DeRezAckMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 293U: {
                        RezObjectMessage * m = new RezObjectMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 294U: {
                        RezObjectFromNotecardMessage * m = new RezObjectFromNotecardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 295U: {
                        TransferInventoryMessage * m = new TransferInventoryMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 296U: {
                        TransferInventoryAckMessage * m = new TransferInventoryAckMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 297U: {
                        AcceptFriendshipMessage * m = new AcceptFriendshipMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 298U: {
                        DeclineFriendshipMessage * m = new DeclineFriendshipMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 299U: {
                        FormFriendshipMessage * m = new FormFriendshipMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 300U: {
                        TerminateFriendshipMessage * m = new TerminateFriendshipMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 301U: {
                        OfferCallingCardMessage * m = new OfferCallingCardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 302U: {
                        AcceptCallingCardMessage * m = new AcceptCallingCardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 303U: {
                        DeclineCallingCardMessage * m = new DeclineCallingCardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 304U: {
                        RezScriptMessage * m = new RezScriptMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 305U: {
                        CreateInventoryItemMessage * m = new CreateInventoryItemMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 306U: {
                        CreateLandmarkForEventMessage * m = new CreateLandmarkForEventMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 307U: {
                        EventLocationRequestMessage * m = new EventLocationRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 308U: {
                        EventLocationReplyMessage * m = new EventLocationReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 309U: {
                        RegionHandleRequestMessage * m = new RegionHandleRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 310U: {
                        RegionIDAndHandleReplyMessage * m = new RegionIDAndHandleReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 311U: {
                        MoneyTransferRequestMessage * m = new MoneyTransferRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 312U: {
                        MoneyTransferBackendMessage * m = new MoneyTransferBackendMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 313U: {
                        MoneyBalanceRequestMessage * m = new MoneyBalanceRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 314U: {
                        MoneyBalanceReplyMessage * m = new MoneyBalanceReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 315U: {
                        RoutedMoneyBalanceReplyMessage * m = new RoutedMoneyBalanceReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 316U: {
                        ActivateGesturesMessage * m = new ActivateGesturesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 317U: {
                        DeactivateGesturesMessage * m = new DeactivateGesturesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 318U: {
                        MuteListUpdateMessage * m = new MuteListUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 319U: {
                        UseCachedMuteListMessage * m = new UseCachedMuteListMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 320U: {
                        GrantUserRightsMessage * m = new GrantUserRightsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 321U: {
                        ChangeUserRightsMessage * m = new ChangeUserRightsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 322U: {
                        OnlineNotificationMessage * m = new OnlineNotificationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 323U: {
                        OfflineNotificationMessage * m = new OfflineNotificationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 324U: {
                        SetStartLocationRequestMessage * m = new SetStartLocationRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 325U: {
                        SetStartLocationMessage * m = new SetStartLocationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 326U: {
                        NetTestMessage * m = new NetTestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 327U: {
                        SetCPURatioMessage * m = new SetCPURatioMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 328U: {
                        SimCrashedMessage * m = new SimCrashedMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 329U: {
                        NameValuePairMessage * m = new NameValuePairMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 330U: {
                        RemoveNameValuePairMessage * m = new RemoveNameValuePairMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 331U: {
                        UpdateAttachmentMessage * m = new UpdateAttachmentMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 332U: {
                        RemoveAttachmentMessage * m = new RemoveAttachmentMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 333U: {
                        AssetUploadRequestMessage * m = new AssetUploadRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 334U: {
                        AssetUploadCompleteMessage * m = new AssetUploadCompleteMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 335U: {
                        EmailMessageRequestMessage * m = new EmailMessageRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 336U: {
                        EmailMessageReplyMessage * m = new EmailMessageReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 337U: {
                        ScriptDataRequestMessage * m = new ScriptDataRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 338U: {
                        ScriptDataReplyMessage * m = new ScriptDataReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 339U: {
                        CreateGroupRequestMessage * m = new CreateGroupRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 340U: {
                        CreateGroupReplyMessage * m = new CreateGroupReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 341U: {
                        UpdateGroupInfoMessage * m = new UpdateGroupInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 342U: {
                        GroupRoleChangesMessage * m = new GroupRoleChangesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 343U: {
                        JoinGroupRequestMessage * m = new JoinGroupRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 344U: {
                        JoinGroupReplyMessage * m = new JoinGroupReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 345U: {
                        EjectGroupMemberRequestMessage * m = new EjectGroupMemberRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 346U: {
                        EjectGroupMemberReplyMessage * m = new EjectGroupMemberReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 347U: {
                        LeaveGroupRequestMessage * m = new LeaveGroupRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 348U: {
                        LeaveGroupReplyMessage * m = new LeaveGroupReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 349U: {
                        InviteGroupRequestMessage * m = new InviteGroupRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 350U: {
                        InviteGroupResponseMessage * m = new InviteGroupResponseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 351U: {
                        GroupProfileRequestMessage * m = new GroupProfileRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 352U: {
                        GroupProfileReplyMessage * m = new GroupProfileReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 353U: {
                        GroupAccountSummaryRequestMessage * m = new GroupAccountSummaryRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 354U: {
                        GroupAccountSummaryReplyMessage * m = new GroupAccountSummaryReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 355U: {
                        GroupAccountDetailsRequestMessage * m = new GroupAccountDetailsRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 356U: {
                        GroupAccountDetailsReplyMessage * m = new GroupAccountDetailsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 357U: {
                        GroupAccountTransactionsRequestMessage * m = new GroupAccountTransactionsRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 358U: {
                        GroupAccountTransactionsReplyMessage * m = new GroupAccountTransactionsReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 359U: {
                        GroupActiveProposalsRequestMessage * m = new GroupActiveProposalsRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 360U: {
                        GroupActiveProposalItemReplyMessage * m = new GroupActiveProposalItemReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 361U: {
                        GroupVoteHistoryRequestMessage * m = new GroupVoteHistoryRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 362U: {
                        GroupVoteHistoryItemReplyMessage * m = new GroupVoteHistoryItemReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 363U: {
                        StartGroupProposalMessage * m = new StartGroupProposalMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 364U: {
                        GroupProposalBallotMessage * m = new GroupProposalBallotMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 365U: {
                        TallyVotesMessage * m = new TallyVotesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 366U: {
                        GroupMembersRequestMessage * m = new GroupMembersRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 367U: {
                        GroupMembersReplyMessage * m = new GroupMembersReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 368U: {
                        ActivateGroupMessage * m = new ActivateGroupMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 369U: {
                        SetGroupContributionMessage * m = new SetGroupContributionMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 370U: {
                        SetGroupAcceptNoticesMessage * m = new SetGroupAcceptNoticesMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 371U: {
                        GroupRoleDataRequestMessage * m = new GroupRoleDataRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 372U: {
                        GroupRoleDataReplyMessage * m = new GroupRoleDataReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 373U: {
                        GroupRoleMembersRequestMessage * m = new GroupRoleMembersRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 374U: {
                        GroupRoleMembersReplyMessage * m = new GroupRoleMembersReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 375U: {
                        GroupTitlesRequestMessage * m = new GroupTitlesRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 376U: {
                        GroupTitlesReplyMessage * m = new GroupTitlesReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 377U: {
                        GroupTitleUpdateMessage * m = new GroupTitleUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 378U: {
                        GroupRoleUpdateMessage * m = new GroupRoleUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 379U: {
                        LiveHelpGroupRequestMessage * m = new LiveHelpGroupRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 380U: {
                        LiveHelpGroupReplyMessage * m = new LiveHelpGroupReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 381U: {
                        AgentWearablesRequestMessage * m = new AgentWearablesRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 382U: {
                        AgentWearablesUpdateMessage * m = new AgentWearablesUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 383U: {
                        AgentIsNowWearingMessage * m = new AgentIsNowWearingMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 384U: {
                        AgentCachedTextureMessage * m = new AgentCachedTextureMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 385U: {
                        AgentCachedTextureResponseMessage * m = new AgentCachedTextureResponseMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 386U: {
                        AgentDataUpdateRequestMessage * m = new AgentDataUpdateRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 387U: {
                        AgentDataUpdateMessage * m = new AgentDataUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 388U: {
                        GroupDataUpdateMessage * m = new GroupDataUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 389U: {
                        AgentGroupDataUpdateMessage * m = new AgentGroupDataUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 390U: {
                        AgentDropGroupMessage * m = new AgentDropGroupMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 391U: {
                        LogTextMessageMessage * m = new LogTextMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 392U: {
                        CreateTrustedCircuitMessage * m = new CreateTrustedCircuitMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 393U: {
                        DenyTrustedCircuitMessage * m = new DenyTrustedCircuitMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 394U: {
                        RequestTrustedCircuitMessage * m = new RequestTrustedCircuitMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 395U: {
                        RezSingleAttachmentFromInvMessage * m = new RezSingleAttachmentFromInvMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 396U: {
                        RezMultipleAttachmentsFromInvMessage * m = new RezMultipleAttachmentsFromInvMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 397U: {
                        DetachAttachmentIntoInvMessage * m = new DetachAttachmentIntoInvMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 398U: {
                        CreateNewOutfitAttachmentsMessage * m = new CreateNewOutfitAttachmentsMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 399U: {
                        UserInfoRequestMessage * m = new UserInfoRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 400U: {
                        UserInfoReplyMessage * m = new UserInfoReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 401U: {
                        UpdateUserInfoMessage * m = new UpdateUserInfoMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 402U: {
                        ParcelRenameMessage * m = new ParcelRenameMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 403U: {
                        InitiateDownloadMessage * m = new InitiateDownloadMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 404U: {
                        SystemMessageMessage * m = new SystemMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 405U: {
                        MapLayerRequestMessage * m = new MapLayerRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 406U: {
                        MapLayerReplyMessage * m = new MapLayerReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 407U: {
                        MapBlockRequestMessage * m = new MapBlockRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 408U: {
                        MapNameRequestMessage * m = new MapNameRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 409U: {
                        MapBlockReplyMessage * m = new MapBlockReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 410U: {
                        MapItemRequestMessage * m = new MapItemRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 411U: {
                        MapItemReplyMessage * m = new MapItemReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 412U: {
                        SendPostcardMessage * m = new SendPostcardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 413U: {
                        RpcChannelRequestMessage * m = new RpcChannelRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 414U: {
                        RpcChannelReplyMessage * m = new RpcChannelReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 415U: {
                        RpcScriptRequestInboundMessage * m = new RpcScriptRequestInboundMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 416U: {
                        RpcScriptRequestInboundForwardMessage * m = new RpcScriptRequestInboundForwardMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 417U: {
                        RpcScriptReplyInboundMessage * m = new RpcScriptReplyInboundMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 418U: {
                        ScriptMailRegistrationMessage * m = new ScriptMailRegistrationMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 419U: {
                        ParcelMediaCommandMessageMessage * m = new ParcelMediaCommandMessageMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 420U: {
                        ParcelMediaUpdateMessage * m = new ParcelMediaUpdateMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 421U: {
                        LandStatRequestMessage * m = new LandStatRequestMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 422U: {
                        LandStatReplyMessage * m = new LandStatReplyMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 423U: {
                        ErrorMessage * m = new ErrorMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 424U: {
                        ObjectIncludeInSearchMessage * m = new ObjectIncludeInSearchMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                    case 425U: {
                        RezRestoreToWorldMessage * m = new RezRestoreToWorldMessage(); 
                        s>>(*m); 
                        bytes=buff.readAll(); 
                        return m; 
                        break; 
                    }
                }
            }
        }else{
            quint8 bb=bytes[1];
            bytes=bytes.mid(2);
            QBuffer buff(&bytes);
            buff.open(QIODevice::ReadOnly);
            QDataStream s(&buff); 
            switch(bb){
                case 1U: {
                    ObjectAddMessage * m = new ObjectAddMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 2U: {
                    MultipleObjectUpdateMessage * m = new MultipleObjectUpdateMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 3U: {
                    RequestMultipleObjectsMessage * m = new RequestMultipleObjectsMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 4U: {
                    ObjectPositionMessage * m = new ObjectPositionMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 5U: {
                    RequestObjectPropertiesFamilyMessage * m = new RequestObjectPropertiesFamilyMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 6U: {
                    CoarseLocationUpdateMessage * m = new CoarseLocationUpdateMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 7U: {
                    CrossedRegionMessage * m = new CrossedRegionMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 8U: {
                    ConfirmEnableSimulatorMessage * m = new ConfirmEnableSimulatorMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 9U: {
                    ObjectPropertiesMessage * m = new ObjectPropertiesMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 10U: {
                    ObjectPropertiesFamilyMessage * m = new ObjectPropertiesFamilyMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 11U: {
                    ParcelPropertiesRequestMessage * m = new ParcelPropertiesRequestMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 12U: {
                    SimStatusMessage * m = new SimStatusMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 13U: {
                    AttachedSoundMessage * m = new AttachedSoundMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 14U: {
                    AttachedSoundGainChangeMessage * m = new AttachedSoundGainChangeMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 15U: {
                    PreloadSoundMessage * m = new PreloadSoundMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 16U: {
                    InternalScriptMailMessage * m = new InternalScriptMailMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
                case 17U: {
                    ViewerEffectMessage * m = new ViewerEffectMessage(); 
                    s>>(*m); 
                    bytes=buff.readAll(); 
                    return m; 
                    break; 
                }
            }
        }
    }else{
        quint8 bb=bytes[0];
        bytes=bytes.mid(1);
        QBuffer buff(&bytes);
        buff.open(QIODevice::ReadOnly);
        QDataStream s(&buff); 
        switch(bb){
            case 1U: {
                StartPingCheckMessage * m = new StartPingCheckMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 2U: {
                CompletePingCheckMessage * m = new CompletePingCheckMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 3U: {
                NeighborListMessage * m = new NeighborListMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 4U: {
                AgentUpdateMessage * m = new AgentUpdateMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 5U: {
                AgentAnimationMessage * m = new AgentAnimationMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 6U: {
                AgentRequestSitMessage * m = new AgentRequestSitMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 7U: {
                AgentSitMessage * m = new AgentSitMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 8U: {
                RequestImageMessage * m = new RequestImageMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 9U: {
                ImageDataMessage * m = new ImageDataMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 10U: {
                ImagePacketMessage * m = new ImagePacketMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 11U: {
                LayerDataMessage * m = new LayerDataMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 12U: {
                ObjectUpdateMessage * m = new ObjectUpdateMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 13U: {
                ObjectUpdateCompressedMessage * m = new ObjectUpdateCompressedMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 14U: {
                ObjectUpdateCachedMessage * m = new ObjectUpdateCachedMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 15U: {
                ImprovedTerseObjectUpdateMessage * m = new ImprovedTerseObjectUpdateMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 16U: {
                KillObjectMessage * m = new KillObjectMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 17U: {
                TransferPacketMessage * m = new TransferPacketMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 18U: {
                SendXferPacketMessage * m = new SendXferPacketMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 19U: {
                ConfirmXferPacketMessage * m = new ConfirmXferPacketMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 20U: {
                AvatarAnimationMessage * m = new AvatarAnimationMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 21U: {
                AvatarSitResponseMessage * m = new AvatarSitResponseMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 22U: {
                CameraConstraintMessage * m = new CameraConstraintMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 23U: {
                ParcelPropertiesMessage * m = new ParcelPropertiesMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 24U: {
                EdgeDataPacketMessage * m = new EdgeDataPacketMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 25U: {
                ChildAgentUpdateMessage * m = new ChildAgentUpdateMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 26U: {
                ChildAgentAliveMessage * m = new ChildAgentAliveMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 27U: {
                ChildAgentPositionUpdateMessage * m = new ChildAgentPositionUpdateMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 28U: {
                AtomicPassObjectMessage * m = new AtomicPassObjectMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
            case 29U: {
                SoundTriggerMessage * m = new SoundTriggerMessage(); 
                s>>(*m); 
                bytes=buff.readAll(); 
                return m; 
                break; 
            }
        }
    }
    return 0;
}

const char *  qtsl::udp::typeName(MessageType type){
    switch(type){
        case None: 
            return "None"; 
        case TestMessageType: 
            return "TestMessage"; 
        case PacketAckType: 
            return "PacketAck"; 
        case OpenCircuitType: 
            return "OpenCircuit"; 
        case CloseCircuitType: 
            return "CloseCircuit"; 
        case StartPingCheckType: 
            return "StartPingCheck"; 
        case CompletePingCheckType: 
            return "CompletePingCheck"; 
        case AddCircuitCodeType: 
            return "AddCircuitCode"; 
        case UseCircuitCodeType: 
            return "UseCircuitCode"; 
        case NeighborListType: 
            return "NeighborList"; 
        case AvatarTextureUpdateType: 
            return "AvatarTextureUpdate"; 
        case SimulatorMapUpdateType: 
            return "SimulatorMapUpdate"; 
        case SimulatorSetMapType: 
            return "SimulatorSetMap"; 
        case SubscribeLoadType: 
            return "SubscribeLoad"; 
        case UnsubscribeLoadType: 
            return "UnsubscribeLoad"; 
        case SimulatorReadyType: 
            return "SimulatorReady"; 
        case TelehubInfoType: 
            return "TelehubInfo"; 
        case SimulatorPresentAtLocationType: 
            return "SimulatorPresentAtLocation"; 
        case SimulatorLoadType: 
            return "SimulatorLoad"; 
        case SimulatorShutdownRequestType: 
            return "SimulatorShutdownRequest"; 
        case RegionPresenceRequestByRegionIDType: 
            return "RegionPresenceRequestByRegionID"; 
        case RegionPresenceRequestByHandleType: 
            return "RegionPresenceRequestByHandle"; 
        case RegionPresenceResponseType: 
            return "RegionPresenceResponse"; 
        case UpdateSimulatorType: 
            return "UpdateSimulator"; 
        case LogDwellTimeType: 
            return "LogDwellTime"; 
        case FeatureDisabledType: 
            return "FeatureDisabled"; 
        case LogFailedMoneyTransactionType: 
            return "LogFailedMoneyTransaction"; 
        case UserReportInternalType: 
            return "UserReportInternal"; 
        case SetSimStatusInDatabaseType: 
            return "SetSimStatusInDatabase"; 
        case SetSimPresenceInDatabaseType: 
            return "SetSimPresenceInDatabase"; 
        case EconomyDataRequestType: 
            return "EconomyDataRequest"; 
        case EconomyDataType: 
            return "EconomyData"; 
        case AvatarPickerRequestType: 
            return "AvatarPickerRequest"; 
        case AvatarPickerRequestBackendType: 
            return "AvatarPickerRequestBackend"; 
        case AvatarPickerReplyType: 
            return "AvatarPickerReply"; 
        case PlacesQueryType: 
            return "PlacesQuery"; 
        case PlacesReplyType: 
            return "PlacesReply"; 
        case DirFindQueryType: 
            return "DirFindQuery"; 
        case DirFindQueryBackendType: 
            return "DirFindQueryBackend"; 
        case DirPlacesQueryType: 
            return "DirPlacesQuery"; 
        case DirPlacesQueryBackendType: 
            return "DirPlacesQueryBackend"; 
        case DirPlacesReplyType: 
            return "DirPlacesReply"; 
        case DirPeopleReplyType: 
            return "DirPeopleReply"; 
        case DirEventsReplyType: 
            return "DirEventsReply"; 
        case DirGroupsReplyType: 
            return "DirGroupsReply"; 
        case DirClassifiedQueryType: 
            return "DirClassifiedQuery"; 
        case DirClassifiedQueryBackendType: 
            return "DirClassifiedQueryBackend"; 
        case DirClassifiedReplyType: 
            return "DirClassifiedReply"; 
        case AvatarClassifiedReplyType: 
            return "AvatarClassifiedReply"; 
        case ClassifiedInfoRequestType: 
            return "ClassifiedInfoRequest"; 
        case ClassifiedInfoReplyType: 
            return "ClassifiedInfoReply"; 
        case ClassifiedInfoUpdateType: 
            return "ClassifiedInfoUpdate"; 
        case ClassifiedDeleteType: 
            return "ClassifiedDelete"; 
        case ClassifiedGodDeleteType: 
            return "ClassifiedGodDelete"; 
        case DirLandQueryType: 
            return "DirLandQuery"; 
        case DirLandQueryBackendType: 
            return "DirLandQueryBackend"; 
        case DirLandReplyType: 
            return "DirLandReply"; 
        case DirPopularQueryType: 
            return "DirPopularQuery"; 
        case DirPopularQueryBackendType: 
            return "DirPopularQueryBackend"; 
        case DirPopularReplyType: 
            return "DirPopularReply"; 
        case ParcelInfoRequestType: 
            return "ParcelInfoRequest"; 
        case ParcelInfoReplyType: 
            return "ParcelInfoReply"; 
        case ParcelObjectOwnersRequestType: 
            return "ParcelObjectOwnersRequest"; 
        case ParcelObjectOwnersReplyType: 
            return "ParcelObjectOwnersReply"; 
        case GroupNoticesListRequestType: 
            return "GroupNoticesListRequest"; 
        case GroupNoticesListReplyType: 
            return "GroupNoticesListReply"; 
        case GroupNoticeRequestType: 
            return "GroupNoticeRequest"; 
        case GroupNoticeAddType: 
            return "GroupNoticeAdd"; 
        case TeleportRequestType: 
            return "TeleportRequest"; 
        case TeleportLocationRequestType: 
            return "TeleportLocationRequest"; 
        case TeleportLocalType: 
            return "TeleportLocal"; 
        case TeleportLandmarkRequestType: 
            return "TeleportLandmarkRequest"; 
        case TeleportProgressType: 
            return "TeleportProgress"; 
        case DataHomeLocationRequestType: 
            return "DataHomeLocationRequest"; 
        case DataHomeLocationReplyType: 
            return "DataHomeLocationReply"; 
        case TeleportFinishType: 
            return "TeleportFinish"; 
        case StartLureType: 
            return "StartLure"; 
        case TeleportLureRequestType: 
            return "TeleportLureRequest"; 
        case TeleportCancelType: 
            return "TeleportCancel"; 
        case TeleportStartType: 
            return "TeleportStart"; 
        case TeleportFailedType: 
            return "TeleportFailed"; 
        case UndoType: 
            return "Undo"; 
        case RedoType: 
            return "Redo"; 
        case UndoLandType: 
            return "UndoLand"; 
        case AgentPauseType: 
            return "AgentPause"; 
        case AgentResumeType: 
            return "AgentResume"; 
        case AgentUpdateType: 
            return "AgentUpdate"; 
        case ChatFromViewerType: 
            return "ChatFromViewer"; 
        case AgentThrottleType: 
            return "AgentThrottle"; 
        case AgentFOVType: 
            return "AgentFOV"; 
        case AgentHeightWidthType: 
            return "AgentHeightWidth"; 
        case AgentSetAppearanceType: 
            return "AgentSetAppearance"; 
        case AgentAnimationType: 
            return "AgentAnimation"; 
        case AgentRequestSitType: 
            return "AgentRequestSit"; 
        case AgentSitType: 
            return "AgentSit"; 
        case AgentQuitCopyType: 
            return "AgentQuitCopy"; 
        case RequestImageType: 
            return "RequestImage"; 
        case ImageNotInDatabaseType: 
            return "ImageNotInDatabase"; 
        case RebakeAvatarTexturesType: 
            return "RebakeAvatarTextures"; 
        case SetAlwaysRunType: 
            return "SetAlwaysRun"; 
        case ObjectAddType: 
            return "ObjectAdd"; 
        case ObjectDeleteType: 
            return "ObjectDelete"; 
        case ObjectDuplicateType: 
            return "ObjectDuplicate"; 
        case ObjectDuplicateOnRayType: 
            return "ObjectDuplicateOnRay"; 
        case MultipleObjectUpdateType: 
            return "MultipleObjectUpdate"; 
        case RequestMultipleObjectsType: 
            return "RequestMultipleObjects"; 
        case ObjectPositionType: 
            return "ObjectPosition"; 
        case ObjectScaleType: 
            return "ObjectScale"; 
        case ObjectRotationType: 
            return "ObjectRotation"; 
        case ObjectFlagUpdateType: 
            return "ObjectFlagUpdate"; 
        case ObjectClickActionType: 
            return "ObjectClickAction"; 
        case ObjectImageType: 
            return "ObjectImage"; 
        case ObjectMaterialType: 
            return "ObjectMaterial"; 
        case ObjectShapeType: 
            return "ObjectShape"; 
        case ObjectExtraParamsType: 
            return "ObjectExtraParams"; 
        case ObjectOwnerType: 
            return "ObjectOwner"; 
        case ObjectGroupType: 
            return "ObjectGroup"; 
        case ObjectBuyType: 
            return "ObjectBuy"; 
        case BuyObjectInventoryType: 
            return "BuyObjectInventory"; 
        case DerezContainerType: 
            return "DerezContainer"; 
        case ObjectPermissionsType: 
            return "ObjectPermissions"; 
        case ObjectSaleInfoType: 
            return "ObjectSaleInfo"; 
        case ObjectNameType: 
            return "ObjectName"; 
        case ObjectDescriptionType: 
            return "ObjectDescription"; 
        case ObjectCategoryType: 
            return "ObjectCategory"; 
        case ObjectSelectType: 
            return "ObjectSelect"; 
        case ObjectDeselectType: 
            return "ObjectDeselect"; 
        case ObjectAttachType: 
            return "ObjectAttach"; 
        case ObjectDetachType: 
            return "ObjectDetach"; 
        case ObjectDropType: 
            return "ObjectDrop"; 
        case ObjectLinkType: 
            return "ObjectLink"; 
        case ObjectDelinkType: 
            return "ObjectDelink"; 
        case ObjectGrabType: 
            return "ObjectGrab"; 
        case ObjectGrabUpdateType: 
            return "ObjectGrabUpdate"; 
        case ObjectDeGrabType: 
            return "ObjectDeGrab"; 
        case ObjectSpinStartType: 
            return "ObjectSpinStart"; 
        case ObjectSpinUpdateType: 
            return "ObjectSpinUpdate"; 
        case ObjectSpinStopType: 
            return "ObjectSpinStop"; 
        case ObjectExportSelectedType: 
            return "ObjectExportSelected"; 
        case ModifyLandType: 
            return "ModifyLand"; 
        case VelocityInterpolateOnType: 
            return "VelocityInterpolateOn"; 
        case VelocityInterpolateOffType: 
            return "VelocityInterpolateOff"; 
        case StateSaveType: 
            return "StateSave"; 
        case ReportAutosaveCrashType: 
            return "ReportAutosaveCrash"; 
        case SimWideDeletesType: 
            return "SimWideDeletes"; 
        case RequestObjectPropertiesFamilyType: 
            return "RequestObjectPropertiesFamily"; 
        case TrackAgentType: 
            return "TrackAgent"; 
        case ViewerStatsType: 
            return "ViewerStats"; 
        case ScriptAnswerYesType: 
            return "ScriptAnswerYes"; 
        case UserReportType: 
            return "UserReport"; 
        case AlertMessageType: 
            return "AlertMessage"; 
        case AgentAlertMessageType: 
            return "AgentAlertMessage"; 
        case MeanCollisionAlertType: 
            return "MeanCollisionAlert"; 
        case ViewerFrozenMessageType: 
            return "ViewerFrozenMessage"; 
        case HealthMessageType: 
            return "HealthMessage"; 
        case ChatFromSimulatorType: 
            return "ChatFromSimulator"; 
        case SimStatsType: 
            return "SimStats"; 
        case RequestRegionInfoType: 
            return "RequestRegionInfo"; 
        case RegionInfoType: 
            return "RegionInfo"; 
        case GodUpdateRegionInfoType: 
            return "GodUpdateRegionInfo"; 
        case NearestLandingRegionRequestType: 
            return "NearestLandingRegionRequest"; 
        case NearestLandingRegionReplyType: 
            return "NearestLandingRegionReply"; 
        case NearestLandingRegionUpdatedType: 
            return "NearestLandingRegionUpdated"; 
        case TeleportLandingStatusChangedType: 
            return "TeleportLandingStatusChanged"; 
        case RegionHandshakeType: 
            return "RegionHandshake"; 
        case RegionHandshakeReplyType: 
            return "RegionHandshakeReply"; 
        case CoarseLocationUpdateType: 
            return "CoarseLocationUpdate"; 
        case ImageDataType: 
            return "ImageData"; 
        case ImagePacketType: 
            return "ImagePacket"; 
        case LayerDataType: 
            return "LayerData"; 
        case ObjectUpdateType: 
            return "ObjectUpdate"; 
        case ObjectUpdateCompressedType: 
            return "ObjectUpdateCompressed"; 
        case ObjectUpdateCachedType: 
            return "ObjectUpdateCached"; 
        case ImprovedTerseObjectUpdateType: 
            return "ImprovedTerseObjectUpdate"; 
        case KillObjectType: 
            return "KillObject"; 
        case CrossedRegionType: 
            return "CrossedRegion"; 
        case SimulatorViewerTimeMessageType: 
            return "SimulatorViewerTimeMessage"; 
        case EnableSimulatorType: 
            return "EnableSimulator"; 
        case DisableSimulatorType: 
            return "DisableSimulator"; 
        case ConfirmEnableSimulatorType: 
            return "ConfirmEnableSimulator"; 
        case TransferRequestType: 
            return "TransferRequest"; 
        case TransferInfoType: 
            return "TransferInfo"; 
        case TransferPacketType: 
            return "TransferPacket"; 
        case TransferAbortType: 
            return "TransferAbort"; 
        case RequestXferType: 
            return "RequestXfer"; 
        case SendXferPacketType: 
            return "SendXferPacket"; 
        case ConfirmXferPacketType: 
            return "ConfirmXferPacket"; 
        case AbortXferType: 
            return "AbortXfer"; 
        case AvatarAnimationType: 
            return "AvatarAnimation"; 
        case AvatarAppearanceType: 
            return "AvatarAppearance"; 
        case AvatarSitResponseType: 
            return "AvatarSitResponse"; 
        case SetFollowCamPropertiesType: 
            return "SetFollowCamProperties"; 
        case ClearFollowCamPropertiesType: 
            return "ClearFollowCamProperties"; 
        case CameraConstraintType: 
            return "CameraConstraint"; 
        case ObjectPropertiesType: 
            return "ObjectProperties"; 
        case ObjectPropertiesFamilyType: 
            return "ObjectPropertiesFamily"; 
        case RequestPayPriceType: 
            return "RequestPayPrice"; 
        case PayPriceReplyType: 
            return "PayPriceReply"; 
        case KickUserType: 
            return "KickUser"; 
        case KickUserAckType: 
            return "KickUserAck"; 
        case GodKickUserType: 
            return "GodKickUser"; 
        case SystemKickUserType: 
            return "SystemKickUser"; 
        case EjectUserType: 
            return "EjectUser"; 
        case FreezeUserType: 
            return "FreezeUser"; 
        case AvatarPropertiesRequestType: 
            return "AvatarPropertiesRequest"; 
        case AvatarPropertiesRequestBackendType: 
            return "AvatarPropertiesRequestBackend"; 
        case AvatarPropertiesReplyType: 
            return "AvatarPropertiesReply"; 
        case AvatarInterestsReplyType: 
            return "AvatarInterestsReply"; 
        case AvatarGroupsReplyType: 
            return "AvatarGroupsReply"; 
        case AvatarPropertiesUpdateType: 
            return "AvatarPropertiesUpdate"; 
        case AvatarInterestsUpdateType: 
            return "AvatarInterestsUpdate"; 
        case AvatarNotesReplyType: 
            return "AvatarNotesReply"; 
        case AvatarNotesUpdateType: 
            return "AvatarNotesUpdate"; 
        case AvatarPicksReplyType: 
            return "AvatarPicksReply"; 
        case EventInfoRequestType: 
            return "EventInfoRequest"; 
        case EventInfoReplyType: 
            return "EventInfoReply"; 
        case EventNotificationAddRequestType: 
            return "EventNotificationAddRequest"; 
        case EventNotificationRemoveRequestType: 
            return "EventNotificationRemoveRequest"; 
        case EventGodDeleteType: 
            return "EventGodDelete"; 
        case PickInfoReplyType: 
            return "PickInfoReply"; 
        case PickInfoUpdateType: 
            return "PickInfoUpdate"; 
        case PickDeleteType: 
            return "PickDelete"; 
        case PickGodDeleteType: 
            return "PickGodDelete"; 
        case ScriptQuestionType: 
            return "ScriptQuestion"; 
        case ScriptControlChangeType: 
            return "ScriptControlChange"; 
        case ScriptDialogType: 
            return "ScriptDialog"; 
        case ScriptDialogReplyType: 
            return "ScriptDialogReply"; 
        case ForceScriptControlReleaseType: 
            return "ForceScriptControlRelease"; 
        case RevokePermissionsType: 
            return "RevokePermissions"; 
        case LoadURLType: 
            return "LoadURL"; 
        case ScriptTeleportRequestType: 
            return "ScriptTeleportRequest"; 
        case ParcelOverlayType: 
            return "ParcelOverlay"; 
        case ParcelPropertiesRequestType: 
            return "ParcelPropertiesRequest"; 
        case ParcelPropertiesRequestByIDType: 
            return "ParcelPropertiesRequestByID"; 
        case ParcelPropertiesType: 
            return "ParcelProperties"; 
        case ParcelPropertiesUpdateType: 
            return "ParcelPropertiesUpdate"; 
        case ParcelReturnObjectsType: 
            return "ParcelReturnObjects"; 
        case ParcelSetOtherCleanTimeType: 
            return "ParcelSetOtherCleanTime"; 
        case ParcelDisableObjectsType: 
            return "ParcelDisableObjects"; 
        case ParcelSelectObjectsType: 
            return "ParcelSelectObjects"; 
        case EstateCovenantRequestType: 
            return "EstateCovenantRequest"; 
        case EstateCovenantReplyType: 
            return "EstateCovenantReply"; 
        case ForceObjectSelectType: 
            return "ForceObjectSelect"; 
        case ParcelBuyPassType: 
            return "ParcelBuyPass"; 
        case ParcelDeedToGroupType: 
            return "ParcelDeedToGroup"; 
        case ParcelReclaimType: 
            return "ParcelReclaim"; 
        case ParcelClaimType: 
            return "ParcelClaim"; 
        case ParcelJoinType: 
            return "ParcelJoin"; 
        case ParcelDivideType: 
            return "ParcelDivide"; 
        case ParcelReleaseType: 
            return "ParcelRelease"; 
        case ParcelBuyType: 
            return "ParcelBuy"; 
        case ParcelGodForceOwnerType: 
            return "ParcelGodForceOwner"; 
        case ParcelAccessListRequestType: 
            return "ParcelAccessListRequest"; 
        case ParcelAccessListReplyType: 
            return "ParcelAccessListReply"; 
        case ParcelAccessListUpdateType: 
            return "ParcelAccessListUpdate"; 
        case ParcelDwellRequestType: 
            return "ParcelDwellRequest"; 
        case ParcelDwellReplyType: 
            return "ParcelDwellReply"; 
        case RequestParcelTransferType: 
            return "RequestParcelTransfer"; 
        case UpdateParcelType: 
            return "UpdateParcel"; 
        case RemoveParcelType: 
            return "RemoveParcel"; 
        case MergeParcelType: 
            return "MergeParcel"; 
        case LogParcelChangesType: 
            return "LogParcelChanges"; 
        case CheckParcelSalesType: 
            return "CheckParcelSales"; 
        case ParcelSalesType: 
            return "ParcelSales"; 
        case ParcelGodMarkAsContentType: 
            return "ParcelGodMarkAsContent"; 
        case ViewerStartAuctionType: 
            return "ViewerStartAuction"; 
        case StartAuctionType: 
            return "StartAuction"; 
        case ConfirmAuctionStartType: 
            return "ConfirmAuctionStart"; 
        case CompleteAuctionType: 
            return "CompleteAuction"; 
        case CancelAuctionType: 
            return "CancelAuction"; 
        case CheckParcelAuctionsType: 
            return "CheckParcelAuctions"; 
        case ParcelAuctionsType: 
            return "ParcelAuctions"; 
        case UUIDNameRequestType: 
            return "UUIDNameRequest"; 
        case UUIDNameReplyType: 
            return "UUIDNameReply"; 
        case UUIDGroupNameRequestType: 
            return "UUIDGroupNameRequest"; 
        case UUIDGroupNameReplyType: 
            return "UUIDGroupNameReply"; 
        case ChatPassType: 
            return "ChatPass"; 
        case EdgeDataPacketType: 
            return "EdgeDataPacket"; 
        case SimStatusType: 
            return "SimStatus"; 
        case ChildAgentUpdateType: 
            return "ChildAgentUpdate"; 
        case ChildAgentAliveType: 
            return "ChildAgentAlive"; 
        case ChildAgentPositionUpdateType: 
            return "ChildAgentPositionUpdate"; 
        case ChildAgentDyingType: 
            return "ChildAgentDying"; 
        case ChildAgentUnknownType: 
            return "ChildAgentUnknown"; 
        case AtomicPassObjectType: 
            return "AtomicPassObject"; 
        case KillChildAgentsType: 
            return "KillChildAgents"; 
        case GetScriptRunningType: 
            return "GetScriptRunning"; 
        case ScriptRunningReplyType: 
            return "ScriptRunningReply"; 
        case SetScriptRunningType: 
            return "SetScriptRunning"; 
        case ScriptResetType: 
            return "ScriptReset"; 
        case ScriptSensorRequestType: 
            return "ScriptSensorRequest"; 
        case ScriptSensorReplyType: 
            return "ScriptSensorReply"; 
        case CompleteAgentMovementType: 
            return "CompleteAgentMovement"; 
        case AgentMovementCompleteType: 
            return "AgentMovementComplete"; 
        case DataServerLogoutType: 
            return "DataServerLogout"; 
        case LogoutRequestType: 
            return "LogoutRequest"; 
        case LogoutReplyType: 
            return "LogoutReply"; 
        case ImprovedInstantMessageType: 
            return "ImprovedInstantMessage"; 
        case RetrieveInstantMessagesType: 
            return "RetrieveInstantMessages"; 
        case FindAgentType: 
            return "FindAgent"; 
        case RequestGodlikePowersType: 
            return "RequestGodlikePowers"; 
        case GrantGodlikePowersType: 
            return "GrantGodlikePowers"; 
        case GodlikeMessageType: 
            return "GodlikeMessage"; 
        case EstateOwnerMessageType: 
            return "EstateOwnerMessage"; 
        case GenericMessageType: 
            return "GenericMessage"; 
        case MuteListRequestType: 
            return "MuteListRequest"; 
        case UpdateMuteListEntryType: 
            return "UpdateMuteListEntry"; 
        case RemoveMuteListEntryType: 
            return "RemoveMuteListEntry"; 
        case CopyInventoryFromNotecardType: 
            return "CopyInventoryFromNotecard"; 
        case UpdateInventoryItemType: 
            return "UpdateInventoryItem"; 
        case UpdateCreateInventoryItemType: 
            return "UpdateCreateInventoryItem"; 
        case MoveInventoryItemType: 
            return "MoveInventoryItem"; 
        case CopyInventoryItemType: 
            return "CopyInventoryItem"; 
        case RemoveInventoryItemType: 
            return "RemoveInventoryItem"; 
        case ChangeInventoryItemFlagsType: 
            return "ChangeInventoryItemFlags"; 
        case SaveAssetIntoInventoryType: 
            return "SaveAssetIntoInventory"; 
        case CreateInventoryFolderType: 
            return "CreateInventoryFolder"; 
        case UpdateInventoryFolderType: 
            return "UpdateInventoryFolder"; 
        case MoveInventoryFolderType: 
            return "MoveInventoryFolder"; 
        case RemoveInventoryFolderType: 
            return "RemoveInventoryFolder"; 
        case FetchInventoryDescendentsType: 
            return "FetchInventoryDescendents"; 
        case InventoryDescendentsType: 
            return "InventoryDescendents"; 
        case FetchInventoryType: 
            return "FetchInventory"; 
        case FetchInventoryReplyType: 
            return "FetchInventoryReply"; 
        case BulkUpdateInventoryType: 
            return "BulkUpdateInventory"; 
        case RequestInventoryAssetType: 
            return "RequestInventoryAsset"; 
        case InventoryAssetResponseType: 
            return "InventoryAssetResponse"; 
        case RemoveInventoryObjectsType: 
            return "RemoveInventoryObjects"; 
        case PurgeInventoryDescendentsType: 
            return "PurgeInventoryDescendents"; 
        case UpdateTaskInventoryType: 
            return "UpdateTaskInventory"; 
        case RemoveTaskInventoryType: 
            return "RemoveTaskInventory"; 
        case MoveTaskInventoryType: 
            return "MoveTaskInventory"; 
        case RequestTaskInventoryType: 
            return "RequestTaskInventory"; 
        case ReplyTaskInventoryType: 
            return "ReplyTaskInventory"; 
        case DeRezObjectType: 
            return "DeRezObject"; 
        case DeRezAckType: 
            return "DeRezAck"; 
        case RezObjectType: 
            return "RezObject"; 
        case RezObjectFromNotecardType: 
            return "RezObjectFromNotecard"; 
        case TransferInventoryType: 
            return "TransferInventory"; 
        case TransferInventoryAckType: 
            return "TransferInventoryAck"; 
        case AcceptFriendshipType: 
            return "AcceptFriendship"; 
        case DeclineFriendshipType: 
            return "DeclineFriendship"; 
        case FormFriendshipType: 
            return "FormFriendship"; 
        case TerminateFriendshipType: 
            return "TerminateFriendship"; 
        case OfferCallingCardType: 
            return "OfferCallingCard"; 
        case AcceptCallingCardType: 
            return "AcceptCallingCard"; 
        case DeclineCallingCardType: 
            return "DeclineCallingCard"; 
        case RezScriptType: 
            return "RezScript"; 
        case CreateInventoryItemType: 
            return "CreateInventoryItem"; 
        case CreateLandmarkForEventType: 
            return "CreateLandmarkForEvent"; 
        case EventLocationRequestType: 
            return "EventLocationRequest"; 
        case EventLocationReplyType: 
            return "EventLocationReply"; 
        case RegionHandleRequestType: 
            return "RegionHandleRequest"; 
        case RegionIDAndHandleReplyType: 
            return "RegionIDAndHandleReply"; 
        case MoneyTransferRequestType: 
            return "MoneyTransferRequest"; 
        case MoneyTransferBackendType: 
            return "MoneyTransferBackend"; 
        case MoneyBalanceRequestType: 
            return "MoneyBalanceRequest"; 
        case MoneyBalanceReplyType: 
            return "MoneyBalanceReply"; 
        case RoutedMoneyBalanceReplyType: 
            return "RoutedMoneyBalanceReply"; 
        case ActivateGesturesType: 
            return "ActivateGestures"; 
        case DeactivateGesturesType: 
            return "DeactivateGestures"; 
        case MuteListUpdateType: 
            return "MuteListUpdate"; 
        case UseCachedMuteListType: 
            return "UseCachedMuteList"; 
        case GrantUserRightsType: 
            return "GrantUserRights"; 
        case ChangeUserRightsType: 
            return "ChangeUserRights"; 
        case OnlineNotificationType: 
            return "OnlineNotification"; 
        case OfflineNotificationType: 
            return "OfflineNotification"; 
        case SetStartLocationRequestType: 
            return "SetStartLocationRequest"; 
        case SetStartLocationType: 
            return "SetStartLocation"; 
        case NetTestType: 
            return "NetTest"; 
        case SetCPURatioType: 
            return "SetCPURatio"; 
        case SimCrashedType: 
            return "SimCrashed"; 
        case NameValuePairType: 
            return "NameValuePair"; 
        case RemoveNameValuePairType: 
            return "RemoveNameValuePair"; 
        case UpdateAttachmentType: 
            return "UpdateAttachment"; 
        case RemoveAttachmentType: 
            return "RemoveAttachment"; 
        case SoundTriggerType: 
            return "SoundTrigger"; 
        case AttachedSoundType: 
            return "AttachedSound"; 
        case AttachedSoundGainChangeType: 
            return "AttachedSoundGainChange"; 
        case PreloadSoundType: 
            return "PreloadSound"; 
        case AssetUploadRequestType: 
            return "AssetUploadRequest"; 
        case AssetUploadCompleteType: 
            return "AssetUploadComplete"; 
        case EmailMessageRequestType: 
            return "EmailMessageRequest"; 
        case EmailMessageReplyType: 
            return "EmailMessageReply"; 
        case InternalScriptMailType: 
            return "InternalScriptMail"; 
        case ScriptDataRequestType: 
            return "ScriptDataRequest"; 
        case ScriptDataReplyType: 
            return "ScriptDataReply"; 
        case CreateGroupRequestType: 
            return "CreateGroupRequest"; 
        case CreateGroupReplyType: 
            return "CreateGroupReply"; 
        case UpdateGroupInfoType: 
            return "UpdateGroupInfo"; 
        case GroupRoleChangesType: 
            return "GroupRoleChanges"; 
        case JoinGroupRequestType: 
            return "JoinGroupRequest"; 
        case JoinGroupReplyType: 
            return "JoinGroupReply"; 
        case EjectGroupMemberRequestType: 
            return "EjectGroupMemberRequest"; 
        case EjectGroupMemberReplyType: 
            return "EjectGroupMemberReply"; 
        case LeaveGroupRequestType: 
            return "LeaveGroupRequest"; 
        case LeaveGroupReplyType: 
            return "LeaveGroupReply"; 
        case InviteGroupRequestType: 
            return "InviteGroupRequest"; 
        case InviteGroupResponseType: 
            return "InviteGroupResponse"; 
        case GroupProfileRequestType: 
            return "GroupProfileRequest"; 
        case GroupProfileReplyType: 
            return "GroupProfileReply"; 
        case GroupAccountSummaryRequestType: 
            return "GroupAccountSummaryRequest"; 
        case GroupAccountSummaryReplyType: 
            return "GroupAccountSummaryReply"; 
        case GroupAccountDetailsRequestType: 
            return "GroupAccountDetailsRequest"; 
        case GroupAccountDetailsReplyType: 
            return "GroupAccountDetailsReply"; 
        case GroupAccountTransactionsRequestType: 
            return "GroupAccountTransactionsRequest"; 
        case GroupAccountTransactionsReplyType: 
            return "GroupAccountTransactionsReply"; 
        case GroupActiveProposalsRequestType: 
            return "GroupActiveProposalsRequest"; 
        case GroupActiveProposalItemReplyType: 
            return "GroupActiveProposalItemReply"; 
        case GroupVoteHistoryRequestType: 
            return "GroupVoteHistoryRequest"; 
        case GroupVoteHistoryItemReplyType: 
            return "GroupVoteHistoryItemReply"; 
        case StartGroupProposalType: 
            return "StartGroupProposal"; 
        case GroupProposalBallotType: 
            return "GroupProposalBallot"; 
        case TallyVotesType: 
            return "TallyVotes"; 
        case GroupMembersRequestType: 
            return "GroupMembersRequest"; 
        case GroupMembersReplyType: 
            return "GroupMembersReply"; 
        case ActivateGroupType: 
            return "ActivateGroup"; 
        case SetGroupContributionType: 
            return "SetGroupContribution"; 
        case SetGroupAcceptNoticesType: 
            return "SetGroupAcceptNotices"; 
        case GroupRoleDataRequestType: 
            return "GroupRoleDataRequest"; 
        case GroupRoleDataReplyType: 
            return "GroupRoleDataReply"; 
        case GroupRoleMembersRequestType: 
            return "GroupRoleMembersRequest"; 
        case GroupRoleMembersReplyType: 
            return "GroupRoleMembersReply"; 
        case GroupTitlesRequestType: 
            return "GroupTitlesRequest"; 
        case GroupTitlesReplyType: 
            return "GroupTitlesReply"; 
        case GroupTitleUpdateType: 
            return "GroupTitleUpdate"; 
        case GroupRoleUpdateType: 
            return "GroupRoleUpdate"; 
        case LiveHelpGroupRequestType: 
            return "LiveHelpGroupRequest"; 
        case LiveHelpGroupReplyType: 
            return "LiveHelpGroupReply"; 
        case AgentWearablesRequestType: 
            return "AgentWearablesRequest"; 
        case AgentWearablesUpdateType: 
            return "AgentWearablesUpdate"; 
        case AgentIsNowWearingType: 
            return "AgentIsNowWearing"; 
        case AgentCachedTextureType: 
            return "AgentCachedTexture"; 
        case AgentCachedTextureResponseType: 
            return "AgentCachedTextureResponse"; 
        case AgentDataUpdateRequestType: 
            return "AgentDataUpdateRequest"; 
        case AgentDataUpdateType: 
            return "AgentDataUpdate"; 
        case GroupDataUpdateType: 
            return "GroupDataUpdate"; 
        case AgentGroupDataUpdateType: 
            return "AgentGroupDataUpdate"; 
        case AgentDropGroupType: 
            return "AgentDropGroup"; 
        case LogTextMessageType: 
            return "LogTextMessage"; 
        case ViewerEffectType: 
            return "ViewerEffect"; 
        case CreateTrustedCircuitType: 
            return "CreateTrustedCircuit"; 
        case DenyTrustedCircuitType: 
            return "DenyTrustedCircuit"; 
        case RequestTrustedCircuitType: 
            return "RequestTrustedCircuit"; 
        case RezSingleAttachmentFromInvType: 
            return "RezSingleAttachmentFromInv"; 
        case RezMultipleAttachmentsFromInvType: 
            return "RezMultipleAttachmentsFromInv"; 
        case DetachAttachmentIntoInvType: 
            return "DetachAttachmentIntoInv"; 
        case CreateNewOutfitAttachmentsType: 
            return "CreateNewOutfitAttachments"; 
        case UserInfoRequestType: 
            return "UserInfoRequest"; 
        case UserInfoReplyType: 
            return "UserInfoReply"; 
        case UpdateUserInfoType: 
            return "UpdateUserInfo"; 
        case ParcelRenameType: 
            return "ParcelRename"; 
        case InitiateDownloadType: 
            return "InitiateDownload"; 
        case SystemMessageType: 
            return "SystemMessage"; 
        case MapLayerRequestType: 
            return "MapLayerRequest"; 
        case MapLayerReplyType: 
            return "MapLayerReply"; 
        case MapBlockRequestType: 
            return "MapBlockRequest"; 
        case MapNameRequestType: 
            return "MapNameRequest"; 
        case MapBlockReplyType: 
            return "MapBlockReply"; 
        case MapItemRequestType: 
            return "MapItemRequest"; 
        case MapItemReplyType: 
            return "MapItemReply"; 
        case SendPostcardType: 
            return "SendPostcard"; 
        case RpcChannelRequestType: 
            return "RpcChannelRequest"; 
        case RpcChannelReplyType: 
            return "RpcChannelReply"; 
        case RpcScriptRequestInboundType: 
            return "RpcScriptRequestInbound"; 
        case RpcScriptRequestInboundForwardType: 
            return "RpcScriptRequestInboundForward"; 
        case RpcScriptReplyInboundType: 
            return "RpcScriptReplyInbound"; 
        case ScriptMailRegistrationType: 
            return "ScriptMailRegistration"; 
        case ParcelMediaCommandMessageType: 
            return "ParcelMediaCommandMessage"; 
        case ParcelMediaUpdateType: 
            return "ParcelMediaUpdate"; 
        case LandStatRequestType: 
            return "LandStatRequest"; 
        case LandStatReplyType: 
            return "LandStatReply"; 
        case ErrorType: 
            return "Error"; 
        case ObjectIncludeInSearchType: 
            return "ObjectIncludeInSearch"; 
        case RezRestoreToWorldType: 
            return "RezRestoreToWorld"; 
    }
    return 0; 
}
