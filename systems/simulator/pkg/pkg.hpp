#ifndef QTSL_UDP_PKG_H
#define QTSL_UDP_PKG_H
#include <QVector>
#include <QtEndian>
#include <QDataStream>
#include <QBuffer>
#include "lltypes.hpp"
namespace qtsl{
namespace udp{

enum IdByte{
    Low,
    High,
    Medium,
    Fixed
};

enum MessageType{
    None = 0,
    TestMessageType = 4294901761U,
    PacketAckType = 4294967291U,
    OpenCircuitType = 4294967292U,
    CloseCircuitType = 4294967293U,
    StartPingCheckType = 1U,
    CompletePingCheckType = 2U,
    AddCircuitCodeType = 4294901762U,
    UseCircuitCodeType = 4294901763U,
    NeighborListType = 3U,
    AvatarTextureUpdateType = 4294901764U,
    SimulatorMapUpdateType = 4294901765U,
    SimulatorSetMapType = 4294901766U,
    SubscribeLoadType = 4294901767U,
    UnsubscribeLoadType = 4294901768U,
    SimulatorReadyType = 4294901769U,
    TelehubInfoType = 4294901770U,
    SimulatorPresentAtLocationType = 4294901771U,
    SimulatorLoadType = 4294901772U,
    SimulatorShutdownRequestType = 4294901773U,
    RegionPresenceRequestByRegionIDType = 4294901774U,
    RegionPresenceRequestByHandleType = 4294901775U,
    RegionPresenceResponseType = 4294901776U,
    UpdateSimulatorType = 4294901777U,
    LogDwellTimeType = 4294901778U,
    FeatureDisabledType = 4294901779U,
    LogFailedMoneyTransactionType = 4294901780U,
    UserReportInternalType = 4294901781U,
    SetSimStatusInDatabaseType = 4294901782U,
    SetSimPresenceInDatabaseType = 4294901783U,
    EconomyDataRequestType = 4294901784U,
    EconomyDataType = 4294901785U,
    AvatarPickerRequestType = 4294901786U,
    AvatarPickerRequestBackendType = 4294901787U,
    AvatarPickerReplyType = 4294901788U,
    PlacesQueryType = 4294901789U,
    PlacesReplyType = 4294901790U,
    DirFindQueryType = 4294901791U,
    DirFindQueryBackendType = 4294901792U,
    DirPlacesQueryType = 4294901793U,
    DirPlacesQueryBackendType = 4294901794U,
    DirPlacesReplyType = 4294901795U,
    DirPeopleReplyType = 4294901796U,
    DirEventsReplyType = 4294901797U,
    DirGroupsReplyType = 4294901798U,
    DirClassifiedQueryType = 4294901799U,
    DirClassifiedQueryBackendType = 4294901800U,
    DirClassifiedReplyType = 4294901801U,
    AvatarClassifiedReplyType = 4294901802U,
    ClassifiedInfoRequestType = 4294901803U,
    ClassifiedInfoReplyType = 4294901804U,
    ClassifiedInfoUpdateType = 4294901805U,
    ClassifiedDeleteType = 4294901806U,
    ClassifiedGodDeleteType = 4294901807U,
    DirLandQueryType = 4294901808U,
    DirLandQueryBackendType = 4294901809U,
    DirLandReplyType = 4294901810U,
    DirPopularQueryType = 4294901811U,
    DirPopularQueryBackendType = 4294901812U,
    DirPopularReplyType = 4294901813U,
    ParcelInfoRequestType = 4294901814U,
    ParcelInfoReplyType = 4294901815U,
    ParcelObjectOwnersRequestType = 4294901816U,
    ParcelObjectOwnersReplyType = 4294901817U,
    GroupNoticesListRequestType = 4294901818U,
    GroupNoticesListReplyType = 4294901819U,
    GroupNoticeRequestType = 4294901820U,
    GroupNoticeAddType = 4294901821U,
    TeleportRequestType = 4294901822U,
    TeleportLocationRequestType = 4294901823U,
    TeleportLocalType = 4294901824U,
    TeleportLandmarkRequestType = 4294901825U,
    TeleportProgressType = 4294901826U,
    DataHomeLocationRequestType = 4294901827U,
    DataHomeLocationReplyType = 4294901828U,
    TeleportFinishType = 4294901829U,
    StartLureType = 4294901830U,
    TeleportLureRequestType = 4294901831U,
    TeleportCancelType = 4294901832U,
    TeleportStartType = 4294901833U,
    TeleportFailedType = 4294901834U,
    UndoType = 4294901835U,
    RedoType = 4294901836U,
    UndoLandType = 4294901837U,
    AgentPauseType = 4294901838U,
    AgentResumeType = 4294901839U,
    AgentUpdateType = 4U,
    ChatFromViewerType = 4294901840U,
    AgentThrottleType = 4294901841U,
    AgentFOVType = 4294901842U,
    AgentHeightWidthType = 4294901843U,
    AgentSetAppearanceType = 4294901844U,
    AgentAnimationType = 5U,
    AgentRequestSitType = 6U,
    AgentSitType = 7U,
    AgentQuitCopyType = 4294901845U,
    RequestImageType = 8U,
    ImageNotInDatabaseType = 4294901846U,
    RebakeAvatarTexturesType = 4294901847U,
    SetAlwaysRunType = 4294901848U,
    ObjectAddType = 65281U,
    ObjectDeleteType = 4294901849U,
    ObjectDuplicateType = 4294901850U,
    ObjectDuplicateOnRayType = 4294901851U,
    MultipleObjectUpdateType = 65282U,
    RequestMultipleObjectsType = 65283U,
    ObjectPositionType = 65284U,
    ObjectScaleType = 4294901852U,
    ObjectRotationType = 4294901853U,
    ObjectFlagUpdateType = 4294901854U,
    ObjectClickActionType = 4294901855U,
    ObjectImageType = 4294901856U,
    ObjectMaterialType = 4294901857U,
    ObjectShapeType = 4294901858U,
    ObjectExtraParamsType = 4294901859U,
    ObjectOwnerType = 4294901860U,
    ObjectGroupType = 4294901861U,
    ObjectBuyType = 4294901862U,
    BuyObjectInventoryType = 4294901863U,
    DerezContainerType = 4294901864U,
    ObjectPermissionsType = 4294901865U,
    ObjectSaleInfoType = 4294901866U,
    ObjectNameType = 4294901867U,
    ObjectDescriptionType = 4294901868U,
    ObjectCategoryType = 4294901869U,
    ObjectSelectType = 4294901870U,
    ObjectDeselectType = 4294901871U,
    ObjectAttachType = 4294901872U,
    ObjectDetachType = 4294901873U,
    ObjectDropType = 4294901874U,
    ObjectLinkType = 4294901875U,
    ObjectDelinkType = 4294901876U,
    ObjectGrabType = 4294901877U,
    ObjectGrabUpdateType = 4294901878U,
    ObjectDeGrabType = 4294901879U,
    ObjectSpinStartType = 4294901880U,
    ObjectSpinUpdateType = 4294901881U,
    ObjectSpinStopType = 4294901882U,
    ObjectExportSelectedType = 4294901883U,
    ModifyLandType = 4294901884U,
    VelocityInterpolateOnType = 4294901885U,
    VelocityInterpolateOffType = 4294901886U,
    StateSaveType = 4294901887U,
    ReportAutosaveCrashType = 4294901888U,
    SimWideDeletesType = 4294901889U,
    RequestObjectPropertiesFamilyType = 65285U,
    TrackAgentType = 4294901890U,
    ViewerStatsType = 4294901891U,
    ScriptAnswerYesType = 4294901892U,
    UserReportType = 4294901893U,
    AlertMessageType = 4294901894U,
    AgentAlertMessageType = 4294901895U,
    MeanCollisionAlertType = 4294901896U,
    ViewerFrozenMessageType = 4294901897U,
    HealthMessageType = 4294901898U,
    ChatFromSimulatorType = 4294901899U,
    SimStatsType = 4294901900U,
    RequestRegionInfoType = 4294901901U,
    RegionInfoType = 4294901902U,
    GodUpdateRegionInfoType = 4294901903U,
    NearestLandingRegionRequestType = 4294901904U,
    NearestLandingRegionReplyType = 4294901905U,
    NearestLandingRegionUpdatedType = 4294901906U,
    TeleportLandingStatusChangedType = 4294901907U,
    RegionHandshakeType = 4294901908U,
    RegionHandshakeReplyType = 4294901909U,
    CoarseLocationUpdateType = 65286U,
    ImageDataType = 9U,
    ImagePacketType = 10U,
    LayerDataType = 11U,
    ObjectUpdateType = 12U,
    ObjectUpdateCompressedType = 13U,
    ObjectUpdateCachedType = 14U,
    ImprovedTerseObjectUpdateType = 15U,
    KillObjectType = 16U,
    CrossedRegionType = 65287U,
    SimulatorViewerTimeMessageType = 4294901910U,
    EnableSimulatorType = 4294901911U,
    DisableSimulatorType = 4294901912U,
    ConfirmEnableSimulatorType = 65288U,
    TransferRequestType = 4294901913U,
    TransferInfoType = 4294901914U,
    TransferPacketType = 17U,
    TransferAbortType = 4294901915U,
    RequestXferType = 4294901916U,
    SendXferPacketType = 18U,
    ConfirmXferPacketType = 19U,
    AbortXferType = 4294901917U,
    AvatarAnimationType = 20U,
    AvatarAppearanceType = 4294901918U,
    AvatarSitResponseType = 21U,
    SetFollowCamPropertiesType = 4294901919U,
    ClearFollowCamPropertiesType = 4294901920U,
    CameraConstraintType = 22U,
    ObjectPropertiesType = 65289U,
    ObjectPropertiesFamilyType = 65290U,
    RequestPayPriceType = 4294901921U,
    PayPriceReplyType = 4294901922U,
    KickUserType = 4294901923U,
    KickUserAckType = 4294901924U,
    GodKickUserType = 4294901925U,
    SystemKickUserType = 4294901926U,
    EjectUserType = 4294901927U,
    FreezeUserType = 4294901928U,
    AvatarPropertiesRequestType = 4294901929U,
    AvatarPropertiesRequestBackendType = 4294901930U,
    AvatarPropertiesReplyType = 4294901931U,
    AvatarInterestsReplyType = 4294901932U,
    AvatarGroupsReplyType = 4294901933U,
    AvatarPropertiesUpdateType = 4294901934U,
    AvatarInterestsUpdateType = 4294901935U,
    AvatarNotesReplyType = 4294901936U,
    AvatarNotesUpdateType = 4294901937U,
    AvatarPicksReplyType = 4294901938U,
    EventInfoRequestType = 4294901939U,
    EventInfoReplyType = 4294901940U,
    EventNotificationAddRequestType = 4294901941U,
    EventNotificationRemoveRequestType = 4294901942U,
    EventGodDeleteType = 4294901943U,
    PickInfoReplyType = 4294901944U,
    PickInfoUpdateType = 4294901945U,
    PickDeleteType = 4294901946U,
    PickGodDeleteType = 4294901947U,
    ScriptQuestionType = 4294901948U,
    ScriptControlChangeType = 4294901949U,
    ScriptDialogType = 4294901950U,
    ScriptDialogReplyType = 4294901951U,
    ForceScriptControlReleaseType = 4294901952U,
    RevokePermissionsType = 4294901953U,
    LoadURLType = 4294901954U,
    ScriptTeleportRequestType = 4294901955U,
    ParcelOverlayType = 4294901956U,
    ParcelPropertiesRequestType = 65291U,
    ParcelPropertiesRequestByIDType = 4294901957U,
    ParcelPropertiesType = 23U,
    ParcelPropertiesUpdateType = 4294901958U,
    ParcelReturnObjectsType = 4294901959U,
    ParcelSetOtherCleanTimeType = 4294901960U,
    ParcelDisableObjectsType = 4294901961U,
    ParcelSelectObjectsType = 4294901962U,
    EstateCovenantRequestType = 4294901963U,
    EstateCovenantReplyType = 4294901964U,
    ForceObjectSelectType = 4294901965U,
    ParcelBuyPassType = 4294901966U,
    ParcelDeedToGroupType = 4294901967U,
    ParcelReclaimType = 4294901968U,
    ParcelClaimType = 4294901969U,
    ParcelJoinType = 4294901970U,
    ParcelDivideType = 4294901971U,
    ParcelReleaseType = 4294901972U,
    ParcelBuyType = 4294901973U,
    ParcelGodForceOwnerType = 4294901974U,
    ParcelAccessListRequestType = 4294901975U,
    ParcelAccessListReplyType = 4294901976U,
    ParcelAccessListUpdateType = 4294901977U,
    ParcelDwellRequestType = 4294901978U,
    ParcelDwellReplyType = 4294901979U,
    RequestParcelTransferType = 4294901980U,
    UpdateParcelType = 4294901981U,
    RemoveParcelType = 4294901982U,
    MergeParcelType = 4294901983U,
    LogParcelChangesType = 4294901984U,
    CheckParcelSalesType = 4294901985U,
    ParcelSalesType = 4294901986U,
    ParcelGodMarkAsContentType = 4294901987U,
    ViewerStartAuctionType = 4294901988U,
    StartAuctionType = 4294901989U,
    ConfirmAuctionStartType = 4294901990U,
    CompleteAuctionType = 4294901991U,
    CancelAuctionType = 4294901992U,
    CheckParcelAuctionsType = 4294901993U,
    ParcelAuctionsType = 4294901994U,
    UUIDNameRequestType = 4294901995U,
    UUIDNameReplyType = 4294901996U,
    UUIDGroupNameRequestType = 4294901997U,
    UUIDGroupNameReplyType = 4294901998U,
    ChatPassType = 4294901999U,
    EdgeDataPacketType = 24U,
    SimStatusType = 65292U,
    ChildAgentUpdateType = 25U,
    ChildAgentAliveType = 26U,
    ChildAgentPositionUpdateType = 27U,
    ChildAgentDyingType = 4294902000U,
    ChildAgentUnknownType = 4294902001U,
    AtomicPassObjectType = 28U,
    KillChildAgentsType = 4294902002U,
    GetScriptRunningType = 4294902003U,
    ScriptRunningReplyType = 4294902004U,
    SetScriptRunningType = 4294902005U,
    ScriptResetType = 4294902006U,
    ScriptSensorRequestType = 4294902007U,
    ScriptSensorReplyType = 4294902008U,
    CompleteAgentMovementType = 4294902009U,
    AgentMovementCompleteType = 4294902010U,
    DataServerLogoutType = 4294902011U,
    LogoutRequestType = 4294902012U,
    LogoutReplyType = 4294902013U,
    ImprovedInstantMessageType = 4294902014U,
    RetrieveInstantMessagesType = 4294902015U,
    FindAgentType = 4294902016U,
    RequestGodlikePowersType = 4294902017U,
    GrantGodlikePowersType = 4294902018U,
    GodlikeMessageType = 4294902019U,
    EstateOwnerMessageType = 4294902020U,
    GenericMessageType = 4294902021U,
    MuteListRequestType = 4294902022U,
    UpdateMuteListEntryType = 4294902023U,
    RemoveMuteListEntryType = 4294902024U,
    CopyInventoryFromNotecardType = 4294902025U,
    UpdateInventoryItemType = 4294902026U,
    UpdateCreateInventoryItemType = 4294902027U,
    MoveInventoryItemType = 4294902028U,
    CopyInventoryItemType = 4294902029U,
    RemoveInventoryItemType = 4294902030U,
    ChangeInventoryItemFlagsType = 4294902031U,
    SaveAssetIntoInventoryType = 4294902032U,
    CreateInventoryFolderType = 4294902033U,
    UpdateInventoryFolderType = 4294902034U,
    MoveInventoryFolderType = 4294902035U,
    RemoveInventoryFolderType = 4294902036U,
    FetchInventoryDescendentsType = 4294902037U,
    InventoryDescendentsType = 4294902038U,
    FetchInventoryType = 4294902039U,
    FetchInventoryReplyType = 4294902040U,
    BulkUpdateInventoryType = 4294902041U,
    RequestInventoryAssetType = 4294902042U,
    InventoryAssetResponseType = 4294902043U,
    RemoveInventoryObjectsType = 4294902044U,
    PurgeInventoryDescendentsType = 4294902045U,
    UpdateTaskInventoryType = 4294902046U,
    RemoveTaskInventoryType = 4294902047U,
    MoveTaskInventoryType = 4294902048U,
    RequestTaskInventoryType = 4294902049U,
    ReplyTaskInventoryType = 4294902050U,
    DeRezObjectType = 4294902051U,
    DeRezAckType = 4294902052U,
    RezObjectType = 4294902053U,
    RezObjectFromNotecardType = 4294902054U,
    TransferInventoryType = 4294902055U,
    TransferInventoryAckType = 4294902056U,
    AcceptFriendshipType = 4294902057U,
    DeclineFriendshipType = 4294902058U,
    FormFriendshipType = 4294902059U,
    TerminateFriendshipType = 4294902060U,
    OfferCallingCardType = 4294902061U,
    AcceptCallingCardType = 4294902062U,
    DeclineCallingCardType = 4294902063U,
    RezScriptType = 4294902064U,
    CreateInventoryItemType = 4294902065U,
    CreateLandmarkForEventType = 4294902066U,
    EventLocationRequestType = 4294902067U,
    EventLocationReplyType = 4294902068U,
    RegionHandleRequestType = 4294902069U,
    RegionIDAndHandleReplyType = 4294902070U,
    MoneyTransferRequestType = 4294902071U,
    MoneyTransferBackendType = 4294902072U,
    MoneyBalanceRequestType = 4294902073U,
    MoneyBalanceReplyType = 4294902074U,
    RoutedMoneyBalanceReplyType = 4294902075U,
    ActivateGesturesType = 4294902076U,
    DeactivateGesturesType = 4294902077U,
    MuteListUpdateType = 4294902078U,
    UseCachedMuteListType = 4294902079U,
    GrantUserRightsType = 4294902080U,
    ChangeUserRightsType = 4294902081U,
    OnlineNotificationType = 4294902082U,
    OfflineNotificationType = 4294902083U,
    SetStartLocationRequestType = 4294902084U,
    SetStartLocationType = 4294902085U,
    NetTestType = 4294902086U,
    SetCPURatioType = 4294902087U,
    SimCrashedType = 4294902088U,
    NameValuePairType = 4294902089U,
    RemoveNameValuePairType = 4294902090U,
    UpdateAttachmentType = 4294902091U,
    RemoveAttachmentType = 4294902092U,
    SoundTriggerType = 29U,
    AttachedSoundType = 65293U,
    AttachedSoundGainChangeType = 65294U,
    PreloadSoundType = 65295U,
    AssetUploadRequestType = 4294902093U,
    AssetUploadCompleteType = 4294902094U,
    EmailMessageRequestType = 4294902095U,
    EmailMessageReplyType = 4294902096U,
    InternalScriptMailType = 65296U,
    ScriptDataRequestType = 4294902097U,
    ScriptDataReplyType = 4294902098U,
    CreateGroupRequestType = 4294902099U,
    CreateGroupReplyType = 4294902100U,
    UpdateGroupInfoType = 4294902101U,
    GroupRoleChangesType = 4294902102U,
    JoinGroupRequestType = 4294902103U,
    JoinGroupReplyType = 4294902104U,
    EjectGroupMemberRequestType = 4294902105U,
    EjectGroupMemberReplyType = 4294902106U,
    LeaveGroupRequestType = 4294902107U,
    LeaveGroupReplyType = 4294902108U,
    InviteGroupRequestType = 4294902109U,
    InviteGroupResponseType = 4294902110U,
    GroupProfileRequestType = 4294902111U,
    GroupProfileReplyType = 4294902112U,
    GroupAccountSummaryRequestType = 4294902113U,
    GroupAccountSummaryReplyType = 4294902114U,
    GroupAccountDetailsRequestType = 4294902115U,
    GroupAccountDetailsReplyType = 4294902116U,
    GroupAccountTransactionsRequestType = 4294902117U,
    GroupAccountTransactionsReplyType = 4294902118U,
    GroupActiveProposalsRequestType = 4294902119U,
    GroupActiveProposalItemReplyType = 4294902120U,
    GroupVoteHistoryRequestType = 4294902121U,
    GroupVoteHistoryItemReplyType = 4294902122U,
    StartGroupProposalType = 4294902123U,
    GroupProposalBallotType = 4294902124U,
    TallyVotesType = 4294902125U,
    GroupMembersRequestType = 4294902126U,
    GroupMembersReplyType = 4294902127U,
    ActivateGroupType = 4294902128U,
    SetGroupContributionType = 4294902129U,
    SetGroupAcceptNoticesType = 4294902130U,
    GroupRoleDataRequestType = 4294902131U,
    GroupRoleDataReplyType = 4294902132U,
    GroupRoleMembersRequestType = 4294902133U,
    GroupRoleMembersReplyType = 4294902134U,
    GroupTitlesRequestType = 4294902135U,
    GroupTitlesReplyType = 4294902136U,
    GroupTitleUpdateType = 4294902137U,
    GroupRoleUpdateType = 4294902138U,
    LiveHelpGroupRequestType = 4294902139U,
    LiveHelpGroupReplyType = 4294902140U,
    AgentWearablesRequestType = 4294902141U,
    AgentWearablesUpdateType = 4294902142U,
    AgentIsNowWearingType = 4294902143U,
    AgentCachedTextureType = 4294902144U,
    AgentCachedTextureResponseType = 4294902145U,
    AgentDataUpdateRequestType = 4294902146U,
    AgentDataUpdateType = 4294902147U,
    GroupDataUpdateType = 4294902148U,
    AgentGroupDataUpdateType = 4294902149U,
    AgentDropGroupType = 4294902150U,
    LogTextMessageType = 4294902151U,
    ViewerEffectType = 65297U,
    CreateTrustedCircuitType = 4294902152U,
    DenyTrustedCircuitType = 4294902153U,
    RequestTrustedCircuitType = 4294902154U,
    RezSingleAttachmentFromInvType = 4294902155U,
    RezMultipleAttachmentsFromInvType = 4294902156U,
    DetachAttachmentIntoInvType = 4294902157U,
    CreateNewOutfitAttachmentsType = 4294902158U,
    UserInfoRequestType = 4294902159U,
    UserInfoReplyType = 4294902160U,
    UpdateUserInfoType = 4294902161U,
    ParcelRenameType = 4294902162U,
    InitiateDownloadType = 4294902163U,
    SystemMessageType = 4294902164U,
    MapLayerRequestType = 4294902165U,
    MapLayerReplyType = 4294902166U,
    MapBlockRequestType = 4294902167U,
    MapNameRequestType = 4294902168U,
    MapBlockReplyType = 4294902169U,
    MapItemRequestType = 4294902170U,
    MapItemReplyType = 4294902171U,
    SendPostcardType = 4294902172U,
    RpcChannelRequestType = 4294902173U,
    RpcChannelReplyType = 4294902174U,
    RpcScriptRequestInboundType = 4294902175U,
    RpcScriptRequestInboundForwardType = 4294902176U,
    RpcScriptReplyInboundType = 4294902177U,
    ScriptMailRegistrationType = 4294902178U,
    ParcelMediaCommandMessageType = 4294902179U,
    ParcelMediaUpdateType = 4294902180U,
    LandStatRequestType = 4294902181U,
    LandStatReplyType = 4294902182U,
    ErrorType = 4294902183U,
    ObjectIncludeInSearchType = 4294902184U,
    RezRestoreToWorldType = 4294902185U
};

struct UdpMessage{
    MessageType type;
};

struct TestMessageMessage : UdpMessage {
    static const quint32 id=1U;
    static const IdByte byte=Low;

    TestMessageMessage ();

    struct TestBlock1Block {
        lltypes::U32 Test1;
    };
    struct NeighborBlockBlock {
        lltypes::U32 Test0;
        lltypes::U32 Test1;
        lltypes::U32 Test2;
    };
    TestBlock1Block TestBlock1;
    QVector<NeighborBlockBlock> NeighborBlock;
};

QDataStream &operator<<(QDataStream & out, const TestMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  TestMessageMessage & o);

struct PacketAckMessage : UdpMessage {
    static const quint32 id=4294967291U;
    static const IdByte byte=Fixed;

    PacketAckMessage ();

    struct PacketsBlock {
        lltypes::U32 ID;
    };
    QVector<PacketsBlock> Packets;
};

QDataStream &operator<<(QDataStream & out, const PacketAckMessage & o);
QDataStream &operator>>(QDataStream & in,  PacketAckMessage & o);

struct OpenCircuitMessage : UdpMessage {
    static const quint32 id=4294967292U;
    static const IdByte byte=Fixed;

    OpenCircuitMessage ();

    struct CircuitInfoBlock {
        lltypes::IPADDR IP;
        lltypes::IPPORT Port;
    };
    CircuitInfoBlock CircuitInfo;
};

QDataStream &operator<<(QDataStream & out, const OpenCircuitMessage & o);
QDataStream &operator>>(QDataStream & in,  OpenCircuitMessage & o);

struct CloseCircuitMessage : UdpMessage {
    static const quint32 id=4294967293U;
    static const IdByte byte=Fixed;

    CloseCircuitMessage ();

};

QDataStream &operator<<(QDataStream & out, const CloseCircuitMessage & o);
QDataStream &operator>>(QDataStream & in,  CloseCircuitMessage & o);

struct StartPingCheckMessage : UdpMessage {
    static const quint32 id=1U;
    static const IdByte byte=High;

    StartPingCheckMessage ();

    struct PingIDBlock {
        lltypes::U8 PingID;
        lltypes::U32 OldestUnacked;
    };
    PingIDBlock PingID;
};

QDataStream &operator<<(QDataStream & out, const StartPingCheckMessage & o);
QDataStream &operator>>(QDataStream & in,  StartPingCheckMessage & o);

struct CompletePingCheckMessage : UdpMessage {
    static const quint32 id=2U;
    static const IdByte byte=High;

    CompletePingCheckMessage ();

    struct PingIDBlock {
        lltypes::U8 PingID;
    };
    PingIDBlock PingID;
};

QDataStream &operator<<(QDataStream & out, const CompletePingCheckMessage & o);
QDataStream &operator>>(QDataStream & in,  CompletePingCheckMessage & o);

struct AddCircuitCodeMessage : UdpMessage {
    static const quint32 id=2U;
    static const IdByte byte=Low;

    AddCircuitCodeMessage ();

    struct CircuitCodeBlock {
        lltypes::U32 Code;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID AgentID;
    };
    CircuitCodeBlock CircuitCode;
};

QDataStream &operator<<(QDataStream & out, const AddCircuitCodeMessage & o);
QDataStream &operator>>(QDataStream & in,  AddCircuitCodeMessage & o);

struct UseCircuitCodeMessage : UdpMessage {
    static const quint32 id=3U;
    static const IdByte byte=Low;

    UseCircuitCodeMessage ();

    struct CircuitCodeBlock {
        lltypes::U32 Code;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID ID;
    };
    CircuitCodeBlock CircuitCode;
};

QDataStream &operator<<(QDataStream & out, const UseCircuitCodeMessage & o);
QDataStream &operator>>(QDataStream & in,  UseCircuitCodeMessage & o);

struct NeighborListMessage : UdpMessage {
    static const quint32 id=3U;
    static const IdByte byte=High;

    NeighborListMessage ();

    struct NeighborBlockBlock {
        lltypes::IPADDR IP;
        lltypes::IPPORT Port;
        lltypes::IPADDR PublicIP;
        lltypes::IPPORT PublicPort;
        lltypes::LLUUID RegionID;
        lltypes::Variable<1> Name;
        lltypes::U8 SimAccess;
    };
    QVector<NeighborBlockBlock> NeighborBlock;
};

QDataStream &operator<<(QDataStream & out, const NeighborListMessage & o);
QDataStream &operator>>(QDataStream & in,  NeighborListMessage & o);

struct AvatarTextureUpdateMessage : UdpMessage {
    static const quint32 id=4U;
    static const IdByte byte=Low;

    AvatarTextureUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::BOOL TexturesChanged;
    };
    struct WearableDataBlock {
        lltypes::LLUUID CacheID;
        lltypes::U8 TextureIndex;
        lltypes::Variable<1> HostName;
    };
    struct TextureDataBlock {
        lltypes::LLUUID TextureID;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
    QVector<TextureDataBlock> TextureData;
};

QDataStream &operator<<(QDataStream & out, const AvatarTextureUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarTextureUpdateMessage & o);

struct SimulatorMapUpdateMessage : UdpMessage {
    static const quint32 id=5U;
    static const IdByte byte=Low;

    SimulatorMapUpdateMessage ();

    struct MapDataBlock {
        lltypes::U32 Flags;
    };
    MapDataBlock MapData;
};

QDataStream &operator<<(QDataStream & out, const SimulatorMapUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorMapUpdateMessage & o);

struct SimulatorSetMapMessage : UdpMessage {
    static const quint32 id=6U;
    static const IdByte byte=Low;

    SimulatorSetMapMessage ();

    struct MapDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::S32 Type;
        lltypes::LLUUID MapImage;
    };
    MapDataBlock MapData;
};

QDataStream &operator<<(QDataStream & out, const SimulatorSetMapMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorSetMapMessage & o);

struct SubscribeLoadMessage : UdpMessage {
    static const quint32 id=7U;
    static const IdByte byte=Low;

    SubscribeLoadMessage ();

};

QDataStream &operator<<(QDataStream & out, const SubscribeLoadMessage & o);
QDataStream &operator>>(QDataStream & in,  SubscribeLoadMessage & o);

struct UnsubscribeLoadMessage : UdpMessage {
    static const quint32 id=8U;
    static const IdByte byte=Low;

    UnsubscribeLoadMessage ();

};

QDataStream &operator<<(QDataStream & out, const UnsubscribeLoadMessage & o);
QDataStream &operator>>(QDataStream & in,  UnsubscribeLoadMessage & o);

struct SimulatorReadyMessage : UdpMessage {
    static const quint32 id=9U;
    static const IdByte byte=Low;

    SimulatorReadyMessage ();

    struct SimulatorBlockBlock {
        lltypes::Variable<1> SimName;
        lltypes::U8 SimAccess;
        lltypes::U32 RegionFlags;
        lltypes::LLUUID RegionID;
        lltypes::U32 EstateID;
        lltypes::U32 ParentEstateID;
    };
    struct TelehubBlockBlock {
        lltypes::BOOL HasTelehub;
        lltypes::LLVector3 TelehubPos;
    };
    SimulatorBlockBlock SimulatorBlock;
    TelehubBlockBlock TelehubBlock;
};

QDataStream &operator<<(QDataStream & out, const SimulatorReadyMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorReadyMessage & o);

struct TelehubInfoMessage : UdpMessage {
    static const quint32 id=10U;
    static const IdByte byte=Low;

    TelehubInfoMessage ();

    struct TelehubBlockBlock {
        lltypes::LLUUID ObjectID;
        lltypes::Variable<1> ObjectName;
        lltypes::LLVector3 TelehubPos;
        lltypes::LLQuaternion TelehubRot;
    };
    struct SpawnPointBlockBlock {
        lltypes::LLVector3 SpawnPointPos;
    };
    TelehubBlockBlock TelehubBlock;
    QVector<SpawnPointBlockBlock> SpawnPointBlock;
};

QDataStream &operator<<(QDataStream & out, const TelehubInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  TelehubInfoMessage & o);

struct SimulatorPresentAtLocationMessage : UdpMessage {
    static const quint32 id=11U;
    static const IdByte byte=Low;

    SimulatorPresentAtLocationMessage ();

    struct SimulatorPublicHostBlockBlock {
        lltypes::IPPORT Port;
        lltypes::IPADDR SimulatorIP;
        lltypes::U32 GridX;
        lltypes::U32 GridY;
    };
    struct NeighborBlockBlock {
        lltypes::IPADDR IP;
        lltypes::IPPORT Port;
    };
    struct SimulatorBlockBlock {
        lltypes::Variable<1> SimName;
        lltypes::U8 SimAccess;
        lltypes::U32 RegionFlags;
        lltypes::LLUUID RegionID;
        lltypes::U32 EstateID;
        lltypes::U32 ParentEstateID;
    };
    struct TelehubBlockBlock {
        lltypes::BOOL HasTelehub;
        lltypes::LLVector3 TelehubPos;
    };
    SimulatorPublicHostBlockBlock SimulatorPublicHostBlock;
    QVector<NeighborBlockBlock> NeighborBlock;
    SimulatorBlockBlock SimulatorBlock;
    QVector<TelehubBlockBlock> TelehubBlock;
};

QDataStream &operator<<(QDataStream & out, const SimulatorPresentAtLocationMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorPresentAtLocationMessage & o);

struct SimulatorLoadMessage : UdpMessage {
    static const quint32 id=12U;
    static const IdByte byte=Low;

    SimulatorLoadMessage ();

    struct SimulatorLoadBlock {
        lltypes::F32 TimeDilation;
        lltypes::S32 AgentCount;
        lltypes::BOOL CanAcceptAgents;
    };
    struct AgentListBlock {
        lltypes::U32 CircuitCode;
        lltypes::U8 X;
        lltypes::U8 Y;
    };
    SimulatorLoadBlock SimulatorLoad;
    QVector<AgentListBlock> AgentList;
};

QDataStream &operator<<(QDataStream & out, const SimulatorLoadMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorLoadMessage & o);

struct SimulatorShutdownRequestMessage : UdpMessage {
    static const quint32 id=13U;
    static const IdByte byte=Low;

    SimulatorShutdownRequestMessage ();

};

QDataStream &operator<<(QDataStream & out, const SimulatorShutdownRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorShutdownRequestMessage & o);

struct RegionPresenceRequestByRegionIDMessage : UdpMessage {
    static const quint32 id=14U;
    static const IdByte byte=Low;

    RegionPresenceRequestByRegionIDMessage ();

    struct RegionDataBlock {
        lltypes::LLUUID RegionID;
    };
    QVector<RegionDataBlock> RegionData;
};

QDataStream &operator<<(QDataStream & out, const RegionPresenceRequestByRegionIDMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionPresenceRequestByRegionIDMessage & o);

struct RegionPresenceRequestByHandleMessage : UdpMessage {
    static const quint32 id=15U;
    static const IdByte byte=Low;

    RegionPresenceRequestByHandleMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    QVector<RegionDataBlock> RegionData;
};

QDataStream &operator<<(QDataStream & out, const RegionPresenceRequestByHandleMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionPresenceRequestByHandleMessage & o);

struct RegionPresenceResponseMessage : UdpMessage {
    static const quint32 id=16U;
    static const IdByte byte=Low;

    RegionPresenceResponseMessage ();

    struct RegionDataBlock {
        lltypes::LLUUID RegionID;
        lltypes::U64 RegionHandle;
        lltypes::IPADDR InternalRegionIP;
        lltypes::IPADDR ExternalRegionIP;
        lltypes::IPPORT RegionPort;
        lltypes::F64 ValidUntil;
        lltypes::Variable<1> Message;
    };
    QVector<RegionDataBlock> RegionData;
};

QDataStream &operator<<(QDataStream & out, const RegionPresenceResponseMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionPresenceResponseMessage & o);

struct UpdateSimulatorMessage : UdpMessage {
    static const quint32 id=17U;
    static const IdByte byte=Low;

    UpdateSimulatorMessage ();

    struct SimulatorInfoBlock {
        lltypes::LLUUID RegionID;
        lltypes::Variable<1> SimName;
        lltypes::U32 EstateID;
        lltypes::U8 SimAccess;
    };
    SimulatorInfoBlock SimulatorInfo;
};

QDataStream &operator<<(QDataStream & out, const UpdateSimulatorMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateSimulatorMessage & o);

struct LogDwellTimeMessage : UdpMessage {
    static const quint32 id=18U;
    static const IdByte byte=Low;

    LogDwellTimeMessage ();

    struct DwellInfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::F32 Duration;
        lltypes::Variable<1> SimName;
        lltypes::U32 RegionX;
        lltypes::U32 RegionY;
        lltypes::U8 AvgAgentsInView;
        lltypes::U8 AvgViewerFPS;
    };
    DwellInfoBlock DwellInfo;
};

QDataStream &operator<<(QDataStream & out, const LogDwellTimeMessage & o);
QDataStream &operator>>(QDataStream & in,  LogDwellTimeMessage & o);

struct FeatureDisabledMessage : UdpMessage {
    static const quint32 id=19U;
    static const IdByte byte=Low;

    FeatureDisabledMessage ();

    struct FailureInfoBlock {
        lltypes::Variable<1> ErrorMessage;
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TransactionID;
    };
    FailureInfoBlock FailureInfo;
};

QDataStream &operator<<(QDataStream & out, const FeatureDisabledMessage & o);
QDataStream &operator>>(QDataStream & in,  FeatureDisabledMessage & o);

struct LogFailedMoneyTransactionMessage : UdpMessage {
    static const quint32 id=20U;
    static const IdByte byte=Low;

    LogFailedMoneyTransactionMessage ();

    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::U32 TransactionTime;
        lltypes::S32 TransactionType;
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
        lltypes::U8 Flags;
        lltypes::S32 Amount;
        lltypes::IPADDR SimulatorIP;
        lltypes::U32 GridX;
        lltypes::U32 GridY;
        lltypes::U8 FailureType;
    };
    TransactionDataBlock TransactionData;
};

QDataStream &operator<<(QDataStream & out, const LogFailedMoneyTransactionMessage & o);
QDataStream &operator>>(QDataStream & in,  LogFailedMoneyTransactionMessage & o);

struct UserReportInternalMessage : UdpMessage {
    static const quint32 id=21U;
    static const IdByte byte=Low;

    UserReportInternalMessage ();

    struct ReportDataBlock {
        lltypes::U8 ReportType;
        lltypes::U8 Category;
        lltypes::LLUUID ReporterID;
        lltypes::LLVector3 ViewerPosition;
        lltypes::LLVector3 AgentPosition;
        lltypes::LLUUID ScreenshotID;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID LastOwnerID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID RegionID;
        lltypes::LLUUID AbuserID;
        lltypes::Variable<1> AbuseRegionName;
        lltypes::LLUUID AbuseRegionID;
        lltypes::Variable<1> Summary;
        lltypes::Variable<2> Details;
        lltypes::Variable<1> VersionString;
    };
    ReportDataBlock ReportData;
};

QDataStream &operator<<(QDataStream & out, const UserReportInternalMessage & o);
QDataStream &operator>>(QDataStream & in,  UserReportInternalMessage & o);

struct SetSimStatusInDatabaseMessage : UdpMessage {
    static const quint32 id=22U;
    static const IdByte byte=Low;

    SetSimStatusInDatabaseMessage ();

    struct DataBlock {
        lltypes::LLUUID RegionID;
        lltypes::Variable<1> HostName;
        lltypes::S32 X;
        lltypes::S32 Y;
        lltypes::S32 PID;
        lltypes::S32 AgentCount;
        lltypes::S32 TimeToLive;
        lltypes::Variable<1> Status;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const SetSimStatusInDatabaseMessage & o);
QDataStream &operator>>(QDataStream & in,  SetSimStatusInDatabaseMessage & o);

struct SetSimPresenceInDatabaseMessage : UdpMessage {
    static const quint32 id=23U;
    static const IdByte byte=Low;

    SetSimPresenceInDatabaseMessage ();

    struct SimDataBlock {
        lltypes::LLUUID RegionID;
        lltypes::Variable<1> HostName;
        lltypes::U32 GridX;
        lltypes::U32 GridY;
        lltypes::S32 PID;
        lltypes::S32 AgentCount;
        lltypes::S32 TimeToLive;
        lltypes::Variable<1> Status;
    };
    SimDataBlock SimData;
};

QDataStream &operator<<(QDataStream & out, const SetSimPresenceInDatabaseMessage & o);
QDataStream &operator>>(QDataStream & in,  SetSimPresenceInDatabaseMessage & o);

struct EconomyDataRequestMessage : UdpMessage {
    static const quint32 id=24U;
    static const IdByte byte=Low;

    EconomyDataRequestMessage ();

};

QDataStream &operator<<(QDataStream & out, const EconomyDataRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EconomyDataRequestMessage & o);

struct EconomyDataMessage : UdpMessage {
    static const quint32 id=25U;
    static const IdByte byte=Low;

    EconomyDataMessage ();

    struct InfoBlock {
        lltypes::S32 ObjectCapacity;
        lltypes::S32 ObjectCount;
        lltypes::S32 PriceEnergyUnit;
        lltypes::S32 PriceObjectClaim;
        lltypes::S32 PricePublicObjectDecay;
        lltypes::S32 PricePublicObjectDelete;
        lltypes::S32 PriceParcelClaim;
        lltypes::F32 PriceParcelClaimFactor;
        lltypes::S32 PriceUpload;
        lltypes::S32 PriceRentLight;
        lltypes::S32 TeleportMinPrice;
        lltypes::F32 TeleportPriceExponent;
        lltypes::F32 EnergyEfficiency;
        lltypes::F32 PriceObjectRent;
        lltypes::F32 PriceObjectScaleFactor;
        lltypes::S32 PriceParcelRent;
        lltypes::S32 PriceGroupCreate;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const EconomyDataMessage & o);
QDataStream &operator>>(QDataStream & in,  EconomyDataMessage & o);

struct AvatarPickerRequestMessage : UdpMessage {
    static const quint32 id=26U;
    static const IdByte byte=Low;

    AvatarPickerRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID QueryID;
    };
    struct DataBlock {
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarPickerRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPickerRequestMessage & o);

struct AvatarPickerRequestBackendMessage : UdpMessage {
    static const quint32 id=27U;
    static const IdByte byte=Low;

    AvatarPickerRequestBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID QueryID;
        lltypes::U8 GodLevel;
    };
    struct DataBlock {
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarPickerRequestBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPickerRequestBackendMessage & o);

struct AvatarPickerReplyMessage : UdpMessage {
    static const quint32 id=28U;
    static const IdByte byte=Low;

    AvatarPickerReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID QueryID;
    };
    struct DataBlock {
        lltypes::LLUUID AvatarID;
        lltypes::Variable<1> FirstName;
        lltypes::Variable<1> LastName;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarPickerReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPickerReplyMessage & o);

struct PlacesQueryMessage : UdpMessage {
    static const quint32 id=29U;
    static const IdByte byte=Low;

    PlacesQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID QueryID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
    };
    struct QueryDataBlock {
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S8 Category;
        lltypes::Variable<1> SimName;
    };
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const PlacesQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  PlacesQueryMessage & o);

struct PlacesReplyMessage : UdpMessage {
    static const quint32 id=30U;
    static const IdByte byte=Low;

    PlacesReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID QueryID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID OwnerID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Desc;
        lltypes::S32 ActualArea;
        lltypes::S32 BillableArea;
        lltypes::U8 Flags;
        lltypes::F32 GlobalX;
        lltypes::F32 GlobalY;
        lltypes::F32 GlobalZ;
        lltypes::Variable<1> SimName;
        lltypes::LLUUID SnapshotID;
        lltypes::F32 Dwell;
        lltypes::S32 Price;
    };
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    QVector<QueryDataBlock> QueryData;
};

QDataStream &operator<<(QDataStream & out, const PlacesReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  PlacesReplyMessage & o);

struct DirFindQueryMessage : UdpMessage {
    static const quint32 id=31U;
    static const IdByte byte=Low;

    DirFindQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirFindQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  DirFindQueryMessage & o);

struct DirFindQueryBackendMessage : UdpMessage {
    static const quint32 id=32U;
    static const IdByte byte=Low;

    DirFindQueryBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S32 QueryStart;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirFindQueryBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  DirFindQueryBackendMessage & o);

struct DirPlacesQueryMessage : UdpMessage {
    static const quint32 id=33U;
    static const IdByte byte=Low;

    DirPlacesQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S8 Category;
        lltypes::Variable<1> SimName;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirPlacesQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPlacesQueryMessage & o);

struct DirPlacesQueryBackendMessage : UdpMessage {
    static const quint32 id=34U;
    static const IdByte byte=Low;

    DirPlacesQueryBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S8 Category;
        lltypes::Variable<1> SimName;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirPlacesQueryBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPlacesQueryBackendMessage & o);

struct DirPlacesReplyMessage : UdpMessage {
    static const quint32 id=35U;
    static const IdByte byte=Low;

    DirPlacesReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> Name;
        lltypes::BOOL ForSale;
        lltypes::BOOL Auction;
        lltypes::F32 Dwell;
    };
    struct StatusDataBlock {
        lltypes::U32 Status;
    };
    AgentDataBlock AgentData;
    QVector<QueryDataBlock> QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
    QVector<StatusDataBlock> StatusData;
};

QDataStream &operator<<(QDataStream & out, const DirPlacesReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPlacesReplyMessage & o);

struct DirPeopleReplyMessage : UdpMessage {
    static const quint32 id=36U;
    static const IdByte byte=Low;

    DirPeopleReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID AgentID;
        lltypes::Variable<1> FirstName;
        lltypes::Variable<1> LastName;
        lltypes::Variable<1> Group;
        lltypes::BOOL Online;
        lltypes::S32 Reputation;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
};

QDataStream &operator<<(QDataStream & out, const DirPeopleReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPeopleReplyMessage & o);

struct DirEventsReplyMessage : UdpMessage {
    static const quint32 id=37U;
    static const IdByte byte=Low;

    DirEventsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID OwnerID;
        lltypes::Variable<1> Name;
        lltypes::U32 EventID;
        lltypes::Variable<1> Date;
        lltypes::U32 UnixTime;
        lltypes::U32 EventFlags;
    };
    struct StatusDataBlock {
        lltypes::U32 Status;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
    QVector<StatusDataBlock> StatusData;
};

QDataStream &operator<<(QDataStream & out, const DirEventsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirEventsReplyMessage & o);

struct DirGroupsReplyMessage : UdpMessage {
    static const quint32 id=38U;
    static const IdByte byte=Low;

    DirGroupsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID GroupID;
        lltypes::Variable<1> GroupName;
        lltypes::S32 Members;
        lltypes::F32 SearchOrder;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
};

QDataStream &operator<<(QDataStream & out, const DirGroupsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirGroupsReplyMessage & o);

struct DirClassifiedQueryMessage : UdpMessage {
    static const quint32 id=39U;
    static const IdByte byte=Low;

    DirClassifiedQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::U32 Category;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirClassifiedQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  DirClassifiedQueryMessage & o);

struct DirClassifiedQueryBackendMessage : UdpMessage {
    static const quint32 id=40U;
    static const IdByte byte=Low;

    DirClassifiedQueryBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::U32 Category;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirClassifiedQueryBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  DirClassifiedQueryBackendMessage & o);

struct DirClassifiedReplyMessage : UdpMessage {
    static const quint32 id=41U;
    static const IdByte byte=Low;

    DirClassifiedReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID ClassifiedID;
        lltypes::Variable<1> Name;
        lltypes::U8 ClassifiedFlags;
        lltypes::U32 CreationDate;
        lltypes::U32 ExpirationDate;
        lltypes::S32 PriceForListing;
    };
    struct StatusDataBlock {
        lltypes::U32 Status;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
    QVector<StatusDataBlock> StatusData;
};

QDataStream &operator<<(QDataStream & out, const DirClassifiedReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirClassifiedReplyMessage & o);

struct AvatarClassifiedReplyMessage : UdpMessage {
    static const quint32 id=42U;
    static const IdByte byte=Low;

    AvatarClassifiedReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TargetID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarClassifiedReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarClassifiedReplyMessage & o);

struct ClassifiedInfoRequestMessage : UdpMessage {
    static const quint32 id=43U;
    static const IdByte byte=Low;

    ClassifiedInfoRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ClassifiedInfoRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ClassifiedInfoRequestMessage & o);

struct ClassifiedInfoReplyMessage : UdpMessage {
    static const quint32 id=44U;
    static const IdByte byte=Low;

    ClassifiedInfoReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
        lltypes::LLUUID CreatorID;
        lltypes::U32 CreationDate;
        lltypes::U32 ExpirationDate;
        lltypes::U32 Category;
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Desc;
        lltypes::LLUUID ParcelID;
        lltypes::U32 ParentEstate;
        lltypes::LLUUID SnapshotID;
        lltypes::Variable<1> SimName;
        lltypes::LLVector3d PosGlobal;
        lltypes::Variable<1> ParcelName;
        lltypes::U8 ClassifiedFlags;
        lltypes::S32 PriceForListing;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ClassifiedInfoReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ClassifiedInfoReplyMessage & o);

struct ClassifiedInfoUpdateMessage : UdpMessage {
    static const quint32 id=45U;
    static const IdByte byte=Low;

    ClassifiedInfoUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
        lltypes::U32 Category;
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Desc;
        lltypes::LLUUID ParcelID;
        lltypes::U32 ParentEstate;
        lltypes::LLUUID SnapshotID;
        lltypes::LLVector3d PosGlobal;
        lltypes::U8 ClassifiedFlags;
        lltypes::S32 PriceForListing;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ClassifiedInfoUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ClassifiedInfoUpdateMessage & o);

struct ClassifiedDeleteMessage : UdpMessage {
    static const quint32 id=46U;
    static const IdByte byte=Low;

    ClassifiedDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ClassifiedDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  ClassifiedDeleteMessage & o);

struct ClassifiedGodDeleteMessage : UdpMessage {
    static const quint32 id=47U;
    static const IdByte byte=Low;

    ClassifiedGodDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ClassifiedID;
        lltypes::LLUUID QueryID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ClassifiedGodDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  ClassifiedGodDeleteMessage & o);

struct DirLandQueryMessage : UdpMessage {
    static const quint32 id=48U;
    static const IdByte byte=Low;

    DirLandQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::U32 QueryFlags;
        lltypes::U32 SearchType;
        lltypes::S32 Price;
        lltypes::S32 Area;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirLandQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  DirLandQueryMessage & o);

struct DirLandQueryBackendMessage : UdpMessage {
    static const quint32 id=49U;
    static const IdByte byte=Low;

    DirLandQueryBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::U32 QueryFlags;
        lltypes::U32 SearchType;
        lltypes::S32 Price;
        lltypes::S32 Area;
        lltypes::S32 QueryStart;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirLandQueryBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  DirLandQueryBackendMessage & o);

struct DirLandReplyMessage : UdpMessage {
    static const quint32 id=50U;
    static const IdByte byte=Low;

    DirLandReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> Name;
        lltypes::BOOL Auction;
        lltypes::BOOL ForSale;
        lltypes::S32 SalePrice;
        lltypes::S32 ActualArea;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
};

QDataStream &operator<<(QDataStream & out, const DirLandReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirLandReplyMessage & o);

struct DirPopularQueryMessage : UdpMessage {
    static const quint32 id=51U;
    static const IdByte byte=Low;

    DirPopularQueryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::U32 QueryFlags;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirPopularQueryMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPopularQueryMessage & o);

struct DirPopularQueryBackendMessage : UdpMessage {
    static const quint32 id=52U;
    static const IdByte byte=Low;

    DirPopularQueryBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::U32 QueryFlags;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const DirPopularQueryBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPopularQueryBackendMessage & o);

struct DirPopularReplyMessage : UdpMessage {
    static const quint32 id=53U;
    static const IdByte byte=Low;

    DirPopularReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct QueryRepliesBlock {
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> Name;
        lltypes::F32 Dwell;
    };
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    QVector<QueryRepliesBlock> QueryReplies;
};

QDataStream &operator<<(QDataStream & out, const DirPopularReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DirPopularReplyMessage & o);

struct ParcelInfoRequestMessage : UdpMessage {
    static const quint32 id=54U;
    static const IdByte byte=Low;

    ParcelInfoRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ParcelID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelInfoRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelInfoRequestMessage & o);

struct ParcelInfoReplyMessage : UdpMessage {
    static const quint32 id=55U;
    static const IdByte byte=Low;

    ParcelInfoReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::LLUUID OwnerID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Desc;
        lltypes::S32 ActualArea;
        lltypes::S32 BillableArea;
        lltypes::U8 Flags;
        lltypes::F32 GlobalX;
        lltypes::F32 GlobalY;
        lltypes::F32 GlobalZ;
        lltypes::Variable<1> SimName;
        lltypes::LLUUID SnapshotID;
        lltypes::F32 Dwell;
        lltypes::S32 SalePrice;
        lltypes::S32 AuctionID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelInfoReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelInfoReplyMessage & o);

struct ParcelObjectOwnersRequestMessage : UdpMessage {
    static const quint32 id=56U;
    static const IdByte byte=Low;

    ParcelObjectOwnersRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelObjectOwnersRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelObjectOwnersRequestMessage & o);

struct ParcelObjectOwnersReplyMessage : UdpMessage {
    static const quint32 id=57U;
    static const IdByte byte=Low;

    ParcelObjectOwnersReplyMessage ();

    struct DataBlock {
        lltypes::LLUUID OwnerID;
        lltypes::BOOL IsGroupOwned;
        lltypes::S32 Count;
        lltypes::BOOL OnlineStatus;
    };
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelObjectOwnersReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelObjectOwnersReplyMessage & o);

struct GroupNoticesListRequestMessage : UdpMessage {
    static const quint32 id=58U;
    static const IdByte byte=Low;

    GroupNoticesListRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const GroupNoticesListRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupNoticesListRequestMessage & o);

struct GroupNoticesListReplyMessage : UdpMessage {
    static const quint32 id=59U;
    static const IdByte byte=Low;

    GroupNoticesListReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct DataBlock {
        lltypes::LLUUID NoticeID;
        lltypes::U32 Timestamp;
        lltypes::Variable<2> FromName;
        lltypes::Variable<2> Subject;
        lltypes::BOOL HasAttachment;
        lltypes::U8 AssetType;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const GroupNoticesListReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupNoticesListReplyMessage & o);

struct GroupNoticeRequestMessage : UdpMessage {
    static const quint32 id=60U;
    static const IdByte byte=Low;

    GroupNoticeRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupNoticeID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const GroupNoticeRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupNoticeRequestMessage & o);

struct GroupNoticeAddMessage : UdpMessage {
    static const quint32 id=61U;
    static const IdByte byte=Low;

    GroupNoticeAddMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct MessageBlockBlock {
        lltypes::LLUUID ToGroupID;
        lltypes::LLUUID ID;
        lltypes::U8 Dialog;
        lltypes::Variable<1> FromAgentName;
        lltypes::Variable<2> Message;
        lltypes::Variable<2> BinaryBucket;
    };
    AgentDataBlock AgentData;
    MessageBlockBlock MessageBlock;
};

QDataStream &operator<<(QDataStream & out, const GroupNoticeAddMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupNoticeAddMessage & o);

struct TeleportRequestMessage : UdpMessage {
    static const quint32 id=62U;
    static const IdByte byte=Low;

    TeleportRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InfoBlock {
        lltypes::LLUUID RegionID;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
    };
    AgentDataBlock AgentData;
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportRequestMessage & o);

struct TeleportLocationRequestMessage : UdpMessage {
    static const quint32 id=63U;
    static const IdByte byte=Low;

    TeleportLocationRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InfoBlock {
        lltypes::U64 RegionHandle;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
    };
    AgentDataBlock AgentData;
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportLocationRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportLocationRequestMessage & o);

struct TeleportLocalMessage : UdpMessage {
    static const quint32 id=64U;
    static const IdByte byte=Low;

    TeleportLocalMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 LocationID;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
        lltypes::U32 TeleportFlags;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportLocalMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportLocalMessage & o);

struct TeleportLandmarkRequestMessage : UdpMessage {
    static const quint32 id=65U;
    static const IdByte byte=Low;

    TeleportLandmarkRequestMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID LandmarkID;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportLandmarkRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportLandmarkRequestMessage & o);

struct TeleportProgressMessage : UdpMessage {
    static const quint32 id=66U;
    static const IdByte byte=Low;

    TeleportProgressMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct InfoBlock {
        lltypes::U32 TeleportFlags;
        lltypes::Variable<1> Message;
    };
    AgentDataBlock AgentData;
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportProgressMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportProgressMessage & o);

struct DataHomeLocationRequestMessage : UdpMessage {
    static const quint32 id=67U;
    static const IdByte byte=Low;

    DataHomeLocationRequestMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 KickedFromEstateID;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const DataHomeLocationRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  DataHomeLocationRequestMessage & o);

struct DataHomeLocationReplyMessage : UdpMessage {
    static const quint32 id=68U;
    static const IdByte byte=Low;

    DataHomeLocationReplyMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::U64 RegionHandle;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const DataHomeLocationReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  DataHomeLocationReplyMessage & o);

struct TeleportFinishMessage : UdpMessage {
    static const quint32 id=69U;
    static const IdByte byte=Low;

    TeleportFinishMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 LocationID;
        lltypes::IPADDR SimIP;
        lltypes::IPPORT SimPort;
        lltypes::U64 RegionHandle;
        lltypes::Variable<2> SeedCapability;
        lltypes::U8 SimAccess;
        lltypes::U32 TeleportFlags;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportFinishMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportFinishMessage & o);

struct StartLureMessage : UdpMessage {
    static const quint32 id=70U;
    static const IdByte byte=Low;

    StartLureMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InfoBlock {
        lltypes::U8 LureType;
        lltypes::Variable<1> Message;
    };
    struct TargetDataBlock {
        lltypes::LLUUID TargetID;
    };
    AgentDataBlock AgentData;
    InfoBlock Info;
    QVector<TargetDataBlock> TargetData;
};

QDataStream &operator<<(QDataStream & out, const StartLureMessage & o);
QDataStream &operator>>(QDataStream & in,  StartLureMessage & o);

struct TeleportLureRequestMessage : UdpMessage {
    static const quint32 id=71U;
    static const IdByte byte=Low;

    TeleportLureRequestMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID LureID;
        lltypes::U32 TeleportFlags;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportLureRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportLureRequestMessage & o);

struct TeleportCancelMessage : UdpMessage {
    static const quint32 id=72U;
    static const IdByte byte=Low;

    TeleportCancelMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportCancelMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportCancelMessage & o);

struct TeleportStartMessage : UdpMessage {
    static const quint32 id=73U;
    static const IdByte byte=Low;

    TeleportStartMessage ();

    struct InfoBlock {
        lltypes::U32 TeleportFlags;
    };
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const TeleportStartMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportStartMessage & o);

struct TeleportFailedMessage : UdpMessage {
    static const quint32 id=74U;
    static const IdByte byte=Low;

    TeleportFailedMessage ();

    struct InfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::Variable<1> Reason;
    };
    struct AlertInfoBlock {
        lltypes::Variable<1> Message;
        lltypes::Variable<1> ExtraParams;
    };
    InfoBlock Info;
    QVector<AlertInfoBlock> AlertInfo;
};

QDataStream &operator<<(QDataStream & out, const TeleportFailedMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportFailedMessage & o);

struct UndoMessage : UdpMessage {
    static const quint32 id=75U;
    static const IdByte byte=Low;

    UndoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const UndoMessage & o);
QDataStream &operator>>(QDataStream & in,  UndoMessage & o);

struct RedoMessage : UdpMessage {
    static const quint32 id=76U;
    static const IdByte byte=Low;

    RedoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RedoMessage & o);
QDataStream &operator>>(QDataStream & in,  RedoMessage & o);

struct UndoLandMessage : UdpMessage {
    static const quint32 id=77U;
    static const IdByte byte=Low;

    UndoLandMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const UndoLandMessage & o);
QDataStream &operator>>(QDataStream & in,  UndoLandMessage & o);

struct AgentPauseMessage : UdpMessage {
    static const quint32 id=78U;
    static const IdByte byte=Low;

    AgentPauseMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 SerialNum;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentPauseMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentPauseMessage & o);

struct AgentResumeMessage : UdpMessage {
    static const quint32 id=79U;
    static const IdByte byte=Low;

    AgentResumeMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 SerialNum;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentResumeMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentResumeMessage & o);

struct AgentUpdateMessage : UdpMessage {
    static const quint32 id=4U;
    static const IdByte byte=High;

    AgentUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLQuaternion BodyRotation;
        lltypes::LLQuaternion HeadRotation;
        lltypes::U8 State;
        lltypes::LLVector3 CameraCenter;
        lltypes::LLVector3 CameraAtAxis;
        lltypes::LLVector3 CameraLeftAxis;
        lltypes::LLVector3 CameraUpAxis;
        lltypes::F32 Far;
        lltypes::U32 ControlFlags;
        lltypes::U8 Flags;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentUpdateMessage & o);

struct ChatFromViewerMessage : UdpMessage {
    static const quint32 id=80U;
    static const IdByte byte=Low;

    ChatFromViewerMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ChatDataBlock {
        lltypes::Variable<2> Message;
        lltypes::U8 Type;
        lltypes::S32 Channel;
    };
    AgentDataBlock AgentData;
    ChatDataBlock ChatData;
};

QDataStream &operator<<(QDataStream & out, const ChatFromViewerMessage & o);
QDataStream &operator>>(QDataStream & in,  ChatFromViewerMessage & o);

struct AgentThrottleMessage : UdpMessage {
    static const quint32 id=81U;
    static const IdByte byte=Low;

    AgentThrottleMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 CircuitCode;
    };
    struct ThrottleBlock {
        lltypes::U32 GenCounter;
        lltypes::Variable<1> Throttles;
    };
    AgentDataBlock AgentData;
    ThrottleBlock Throttle;
};

QDataStream &operator<<(QDataStream & out, const AgentThrottleMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentThrottleMessage & o);

struct AgentFOVMessage : UdpMessage {
    static const quint32 id=82U;
    static const IdByte byte=Low;

    AgentFOVMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 CircuitCode;
    };
    struct FOVBlockBlock {
        lltypes::U32 GenCounter;
        lltypes::F32 VerticalAngle;
    };
    AgentDataBlock AgentData;
    FOVBlockBlock FOVBlock;
};

QDataStream &operator<<(QDataStream & out, const AgentFOVMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentFOVMessage & o);

struct AgentHeightWidthMessage : UdpMessage {
    static const quint32 id=83U;
    static const IdByte byte=Low;

    AgentHeightWidthMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 CircuitCode;
    };
    struct HeightWidthBlockBlock {
        lltypes::U32 GenCounter;
        lltypes::U16 Height;
        lltypes::U16 Width;
    };
    AgentDataBlock AgentData;
    HeightWidthBlockBlock HeightWidthBlock;
};

QDataStream &operator<<(QDataStream & out, const AgentHeightWidthMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentHeightWidthMessage & o);

struct AgentSetAppearanceMessage : UdpMessage {
    static const quint32 id=84U;
    static const IdByte byte=Low;

    AgentSetAppearanceMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 SerialNum;
        lltypes::LLVector3 Size;
    };
    struct WearableDataBlock {
        lltypes::LLUUID CacheID;
        lltypes::U8 TextureIndex;
    };
    struct ObjectDataBlock {
        lltypes::Variable<2> TextureEntry;
    };
    struct VisualParamBlock {
        lltypes::U8 ParamValue;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
    ObjectDataBlock ObjectData;
    QVector<VisualParamBlock> VisualParam;
};

QDataStream &operator<<(QDataStream & out, const AgentSetAppearanceMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentSetAppearanceMessage & o);

struct AgentAnimationMessage : UdpMessage {
    static const quint32 id=5U;
    static const IdByte byte=High;

    AgentAnimationMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct AnimationListBlock {
        lltypes::LLUUID AnimID;
        lltypes::BOOL StartAnim;
    };
    struct PhysicalAvatarEventListBlock {
        lltypes::Variable<1> TypeData;
    };
    AgentDataBlock AgentData;
    QVector<AnimationListBlock> AnimationList;
    QVector<PhysicalAvatarEventListBlock> PhysicalAvatarEventList;
};

QDataStream &operator<<(QDataStream & out, const AgentAnimationMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentAnimationMessage & o);

struct AgentRequestSitMessage : UdpMessage {
    static const quint32 id=6U;
    static const IdByte byte=High;

    AgentRequestSitMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TargetObjectBlock {
        lltypes::LLUUID TargetID;
        lltypes::LLVector3 Offset;
    };
    AgentDataBlock AgentData;
    TargetObjectBlock TargetObject;
};

QDataStream &operator<<(QDataStream & out, const AgentRequestSitMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentRequestSitMessage & o);

struct AgentSitMessage : UdpMessage {
    static const quint32 id=7U;
    static const IdByte byte=High;

    AgentSitMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentSitMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentSitMessage & o);

struct AgentQuitCopyMessage : UdpMessage {
    static const quint32 id=85U;
    static const IdByte byte=Low;

    AgentQuitCopyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct FuseBlockBlock {
        lltypes::U32 ViewerCircuitCode;
    };
    AgentDataBlock AgentData;
    FuseBlockBlock FuseBlock;
};

QDataStream &operator<<(QDataStream & out, const AgentQuitCopyMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentQuitCopyMessage & o);

struct RequestImageMessage : UdpMessage {
    static const quint32 id=8U;
    static const IdByte byte=High;

    RequestImageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RequestImageBlock {
        lltypes::LLUUID Image;
        lltypes::S8 DiscardLevel;
        lltypes::F32 DownloadPriority;
        lltypes::U32 Packet;
        lltypes::U8 Type;
    };
    AgentDataBlock AgentData;
    QVector<RequestImageBlock> RequestImage;
};

QDataStream &operator<<(QDataStream & out, const RequestImageMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestImageMessage & o);

struct ImageNotInDatabaseMessage : UdpMessage {
    static const quint32 id=86U;
    static const IdByte byte=Low;

    ImageNotInDatabaseMessage ();

    struct ImageIDBlock {
        lltypes::LLUUID ID;
    };
    ImageIDBlock ImageID;
};

QDataStream &operator<<(QDataStream & out, const ImageNotInDatabaseMessage & o);
QDataStream &operator>>(QDataStream & in,  ImageNotInDatabaseMessage & o);

struct RebakeAvatarTexturesMessage : UdpMessage {
    static const quint32 id=87U;
    static const IdByte byte=Low;

    RebakeAvatarTexturesMessage ();

    struct TextureDataBlock {
        lltypes::LLUUID TextureID;
    };
    TextureDataBlock TextureData;
};

QDataStream &operator<<(QDataStream & out, const RebakeAvatarTexturesMessage & o);
QDataStream &operator>>(QDataStream & in,  RebakeAvatarTexturesMessage & o);

struct SetAlwaysRunMessage : UdpMessage {
    static const quint32 id=88U;
    static const IdByte byte=Low;

    SetAlwaysRunMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::BOOL AlwaysRun;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const SetAlwaysRunMessage & o);
QDataStream &operator>>(QDataStream & in,  SetAlwaysRunMessage & o);

struct ObjectAddMessage : UdpMessage {
    static const quint32 id=1U;
    static const IdByte byte=Medium;

    ObjectAddMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct ObjectDataBlock {
        lltypes::U8 PCode;
        lltypes::U8 Material;
        lltypes::U32 AddFlags;
        lltypes::U8 PathCurve;
        lltypes::U8 ProfileCurve;
        lltypes::U16 PathBegin;
        lltypes::U16 PathEnd;
        lltypes::U8 PathScaleX;
        lltypes::U8 PathScaleY;
        lltypes::U8 PathShearX;
        lltypes::U8 PathShearY;
        lltypes::S8 PathTwist;
        lltypes::S8 PathTwistBegin;
        lltypes::S8 PathRadiusOffset;
        lltypes::S8 PathTaperX;
        lltypes::S8 PathTaperY;
        lltypes::U8 PathRevolutions;
        lltypes::S8 PathSkew;
        lltypes::U16 ProfileBegin;
        lltypes::U16 ProfileEnd;
        lltypes::U16 ProfileHollow;
        lltypes::U8 BypassRaycast;
        lltypes::LLVector3 RayStart;
        lltypes::LLVector3 RayEnd;
        lltypes::LLUUID RayTargetID;
        lltypes::U8 RayEndIsIntersection;
        lltypes::LLVector3 Scale;
        lltypes::LLQuaternion Rotation;
        lltypes::U8 State;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectAddMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectAddMessage & o);

struct ObjectDeleteMessage : UdpMessage {
    static const quint32 id=89U;
    static const IdByte byte=Low;

    ObjectDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::BOOL Force;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDeleteMessage & o);

struct ObjectDuplicateMessage : UdpMessage {
    static const quint32 id=90U;
    static const IdByte byte=Low;

    ObjectDuplicateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct SharedDataBlock {
        lltypes::LLVector3 Offset;
        lltypes::U32 DuplicateFlags;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    SharedDataBlock SharedData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDuplicateMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDuplicateMessage & o);

struct ObjectDuplicateOnRayMessage : UdpMessage {
    static const quint32 id=91U;
    static const IdByte byte=Low;

    ObjectDuplicateOnRayMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
        lltypes::LLVector3 RayStart;
        lltypes::LLVector3 RayEnd;
        lltypes::BOOL BypassRaycast;
        lltypes::BOOL RayEndIsIntersection;
        lltypes::BOOL CopyCenters;
        lltypes::BOOL CopyRotates;
        lltypes::LLUUID RayTargetID;
        lltypes::U32 DuplicateFlags;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDuplicateOnRayMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDuplicateOnRayMessage & o);

struct MultipleObjectUpdateMessage : UdpMessage {
    static const quint32 id=2U;
    static const IdByte byte=Medium;

    MultipleObjectUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 Type;
        lltypes::Variable<1> Data;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const MultipleObjectUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  MultipleObjectUpdateMessage & o);

struct RequestMultipleObjectsMessage : UdpMessage {
    static const quint32 id=3U;
    static const IdByte byte=Medium;

    RequestMultipleObjectsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U8 CacheMissType;
        lltypes::U32 ID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RequestMultipleObjectsMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestMultipleObjectsMessage & o);

struct ObjectPositionMessage : UdpMessage {
    static const quint32 id=4U;
    static const IdByte byte=Medium;

    ObjectPositionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::LLVector3 Position;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectPositionMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectPositionMessage & o);

struct ObjectScaleMessage : UdpMessage {
    static const quint32 id=92U;
    static const IdByte byte=Low;

    ObjectScaleMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::LLVector3 Scale;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectScaleMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectScaleMessage & o);

struct ObjectRotationMessage : UdpMessage {
    static const quint32 id=93U;
    static const IdByte byte=Low;

    ObjectRotationMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::LLQuaternion Rotation;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectRotationMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectRotationMessage & o);

struct ObjectFlagUpdateMessage : UdpMessage {
    static const quint32 id=94U;
    static const IdByte byte=Low;

    ObjectFlagUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 ObjectLocalID;
        lltypes::BOOL UsePhysics;
        lltypes::BOOL IsTemporary;
        lltypes::BOOL IsPhantom;
        lltypes::BOOL CastsShadows;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ObjectFlagUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectFlagUpdateMessage & o);

struct ObjectClickActionMessage : UdpMessage {
    static const quint32 id=95U;
    static const IdByte byte=Low;

    ObjectClickActionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 ClickAction;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectClickActionMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectClickActionMessage & o);

struct ObjectImageMessage : UdpMessage {
    static const quint32 id=96U;
    static const IdByte byte=Low;

    ObjectImageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::Variable<1> MediaURL;
        lltypes::Variable<2> TextureEntry;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectImageMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectImageMessage & o);

struct ObjectMaterialMessage : UdpMessage {
    static const quint32 id=97U;
    static const IdByte byte=Low;

    ObjectMaterialMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 Material;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectMaterialMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectMaterialMessage & o);

struct ObjectShapeMessage : UdpMessage {
    static const quint32 id=98U;
    static const IdByte byte=Low;

    ObjectShapeMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 PathCurve;
        lltypes::U8 ProfileCurve;
        lltypes::U16 PathBegin;
        lltypes::U16 PathEnd;
        lltypes::U8 PathScaleX;
        lltypes::U8 PathScaleY;
        lltypes::U8 PathShearX;
        lltypes::U8 PathShearY;
        lltypes::S8 PathTwist;
        lltypes::S8 PathTwistBegin;
        lltypes::S8 PathRadiusOffset;
        lltypes::S8 PathTaperX;
        lltypes::S8 PathTaperY;
        lltypes::U8 PathRevolutions;
        lltypes::S8 PathSkew;
        lltypes::U16 ProfileBegin;
        lltypes::U16 ProfileEnd;
        lltypes::U16 ProfileHollow;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectShapeMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectShapeMessage & o);

struct ObjectExtraParamsMessage : UdpMessage {
    static const quint32 id=99U;
    static const IdByte byte=Low;

    ObjectExtraParamsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U16 ParamType;
        lltypes::BOOL ParamInUse;
        lltypes::U32 ParamSize;
        lltypes::Variable<1> ParamData;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectExtraParamsMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectExtraParamsMessage & o);

struct ObjectOwnerMessage : UdpMessage {
    static const quint32 id=100U;
    static const IdByte byte=Low;

    ObjectOwnerMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct HeaderDataBlock {
        lltypes::BOOL Override;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectOwnerMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectOwnerMessage & o);

struct ObjectGroupMessage : UdpMessage {
    static const quint32 id=101U;
    static const IdByte byte=Low;

    ObjectGroupMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectGroupMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectGroupMessage & o);

struct ObjectBuyMessage : UdpMessage {
    static const quint32 id=102U;
    static const IdByte byte=Low;

    ObjectBuyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID CategoryID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectBuyMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectBuyMessage & o);

struct BuyObjectInventoryMessage : UdpMessage {
    static const quint32 id=103U;
    static const IdByte byte=Low;

    BuyObjectInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const BuyObjectInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  BuyObjectInventoryMessage & o);

struct DerezContainerMessage : UdpMessage {
    static const quint32 id=104U;
    static const IdByte byte=Low;

    DerezContainerMessage ();

    struct DataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::BOOL Delete;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const DerezContainerMessage & o);
QDataStream &operator>>(QDataStream & in,  DerezContainerMessage & o);

struct ObjectPermissionsMessage : UdpMessage {
    static const quint32 id=105U;
    static const IdByte byte=Low;

    ObjectPermissionsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct HeaderDataBlock {
        lltypes::BOOL Override;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::U8 Field;
        lltypes::U8 Set;
        lltypes::U32 Mask;
    };
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectPermissionsMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectPermissionsMessage & o);

struct ObjectSaleInfoMessage : UdpMessage {
    static const quint32 id=106U;
    static const IdByte byte=Low;

    ObjectSaleInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectSaleInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectSaleInfoMessage & o);

struct ObjectNameMessage : UdpMessage {
    static const quint32 id=107U;
    static const IdByte byte=Low;

    ObjectNameMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectNameMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectNameMessage & o);

struct ObjectDescriptionMessage : UdpMessage {
    static const quint32 id=108U;
    static const IdByte byte=Low;

    ObjectDescriptionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
        lltypes::Variable<1> Description;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDescriptionMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDescriptionMessage & o);

struct ObjectCategoryMessage : UdpMessage {
    static const quint32 id=109U;
    static const IdByte byte=Low;

    ObjectCategoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
        lltypes::U32 Category;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectCategoryMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectCategoryMessage & o);

struct ObjectSelectMessage : UdpMessage {
    static const quint32 id=110U;
    static const IdByte byte=Low;

    ObjectSelectMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectSelectMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectSelectMessage & o);

struct ObjectDeselectMessage : UdpMessage {
    static const quint32 id=111U;
    static const IdByte byte=Low;

    ObjectDeselectMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDeselectMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDeselectMessage & o);

struct ObjectAttachMessage : UdpMessage {
    static const quint32 id=112U;
    static const IdByte byte=Low;

    ObjectAttachMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U8 AttachmentPoint;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::LLQuaternion Rotation;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectAttachMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectAttachMessage & o);

struct ObjectDetachMessage : UdpMessage {
    static const quint32 id=113U;
    static const IdByte byte=Low;

    ObjectDetachMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDetachMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDetachMessage & o);

struct ObjectDropMessage : UdpMessage {
    static const quint32 id=114U;
    static const IdByte byte=Low;

    ObjectDropMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDropMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDropMessage & o);

struct ObjectLinkMessage : UdpMessage {
    static const quint32 id=115U;
    static const IdByte byte=Low;

    ObjectLinkMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectLinkMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectLinkMessage & o);

struct ObjectDelinkMessage : UdpMessage {
    static const quint32 id=116U;
    static const IdByte byte=Low;

    ObjectDelinkMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectDelinkMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDelinkMessage & o);

struct ObjectGrabMessage : UdpMessage {
    static const quint32 id=117U;
    static const IdByte byte=Low;

    ObjectGrabMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
        lltypes::LLVector3 GrabOffset;
    };
    struct SurfaceInfoBlock {
        lltypes::LLVector3 UVCoord;
        lltypes::LLVector3 STCoord;
        lltypes::S32 FaceIndex;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 Normal;
        lltypes::LLVector3 Binormal;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    QVector<SurfaceInfoBlock> SurfaceInfo;
};

QDataStream &operator<<(QDataStream & out, const ObjectGrabMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectGrabMessage & o);

struct ObjectGrabUpdateMessage : UdpMessage {
    static const quint32 id=118U;
    static const IdByte byte=Low;

    ObjectGrabUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLVector3 GrabOffsetInitial;
        lltypes::LLVector3 GrabPosition;
        lltypes::U32 TimeSinceLast;
    };
    struct SurfaceInfoBlock {
        lltypes::LLVector3 UVCoord;
        lltypes::LLVector3 STCoord;
        lltypes::S32 FaceIndex;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 Normal;
        lltypes::LLVector3 Binormal;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    QVector<SurfaceInfoBlock> SurfaceInfo;
};

QDataStream &operator<<(QDataStream & out, const ObjectGrabUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectGrabUpdateMessage & o);

struct ObjectDeGrabMessage : UdpMessage {
    static const quint32 id=119U;
    static const IdByte byte=Low;

    ObjectDeGrabMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 LocalID;
    };
    struct SurfaceInfoBlock {
        lltypes::LLVector3 UVCoord;
        lltypes::LLVector3 STCoord;
        lltypes::S32 FaceIndex;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 Normal;
        lltypes::LLVector3 Binormal;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    QVector<SurfaceInfoBlock> SurfaceInfo;
};

QDataStream &operator<<(QDataStream & out, const ObjectDeGrabMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectDeGrabMessage & o);

struct ObjectSpinStartMessage : UdpMessage {
    static const quint32 id=120U;
    static const IdByte byte=Low;

    ObjectSpinStartMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectSpinStartMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectSpinStartMessage & o);

struct ObjectSpinUpdateMessage : UdpMessage {
    static const quint32 id=121U;
    static const IdByte byte=Low;

    ObjectSpinUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLQuaternion Rotation;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectSpinUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectSpinUpdateMessage & o);

struct ObjectSpinStopMessage : UdpMessage {
    static const quint32 id=122U;
    static const IdByte byte=Low;

    ObjectSpinStopMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectSpinStopMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectSpinStopMessage & o);

struct ObjectExportSelectedMessage : UdpMessage {
    static const quint32 id=123U;
    static const IdByte byte=Low;

    ObjectExportSelectedMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID RequestID;
        lltypes::S16 VolumeDetail;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectExportSelectedMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectExportSelectedMessage & o);

struct ModifyLandMessage : UdpMessage {
    static const quint32 id=124U;
    static const IdByte byte=Low;

    ModifyLandMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ModifyBlockBlock {
        lltypes::U8 Action;
        lltypes::U8 BrushSize;
        lltypes::F32 Seconds;
        lltypes::F32 Height;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::F32 West;
        lltypes::F32 South;
        lltypes::F32 East;
        lltypes::F32 North;
    };
    struct ModifyBlockExtendedBlock {
        lltypes::F32 BrushSize;
    };
    AgentDataBlock AgentData;
    ModifyBlockBlock ModifyBlock;
    QVector<ParcelDataBlock> ParcelData;
    QVector<ModifyBlockExtendedBlock> ModifyBlockExtended;
};

QDataStream &operator<<(QDataStream & out, const ModifyLandMessage & o);
QDataStream &operator>>(QDataStream & in,  ModifyLandMessage & o);

struct VelocityInterpolateOnMessage : UdpMessage {
    static const quint32 id=125U;
    static const IdByte byte=Low;

    VelocityInterpolateOnMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const VelocityInterpolateOnMessage & o);
QDataStream &operator>>(QDataStream & in,  VelocityInterpolateOnMessage & o);

struct VelocityInterpolateOffMessage : UdpMessage {
    static const quint32 id=126U;
    static const IdByte byte=Low;

    VelocityInterpolateOffMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const VelocityInterpolateOffMessage & o);
QDataStream &operator>>(QDataStream & in,  VelocityInterpolateOffMessage & o);

struct StateSaveMessage : UdpMessage {
    static const quint32 id=127U;
    static const IdByte byte=Low;

    StateSaveMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlockBlock {
        lltypes::Variable<1> Filename;
    };
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const StateSaveMessage & o);
QDataStream &operator>>(QDataStream & in,  StateSaveMessage & o);

struct ReportAutosaveCrashMessage : UdpMessage {
    static const quint32 id=128U;
    static const IdByte byte=Low;

    ReportAutosaveCrashMessage ();

    struct AutosaveDataBlock {
        lltypes::S32 PID;
        lltypes::S32 Status;
    };
    AutosaveDataBlock AutosaveData;
};

QDataStream &operator<<(QDataStream & out, const ReportAutosaveCrashMessage & o);
QDataStream &operator>>(QDataStream & in,  ReportAutosaveCrashMessage & o);

struct SimWideDeletesMessage : UdpMessage {
    static const quint32 id=129U;
    static const IdByte byte=Low;

    SimWideDeletesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlockBlock {
        lltypes::LLUUID TargetID;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const SimWideDeletesMessage & o);
QDataStream &operator>>(QDataStream & in,  SimWideDeletesMessage & o);

struct RequestObjectPropertiesFamilyMessage : UdpMessage {
    static const quint32 id=5U;
    static const IdByte byte=Medium;

    RequestObjectPropertiesFamilyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 RequestFlags;
        lltypes::LLUUID ObjectID;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RequestObjectPropertiesFamilyMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestObjectPropertiesFamilyMessage & o);

struct TrackAgentMessage : UdpMessage {
    static const quint32 id=130U;
    static const IdByte byte=Low;

    TrackAgentMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TargetDataBlock {
        lltypes::LLUUID PreyID;
    };
    AgentDataBlock AgentData;
    TargetDataBlock TargetData;
};

QDataStream &operator<<(QDataStream & out, const TrackAgentMessage & o);
QDataStream &operator>>(QDataStream & in,  TrackAgentMessage & o);

struct ViewerStatsMessage : UdpMessage {
    static const quint32 id=131U;
    static const IdByte byte=Low;

    ViewerStatsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::IPADDR IP;
        lltypes::U32 StartTime;
        lltypes::F32 RunTime;
        lltypes::F32 SimFPS;
        lltypes::F32 FPS;
        lltypes::U8 AgentsInView;
        lltypes::F32 Ping;
        lltypes::F64 MetersTraveled;
        lltypes::S32 RegionsVisited;
        lltypes::U32 SysRAM;
        lltypes::Variable<1> SysOS;
        lltypes::Variable<1> SysCPU;
        lltypes::Variable<1> SysGPU;
    };
    struct DownloadTotalsBlock {
        lltypes::U32 World;
        lltypes::U32 Objects;
        lltypes::U32 Textures;
    };
    struct NetStatsBlock {
        lltypes::U32 Bytes;
        lltypes::U32 Packets;
        lltypes::U32 Compressed;
        lltypes::U32 Savings;
    };
    struct FailStatsBlock {
        lltypes::U32 SendPacket;
        lltypes::U32 Dropped;
        lltypes::U32 Resent;
        lltypes::U32 FailedResends;
        lltypes::U32 OffCircuit;
        lltypes::U32 Invalid;
    };
    struct MiscStatsBlock {
        lltypes::U32 Type;
        lltypes::F64 Value;
    };
    AgentDataBlock AgentData;
    DownloadTotalsBlock DownloadTotals;
    QVector<NetStatsBlock> NetStats;
    FailStatsBlock FailStats;
    QVector<MiscStatsBlock> MiscStats;
};

QDataStream &operator<<(QDataStream & out, const ViewerStatsMessage & o);
QDataStream &operator>>(QDataStream & in,  ViewerStatsMessage & o);

struct ScriptAnswerYesMessage : UdpMessage {
    static const quint32 id=132U;
    static const IdByte byte=Low;

    ScriptAnswerYesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::S32 Questions;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ScriptAnswerYesMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptAnswerYesMessage & o);

struct UserReportMessage : UdpMessage {
    static const quint32 id=133U;
    static const IdByte byte=Low;

    UserReportMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ReportDataBlock {
        lltypes::U8 ReportType;
        lltypes::U8 Category;
        lltypes::LLVector3 Position;
        lltypes::U8 CheckFlags;
        lltypes::LLUUID ScreenshotID;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID AbuserID;
        lltypes::Variable<1> AbuseRegionName;
        lltypes::LLUUID AbuseRegionID;
        lltypes::Variable<1> Summary;
        lltypes::Variable<2> Details;
        lltypes::Variable<1> VersionString;
    };
    AgentDataBlock AgentData;
    ReportDataBlock ReportData;
};

QDataStream &operator<<(QDataStream & out, const UserReportMessage & o);
QDataStream &operator>>(QDataStream & in,  UserReportMessage & o);

struct AlertMessageMessage : UdpMessage {
    static const quint32 id=134U;
    static const IdByte byte=Low;

    AlertMessageMessage ();

    struct AlertDataBlock {
        lltypes::Variable<1> Message;
    };
    struct AlertInfoBlock {
        lltypes::Variable<1> Message;
        lltypes::Variable<1> ExtraParams;
    };
    AlertDataBlock AlertData;
    QVector<AlertInfoBlock> AlertInfo;
};

QDataStream &operator<<(QDataStream & out, const AlertMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  AlertMessageMessage & o);

struct AgentAlertMessageMessage : UdpMessage {
    static const quint32 id=135U;
    static const IdByte byte=Low;

    AgentAlertMessageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct AlertDataBlock {
        lltypes::BOOL Modal;
        lltypes::Variable<1> Message;
    };
    AgentDataBlock AgentData;
    AlertDataBlock AlertData;
};

QDataStream &operator<<(QDataStream & out, const AgentAlertMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentAlertMessageMessage & o);

struct MeanCollisionAlertMessage : UdpMessage {
    static const quint32 id=136U;
    static const IdByte byte=Low;

    MeanCollisionAlertMessage ();

    struct MeanCollisionBlock {
        lltypes::LLUUID Victim;
        lltypes::LLUUID Perp;
        lltypes::U32 Time;
        lltypes::F32 Mag;
        lltypes::U8 Type;
    };
    QVector<MeanCollisionBlock> MeanCollision;
};

QDataStream &operator<<(QDataStream & out, const MeanCollisionAlertMessage & o);
QDataStream &operator>>(QDataStream & in,  MeanCollisionAlertMessage & o);

struct ViewerFrozenMessageMessage : UdpMessage {
    static const quint32 id=137U;
    static const IdByte byte=Low;

    ViewerFrozenMessageMessage ();

    struct FrozenDataBlock {
        lltypes::BOOL Data;
    };
    FrozenDataBlock FrozenData;
};

QDataStream &operator<<(QDataStream & out, const ViewerFrozenMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  ViewerFrozenMessageMessage & o);

struct HealthMessageMessage : UdpMessage {
    static const quint32 id=138U;
    static const IdByte byte=Low;

    HealthMessageMessage ();

    struct HealthDataBlock {
        lltypes::F32 Health;
    };
    HealthDataBlock HealthData;
};

QDataStream &operator<<(QDataStream & out, const HealthMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  HealthMessageMessage & o);

struct ChatFromSimulatorMessage : UdpMessage {
    static const quint32 id=139U;
    static const IdByte byte=Low;

    ChatFromSimulatorMessage ();

    struct ChatDataBlock {
        lltypes::Variable<1> FromName;
        lltypes::LLUUID SourceID;
        lltypes::LLUUID OwnerID;
        lltypes::U8 SourceType;
        lltypes::U8 ChatType;
        lltypes::U8 Audible;
        lltypes::LLVector3 Position;
        lltypes::Variable<2> Message;
    };
    ChatDataBlock ChatData;
};

QDataStream &operator<<(QDataStream & out, const ChatFromSimulatorMessage & o);
QDataStream &operator>>(QDataStream & in,  ChatFromSimulatorMessage & o);

struct SimStatsMessage : UdpMessage {
    static const quint32 id=140U;
    static const IdByte byte=Low;

    SimStatsMessage ();

    struct RegionBlock {
        lltypes::U32 RegionX;
        lltypes::U32 RegionY;
        lltypes::U32 RegionFlags;
        lltypes::U32 ObjectCapacity;
    };
    struct StatBlock {
        lltypes::U32 StatID;
        lltypes::F32 StatValue;
    };
    struct PidStatBlock {
        lltypes::S32 PID;
    };
    RegionBlock Region;
    QVector<StatBlock> Stat;
    PidStatBlock PidStat;
};

QDataStream &operator<<(QDataStream & out, const SimStatsMessage & o);
QDataStream &operator>>(QDataStream & in,  SimStatsMessage & o);

struct RequestRegionInfoMessage : UdpMessage {
    static const quint32 id=141U;
    static const IdByte byte=Low;

    RequestRegionInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const RequestRegionInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestRegionInfoMessage & o);

struct RegionInfoMessage : UdpMessage {
    static const quint32 id=142U;
    static const IdByte byte=Low;

    RegionInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RegionInfoBlock {
        lltypes::Variable<1> SimName;
        lltypes::U32 EstateID;
        lltypes::U32 ParentEstateID;
        lltypes::U32 RegionFlags;
        lltypes::U8 SimAccess;
        lltypes::U8 MaxAgents;
        lltypes::F32 BillableFactor;
        lltypes::F32 ObjectBonusFactor;
        lltypes::F32 WaterHeight;
        lltypes::F32 TerrainRaiseLimit;
        lltypes::F32 TerrainLowerLimit;
        lltypes::S32 PricePerMeter;
        lltypes::S32 RedirectGridX;
        lltypes::S32 RedirectGridY;
        lltypes::BOOL UseEstateSun;
        lltypes::F32 SunHour;
    };
    struct RegionInfo2Block {
        lltypes::Variable<1> ProductSKU;
        lltypes::Variable<1> ProductName;
        lltypes::U32 MaxAgents32;
        lltypes::U32 HardMaxAgents;
        lltypes::U32 HardMaxObjects;
    };
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;
    RegionInfo2Block RegionInfo2;
};

QDataStream &operator<<(QDataStream & out, const RegionInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionInfoMessage & o);

struct GodUpdateRegionInfoMessage : UdpMessage {
    static const quint32 id=143U;
    static const IdByte byte=Low;

    GodUpdateRegionInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RegionInfoBlock {
        lltypes::Variable<1> SimName;
        lltypes::U32 EstateID;
        lltypes::U32 ParentEstateID;
        lltypes::U32 RegionFlags;
        lltypes::F32 BillableFactor;
        lltypes::S32 PricePerMeter;
        lltypes::S32 RedirectGridX;
        lltypes::S32 RedirectGridY;
    };
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;
};

QDataStream &operator<<(QDataStream & out, const GodUpdateRegionInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  GodUpdateRegionInfoMessage & o);

struct NearestLandingRegionRequestMessage : UdpMessage {
    static const quint32 id=144U;
    static const IdByte byte=Low;

    NearestLandingRegionRequestMessage ();

    struct RequestingRegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    RequestingRegionDataBlock RequestingRegionData;
};

QDataStream &operator<<(QDataStream & out, const NearestLandingRegionRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  NearestLandingRegionRequestMessage & o);

struct NearestLandingRegionReplyMessage : UdpMessage {
    static const quint32 id=145U;
    static const IdByte byte=Low;

    NearestLandingRegionReplyMessage ();

    struct LandingRegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    LandingRegionDataBlock LandingRegionData;
};

QDataStream &operator<<(QDataStream & out, const NearestLandingRegionReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  NearestLandingRegionReplyMessage & o);

struct NearestLandingRegionUpdatedMessage : UdpMessage {
    static const quint32 id=146U;
    static const IdByte byte=Low;

    NearestLandingRegionUpdatedMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    RegionDataBlock RegionData;
};

QDataStream &operator<<(QDataStream & out, const NearestLandingRegionUpdatedMessage & o);
QDataStream &operator>>(QDataStream & in,  NearestLandingRegionUpdatedMessage & o);

struct TeleportLandingStatusChangedMessage : UdpMessage {
    static const quint32 id=147U;
    static const IdByte byte=Low;

    TeleportLandingStatusChangedMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    RegionDataBlock RegionData;
};

QDataStream &operator<<(QDataStream & out, const TeleportLandingStatusChangedMessage & o);
QDataStream &operator>>(QDataStream & in,  TeleportLandingStatusChangedMessage & o);

struct RegionHandshakeMessage : UdpMessage {
    static const quint32 id=148U;
    static const IdByte byte=Low;

    RegionHandshakeMessage ();

    struct RegionInfoBlock {
        lltypes::U32 RegionFlags;
        lltypes::U8 SimAccess;
        lltypes::Variable<1> SimName;
        lltypes::LLUUID SimOwner;
        lltypes::BOOL IsEstateManager;
        lltypes::F32 WaterHeight;
        lltypes::F32 BillableFactor;
        lltypes::LLUUID CacheID;
        lltypes::LLUUID TerrainBase0;
        lltypes::LLUUID TerrainBase1;
        lltypes::LLUUID TerrainBase2;
        lltypes::LLUUID TerrainBase3;
        lltypes::LLUUID TerrainDetail0;
        lltypes::LLUUID TerrainDetail1;
        lltypes::LLUUID TerrainDetail2;
        lltypes::LLUUID TerrainDetail3;
        lltypes::F32 TerrainStartHeight00;
        lltypes::F32 TerrainStartHeight01;
        lltypes::F32 TerrainStartHeight10;
        lltypes::F32 TerrainStartHeight11;
        lltypes::F32 TerrainHeightRange00;
        lltypes::F32 TerrainHeightRange01;
        lltypes::F32 TerrainHeightRange10;
        lltypes::F32 TerrainHeightRange11;
    };
    struct RegionInfo2Block {
        lltypes::LLUUID RegionID;
    };
    struct RegionInfo3Block {
        lltypes::S32 CPUClassID;
        lltypes::S32 CPURatio;
        lltypes::Variable<1> ColoName;
        lltypes::Variable<1> ProductSKU;
        lltypes::Variable<1> ProductName;
    };
    RegionInfoBlock RegionInfo;
    RegionInfo2Block RegionInfo2;
    RegionInfo3Block RegionInfo3;
};

QDataStream &operator<<(QDataStream & out, const RegionHandshakeMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionHandshakeMessage & o);

struct RegionHandshakeReplyMessage : UdpMessage {
    static const quint32 id=149U;
    static const IdByte byte=Low;

    RegionHandshakeReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RegionInfoBlock {
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;
};

QDataStream &operator<<(QDataStream & out, const RegionHandshakeReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionHandshakeReplyMessage & o);

struct CoarseLocationUpdateMessage : UdpMessage {
    static const quint32 id=6U;
    static const IdByte byte=Medium;

    CoarseLocationUpdateMessage ();

    struct LocationBlock {
        lltypes::U8 X;
        lltypes::U8 Y;
        lltypes::U8 Z;
    };
    struct IndexBlock {
        lltypes::S16 You;
        lltypes::S16 Prey;
    };
    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    QVector<LocationBlock> Location;
    IndexBlock Index;
    QVector<AgentDataBlock> AgentData;
};

QDataStream &operator<<(QDataStream & out, const CoarseLocationUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  CoarseLocationUpdateMessage & o);

struct ImageDataMessage : UdpMessage {
    static const quint32 id=9U;
    static const IdByte byte=High;

    ImageDataMessage ();

    struct ImageIDBlock {
        lltypes::LLUUID ID;
        lltypes::U8 Codec;
        lltypes::U32 Size;
        lltypes::U16 Packets;
    };
    struct ImageDataBlock {
        lltypes::Variable<2> Data;
    };
    ImageIDBlock ImageID;
    ImageDataBlock ImageData;
};

QDataStream &operator<<(QDataStream & out, const ImageDataMessage & o);
QDataStream &operator>>(QDataStream & in,  ImageDataMessage & o);

struct ImagePacketMessage : UdpMessage {
    static const quint32 id=10U;
    static const IdByte byte=High;

    ImagePacketMessage ();

    struct ImageIDBlock {
        lltypes::LLUUID ID;
        lltypes::U16 Packet;
    };
    struct ImageDataBlock {
        lltypes::Variable<2> Data;
    };
    ImageIDBlock ImageID;
    ImageDataBlock ImageData;
};

QDataStream &operator<<(QDataStream & out, const ImagePacketMessage & o);
QDataStream &operator>>(QDataStream & in,  ImagePacketMessage & o);

struct LayerDataMessage : UdpMessage {
    static const quint32 id=11U;
    static const IdByte byte=High;

    LayerDataMessage ();

    struct LayerIDBlock {
        lltypes::U8 Type;
    };
    struct LayerDataBlock {
        lltypes::Variable<2> Data;
    };
    LayerIDBlock LayerID;
    LayerDataBlock LayerData;
};

QDataStream &operator<<(QDataStream & out, const LayerDataMessage & o);
QDataStream &operator>>(QDataStream & in,  LayerDataMessage & o);

struct ObjectUpdateMessage : UdpMessage {
    static const quint32 id=12U;
    static const IdByte byte=High;

    ObjectUpdateMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U16 TimeDilation;
    };
    struct ObjectDataBlock {
        lltypes::U32 ID;
        lltypes::U8 State;
        lltypes::LLUUID FullID;
        lltypes::U32 CRC;
        lltypes::U8 PCode;
        lltypes::U8 Material;
        lltypes::U8 ClickAction;
        lltypes::LLVector3 Scale;
        lltypes::Variable<1> ObjectData;
        lltypes::U32 ParentID;
        lltypes::U32 UpdateFlags;
        lltypes::U8 PathCurve;
        lltypes::U8 ProfileCurve;
        lltypes::U16 PathBegin;
        lltypes::U16 PathEnd;
        lltypes::U8 PathScaleX;
        lltypes::U8 PathScaleY;
        lltypes::U8 PathShearX;
        lltypes::U8 PathShearY;
        lltypes::S8 PathTwist;
        lltypes::S8 PathTwistBegin;
        lltypes::S8 PathRadiusOffset;
        lltypes::S8 PathTaperX;
        lltypes::S8 PathTaperY;
        lltypes::U8 PathRevolutions;
        lltypes::S8 PathSkew;
        lltypes::U16 ProfileBegin;
        lltypes::U16 ProfileEnd;
        lltypes::U16 ProfileHollow;
        lltypes::Variable<2> TextureEntry;
        lltypes::Variable<1> TextureAnim;
        lltypes::Variable<2> NameValue;
        lltypes::Variable<2> Data;
        lltypes::Variable<1> Text;
        lltypes::Fixed<4> TextColor;
        lltypes::Variable<1> MediaURL;
        lltypes::Variable<1> PSBlock;
        lltypes::Variable<1> ExtraParams;
        lltypes::LLUUID Sound;
        lltypes::LLUUID OwnerID;
        lltypes::F32 Gain;
        lltypes::U8 Flags;
        lltypes::F32 Radius;
        lltypes::U8 JointType;
        lltypes::LLVector3 JointPivot;
        lltypes::LLVector3 JointAxisOrAnchor;
    };
    RegionDataBlock RegionData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectUpdateMessage & o);

struct ObjectUpdateCompressedMessage : UdpMessage {
    static const quint32 id=13U;
    static const IdByte byte=High;

    ObjectUpdateCompressedMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U16 TimeDilation;
    };
    struct ObjectDataBlock {
        lltypes::U32 UpdateFlags;
        lltypes::Variable<2> Data;
    };
    RegionDataBlock RegionData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectUpdateCompressedMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectUpdateCompressedMessage & o);

struct ObjectUpdateCachedMessage : UdpMessage {
    static const quint32 id=14U;
    static const IdByte byte=High;

    ObjectUpdateCachedMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U16 TimeDilation;
    };
    struct ObjectDataBlock {
        lltypes::U32 ID;
        lltypes::U32 CRC;
        lltypes::U32 UpdateFlags;
    };
    RegionDataBlock RegionData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectUpdateCachedMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectUpdateCachedMessage & o);

struct ImprovedTerseObjectUpdateMessage : UdpMessage {
    static const quint32 id=15U;
    static const IdByte byte=High;

    ImprovedTerseObjectUpdateMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U16 TimeDilation;
    };
    struct ObjectDataBlock {
        lltypes::Variable<1> Data;
        lltypes::Variable<2> TextureEntry;
    };
    RegionDataBlock RegionData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ImprovedTerseObjectUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ImprovedTerseObjectUpdateMessage & o);

struct KillObjectMessage : UdpMessage {
    static const quint32 id=16U;
    static const IdByte byte=High;

    KillObjectMessage ();

    struct ObjectDataBlock {
        lltypes::U32 ID;
    };
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const KillObjectMessage & o);
QDataStream &operator>>(QDataStream & in,  KillObjectMessage & o);

struct CrossedRegionMessage : UdpMessage {
    static const quint32 id=7U;
    static const IdByte byte=Medium;

    CrossedRegionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RegionDataBlock {
        lltypes::IPADDR SimIP;
        lltypes::IPPORT SimPort;
        lltypes::U64 RegionHandle;
        lltypes::Variable<2> SeedCapability;
    };
    struct InfoBlock {
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
    };
    AgentDataBlock AgentData;
    RegionDataBlock RegionData;
    InfoBlock Info;
};

QDataStream &operator<<(QDataStream & out, const CrossedRegionMessage & o);
QDataStream &operator>>(QDataStream & in,  CrossedRegionMessage & o);

struct SimulatorViewerTimeMessageMessage : UdpMessage {
    static const quint32 id=150U;
    static const IdByte byte=Low;

    SimulatorViewerTimeMessageMessage ();

    struct TimeInfoBlock {
        lltypes::U64 UsecSinceStart;
        lltypes::U32 SecPerDay;
        lltypes::U32 SecPerYear;
        lltypes::LLVector3 SunDirection;
        lltypes::F32 SunPhase;
        lltypes::LLVector3 SunAngVelocity;
    };
    TimeInfoBlock TimeInfo;
};

QDataStream &operator<<(QDataStream & out, const SimulatorViewerTimeMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  SimulatorViewerTimeMessageMessage & o);

struct EnableSimulatorMessage : UdpMessage {
    static const quint32 id=151U;
    static const IdByte byte=Low;

    EnableSimulatorMessage ();

    struct SimulatorInfoBlock {
        lltypes::U64 Handle;
        lltypes::IPADDR IP;
        lltypes::IPPORT Port;
    };
    SimulatorInfoBlock SimulatorInfo;
};

QDataStream &operator<<(QDataStream & out, const EnableSimulatorMessage & o);
QDataStream &operator>>(QDataStream & in,  EnableSimulatorMessage & o);

struct DisableSimulatorMessage : UdpMessage {
    static const quint32 id=152U;
    static const IdByte byte=Low;

    DisableSimulatorMessage ();

};

QDataStream &operator<<(QDataStream & out, const DisableSimulatorMessage & o);
QDataStream &operator>>(QDataStream & in,  DisableSimulatorMessage & o);

struct ConfirmEnableSimulatorMessage : UdpMessage {
    static const quint32 id=8U;
    static const IdByte byte=Medium;

    ConfirmEnableSimulatorMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ConfirmEnableSimulatorMessage & o);
QDataStream &operator>>(QDataStream & in,  ConfirmEnableSimulatorMessage & o);

struct TransferRequestMessage : UdpMessage {
    static const quint32 id=153U;
    static const IdByte byte=Low;

    TransferRequestMessage ();

    struct TransferInfoBlock {
        lltypes::LLUUID TransferID;
        lltypes::S32 ChannelType;
        lltypes::S32 SourceType;
        lltypes::F32 Priority;
        lltypes::Variable<2> Params;
    };
    TransferInfoBlock TransferInfo;
};

QDataStream &operator<<(QDataStream & out, const TransferRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferRequestMessage & o);

struct TransferInfoMessage : UdpMessage {
    static const quint32 id=154U;
    static const IdByte byte=Low;

    TransferInfoMessage ();

    struct TransferInfoBlock {
        lltypes::LLUUID TransferID;
        lltypes::S32 ChannelType;
        lltypes::S32 TargetType;
        lltypes::S32 Status;
        lltypes::S32 Size;
        lltypes::Variable<2> Params;
    };
    TransferInfoBlock TransferInfo;
};

QDataStream &operator<<(QDataStream & out, const TransferInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferInfoMessage & o);

struct TransferPacketMessage : UdpMessage {
    static const quint32 id=17U;
    static const IdByte byte=High;

    TransferPacketMessage ();

    struct TransferDataBlock {
        lltypes::LLUUID TransferID;
        lltypes::S32 ChannelType;
        lltypes::S32 Packet;
        lltypes::S32 Status;
        lltypes::Variable<2> Data;
    };
    TransferDataBlock TransferData;
};

QDataStream &operator<<(QDataStream & out, const TransferPacketMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferPacketMessage & o);

struct TransferAbortMessage : UdpMessage {
    static const quint32 id=155U;
    static const IdByte byte=Low;

    TransferAbortMessage ();

    struct TransferInfoBlock {
        lltypes::LLUUID TransferID;
        lltypes::S32 ChannelType;
    };
    TransferInfoBlock TransferInfo;
};

QDataStream &operator<<(QDataStream & out, const TransferAbortMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferAbortMessage & o);

struct RequestXferMessage : UdpMessage {
    static const quint32 id=156U;
    static const IdByte byte=Low;

    RequestXferMessage ();

    struct XferIDBlock {
        lltypes::U64 ID;
        lltypes::Variable<1> Filename;
        lltypes::U8 FilePath;
        lltypes::BOOL DeleteOnCompletion;
        lltypes::BOOL UseBigPackets;
        lltypes::LLUUID VFileID;
        lltypes::S16 VFileType;
    };
    XferIDBlock XferID;
};

QDataStream &operator<<(QDataStream & out, const RequestXferMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestXferMessage & o);

struct SendXferPacketMessage : UdpMessage {
    static const quint32 id=18U;
    static const IdByte byte=High;

    SendXferPacketMessage ();

    struct XferIDBlock {
        lltypes::U64 ID;
        lltypes::U32 Packet;
    };
    struct DataPacketBlock {
        lltypes::Variable<2> Data;
    };
    XferIDBlock XferID;
    DataPacketBlock DataPacket;
};

QDataStream &operator<<(QDataStream & out, const SendXferPacketMessage & o);
QDataStream &operator>>(QDataStream & in,  SendXferPacketMessage & o);

struct ConfirmXferPacketMessage : UdpMessage {
    static const quint32 id=19U;
    static const IdByte byte=High;

    ConfirmXferPacketMessage ();

    struct XferIDBlock {
        lltypes::U64 ID;
        lltypes::U32 Packet;
    };
    XferIDBlock XferID;
};

QDataStream &operator<<(QDataStream & out, const ConfirmXferPacketMessage & o);
QDataStream &operator>>(QDataStream & in,  ConfirmXferPacketMessage & o);

struct AbortXferMessage : UdpMessage {
    static const quint32 id=157U;
    static const IdByte byte=Low;

    AbortXferMessage ();

    struct XferIDBlock {
        lltypes::U64 ID;
        lltypes::S32 Result;
    };
    XferIDBlock XferID;
};

QDataStream &operator<<(QDataStream & out, const AbortXferMessage & o);
QDataStream &operator>>(QDataStream & in,  AbortXferMessage & o);

struct AvatarAnimationMessage : UdpMessage {
    static const quint32 id=20U;
    static const IdByte byte=High;

    AvatarAnimationMessage ();

    struct SenderBlock {
        lltypes::LLUUID ID;
    };
    struct AnimationListBlock {
        lltypes::LLUUID AnimID;
        lltypes::S32 AnimSequenceID;
    };
    struct AnimationSourceListBlock {
        lltypes::LLUUID ObjectID;
    };
    struct PhysicalAvatarEventListBlock {
        lltypes::Variable<1> TypeData;
    };
    SenderBlock Sender;
    QVector<AnimationListBlock> AnimationList;
    QVector<AnimationSourceListBlock> AnimationSourceList;
    QVector<PhysicalAvatarEventListBlock> PhysicalAvatarEventList;
};

QDataStream &operator<<(QDataStream & out, const AvatarAnimationMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarAnimationMessage & o);

struct AvatarAppearanceMessage : UdpMessage {
    static const quint32 id=158U;
    static const IdByte byte=Low;

    AvatarAppearanceMessage ();

    struct SenderBlock {
        lltypes::LLUUID ID;
        lltypes::BOOL IsTrial;
    };
    struct ObjectDataBlock {
        lltypes::Variable<2> TextureEntry;
    };
    struct VisualParamBlock {
        lltypes::U8 ParamValue;
    };
    SenderBlock Sender;
    ObjectDataBlock ObjectData;
    QVector<VisualParamBlock> VisualParam;
};

QDataStream &operator<<(QDataStream & out, const AvatarAppearanceMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarAppearanceMessage & o);

struct AvatarSitResponseMessage : UdpMessage {
    static const quint32 id=21U;
    static const IdByte byte=High;

    AvatarSitResponseMessage ();

    struct SitObjectBlock {
        lltypes::LLUUID ID;
    };
    struct SitTransformBlock {
        lltypes::BOOL AutoPilot;
        lltypes::LLVector3 SitPosition;
        lltypes::LLQuaternion SitRotation;
        lltypes::LLVector3 CameraEyeOffset;
        lltypes::LLVector3 CameraAtOffset;
        lltypes::BOOL ForceMouselook;
    };
    SitObjectBlock SitObject;
    SitTransformBlock SitTransform;
};

QDataStream &operator<<(QDataStream & out, const AvatarSitResponseMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarSitResponseMessage & o);

struct SetFollowCamPropertiesMessage : UdpMessage {
    static const quint32 id=159U;
    static const IdByte byte=Low;

    SetFollowCamPropertiesMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    struct CameraPropertyBlock {
        lltypes::S32 Type;
        lltypes::F32 Value;
    };
    ObjectDataBlock ObjectData;
    QVector<CameraPropertyBlock> CameraProperty;
};

QDataStream &operator<<(QDataStream & out, const SetFollowCamPropertiesMessage & o);
QDataStream &operator>>(QDataStream & in,  SetFollowCamPropertiesMessage & o);

struct ClearFollowCamPropertiesMessage : UdpMessage {
    static const quint32 id=160U;
    static const IdByte byte=Low;

    ClearFollowCamPropertiesMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ClearFollowCamPropertiesMessage & o);
QDataStream &operator>>(QDataStream & in,  ClearFollowCamPropertiesMessage & o);

struct CameraConstraintMessage : UdpMessage {
    static const quint32 id=22U;
    static const IdByte byte=High;

    CameraConstraintMessage ();

    struct CameraCollidePlaneBlock {
        lltypes::LLVector4 Plane;
    };
    CameraCollidePlaneBlock CameraCollidePlane;
};

QDataStream &operator<<(QDataStream & out, const CameraConstraintMessage & o);
QDataStream &operator>>(QDataStream & in,  CameraConstraintMessage & o);

struct ObjectPropertiesMessage : UdpMessage {
    static const quint32 id=9U;
    static const IdByte byte=Medium;

    ObjectPropertiesMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U64 CreationDate;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::S32 OwnershipCost;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::U8 AggregatePerms;
        lltypes::U8 AggregatePermTextures;
        lltypes::U8 AggregatePermTexturesOwner;
        lltypes::U32 Category;
        lltypes::S16 InventorySerial;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID FromTaskID;
        lltypes::LLUUID LastOwnerID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::Variable<1> TouchName;
        lltypes::Variable<1> SitName;
        lltypes::Variable<1> TextureID;
    };
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectPropertiesMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectPropertiesMessage & o);

struct ObjectPropertiesFamilyMessage : UdpMessage {
    static const quint32 id=10U;
    static const IdByte byte=Medium;

    ObjectPropertiesFamilyMessage ();

    struct ObjectDataBlock {
        lltypes::U32 RequestFlags;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::S32 OwnershipCost;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::U32 Category;
        lltypes::LLUUID LastOwnerID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
    };
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectPropertiesFamilyMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectPropertiesFamilyMessage & o);

struct RequestPayPriceMessage : UdpMessage {
    static const quint32 id=161U;
    static const IdByte byte=Low;

    RequestPayPriceMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
    };
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RequestPayPriceMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestPayPriceMessage & o);

struct PayPriceReplyMessage : UdpMessage {
    static const quint32 id=162U;
    static const IdByte byte=Low;

    PayPriceReplyMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::S32 DefaultPayPrice;
    };
    struct ButtonDataBlock {
        lltypes::S32 PayButton;
    };
    ObjectDataBlock ObjectData;
    QVector<ButtonDataBlock> ButtonData;
};

QDataStream &operator<<(QDataStream & out, const PayPriceReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  PayPriceReplyMessage & o);

struct KickUserMessage : UdpMessage {
    static const quint32 id=163U;
    static const IdByte byte=Low;

    KickUserMessage ();

    struct TargetBlockBlock {
        lltypes::IPADDR TargetIP;
        lltypes::IPPORT TargetPort;
    };
    struct UserInfoBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::Variable<2> Reason;
    };
    TargetBlockBlock TargetBlock;
    UserInfoBlock UserInfo;
};

QDataStream &operator<<(QDataStream & out, const KickUserMessage & o);
QDataStream &operator>>(QDataStream & in,  KickUserMessage & o);

struct KickUserAckMessage : UdpMessage {
    static const quint32 id=164U;
    static const IdByte byte=Low;

    KickUserAckMessage ();

    struct UserInfoBlock {
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
    };
    UserInfoBlock UserInfo;
};

QDataStream &operator<<(QDataStream & out, const KickUserAckMessage & o);
QDataStream &operator>>(QDataStream & in,  KickUserAckMessage & o);

struct GodKickUserMessage : UdpMessage {
    static const quint32 id=165U;
    static const IdByte byte=Low;

    GodKickUserMessage ();

    struct UserInfoBlock {
        lltypes::LLUUID GodID;
        lltypes::LLUUID GodSessionID;
        lltypes::LLUUID AgentID;
        lltypes::U32 KickFlags;
        lltypes::Variable<2> Reason;
    };
    UserInfoBlock UserInfo;
};

QDataStream &operator<<(QDataStream & out, const GodKickUserMessage & o);
QDataStream &operator>>(QDataStream & in,  GodKickUserMessage & o);

struct SystemKickUserMessage : UdpMessage {
    static const quint32 id=166U;
    static const IdByte byte=Low;

    SystemKickUserMessage ();

    struct AgentInfoBlock {
        lltypes::LLUUID AgentID;
    };
    QVector<AgentInfoBlock> AgentInfo;
};

QDataStream &operator<<(QDataStream & out, const SystemKickUserMessage & o);
QDataStream &operator>>(QDataStream & in,  SystemKickUserMessage & o);

struct EjectUserMessage : UdpMessage {
    static const quint32 id=167U;
    static const IdByte byte=Low;

    EjectUserMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID TargetID;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const EjectUserMessage & o);
QDataStream &operator>>(QDataStream & in,  EjectUserMessage & o);

struct FreezeUserMessage : UdpMessage {
    static const quint32 id=168U;
    static const IdByte byte=Low;

    FreezeUserMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID TargetID;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const FreezeUserMessage & o);
QDataStream &operator>>(QDataStream & in,  FreezeUserMessage & o);

struct AvatarPropertiesRequestMessage : UdpMessage {
    static const quint32 id=169U;
    static const IdByte byte=Low;

    AvatarPropertiesRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID AvatarID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AvatarPropertiesRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPropertiesRequestMessage & o);

struct AvatarPropertiesRequestBackendMessage : UdpMessage {
    static const quint32 id=170U;
    static const IdByte byte=Low;

    AvatarPropertiesRequestBackendMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID AvatarID;
        lltypes::U8 GodLevel;
        lltypes::BOOL WebProfilesDisabled;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AvatarPropertiesRequestBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPropertiesRequestBackendMessage & o);

struct AvatarPropertiesReplyMessage : UdpMessage {
    static const quint32 id=171U;
    static const IdByte byte=Low;

    AvatarPropertiesReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID AvatarID;
    };
    struct PropertiesDataBlock {
        lltypes::LLUUID ImageID;
        lltypes::LLUUID FLImageID;
        lltypes::LLUUID PartnerID;
        lltypes::Variable<2> AboutText;
        lltypes::Variable<1> FLAboutText;
        lltypes::Variable<1> BornOn;
        lltypes::Variable<1> ProfileURL;
        lltypes::Variable<1> CharterMember;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;
};

QDataStream &operator<<(QDataStream & out, const AvatarPropertiesReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPropertiesReplyMessage & o);

struct AvatarInterestsReplyMessage : UdpMessage {
    static const quint32 id=172U;
    static const IdByte byte=Low;

    AvatarInterestsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID AvatarID;
    };
    struct PropertiesDataBlock {
        lltypes::U32 WantToMask;
        lltypes::Variable<1> WantToText;
        lltypes::U32 SkillsMask;
        lltypes::Variable<1> SkillsText;
        lltypes::Variable<1> LanguagesText;
    };
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;
};

QDataStream &operator<<(QDataStream & out, const AvatarInterestsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarInterestsReplyMessage & o);

struct AvatarGroupsReplyMessage : UdpMessage {
    static const quint32 id=173U;
    static const IdByte byte=Low;

    AvatarGroupsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID AvatarID;
    };
    struct GroupDataBlock {
        lltypes::U64 GroupPowers;
        lltypes::BOOL AcceptNotices;
        lltypes::Variable<1> GroupTitle;
        lltypes::LLUUID GroupID;
        lltypes::Variable<1> GroupName;
        lltypes::LLUUID GroupInsigniaID;
    };
    struct NewGroupDataBlock {
        lltypes::BOOL ListInProfile;
    };
    AgentDataBlock AgentData;
    QVector<GroupDataBlock> GroupData;
    NewGroupDataBlock NewGroupData;
};

QDataStream &operator<<(QDataStream & out, const AvatarGroupsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarGroupsReplyMessage & o);

struct AvatarPropertiesUpdateMessage : UdpMessage {
    static const quint32 id=174U;
    static const IdByte byte=Low;

    AvatarPropertiesUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct PropertiesDataBlock {
        lltypes::LLUUID ImageID;
        lltypes::LLUUID FLImageID;
        lltypes::Variable<2> AboutText;
        lltypes::Variable<1> FLAboutText;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
        lltypes::Variable<1> ProfileURL;
    };
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;
};

QDataStream &operator<<(QDataStream & out, const AvatarPropertiesUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPropertiesUpdateMessage & o);

struct AvatarInterestsUpdateMessage : UdpMessage {
    static const quint32 id=175U;
    static const IdByte byte=Low;

    AvatarInterestsUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct PropertiesDataBlock {
        lltypes::U32 WantToMask;
        lltypes::Variable<1> WantToText;
        lltypes::U32 SkillsMask;
        lltypes::Variable<1> SkillsText;
        lltypes::Variable<1> LanguagesText;
    };
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;
};

QDataStream &operator<<(QDataStream & out, const AvatarInterestsUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarInterestsUpdateMessage & o);

struct AvatarNotesReplyMessage : UdpMessage {
    static const quint32 id=176U;
    static const IdByte byte=Low;

    AvatarNotesReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::LLUUID TargetID;
        lltypes::Variable<2> Notes;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarNotesReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarNotesReplyMessage & o);

struct AvatarNotesUpdateMessage : UdpMessage {
    static const quint32 id=177U;
    static const IdByte byte=Low;

    AvatarNotesUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID TargetID;
        lltypes::Variable<2> Notes;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarNotesUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarNotesUpdateMessage & o);

struct AvatarPicksReplyMessage : UdpMessage {
    static const quint32 id=178U;
    static const IdByte byte=Low;

    AvatarPicksReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TargetID;
    };
    struct DataBlock {
        lltypes::LLUUID PickID;
        lltypes::Variable<1> PickName;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const AvatarPicksReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  AvatarPicksReplyMessage & o);

struct EventInfoRequestMessage : UdpMessage {
    static const quint32 id=179U;
    static const IdByte byte=Low;

    EventInfoRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventInfoRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EventInfoRequestMessage & o);

struct EventInfoReplyMessage : UdpMessage {
    static const quint32 id=180U;
    static const IdByte byte=Low;

    EventInfoReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
        lltypes::Variable<1> Creator;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Category;
        lltypes::Variable<2> Desc;
        lltypes::Variable<1> Date;
        lltypes::U32 DateUTC;
        lltypes::U32 Duration;
        lltypes::U32 Cover;
        lltypes::U32 Amount;
        lltypes::Variable<1> SimName;
        lltypes::LLVector3d GlobalPos;
        lltypes::U32 EventFlags;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventInfoReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  EventInfoReplyMessage & o);

struct EventNotificationAddRequestMessage : UdpMessage {
    static const quint32 id=181U;
    static const IdByte byte=Low;

    EventNotificationAddRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventNotificationAddRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EventNotificationAddRequestMessage & o);

struct EventNotificationRemoveRequestMessage : UdpMessage {
    static const quint32 id=182U;
    static const IdByte byte=Low;

    EventNotificationRemoveRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventNotificationRemoveRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EventNotificationRemoveRequestMessage & o);

struct EventGodDeleteMessage : UdpMessage {
    static const quint32 id=183U;
    static const IdByte byte=Low;

    EventGodDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::Variable<1> QueryText;
        lltypes::U32 QueryFlags;
        lltypes::S32 QueryStart;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const EventGodDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  EventGodDeleteMessage & o);

struct PickInfoReplyMessage : UdpMessage {
    static const quint32 id=184U;
    static const IdByte byte=Low;

    PickInfoReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::LLUUID PickID;
        lltypes::LLUUID CreatorID;
        lltypes::BOOL TopPick;
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Desc;
        lltypes::LLUUID SnapshotID;
        lltypes::Variable<1> User;
        lltypes::Variable<1> OriginalName;
        lltypes::Variable<1> SimName;
        lltypes::LLVector3d PosGlobal;
        lltypes::S32 SortOrder;
        lltypes::BOOL Enabled;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const PickInfoReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  PickInfoReplyMessage & o);

struct PickInfoUpdateMessage : UdpMessage {
    static const quint32 id=185U;
    static const IdByte byte=Low;

    PickInfoUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID PickID;
        lltypes::LLUUID CreatorID;
        lltypes::BOOL TopPick;
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Desc;
        lltypes::LLUUID SnapshotID;
        lltypes::LLVector3d PosGlobal;
        lltypes::S32 SortOrder;
        lltypes::BOOL Enabled;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const PickInfoUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  PickInfoUpdateMessage & o);

struct PickDeleteMessage : UdpMessage {
    static const quint32 id=186U;
    static const IdByte byte=Low;

    PickDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID PickID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const PickDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  PickDeleteMessage & o);

struct PickGodDeleteMessage : UdpMessage {
    static const quint32 id=187U;
    static const IdByte byte=Low;

    PickGodDeleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID PickID;
        lltypes::LLUUID QueryID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const PickGodDeleteMessage & o);
QDataStream &operator>>(QDataStream & in,  PickGodDeleteMessage & o);

struct ScriptQuestionMessage : UdpMessage {
    static const quint32 id=188U;
    static const IdByte byte=Low;

    ScriptQuestionMessage ();

    struct DataBlock {
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::Variable<1> ObjectName;
        lltypes::Variable<1> ObjectOwner;
        lltypes::S32 Questions;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ScriptQuestionMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptQuestionMessage & o);

struct ScriptControlChangeMessage : UdpMessage {
    static const quint32 id=189U;
    static const IdByte byte=Low;

    ScriptControlChangeMessage ();

    struct DataBlock {
        lltypes::BOOL TakeControls;
        lltypes::U32 Controls;
        lltypes::BOOL PassToAgent;
    };
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const ScriptControlChangeMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptControlChangeMessage & o);

struct ScriptDialogMessage : UdpMessage {
    static const quint32 id=190U;
    static const IdByte byte=Low;

    ScriptDialogMessage ();

    struct DataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::Variable<1> FirstName;
        lltypes::Variable<1> LastName;
        lltypes::Variable<1> ObjectName;
        lltypes::Variable<2> Message;
        lltypes::S32 ChatChannel;
        lltypes::LLUUID ImageID;
    };
    struct ButtonsBlock {
        lltypes::Variable<1> ButtonLabel;
    };
    DataBlock Data;
    QVector<ButtonsBlock> Buttons;
};

QDataStream &operator<<(QDataStream & out, const ScriptDialogMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptDialogMessage & o);

struct ScriptDialogReplyMessage : UdpMessage {
    static const quint32 id=191U;
    static const IdByte byte=Low;

    ScriptDialogReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::S32 ChatChannel;
        lltypes::S32 ButtonIndex;
        lltypes::Variable<1> ButtonLabel;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ScriptDialogReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptDialogReplyMessage & o);

struct ForceScriptControlReleaseMessage : UdpMessage {
    static const quint32 id=192U;
    static const IdByte byte=Low;

    ForceScriptControlReleaseMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ForceScriptControlReleaseMessage & o);
QDataStream &operator>>(QDataStream & in,  ForceScriptControlReleaseMessage & o);

struct RevokePermissionsMessage : UdpMessage {
    static const quint32 id=193U;
    static const IdByte byte=Low;

    RevokePermissionsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::U32 ObjectPermissions;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const RevokePermissionsMessage & o);
QDataStream &operator>>(QDataStream & in,  RevokePermissionsMessage & o);

struct LoadURLMessage : UdpMessage {
    static const quint32 id=194U;
    static const IdByte byte=Low;

    LoadURLMessage ();

    struct DataBlock {
        lltypes::Variable<1> ObjectName;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::BOOL OwnerIsGroup;
        lltypes::Variable<1> Message;
        lltypes::Variable<1> URL;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const LoadURLMessage & o);
QDataStream &operator>>(QDataStream & in,  LoadURLMessage & o);

struct ScriptTeleportRequestMessage : UdpMessage {
    static const quint32 id=195U;
    static const IdByte byte=Low;

    ScriptTeleportRequestMessage ();

    struct DataBlock {
        lltypes::Variable<1> ObjectName;
        lltypes::Variable<1> SimName;
        lltypes::LLVector3 SimPosition;
        lltypes::LLVector3 LookAt;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ScriptTeleportRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptTeleportRequestMessage & o);

struct ParcelOverlayMessage : UdpMessage {
    static const quint32 id=196U;
    static const IdByte byte=Low;

    ParcelOverlayMessage ();

    struct ParcelDataBlock {
        lltypes::S32 SequenceID;
        lltypes::Variable<2> Data;
    };
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelOverlayMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelOverlayMessage & o);

struct ParcelPropertiesRequestMessage : UdpMessage {
    static const quint32 id=11U;
    static const IdByte byte=Medium;

    ParcelPropertiesRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 SequenceID;
        lltypes::F32 West;
        lltypes::F32 South;
        lltypes::F32 East;
        lltypes::F32 North;
        lltypes::BOOL SnapSelection;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelPropertiesRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelPropertiesRequestMessage & o);

struct ParcelPropertiesRequestByIDMessage : UdpMessage {
    static const quint32 id=197U;
    static const IdByte byte=Low;

    ParcelPropertiesRequestByIDMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 SequenceID;
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelPropertiesRequestByIDMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelPropertiesRequestByIDMessage & o);

struct ParcelPropertiesMessage : UdpMessage {
    static const quint32 id=23U;
    static const IdByte byte=High;

    ParcelPropertiesMessage ();

    struct ParcelDataBlock {
        lltypes::S32 RequestResult;
        lltypes::S32 SequenceID;
        lltypes::BOOL SnapSelection;
        lltypes::S32 SelfCount;
        lltypes::S32 OtherCount;
        lltypes::S32 PublicCount;
        lltypes::S32 LocalID;
        lltypes::LLUUID OwnerID;
        lltypes::BOOL IsGroupOwned;
        lltypes::U32 AuctionID;
        lltypes::S32 ClaimDate;
        lltypes::S32 ClaimPrice;
        lltypes::S32 RentPrice;
        lltypes::LLVector3 AABBMin;
        lltypes::LLVector3 AABBMax;
        lltypes::Variable<2> Bitmap;
        lltypes::S32 Area;
        lltypes::U8 Status;
        lltypes::S32 SimWideMaxPrims;
        lltypes::S32 SimWideTotalPrims;
        lltypes::S32 MaxPrims;
        lltypes::S32 TotalPrims;
        lltypes::S32 OwnerPrims;
        lltypes::S32 GroupPrims;
        lltypes::S32 OtherPrims;
        lltypes::S32 SelectedPrims;
        lltypes::F32 ParcelPrimBonus;
        lltypes::S32 OtherCleanTime;
        lltypes::U32 ParcelFlags;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Desc;
        lltypes::Variable<1> MusicURL;
        lltypes::Variable<1> MediaURL;
        lltypes::LLUUID MediaID;
        lltypes::U8 MediaAutoScale;
        lltypes::LLUUID GroupID;
        lltypes::S32 PassPrice;
        lltypes::F32 PassHours;
        lltypes::U8 Category;
        lltypes::LLUUID AuthBuyerID;
        lltypes::LLUUID SnapshotID;
        lltypes::LLVector3 UserLocation;
        lltypes::LLVector3 UserLookAt;
        lltypes::U8 LandingType;
        lltypes::BOOL RegionPushOverride;
        lltypes::BOOL RegionDenyAnonymous;
        lltypes::BOOL RegionDenyIdentified;
        lltypes::BOOL RegionDenyTransacted;
    };
    struct AgeVerificationBlockBlock {
        lltypes::BOOL RegionDenyAgeUnverified;
    };
    ParcelDataBlock ParcelData;
    AgeVerificationBlockBlock AgeVerificationBlock;
};

QDataStream &operator<<(QDataStream & out, const ParcelPropertiesMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelPropertiesMessage & o);

struct ParcelPropertiesUpdateMessage : UdpMessage {
    static const quint32 id=198U;
    static const IdByte byte=Low;

    ParcelPropertiesUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::U32 Flags;
        lltypes::U32 ParcelFlags;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Desc;
        lltypes::Variable<1> MusicURL;
        lltypes::Variable<1> MediaURL;
        lltypes::LLUUID MediaID;
        lltypes::U8 MediaAutoScale;
        lltypes::LLUUID GroupID;
        lltypes::S32 PassPrice;
        lltypes::F32 PassHours;
        lltypes::U8 Category;
        lltypes::LLUUID AuthBuyerID;
        lltypes::LLUUID SnapshotID;
        lltypes::LLVector3 UserLocation;
        lltypes::LLVector3 UserLookAt;
        lltypes::U8 LandingType;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelPropertiesUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelPropertiesUpdateMessage & o);

struct ParcelReturnObjectsMessage : UdpMessage {
    static const quint32 id=199U;
    static const IdByte byte=Low;

    ParcelReturnObjectsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::U32 ReturnType;
    };
    struct TaskIDsBlock {
        lltypes::LLUUID TaskID;
    };
    struct OwnerIDsBlock {
        lltypes::LLUUID OwnerID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    QVector<TaskIDsBlock> TaskIDs;
    QVector<OwnerIDsBlock> OwnerIDs;
};

QDataStream &operator<<(QDataStream & out, const ParcelReturnObjectsMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelReturnObjectsMessage & o);

struct ParcelSetOtherCleanTimeMessage : UdpMessage {
    static const quint32 id=200U;
    static const IdByte byte=Low;

    ParcelSetOtherCleanTimeMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::S32 OtherCleanTime;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelSetOtherCleanTimeMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelSetOtherCleanTimeMessage & o);

struct ParcelDisableObjectsMessage : UdpMessage {
    static const quint32 id=201U;
    static const IdByte byte=Low;

    ParcelDisableObjectsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::U32 ReturnType;
    };
    struct TaskIDsBlock {
        lltypes::LLUUID TaskID;
    };
    struct OwnerIDsBlock {
        lltypes::LLUUID OwnerID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    QVector<TaskIDsBlock> TaskIDs;
    QVector<OwnerIDsBlock> OwnerIDs;
};

QDataStream &operator<<(QDataStream & out, const ParcelDisableObjectsMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelDisableObjectsMessage & o);

struct ParcelSelectObjectsMessage : UdpMessage {
    static const quint32 id=202U;
    static const IdByte byte=Low;

    ParcelSelectObjectsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::U32 ReturnType;
    };
    struct ReturnIDsBlock {
        lltypes::LLUUID ReturnID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    QVector<ReturnIDsBlock> ReturnIDs;
};

QDataStream &operator<<(QDataStream & out, const ParcelSelectObjectsMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelSelectObjectsMessage & o);

struct EstateCovenantRequestMessage : UdpMessage {
    static const quint32 id=203U;
    static const IdByte byte=Low;

    EstateCovenantRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const EstateCovenantRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EstateCovenantRequestMessage & o);

struct EstateCovenantReplyMessage : UdpMessage {
    static const quint32 id=204U;
    static const IdByte byte=Low;

    EstateCovenantReplyMessage ();

    struct DataBlock {
        lltypes::LLUUID CovenantID;
        lltypes::U32 CovenantTimestamp;
        lltypes::Variable<1> EstateName;
        lltypes::LLUUID EstateOwnerID;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const EstateCovenantReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  EstateCovenantReplyMessage & o);

struct ForceObjectSelectMessage : UdpMessage {
    static const quint32 id=205U;
    static const IdByte byte=Low;

    ForceObjectSelectMessage ();

    struct HeaderBlock {
        lltypes::BOOL ResetList;
    };
    struct DataBlock {
        lltypes::U32 LocalID;
    };
    HeaderBlock Header;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const ForceObjectSelectMessage & o);
QDataStream &operator>>(QDataStream & in,  ForceObjectSelectMessage & o);

struct ParcelBuyPassMessage : UdpMessage {
    static const quint32 id=206U;
    static const IdByte byte=Low;

    ParcelBuyPassMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelBuyPassMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelBuyPassMessage & o);

struct ParcelDeedToGroupMessage : UdpMessage {
    static const quint32 id=207U;
    static const IdByte byte=Low;

    ParcelDeedToGroupMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelDeedToGroupMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelDeedToGroupMessage & o);

struct ParcelReclaimMessage : UdpMessage {
    static const quint32 id=208U;
    static const IdByte byte=Low;

    ParcelReclaimMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelReclaimMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelReclaimMessage & o);

struct ParcelClaimMessage : UdpMessage {
    static const quint32 id=209U;
    static const IdByte byte=Low;

    ParcelClaimMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL IsGroupOwned;
        lltypes::BOOL Final;
    };
    struct ParcelDataBlock {
        lltypes::F32 West;
        lltypes::F32 South;
        lltypes::F32 East;
        lltypes::F32 North;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelClaimMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelClaimMessage & o);

struct ParcelJoinMessage : UdpMessage {
    static const quint32 id=210U;
    static const IdByte byte=Low;

    ParcelJoinMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::F32 West;
        lltypes::F32 South;
        lltypes::F32 East;
        lltypes::F32 North;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelJoinMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelJoinMessage & o);

struct ParcelDivideMessage : UdpMessage {
    static const quint32 id=211U;
    static const IdByte byte=Low;

    ParcelDivideMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::F32 West;
        lltypes::F32 South;
        lltypes::F32 East;
        lltypes::F32 North;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelDivideMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelDivideMessage & o);

struct ParcelReleaseMessage : UdpMessage {
    static const quint32 id=212U;
    static const IdByte byte=Low;

    ParcelReleaseMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelReleaseMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelReleaseMessage & o);

struct ParcelBuyMessage : UdpMessage {
    static const quint32 id=213U;
    static const IdByte byte=Low;

    ParcelBuyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL IsGroupOwned;
        lltypes::BOOL RemoveContribution;
        lltypes::S32 LocalID;
        lltypes::BOOL Final;
    };
    struct ParcelDataBlock {
        lltypes::S32 Price;
        lltypes::S32 Area;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelBuyMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelBuyMessage & o);

struct ParcelGodForceOwnerMessage : UdpMessage {
    static const quint32 id=214U;
    static const IdByte byte=Low;

    ParcelGodForceOwnerMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID OwnerID;
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelGodForceOwnerMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelGodForceOwnerMessage & o);

struct ParcelAccessListRequestMessage : UdpMessage {
    static const quint32 id=215U;
    static const IdByte byte=Low;

    ParcelAccessListRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::S32 SequenceID;
        lltypes::U32 Flags;
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelAccessListRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelAccessListRequestMessage & o);

struct ParcelAccessListReplyMessage : UdpMessage {
    static const quint32 id=216U;
    static const IdByte byte=Low;

    ParcelAccessListReplyMessage ();

    struct DataBlock {
        lltypes::LLUUID AgentID;
        lltypes::S32 SequenceID;
        lltypes::U32 Flags;
        lltypes::S32 LocalID;
    };
    struct ListBlock {
        lltypes::LLUUID ID;
        lltypes::S32 Time;
        lltypes::U32 Flags;
    };
    DataBlock Data;
    QVector<ListBlock> List;
};

QDataStream &operator<<(QDataStream & out, const ParcelAccessListReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelAccessListReplyMessage & o);

struct ParcelAccessListUpdateMessage : UdpMessage {
    static const quint32 id=217U;
    static const IdByte byte=Low;

    ParcelAccessListUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::U32 Flags;
        lltypes::S32 LocalID;
        lltypes::LLUUID TransactionID;
        lltypes::S32 SequenceID;
        lltypes::S32 Sections;
    };
    struct ListBlock {
        lltypes::LLUUID ID;
        lltypes::S32 Time;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
    QVector<ListBlock> List;
};

QDataStream &operator<<(QDataStream & out, const ParcelAccessListUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelAccessListUpdateMessage & o);

struct ParcelDwellRequestMessage : UdpMessage {
    static const quint32 id=218U;
    static const IdByte byte=Low;

    ParcelDwellRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::S32 LocalID;
        lltypes::LLUUID ParcelID;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelDwellRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelDwellRequestMessage & o);

struct ParcelDwellReplyMessage : UdpMessage {
    static const quint32 id=219U;
    static const IdByte byte=Low;

    ParcelDwellReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::S32 LocalID;
        lltypes::LLUUID ParcelID;
        lltypes::F32 Dwell;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ParcelDwellReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelDwellReplyMessage & o);

struct RequestParcelTransferMessage : UdpMessage {
    static const quint32 id=220U;
    static const IdByte byte=Low;

    RequestParcelTransferMessage ();

    struct DataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::U32 TransactionTime;
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
        lltypes::LLUUID OwnerID;
        lltypes::U8 Flags;
        lltypes::S32 TransactionType;
        lltypes::S32 Amount;
        lltypes::S32 BillableArea;
        lltypes::S32 ActualArea;
        lltypes::BOOL Final;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const RequestParcelTransferMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestParcelTransferMessage & o);

struct UpdateParcelMessage : UdpMessage {
    static const quint32 id=221U;
    static const IdByte byte=Low;

    UpdateParcelMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::U64 RegionHandle;
        lltypes::LLUUID OwnerID;
        lltypes::BOOL GroupOwned;
        lltypes::U8 Status;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::Variable<1> MusicURL;
        lltypes::F32 RegionX;
        lltypes::F32 RegionY;
        lltypes::S32 ActualArea;
        lltypes::S32 BillableArea;
        lltypes::BOOL ShowDir;
        lltypes::BOOL IsForSale;
        lltypes::U8 Category;
        lltypes::LLUUID SnapshotID;
        lltypes::LLVector3 UserLocation;
        lltypes::S32 SalePrice;
        lltypes::LLUUID AuthorizedBuyerID;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
    };
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const UpdateParcelMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateParcelMessage & o);

struct RemoveParcelMessage : UdpMessage {
    static const quint32 id=222U;
    static const IdByte byte=Low;

    RemoveParcelMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const RemoveParcelMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveParcelMessage & o);

struct MergeParcelMessage : UdpMessage {
    static const quint32 id=223U;
    static const IdByte byte=Low;

    MergeParcelMessage ();

    struct MasterParcelDataBlock {
        lltypes::LLUUID MasterID;
    };
    struct SlaveParcelDataBlock {
        lltypes::LLUUID SlaveID;
    };
    MasterParcelDataBlock MasterParcelData;
    QVector<SlaveParcelDataBlock> SlaveParcelData;
};

QDataStream &operator<<(QDataStream & out, const MergeParcelMessage & o);
QDataStream &operator>>(QDataStream & in,  MergeParcelMessage & o);

struct LogParcelChangesMessage : UdpMessage {
    static const quint32 id=224U;
    static const IdByte byte=Low;

    LogParcelChangesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::LLUUID OwnerID;
        lltypes::BOOL IsOwnerGroup;
        lltypes::S32 ActualArea;
        lltypes::S8 Action;
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    RegionDataBlock RegionData;
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const LogParcelChangesMessage & o);
QDataStream &operator>>(QDataStream & in,  LogParcelChangesMessage & o);

struct CheckParcelSalesMessage : UdpMessage {
    static const quint32 id=225U;
    static const IdByte byte=Low;

    CheckParcelSalesMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    QVector<RegionDataBlock> RegionData;
};

QDataStream &operator<<(QDataStream & out, const CheckParcelSalesMessage & o);
QDataStream &operator>>(QDataStream & in,  CheckParcelSalesMessage & o);

struct ParcelSalesMessage : UdpMessage {
    static const quint32 id=226U;
    static const IdByte byte=Low;

    ParcelSalesMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::LLUUID BuyerID;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelSalesMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelSalesMessage & o);

struct ParcelGodMarkAsContentMessage : UdpMessage {
    static const quint32 id=227U;
    static const IdByte byte=Low;

    ParcelGodMarkAsContentMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelGodMarkAsContentMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelGodMarkAsContentMessage & o);

struct ViewerStartAuctionMessage : UdpMessage {
    static const quint32 id=228U;
    static const IdByte byte=Low;

    ViewerStartAuctionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ParcelDataBlock {
        lltypes::S32 LocalID;
        lltypes::LLUUID SnapshotID;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ViewerStartAuctionMessage & o);
QDataStream &operator>>(QDataStream & in,  ViewerStartAuctionMessage & o);

struct StartAuctionMessage : UdpMessage {
    static const quint32 id=229U;
    static const IdByte byte=Low;

    StartAuctionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::LLUUID SnapshotID;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
};

QDataStream &operator<<(QDataStream & out, const StartAuctionMessage & o);
QDataStream &operator>>(QDataStream & in,  StartAuctionMessage & o);

struct ConfirmAuctionStartMessage : UdpMessage {
    static const quint32 id=230U;
    static const IdByte byte=Low;

    ConfirmAuctionStartMessage ();

    struct AuctionDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::U32 AuctionID;
    };
    AuctionDataBlock AuctionData;
};

QDataStream &operator<<(QDataStream & out, const ConfirmAuctionStartMessage & o);
QDataStream &operator>>(QDataStream & in,  ConfirmAuctionStartMessage & o);

struct CompleteAuctionMessage : UdpMessage {
    static const quint32 id=231U;
    static const IdByte byte=Low;

    CompleteAuctionMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const CompleteAuctionMessage & o);
QDataStream &operator>>(QDataStream & in,  CompleteAuctionMessage & o);

struct CancelAuctionMessage : UdpMessage {
    static const quint32 id=232U;
    static const IdByte byte=Low;

    CancelAuctionMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const CancelAuctionMessage & o);
QDataStream &operator>>(QDataStream & in,  CancelAuctionMessage & o);

struct CheckParcelAuctionsMessage : UdpMessage {
    static const quint32 id=233U;
    static const IdByte byte=Low;

    CheckParcelAuctionsMessage ();

    struct RegionDataBlock {
        lltypes::U64 RegionHandle;
    };
    QVector<RegionDataBlock> RegionData;
};

QDataStream &operator<<(QDataStream & out, const CheckParcelAuctionsMessage & o);
QDataStream &operator>>(QDataStream & in,  CheckParcelAuctionsMessage & o);

struct ParcelAuctionsMessage : UdpMessage {
    static const quint32 id=234U;
    static const IdByte byte=Low;

    ParcelAuctionsMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::LLUUID WinnerID;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelAuctionsMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelAuctionsMessage & o);

struct UUIDNameRequestMessage : UdpMessage {
    static const quint32 id=235U;
    static const IdByte byte=Low;

    UUIDNameRequestMessage ();

    struct UUIDNameBlockBlock {
        lltypes::LLUUID ID;
    };
    QVector<UUIDNameBlockBlock> UUIDNameBlock;
};

QDataStream &operator<<(QDataStream & out, const UUIDNameRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  UUIDNameRequestMessage & o);

struct UUIDNameReplyMessage : UdpMessage {
    static const quint32 id=236U;
    static const IdByte byte=Low;

    UUIDNameReplyMessage ();

    struct UUIDNameBlockBlock {
        lltypes::LLUUID ID;
        lltypes::Variable<1> FirstName;
        lltypes::Variable<1> LastName;
    };
    QVector<UUIDNameBlockBlock> UUIDNameBlock;
};

QDataStream &operator<<(QDataStream & out, const UUIDNameReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  UUIDNameReplyMessage & o);

struct UUIDGroupNameRequestMessage : UdpMessage {
    static const quint32 id=237U;
    static const IdByte byte=Low;

    UUIDGroupNameRequestMessage ();

    struct UUIDNameBlockBlock {
        lltypes::LLUUID ID;
    };
    QVector<UUIDNameBlockBlock> UUIDNameBlock;
};

QDataStream &operator<<(QDataStream & out, const UUIDGroupNameRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  UUIDGroupNameRequestMessage & o);

struct UUIDGroupNameReplyMessage : UdpMessage {
    static const quint32 id=238U;
    static const IdByte byte=Low;

    UUIDGroupNameReplyMessage ();

    struct UUIDNameBlockBlock {
        lltypes::LLUUID ID;
        lltypes::Variable<1> GroupName;
    };
    QVector<UUIDNameBlockBlock> UUIDNameBlock;
};

QDataStream &operator<<(QDataStream & out, const UUIDGroupNameReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  UUIDGroupNameReplyMessage & o);

struct ChatPassMessage : UdpMessage {
    static const quint32 id=239U;
    static const IdByte byte=Low;

    ChatPassMessage ();

    struct ChatDataBlock {
        lltypes::S32 Channel;
        lltypes::LLVector3 Position;
        lltypes::LLUUID ID;
        lltypes::LLUUID OwnerID;
        lltypes::Variable<1> Name;
        lltypes::U8 SourceType;
        lltypes::U8 Type;
        lltypes::F32 Radius;
        lltypes::U8 SimAccess;
        lltypes::Variable<2> Message;
    };
    ChatDataBlock ChatData;
};

QDataStream &operator<<(QDataStream & out, const ChatPassMessage & o);
QDataStream &operator>>(QDataStream & in,  ChatPassMessage & o);

struct EdgeDataPacketMessage : UdpMessage {
    static const quint32 id=24U;
    static const IdByte byte=High;

    EdgeDataPacketMessage ();

    struct EdgeDataBlock {
        lltypes::U8 LayerType;
        lltypes::U8 Direction;
        lltypes::Variable<2> LayerData;
    };
    EdgeDataBlock EdgeData;
};

QDataStream &operator<<(QDataStream & out, const EdgeDataPacketMessage & o);
QDataStream &operator>>(QDataStream & in,  EdgeDataPacketMessage & o);

struct SimStatusMessage : UdpMessage {
    static const quint32 id=12U;
    static const IdByte byte=Medium;

    SimStatusMessage ();

    struct SimStatusBlock {
        lltypes::BOOL CanAcceptAgents;
        lltypes::BOOL CanAcceptTasks;
    };
    SimStatusBlock SimStatus;
};

QDataStream &operator<<(QDataStream & out, const SimStatusMessage & o);
QDataStream &operator>>(QDataStream & in,  SimStatusMessage & o);

struct ChildAgentUpdateMessage : UdpMessage {
    static const quint32 id=25U;
    static const IdByte byte=High;

    ChildAgentUpdateMessage ();

    struct AgentDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U32 ViewerCircuitCode;
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLVector3 AgentPos;
        lltypes::LLVector3 AgentVel;
        lltypes::LLVector3 Center;
        lltypes::LLVector3 Size;
        lltypes::LLVector3 AtAxis;
        lltypes::LLVector3 LeftAxis;
        lltypes::LLVector3 UpAxis;
        lltypes::BOOL ChangedGrid;
        lltypes::F32 Far;
        lltypes::F32 Aspect;
        lltypes::Variable<1> Throttles;
        lltypes::U32 LocomotionState;
        lltypes::LLQuaternion HeadRotation;
        lltypes::LLQuaternion BodyRotation;
        lltypes::U32 ControlFlags;
        lltypes::F32 EnergyLevel;
        lltypes::U8 GodLevel;
        lltypes::BOOL AlwaysRun;
        lltypes::LLUUID PreyAgent;
        lltypes::U8 AgentAccess;
        lltypes::Variable<2> AgentTextures;
        lltypes::LLUUID ActiveGroupID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::U64 GroupPowers;
        lltypes::BOOL AcceptNotices;
    };
    struct AnimationDataBlock {
        lltypes::LLUUID Animation;
        lltypes::LLUUID ObjectID;
    };
    struct GranterBlockBlock {
        lltypes::LLUUID GranterID;
    };
    struct NVPairDataBlock {
        lltypes::Variable<2> NVPairs;
    };
    struct VisualParamBlock {
        lltypes::U8 ParamValue;
    };
    AgentDataBlock AgentData;
    QVector<GroupDataBlock> GroupData;
    QVector<AnimationDataBlock> AnimationData;
    QVector<GranterBlockBlock> GranterBlock;
    QVector<NVPairDataBlock> NVPairData;
    QVector<VisualParamBlock> VisualParam;
};

QDataStream &operator<<(QDataStream & out, const ChildAgentUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ChildAgentUpdateMessage & o);

struct ChildAgentAliveMessage : UdpMessage {
    static const quint32 id=26U;
    static const IdByte byte=High;

    ChildAgentAliveMessage ();

    struct AgentDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U32 ViewerCircuitCode;
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ChildAgentAliveMessage & o);
QDataStream &operator>>(QDataStream & in,  ChildAgentAliveMessage & o);

struct ChildAgentPositionUpdateMessage : UdpMessage {
    static const quint32 id=27U;
    static const IdByte byte=High;

    ChildAgentPositionUpdateMessage ();

    struct AgentDataBlock {
        lltypes::U64 RegionHandle;
        lltypes::U32 ViewerCircuitCode;
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLVector3 AgentPos;
        lltypes::LLVector3 AgentVel;
        lltypes::LLVector3 Center;
        lltypes::LLVector3 Size;
        lltypes::LLVector3 AtAxis;
        lltypes::LLVector3 LeftAxis;
        lltypes::LLVector3 UpAxis;
        lltypes::BOOL ChangedGrid;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ChildAgentPositionUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ChildAgentPositionUpdateMessage & o);

struct ChildAgentDyingMessage : UdpMessage {
    static const quint32 id=240U;
    static const IdByte byte=Low;

    ChildAgentDyingMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ChildAgentDyingMessage & o);
QDataStream &operator>>(QDataStream & in,  ChildAgentDyingMessage & o);

struct ChildAgentUnknownMessage : UdpMessage {
    static const quint32 id=241U;
    static const IdByte byte=Low;

    ChildAgentUnknownMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ChildAgentUnknownMessage & o);
QDataStream &operator>>(QDataStream & in,  ChildAgentUnknownMessage & o);

struct AtomicPassObjectMessage : UdpMessage {
    static const quint32 id=28U;
    static const IdByte byte=High;

    AtomicPassObjectMessage ();

    struct TaskDataBlock {
        lltypes::LLUUID TaskID;
        lltypes::BOOL AttachmentNeedsSave;
    };
    TaskDataBlock TaskData;
};

QDataStream &operator<<(QDataStream & out, const AtomicPassObjectMessage & o);
QDataStream &operator>>(QDataStream & in,  AtomicPassObjectMessage & o);

struct KillChildAgentsMessage : UdpMessage {
    static const quint32 id=242U;
    static const IdByte byte=Low;

    KillChildAgentsMessage ();

    struct IDBlockBlock {
        lltypes::LLUUID AgentID;
    };
    IDBlockBlock IDBlock;
};

QDataStream &operator<<(QDataStream & out, const KillChildAgentsMessage & o);
QDataStream &operator>>(QDataStream & in,  KillChildAgentsMessage & o);

struct GetScriptRunningMessage : UdpMessage {
    static const quint32 id=243U;
    static const IdByte byte=Low;

    GetScriptRunningMessage ();

    struct ScriptBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ItemID;
    };
    ScriptBlock Script;
};

QDataStream &operator<<(QDataStream & out, const GetScriptRunningMessage & o);
QDataStream &operator>>(QDataStream & in,  GetScriptRunningMessage & o);

struct ScriptRunningReplyMessage : UdpMessage {
    static const quint32 id=244U;
    static const IdByte byte=Low;

    ScriptRunningReplyMessage ();

    struct ScriptBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ItemID;
        lltypes::BOOL Running;
    };
    ScriptBlock Script;
};

QDataStream &operator<<(QDataStream & out, const ScriptRunningReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptRunningReplyMessage & o);

struct SetScriptRunningMessage : UdpMessage {
    static const quint32 id=245U;
    static const IdByte byte=Low;

    SetScriptRunningMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ScriptBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ItemID;
        lltypes::BOOL Running;
    };
    AgentDataBlock AgentData;
    ScriptBlock Script;
};

QDataStream &operator<<(QDataStream & out, const SetScriptRunningMessage & o);
QDataStream &operator>>(QDataStream & in,  SetScriptRunningMessage & o);

struct ScriptResetMessage : UdpMessage {
    static const quint32 id=246U;
    static const IdByte byte=Low;

    ScriptResetMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ScriptBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    ScriptBlock Script;
};

QDataStream &operator<<(QDataStream & out, const ScriptResetMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptResetMessage & o);

struct ScriptSensorRequestMessage : UdpMessage {
    static const quint32 id=247U;
    static const IdByte byte=Low;

    ScriptSensorRequestMessage ();

    struct RequesterBlock {
        lltypes::LLUUID SourceID;
        lltypes::LLUUID RequestID;
        lltypes::LLUUID SearchID;
        lltypes::LLVector3 SearchPos;
        lltypes::LLQuaternion SearchDir;
        lltypes::Variable<1> SearchName;
        lltypes::S32 Type;
        lltypes::F32 Range;
        lltypes::F32 Arc;
        lltypes::U64 RegionHandle;
        lltypes::U8 SearchRegions;
    };
    RequesterBlock Requester;
};

QDataStream &operator<<(QDataStream & out, const ScriptSensorRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptSensorRequestMessage & o);

struct ScriptSensorReplyMessage : UdpMessage {
    static const quint32 id=248U;
    static const IdByte byte=Low;

    ScriptSensorReplyMessage ();

    struct RequesterBlock {
        lltypes::LLUUID SourceID;
    };
    struct SensedDataBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::LLVector3 Position;
        lltypes::LLVector3 Velocity;
        lltypes::LLQuaternion Rotation;
        lltypes::Variable<1> Name;
        lltypes::S32 Type;
        lltypes::F32 Range;
    };
    RequesterBlock Requester;
    QVector<SensedDataBlock> SensedData;
};

QDataStream &operator<<(QDataStream & out, const ScriptSensorReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptSensorReplyMessage & o);

struct CompleteAgentMovementMessage : UdpMessage {
    static const quint32 id=249U;
    static const IdByte byte=Low;

    CompleteAgentMovementMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 CircuitCode;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const CompleteAgentMovementMessage & o);
QDataStream &operator>>(QDataStream & in,  CompleteAgentMovementMessage & o);

struct AgentMovementCompleteMessage : UdpMessage {
    static const quint32 id=250U;
    static const IdByte byte=Low;

    AgentMovementCompleteMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLVector3 Position;
        lltypes::LLVector3 LookAt;
        lltypes::U64 RegionHandle;
        lltypes::U32 Timestamp;
    };
    struct SimDataBlock {
        lltypes::Variable<2> ChannelVersion;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
    SimDataBlock SimData;
};

QDataStream &operator<<(QDataStream & out, const AgentMovementCompleteMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentMovementCompleteMessage & o);

struct DataServerLogoutMessage : UdpMessage {
    static const quint32 id=251U;
    static const IdByte byte=Low;

    DataServerLogoutMessage ();

    struct UserDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::IPADDR ViewerIP;
        lltypes::BOOL Disconnect;
        lltypes::LLUUID SessionID;
    };
    UserDataBlock UserData;
};

QDataStream &operator<<(QDataStream & out, const DataServerLogoutMessage & o);
QDataStream &operator>>(QDataStream & in,  DataServerLogoutMessage & o);

struct LogoutRequestMessage : UdpMessage {
    static const quint32 id=252U;
    static const IdByte byte=Low;

    LogoutRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const LogoutRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  LogoutRequestMessage & o);

struct LogoutReplyMessage : UdpMessage {
    static const quint32 id=253U;
    static const IdByte byte=Low;

    LogoutReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const LogoutReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  LogoutReplyMessage & o);

struct ImprovedInstantMessageMessage : UdpMessage {
    static const quint32 id=254U;
    static const IdByte byte=Low;

    ImprovedInstantMessageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MessageBlockBlock {
        lltypes::BOOL FromGroup;
        lltypes::LLUUID ToAgentID;
        lltypes::U32 ParentEstateID;
        lltypes::LLUUID RegionID;
        lltypes::LLVector3 Position;
        lltypes::U8 Offline;
        lltypes::U8 Dialog;
        lltypes::LLUUID ID;
        lltypes::U32 Timestamp;
        lltypes::Variable<1> FromAgentName;
        lltypes::Variable<2> Message;
        lltypes::Variable<2> BinaryBucket;
    };
    AgentDataBlock AgentData;
    MessageBlockBlock MessageBlock;
};

QDataStream &operator<<(QDataStream & out, const ImprovedInstantMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  ImprovedInstantMessageMessage & o);

struct RetrieveInstantMessagesMessage : UdpMessage {
    static const quint32 id=255U;
    static const IdByte byte=Low;

    RetrieveInstantMessagesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const RetrieveInstantMessagesMessage & o);
QDataStream &operator>>(QDataStream & in,  RetrieveInstantMessagesMessage & o);

struct FindAgentMessage : UdpMessage {
    static const quint32 id=256U;
    static const IdByte byte=Low;

    FindAgentMessage ();

    struct AgentBlockBlock {
        lltypes::LLUUID Hunter;
        lltypes::LLUUID Prey;
        lltypes::IPADDR SpaceIP;
    };
    struct LocationBlockBlock {
        lltypes::F64 GlobalX;
        lltypes::F64 GlobalY;
    };
    AgentBlockBlock AgentBlock;
    QVector<LocationBlockBlock> LocationBlock;
};

QDataStream &operator<<(QDataStream & out, const FindAgentMessage & o);
QDataStream &operator>>(QDataStream & in,  FindAgentMessage & o);

struct RequestGodlikePowersMessage : UdpMessage {
    static const quint32 id=257U;
    static const IdByte byte=Low;

    RequestGodlikePowersMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RequestBlockBlock {
        lltypes::BOOL Godlike;
        lltypes::LLUUID Token;
    };
    AgentDataBlock AgentData;
    RequestBlockBlock RequestBlock;
};

QDataStream &operator<<(QDataStream & out, const RequestGodlikePowersMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestGodlikePowersMessage & o);

struct GrantGodlikePowersMessage : UdpMessage {
    static const quint32 id=258U;
    static const IdByte byte=Low;

    GrantGodlikePowersMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GrantDataBlock {
        lltypes::U8 GodLevel;
        lltypes::LLUUID Token;
    };
    AgentDataBlock AgentData;
    GrantDataBlock GrantData;
};

QDataStream &operator<<(QDataStream & out, const GrantGodlikePowersMessage & o);
QDataStream &operator>>(QDataStream & in,  GrantGodlikePowersMessage & o);

struct GodlikeMessageMessage : UdpMessage {
    static const quint32 id=259U;
    static const IdByte byte=Low;

    GodlikeMessageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID TransactionID;
    };
    struct MethodDataBlock {
        lltypes::Variable<1> Method;
        lltypes::LLUUID Invoice;
    };
    struct ParamListBlock {
        lltypes::Variable<1> Parameter;
    };
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    QVector<ParamListBlock> ParamList;
};

QDataStream &operator<<(QDataStream & out, const GodlikeMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  GodlikeMessageMessage & o);

struct EstateOwnerMessageMessage : UdpMessage {
    static const quint32 id=260U;
    static const IdByte byte=Low;

    EstateOwnerMessageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID TransactionID;
    };
    struct MethodDataBlock {
        lltypes::Variable<1> Method;
        lltypes::LLUUID Invoice;
    };
    struct ParamListBlock {
        lltypes::Variable<1> Parameter;
    };
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    QVector<ParamListBlock> ParamList;
};

QDataStream &operator<<(QDataStream & out, const EstateOwnerMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  EstateOwnerMessageMessage & o);

struct GenericMessageMessage : UdpMessage {
    static const quint32 id=261U;
    static const IdByte byte=Low;

    GenericMessageMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID TransactionID;
    };
    struct MethodDataBlock {
        lltypes::Variable<1> Method;
        lltypes::LLUUID Invoice;
    };
    struct ParamListBlock {
        lltypes::Variable<1> Parameter;
    };
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    QVector<ParamListBlock> ParamList;
};

QDataStream &operator<<(QDataStream & out, const GenericMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  GenericMessageMessage & o);

struct MuteListRequestMessage : UdpMessage {
    static const quint32 id=262U;
    static const IdByte byte=Low;

    MuteListRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MuteDataBlock {
        lltypes::U32 MuteCRC;
    };
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;
};

QDataStream &operator<<(QDataStream & out, const MuteListRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MuteListRequestMessage & o);

struct UpdateMuteListEntryMessage : UdpMessage {
    static const quint32 id=263U;
    static const IdByte byte=Low;

    UpdateMuteListEntryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MuteDataBlock {
        lltypes::LLUUID MuteID;
        lltypes::Variable<1> MuteName;
        lltypes::S32 MuteType;
        lltypes::U32 MuteFlags;
    };
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;
};

QDataStream &operator<<(QDataStream & out, const UpdateMuteListEntryMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateMuteListEntryMessage & o);

struct RemoveMuteListEntryMessage : UdpMessage {
    static const quint32 id=264U;
    static const IdByte byte=Low;

    RemoveMuteListEntryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MuteDataBlock {
        lltypes::LLUUID MuteID;
        lltypes::Variable<1> MuteName;
    };
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;
};

QDataStream &operator<<(QDataStream & out, const RemoveMuteListEntryMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveMuteListEntryMessage & o);

struct CopyInventoryFromNotecardMessage : UdpMessage {
    static const quint32 id=265U;
    static const IdByte byte=Low;

    CopyInventoryFromNotecardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct NotecardDataBlock {
        lltypes::LLUUID NotecardItemID;
        lltypes::LLUUID ObjectID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    NotecardDataBlock NotecardData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const CopyInventoryFromNotecardMessage & o);
QDataStream &operator>>(QDataStream & in,  CopyInventoryFromNotecardMessage & o);

struct UpdateInventoryItemMessage : UdpMessage {
    static const quint32 id=266U;
    static const IdByte byte=Low;

    UpdateInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID TransactionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::U32 CallbackID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const UpdateInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateInventoryItemMessage & o);

struct UpdateCreateInventoryItemMessage : UdpMessage {
    static const quint32 id=267U;
    static const IdByte byte=Low;

    UpdateCreateInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::BOOL SimApproved;
        lltypes::LLUUID TransactionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::U32 CallbackID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID AssetID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const UpdateCreateInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateCreateInventoryItemMessage & o);

struct MoveInventoryItemMessage : UdpMessage {
    static const quint32 id=268U;
    static const IdByte byte=Low;

    MoveInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::BOOL Stamp;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::Variable<1> NewName;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const MoveInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  MoveInventoryItemMessage & o);

struct CopyInventoryItemMessage : UdpMessage {
    static const quint32 id=269U;
    static const IdByte byte=Low;

    CopyInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::U32 CallbackID;
        lltypes::LLUUID OldAgentID;
        lltypes::LLUUID OldItemID;
        lltypes::LLUUID NewFolderID;
        lltypes::Variable<1> NewName;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const CopyInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  CopyInventoryItemMessage & o);

struct RemoveInventoryItemMessage : UdpMessage {
    static const quint32 id=270U;
    static const IdByte byte=Low;

    RemoveInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RemoveInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveInventoryItemMessage & o);

struct ChangeInventoryItemFlagsMessage : UdpMessage {
    static const quint32 id=271U;
    static const IdByte byte=Low;

    ChangeInventoryItemFlagsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::U32 Flags;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const ChangeInventoryItemFlagsMessage & o);
QDataStream &operator>>(QDataStream & in,  ChangeInventoryItemFlagsMessage & o);

struct SaveAssetIntoInventoryMessage : UdpMessage {
    static const quint32 id=272U;
    static const IdByte byte=Low;

    SaveAssetIntoInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID NewAssetID;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const SaveAssetIntoInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  SaveAssetIntoInventoryMessage & o);

struct CreateInventoryFolderMessage : UdpMessage {
    static const quint32 id=273U;
    static const IdByte byte=Low;

    CreateInventoryFolderMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID ParentID;
        lltypes::S8 Type;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    FolderDataBlock FolderData;
};

QDataStream &operator<<(QDataStream & out, const CreateInventoryFolderMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateInventoryFolderMessage & o);

struct UpdateInventoryFolderMessage : UdpMessage {
    static const quint32 id=274U;
    static const IdByte byte=Low;

    UpdateInventoryFolderMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID ParentID;
        lltypes::S8 Type;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    QVector<FolderDataBlock> FolderData;
};

QDataStream &operator<<(QDataStream & out, const UpdateInventoryFolderMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateInventoryFolderMessage & o);

struct MoveInventoryFolderMessage : UdpMessage {
    static const quint32 id=275U;
    static const IdByte byte=Low;

    MoveInventoryFolderMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::BOOL Stamp;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID ParentID;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const MoveInventoryFolderMessage & o);
QDataStream &operator>>(QDataStream & in,  MoveInventoryFolderMessage & o);

struct RemoveInventoryFolderMessage : UdpMessage {
    static const quint32 id=276U;
    static const IdByte byte=Low;

    RemoveInventoryFolderMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    QVector<FolderDataBlock> FolderData;
};

QDataStream &operator<<(QDataStream & out, const RemoveInventoryFolderMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveInventoryFolderMessage & o);

struct FetchInventoryDescendentsMessage : UdpMessage {
    static const quint32 id=277U;
    static const IdByte byte=Low;

    FetchInventoryDescendentsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID OwnerID;
        lltypes::S32 SortOrder;
        lltypes::BOOL FetchFolders;
        lltypes::BOOL FetchItems;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const FetchInventoryDescendentsMessage & o);
QDataStream &operator>>(QDataStream & in,  FetchInventoryDescendentsMessage & o);

struct InventoryDescendentsMessage : UdpMessage {
    static const quint32 id=278U;
    static const IdByte byte=Low;

    InventoryDescendentsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID OwnerID;
        lltypes::S32 Version;
        lltypes::S32 Descendents;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID ParentID;
        lltypes::S8 Type;
        lltypes::Variable<1> Name;
    };
    struct ItemDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID AssetID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    QVector<FolderDataBlock> FolderData;
    QVector<ItemDataBlock> ItemData;
};

QDataStream &operator<<(QDataStream & out, const InventoryDescendentsMessage & o);
QDataStream &operator>>(QDataStream & in,  InventoryDescendentsMessage & o);

struct FetchInventoryMessage : UdpMessage {
    static const quint32 id=279U;
    static const IdByte byte=Low;

    FetchInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const FetchInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  FetchInventoryMessage & o);

struct FetchInventoryReplyMessage : UdpMessage {
    static const quint32 id=280U;
    static const IdByte byte=Low;

    FetchInventoryReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID AssetID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const FetchInventoryReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  FetchInventoryReplyMessage & o);

struct BulkUpdateInventoryMessage : UdpMessage {
    static const quint32 id=281U;
    static const IdByte byte=Low;

    BulkUpdateInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TransactionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
        lltypes::LLUUID ParentID;
        lltypes::S8 Type;
        lltypes::Variable<1> Name;
    };
    struct ItemDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::U32 CallbackID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID AssetID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    QVector<FolderDataBlock> FolderData;
    QVector<ItemDataBlock> ItemData;
};

QDataStream &operator<<(QDataStream & out, const BulkUpdateInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  BulkUpdateInventoryMessage & o);

struct RequestInventoryAssetMessage : UdpMessage {
    static const quint32 id=282U;
    static const IdByte byte=Low;

    RequestInventoryAssetMessage ();

    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::LLUUID AgentID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID ItemID;
    };
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const RequestInventoryAssetMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestInventoryAssetMessage & o);

struct InventoryAssetResponseMessage : UdpMessage {
    static const quint32 id=283U;
    static const IdByte byte=Low;

    InventoryAssetResponseMessage ();

    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
        lltypes::LLUUID AssetID;
        lltypes::BOOL IsReadable;
    };
    QueryDataBlock QueryData;
};

QDataStream &operator<<(QDataStream & out, const InventoryAssetResponseMessage & o);
QDataStream &operator>>(QDataStream & in,  InventoryAssetResponseMessage & o);

struct RemoveInventoryObjectsMessage : UdpMessage {
    static const quint32 id=284U;
    static const IdByte byte=Low;

    RemoveInventoryObjectsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
    };
    struct ItemDataBlock {
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    QVector<FolderDataBlock> FolderData;
    QVector<ItemDataBlock> ItemData;
};

QDataStream &operator<<(QDataStream & out, const RemoveInventoryObjectsMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveInventoryObjectsMessage & o);

struct PurgeInventoryDescendentsMessage : UdpMessage {
    static const quint32 id=285U;
    static const IdByte byte=Low;

    PurgeInventoryDescendentsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const PurgeInventoryDescendentsMessage & o);
QDataStream &operator>>(QDataStream & in,  PurgeInventoryDescendentsMessage & o);

struct UpdateTaskInventoryMessage : UdpMessage {
    static const quint32 id=286U;
    static const IdByte byte=Low;

    UpdateTaskInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct UpdateDataBlock {
        lltypes::U32 LocalID;
        lltypes::U8 Key;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    UpdateDataBlock UpdateData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const UpdateTaskInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateTaskInventoryMessage & o);

struct RemoveTaskInventoryMessage : UdpMessage {
    static const quint32 id=287U;
    static const IdByte byte=Low;

    RemoveTaskInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::U32 LocalID;
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RemoveTaskInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveTaskInventoryMessage & o);

struct MoveTaskInventoryMessage : UdpMessage {
    static const quint32 id=288U;
    static const IdByte byte=Low;

    MoveTaskInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID FolderID;
    };
    struct InventoryDataBlock {
        lltypes::U32 LocalID;
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const MoveTaskInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  MoveTaskInventoryMessage & o);

struct RequestTaskInventoryMessage : UdpMessage {
    static const quint32 id=289U;
    static const IdByte byte=Low;

    RequestTaskInventoryMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::U32 LocalID;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RequestTaskInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestTaskInventoryMessage & o);

struct ReplyTaskInventoryMessage : UdpMessage {
    static const quint32 id=290U;
    static const IdByte byte=Low;

    ReplyTaskInventoryMessage ();

    struct InventoryDataBlock {
        lltypes::LLUUID TaskID;
        lltypes::S16 Serial;
        lltypes::Variable<1> Filename;
    };
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const ReplyTaskInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  ReplyTaskInventoryMessage & o);

struct DeRezObjectMessage : UdpMessage {
    static const quint32 id=291U;
    static const IdByte byte=Low;

    DeRezObjectMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct AgentBlockBlock {
        lltypes::LLUUID GroupID;
        lltypes::U8 Destination;
        lltypes::LLUUID DestinationID;
        lltypes::LLUUID TransactionID;
        lltypes::U8 PacketCount;
        lltypes::U8 PacketNumber;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
    };
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const DeRezObjectMessage & o);
QDataStream &operator>>(QDataStream & in,  DeRezObjectMessage & o);

struct DeRezAckMessage : UdpMessage {
    static const quint32 id=292U;
    static const IdByte byte=Low;

    DeRezAckMessage ();

    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::BOOL Success;
    };
    TransactionDataBlock TransactionData;
};

QDataStream &operator<<(QDataStream & out, const DeRezAckMessage & o);
QDataStream &operator>>(QDataStream & in,  DeRezAckMessage & o);

struct RezObjectMessage : UdpMessage {
    static const quint32 id=293U;
    static const IdByte byte=Low;

    RezObjectMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct RezDataBlock {
        lltypes::LLUUID FromTaskID;
        lltypes::U8 BypassRaycast;
        lltypes::LLVector3 RayStart;
        lltypes::LLVector3 RayEnd;
        lltypes::LLUUID RayTargetID;
        lltypes::BOOL RayEndIsIntersection;
        lltypes::BOOL RezSelected;
        lltypes::BOOL RemoveItem;
        lltypes::U32 ItemFlags;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RezObjectMessage & o);
QDataStream &operator>>(QDataStream & in,  RezObjectMessage & o);

struct RezObjectFromNotecardMessage : UdpMessage {
    static const quint32 id=294U;
    static const IdByte byte=Low;

    RezObjectFromNotecardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct RezDataBlock {
        lltypes::LLUUID FromTaskID;
        lltypes::U8 BypassRaycast;
        lltypes::LLVector3 RayStart;
        lltypes::LLVector3 RayEnd;
        lltypes::LLUUID RayTargetID;
        lltypes::BOOL RayEndIsIntersection;
        lltypes::BOOL RezSelected;
        lltypes::BOOL RemoveItem;
        lltypes::U32 ItemFlags;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
    };
    struct NotecardDataBlock {
        lltypes::LLUUID NotecardItemID;
        lltypes::LLUUID ObjectID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    NotecardDataBlock NotecardData;
    QVector<InventoryDataBlock> InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RezObjectFromNotecardMessage & o);
QDataStream &operator>>(QDataStream & in,  RezObjectFromNotecardMessage & o);

struct TransferInventoryMessage : UdpMessage {
    static const quint32 id=295U;
    static const IdByte byte=Low;

    TransferInventoryMessage ();

    struct InfoBlockBlock {
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
        lltypes::LLUUID TransactionID;
    };
    struct InventoryBlockBlock {
        lltypes::LLUUID InventoryID;
        lltypes::S8 Type;
    };
    InfoBlockBlock InfoBlock;
    QVector<InventoryBlockBlock> InventoryBlock;
};

QDataStream &operator<<(QDataStream & out, const TransferInventoryMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferInventoryMessage & o);

struct TransferInventoryAckMessage : UdpMessage {
    static const quint32 id=296U;
    static const IdByte byte=Low;

    TransferInventoryAckMessage ();

    struct InfoBlockBlock {
        lltypes::LLUUID TransactionID;
        lltypes::LLUUID InventoryID;
    };
    InfoBlockBlock InfoBlock;
};

QDataStream &operator<<(QDataStream & out, const TransferInventoryAckMessage & o);
QDataStream &operator>>(QDataStream & in,  TransferInventoryAckMessage & o);

struct AcceptFriendshipMessage : UdpMessage {
    static const quint32 id=297U;
    static const IdByte byte=Low;

    AcceptFriendshipMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TransactionBlockBlock {
        lltypes::LLUUID TransactionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    QVector<FolderDataBlock> FolderData;
};

QDataStream &operator<<(QDataStream & out, const AcceptFriendshipMessage & o);
QDataStream &operator>>(QDataStream & in,  AcceptFriendshipMessage & o);

struct DeclineFriendshipMessage : UdpMessage {
    static const quint32 id=298U;
    static const IdByte byte=Low;

    DeclineFriendshipMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TransactionBlockBlock {
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
};

QDataStream &operator<<(QDataStream & out, const DeclineFriendshipMessage & o);
QDataStream &operator>>(QDataStream & in,  DeclineFriendshipMessage & o);

struct FormFriendshipMessage : UdpMessage {
    static const quint32 id=299U;
    static const IdByte byte=Low;

    FormFriendshipMessage ();

    struct AgentBlockBlock {
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
    };
    AgentBlockBlock AgentBlock;
};

QDataStream &operator<<(QDataStream & out, const FormFriendshipMessage & o);
QDataStream &operator>>(QDataStream & in,  FormFriendshipMessage & o);

struct TerminateFriendshipMessage : UdpMessage {
    static const quint32 id=300U;
    static const IdByte byte=Low;

    TerminateFriendshipMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ExBlockBlock {
        lltypes::LLUUID OtherID;
    };
    AgentDataBlock AgentData;
    ExBlockBlock ExBlock;
};

QDataStream &operator<<(QDataStream & out, const TerminateFriendshipMessage & o);
QDataStream &operator>>(QDataStream & in,  TerminateFriendshipMessage & o);

struct OfferCallingCardMessage : UdpMessage {
    static const quint32 id=301U;
    static const IdByte byte=Low;

    OfferCallingCardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct AgentBlockBlock {
        lltypes::LLUUID DestID;
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;
};

QDataStream &operator<<(QDataStream & out, const OfferCallingCardMessage & o);
QDataStream &operator>>(QDataStream & in,  OfferCallingCardMessage & o);

struct AcceptCallingCardMessage : UdpMessage {
    static const quint32 id=302U;
    static const IdByte byte=Low;

    AcceptCallingCardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TransactionBlockBlock {
        lltypes::LLUUID TransactionID;
    };
    struct FolderDataBlock {
        lltypes::LLUUID FolderID;
    };
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    QVector<FolderDataBlock> FolderData;
};

QDataStream &operator<<(QDataStream & out, const AcceptCallingCardMessage & o);
QDataStream &operator>>(QDataStream & in,  AcceptCallingCardMessage & o);

struct DeclineCallingCardMessage : UdpMessage {
    static const quint32 id=303U;
    static const IdByte byte=Low;

    DeclineCallingCardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct TransactionBlockBlock {
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
};

QDataStream &operator<<(QDataStream & out, const DeclineCallingCardMessage & o);
QDataStream &operator>>(QDataStream & in,  DeclineCallingCardMessage & o);

struct RezScriptMessage : UdpMessage {
    static const quint32 id=304U;
    static const IdByte byte=Low;

    RezScriptMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct UpdateBlockBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::BOOL Enabled;
    };
    struct InventoryBlockBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    UpdateBlockBlock UpdateBlock;
    InventoryBlockBlock InventoryBlock;
};

QDataStream &operator<<(QDataStream & out, const RezScriptMessage & o);
QDataStream &operator>>(QDataStream & in,  RezScriptMessage & o);

struct CreateInventoryItemMessage : UdpMessage {
    static const quint32 id=305U;
    static const IdByte byte=Low;

    CreateInventoryItemMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryBlockBlock {
        lltypes::U32 CallbackID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID TransactionID;
        lltypes::U32 NextOwnerMask;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U8 WearableType;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
    };
    AgentDataBlock AgentData;
    InventoryBlockBlock InventoryBlock;
};

QDataStream &operator<<(QDataStream & out, const CreateInventoryItemMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateInventoryItemMessage & o);

struct CreateLandmarkForEventMessage : UdpMessage {
    static const quint32 id=306U;
    static const IdByte byte=Low;

    CreateLandmarkForEventMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    struct InventoryBlockBlock {
        lltypes::LLUUID FolderID;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    InventoryBlockBlock InventoryBlock;
};

QDataStream &operator<<(QDataStream & out, const CreateLandmarkForEventMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateLandmarkForEventMessage & o);

struct EventLocationRequestMessage : UdpMessage {
    static const quint32 id=307U;
    static const IdByte byte=Low;

    EventLocationRequestMessage ();

    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct EventDataBlock {
        lltypes::U32 EventID;
    };
    QueryDataBlock QueryData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventLocationRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EventLocationRequestMessage & o);

struct EventLocationReplyMessage : UdpMessage {
    static const quint32 id=308U;
    static const IdByte byte=Low;

    EventLocationReplyMessage ();

    struct QueryDataBlock {
        lltypes::LLUUID QueryID;
    };
    struct EventDataBlock {
        lltypes::BOOL Success;
        lltypes::LLUUID RegionID;
        lltypes::LLVector3 RegionPos;
    };
    QueryDataBlock QueryData;
    EventDataBlock EventData;
};

QDataStream &operator<<(QDataStream & out, const EventLocationReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  EventLocationReplyMessage & o);

struct RegionHandleRequestMessage : UdpMessage {
    static const quint32 id=309U;
    static const IdByte byte=Low;

    RegionHandleRequestMessage ();

    struct RequestBlockBlock {
        lltypes::LLUUID RegionID;
    };
    RequestBlockBlock RequestBlock;
};

QDataStream &operator<<(QDataStream & out, const RegionHandleRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionHandleRequestMessage & o);

struct RegionIDAndHandleReplyMessage : UdpMessage {
    static const quint32 id=310U;
    static const IdByte byte=Low;

    RegionIDAndHandleReplyMessage ();

    struct ReplyBlockBlock {
        lltypes::LLUUID RegionID;
        lltypes::U64 RegionHandle;
    };
    ReplyBlockBlock ReplyBlock;
};

QDataStream &operator<<(QDataStream & out, const RegionIDAndHandleReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  RegionIDAndHandleReplyMessage & o);

struct MoneyTransferRequestMessage : UdpMessage {
    static const quint32 id=311U;
    static const IdByte byte=Low;

    MoneyTransferRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
        lltypes::U8 Flags;
        lltypes::S32 Amount;
        lltypes::U8 AggregatePermNextOwner;
        lltypes::U8 AggregatePermInventory;
        lltypes::S32 TransactionType;
        lltypes::Variable<1> Description;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const MoneyTransferRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MoneyTransferRequestMessage & o);

struct MoneyTransferBackendMessage : UdpMessage {
    static const quint32 id=312U;
    static const IdByte byte=Low;

    MoneyTransferBackendMessage ();

    struct MoneyDataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::U32 TransactionTime;
        lltypes::LLUUID SourceID;
        lltypes::LLUUID DestID;
        lltypes::U8 Flags;
        lltypes::S32 Amount;
        lltypes::U8 AggregatePermNextOwner;
        lltypes::U8 AggregatePermInventory;
        lltypes::S32 TransactionType;
        lltypes::LLUUID RegionID;
        lltypes::U32 GridX;
        lltypes::U32 GridY;
        lltypes::Variable<1> Description;
    };
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const MoneyTransferBackendMessage & o);
QDataStream &operator>>(QDataStream & in,  MoneyTransferBackendMessage & o);

struct MoneyBalanceRequestMessage : UdpMessage {
    static const quint32 id=313U;
    static const IdByte byte=Low;

    MoneyBalanceRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const MoneyBalanceRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MoneyBalanceRequestMessage & o);

struct MoneyBalanceReplyMessage : UdpMessage {
    static const quint32 id=314U;
    static const IdByte byte=Low;

    MoneyBalanceReplyMessage ();

    struct MoneyDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TransactionID;
        lltypes::BOOL TransactionSuccess;
        lltypes::S32 MoneyBalance;
        lltypes::S32 SquareMetersCredit;
        lltypes::S32 SquareMetersCommitted;
        lltypes::Variable<1> Description;
    };
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const MoneyBalanceReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  MoneyBalanceReplyMessage & o);

struct RoutedMoneyBalanceReplyMessage : UdpMessage {
    static const quint32 id=315U;
    static const IdByte byte=Low;

    RoutedMoneyBalanceReplyMessage ();

    struct TargetBlockBlock {
        lltypes::IPADDR TargetIP;
        lltypes::IPPORT TargetPort;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID TransactionID;
        lltypes::BOOL TransactionSuccess;
        lltypes::S32 MoneyBalance;
        lltypes::S32 SquareMetersCredit;
        lltypes::S32 SquareMetersCommitted;
        lltypes::Variable<1> Description;
    };
    TargetBlockBlock TargetBlock;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const RoutedMoneyBalanceReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  RoutedMoneyBalanceReplyMessage & o);

struct ActivateGesturesMessage : UdpMessage {
    static const quint32 id=316U;
    static const IdByte byte=Low;

    ActivateGesturesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
    };
    struct DataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID AssetID;
        lltypes::U32 GestureFlags;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const ActivateGesturesMessage & o);
QDataStream &operator>>(QDataStream & in,  ActivateGesturesMessage & o);

struct DeactivateGesturesMessage : UdpMessage {
    static const quint32 id=317U;
    static const IdByte byte=Low;

    DeactivateGesturesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
    };
    struct DataBlock {
        lltypes::LLUUID ItemID;
        lltypes::U32 GestureFlags;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const DeactivateGesturesMessage & o);
QDataStream &operator>>(QDataStream & in,  DeactivateGesturesMessage & o);

struct MuteListUpdateMessage : UdpMessage {
    static const quint32 id=318U;
    static const IdByte byte=Low;

    MuteListUpdateMessage ();

    struct MuteDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::Variable<1> Filename;
    };
    MuteDataBlock MuteData;
};

QDataStream &operator<<(QDataStream & out, const MuteListUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  MuteListUpdateMessage & o);

struct UseCachedMuteListMessage : UdpMessage {
    static const quint32 id=319U;
    static const IdByte byte=Low;

    UseCachedMuteListMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const UseCachedMuteListMessage & o);
QDataStream &operator>>(QDataStream & in,  UseCachedMuteListMessage & o);

struct GrantUserRightsMessage : UdpMessage {
    static const quint32 id=320U;
    static const IdByte byte=Low;

    GrantUserRightsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RightsBlock {
        lltypes::LLUUID AgentRelated;
        lltypes::S32 RelatedRights;
    };
    AgentDataBlock AgentData;
    QVector<RightsBlock> Rights;
};

QDataStream &operator<<(QDataStream & out, const GrantUserRightsMessage & o);
QDataStream &operator>>(QDataStream & in,  GrantUserRightsMessage & o);

struct ChangeUserRightsMessage : UdpMessage {
    static const quint32 id=321U;
    static const IdByte byte=Low;

    ChangeUserRightsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct RightsBlock {
        lltypes::LLUUID AgentRelated;
        lltypes::S32 RelatedRights;
    };
    AgentDataBlock AgentData;
    QVector<RightsBlock> Rights;
};

QDataStream &operator<<(QDataStream & out, const ChangeUserRightsMessage & o);
QDataStream &operator>>(QDataStream & in,  ChangeUserRightsMessage & o);

struct OnlineNotificationMessage : UdpMessage {
    static const quint32 id=322U;
    static const IdByte byte=Low;

    OnlineNotificationMessage ();

    struct AgentBlockBlock {
        lltypes::LLUUID AgentID;
    };
    QVector<AgentBlockBlock> AgentBlock;
};

QDataStream &operator<<(QDataStream & out, const OnlineNotificationMessage & o);
QDataStream &operator>>(QDataStream & in,  OnlineNotificationMessage & o);

struct OfflineNotificationMessage : UdpMessage {
    static const quint32 id=323U;
    static const IdByte byte=Low;

    OfflineNotificationMessage ();

    struct AgentBlockBlock {
        lltypes::LLUUID AgentID;
    };
    QVector<AgentBlockBlock> AgentBlock;
};

QDataStream &operator<<(QDataStream & out, const OfflineNotificationMessage & o);
QDataStream &operator>>(QDataStream & in,  OfflineNotificationMessage & o);

struct SetStartLocationRequestMessage : UdpMessage {
    static const quint32 id=324U;
    static const IdByte byte=Low;

    SetStartLocationRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct StartLocationDataBlock {
        lltypes::Variable<1> SimName;
        lltypes::U32 LocationID;
        lltypes::LLVector3 LocationPos;
        lltypes::LLVector3 LocationLookAt;
    };
    AgentDataBlock AgentData;
    StartLocationDataBlock StartLocationData;
};

QDataStream &operator<<(QDataStream & out, const SetStartLocationRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  SetStartLocationRequestMessage & o);

struct SetStartLocationMessage : UdpMessage {
    static const quint32 id=325U;
    static const IdByte byte=Low;

    SetStartLocationMessage ();

    struct StartLocationDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID RegionID;
        lltypes::U32 LocationID;
        lltypes::U64 RegionHandle;
        lltypes::LLVector3 LocationPos;
        lltypes::LLVector3 LocationLookAt;
    };
    StartLocationDataBlock StartLocationData;
};

QDataStream &operator<<(QDataStream & out, const SetStartLocationMessage & o);
QDataStream &operator>>(QDataStream & in,  SetStartLocationMessage & o);

struct NetTestMessage : UdpMessage {
    static const quint32 id=326U;
    static const IdByte byte=Low;

    NetTestMessage ();

    struct NetBlockBlock {
        lltypes::IPPORT Port;
    };
    NetBlockBlock NetBlock;
};

QDataStream &operator<<(QDataStream & out, const NetTestMessage & o);
QDataStream &operator>>(QDataStream & in,  NetTestMessage & o);

struct SetCPURatioMessage : UdpMessage {
    static const quint32 id=327U;
    static const IdByte byte=Low;

    SetCPURatioMessage ();

    struct DataBlock {
        lltypes::U8 Ratio;
    };
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const SetCPURatioMessage & o);
QDataStream &operator>>(QDataStream & in,  SetCPURatioMessage & o);

struct SimCrashedMessage : UdpMessage {
    static const quint32 id=328U;
    static const IdByte byte=Low;

    SimCrashedMessage ();

    struct DataBlock {
        lltypes::U32 RegionX;
        lltypes::U32 RegionY;
    };
    struct UsersBlock {
        lltypes::LLUUID AgentID;
    };
    DataBlock Data;
    QVector<UsersBlock> Users;
};

QDataStream &operator<<(QDataStream & out, const SimCrashedMessage & o);
QDataStream &operator>>(QDataStream & in,  SimCrashedMessage & o);

struct NameValuePairMessage : UdpMessage {
    static const quint32 id=329U;
    static const IdByte byte=Low;

    NameValuePairMessage ();

    struct TaskDataBlock {
        lltypes::LLUUID ID;
    };
    struct NameValueDataBlock {
        lltypes::Variable<2> NVPair;
    };
    TaskDataBlock TaskData;
    QVector<NameValueDataBlock> NameValueData;
};

QDataStream &operator<<(QDataStream & out, const NameValuePairMessage & o);
QDataStream &operator>>(QDataStream & in,  NameValuePairMessage & o);

struct RemoveNameValuePairMessage : UdpMessage {
    static const quint32 id=330U;
    static const IdByte byte=Low;

    RemoveNameValuePairMessage ();

    struct TaskDataBlock {
        lltypes::LLUUID ID;
    };
    struct NameValueDataBlock {
        lltypes::Variable<2> NVPair;
    };
    TaskDataBlock TaskData;
    QVector<NameValueDataBlock> NameValueData;
};

QDataStream &operator<<(QDataStream & out, const RemoveNameValuePairMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveNameValuePairMessage & o);

struct UpdateAttachmentMessage : UdpMessage {
    static const quint32 id=331U;
    static const IdByte byte=Low;

    UpdateAttachmentMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct AttachmentBlockBlock {
        lltypes::U8 AttachmentPoint;
    };
    struct OperationDataBlock {
        lltypes::BOOL AddItem;
        lltypes::BOOL UseExistingAsset;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID AssetID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    AttachmentBlockBlock AttachmentBlock;
    OperationDataBlock OperationData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const UpdateAttachmentMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateAttachmentMessage & o);

struct RemoveAttachmentMessage : UdpMessage {
    static const quint32 id=332U;
    static const IdByte byte=Low;

    RemoveAttachmentMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct AttachmentBlockBlock {
        lltypes::U8 AttachmentPoint;
        lltypes::LLUUID ItemID;
    };
    AgentDataBlock AgentData;
    AttachmentBlockBlock AttachmentBlock;
};

QDataStream &operator<<(QDataStream & out, const RemoveAttachmentMessage & o);
QDataStream &operator>>(QDataStream & in,  RemoveAttachmentMessage & o);

struct SoundTriggerMessage : UdpMessage {
    static const quint32 id=29U;
    static const IdByte byte=High;

    SoundTriggerMessage ();

    struct SoundDataBlock {
        lltypes::LLUUID SoundID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID ParentID;
        lltypes::U64 Handle;
        lltypes::LLVector3 Position;
        lltypes::F32 Gain;
    };
    SoundDataBlock SoundData;
};

QDataStream &operator<<(QDataStream & out, const SoundTriggerMessage & o);
QDataStream &operator>>(QDataStream & in,  SoundTriggerMessage & o);

struct AttachedSoundMessage : UdpMessage {
    static const quint32 id=13U;
    static const IdByte byte=Medium;

    AttachedSoundMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID SoundID;
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::F32 Gain;
        lltypes::U8 Flags;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const AttachedSoundMessage & o);
QDataStream &operator>>(QDataStream & in,  AttachedSoundMessage & o);

struct AttachedSoundGainChangeMessage : UdpMessage {
    static const quint32 id=14U;
    static const IdByte byte=Medium;

    AttachedSoundGainChangeMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID ObjectID;
        lltypes::F32 Gain;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const AttachedSoundGainChangeMessage & o);
QDataStream &operator>>(QDataStream & in,  AttachedSoundGainChangeMessage & o);

struct PreloadSoundMessage : UdpMessage {
    static const quint32 id=15U;
    static const IdByte byte=Medium;

    PreloadSoundMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID ObjectID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID SoundID;
    };
    QVector<DataBlockBlock> DataBlock;
};

QDataStream &operator<<(QDataStream & out, const PreloadSoundMessage & o);
QDataStream &operator>>(QDataStream & in,  PreloadSoundMessage & o);

struct AssetUploadRequestMessage : UdpMessage {
    static const quint32 id=333U;
    static const IdByte byte=Low;

    AssetUploadRequestMessage ();

    struct AssetBlockBlock {
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::BOOL Tempfile;
        lltypes::BOOL StoreLocal;
        lltypes::Variable<2> AssetData;
    };
    AssetBlockBlock AssetBlock;
};

QDataStream &operator<<(QDataStream & out, const AssetUploadRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  AssetUploadRequestMessage & o);

struct AssetUploadCompleteMessage : UdpMessage {
    static const quint32 id=334U;
    static const IdByte byte=Low;

    AssetUploadCompleteMessage ();

    struct AssetBlockBlock {
        lltypes::LLUUID UUID;
        lltypes::S8 Type;
        lltypes::BOOL Success;
    };
    AssetBlockBlock AssetBlock;
};

QDataStream &operator<<(QDataStream & out, const AssetUploadCompleteMessage & o);
QDataStream &operator>>(QDataStream & in,  AssetUploadCompleteMessage & o);

struct EmailMessageRequestMessage : UdpMessage {
    static const quint32 id=335U;
    static const IdByte byte=Low;

    EmailMessageRequestMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID ObjectID;
        lltypes::Variable<1> FromAddress;
        lltypes::Variable<1> Subject;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const EmailMessageRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EmailMessageRequestMessage & o);

struct EmailMessageReplyMessage : UdpMessage {
    static const quint32 id=336U;
    static const IdByte byte=Low;

    EmailMessageReplyMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID ObjectID;
        lltypes::U32 More;
        lltypes::U32 Time;
        lltypes::Variable<1> FromAddress;
        lltypes::Variable<1> Subject;
        lltypes::Variable<2> Data;
        lltypes::Variable<1> MailFilter;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const EmailMessageReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  EmailMessageReplyMessage & o);

struct InternalScriptMailMessage : UdpMessage {
    static const quint32 id=16U;
    static const IdByte byte=Medium;

    InternalScriptMailMessage ();

    struct DataBlockBlock {
        lltypes::Variable<1> From;
        lltypes::LLUUID To;
        lltypes::Variable<1> Subject;
        lltypes::Variable<2> Body;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const InternalScriptMailMessage & o);
QDataStream &operator>>(QDataStream & in,  InternalScriptMailMessage & o);

struct ScriptDataRequestMessage : UdpMessage {
    static const quint32 id=337U;
    static const IdByte byte=Low;

    ScriptDataRequestMessage ();

    struct DataBlockBlock {
        lltypes::U64 Hash;
        lltypes::S8 RequestType;
        lltypes::Variable<2> Request;
    };
    QVector<DataBlockBlock> DataBlock;
};

QDataStream &operator<<(QDataStream & out, const ScriptDataRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptDataRequestMessage & o);

struct ScriptDataReplyMessage : UdpMessage {
    static const quint32 id=338U;
    static const IdByte byte=Low;

    ScriptDataReplyMessage ();

    struct DataBlockBlock {
        lltypes::U64 Hash;
        lltypes::Variable<2> Reply;
    };
    QVector<DataBlockBlock> DataBlock;
};

QDataStream &operator<<(QDataStream & out, const ScriptDataReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptDataReplyMessage & o);

struct CreateGroupRequestMessage : UdpMessage {
    static const quint32 id=339U;
    static const IdByte byte=Low;

    CreateGroupRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Charter;
        lltypes::BOOL ShowInList;
        lltypes::LLUUID InsigniaID;
        lltypes::S32 MembershipFee;
        lltypes::BOOL OpenEnrollment;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const CreateGroupRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateGroupRequestMessage & o);

struct CreateGroupReplyMessage : UdpMessage {
    static const quint32 id=340U;
    static const IdByte byte=Low;

    CreateGroupReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct ReplyDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL Success;
        lltypes::Variable<1> Message;
    };
    AgentDataBlock AgentData;
    ReplyDataBlock ReplyData;
};

QDataStream &operator<<(QDataStream & out, const CreateGroupReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateGroupReplyMessage & o);

struct UpdateGroupInfoMessage : UdpMessage {
    static const quint32 id=341U;
    static const IdByte byte=Low;

    UpdateGroupInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::Variable<2> Charter;
        lltypes::BOOL ShowInList;
        lltypes::LLUUID InsigniaID;
        lltypes::S32 MembershipFee;
        lltypes::BOOL OpenEnrollment;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const UpdateGroupInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateGroupInfoMessage & o);

struct GroupRoleChangesMessage : UdpMessage {
    static const quint32 id=342U;
    static const IdByte byte=Low;

    GroupRoleChangesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct RoleChangeBlock {
        lltypes::LLUUID RoleID;
        lltypes::LLUUID MemberID;
        lltypes::U32 Change;
    };
    AgentDataBlock AgentData;
    QVector<RoleChangeBlock> RoleChange;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleChangesMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleChangesMessage & o);

struct JoinGroupRequestMessage : UdpMessage {
    static const quint32 id=343U;
    static const IdByte byte=Low;

    JoinGroupRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const JoinGroupRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  JoinGroupRequestMessage & o);

struct JoinGroupReplyMessage : UdpMessage {
    static const quint32 id=344U;
    static const IdByte byte=Low;

    JoinGroupReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL Success;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const JoinGroupReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  JoinGroupReplyMessage & o);

struct EjectGroupMemberRequestMessage : UdpMessage {
    static const quint32 id=345U;
    static const IdByte byte=Low;

    EjectGroupMemberRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    struct EjectDataBlock {
        lltypes::LLUUID EjecteeID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    QVector<EjectDataBlock> EjectData;
};

QDataStream &operator<<(QDataStream & out, const EjectGroupMemberRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  EjectGroupMemberRequestMessage & o);

struct EjectGroupMemberReplyMessage : UdpMessage {
    static const quint32 id=346U;
    static const IdByte byte=Low;

    EjectGroupMemberReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    struct EjectDataBlock {
        lltypes::BOOL Success;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    EjectDataBlock EjectData;
};

QDataStream &operator<<(QDataStream & out, const EjectGroupMemberReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  EjectGroupMemberReplyMessage & o);

struct LeaveGroupRequestMessage : UdpMessage {
    static const quint32 id=347U;
    static const IdByte byte=Low;

    LeaveGroupRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const LeaveGroupRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  LeaveGroupRequestMessage & o);

struct LeaveGroupReplyMessage : UdpMessage {
    static const quint32 id=348U;
    static const IdByte byte=Low;

    LeaveGroupReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL Success;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const LeaveGroupReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  LeaveGroupReplyMessage & o);

struct InviteGroupRequestMessage : UdpMessage {
    static const quint32 id=349U;
    static const IdByte byte=Low;

    InviteGroupRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    struct InviteDataBlock {
        lltypes::LLUUID InviteeID;
        lltypes::LLUUID RoleID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    QVector<InviteDataBlock> InviteData;
};

QDataStream &operator<<(QDataStream & out, const InviteGroupRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  InviteGroupRequestMessage & o);

struct InviteGroupResponseMessage : UdpMessage {
    static const quint32 id=350U;
    static const IdByte byte=Low;

    InviteGroupResponseMessage ();

    struct InviteDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID InviteeID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RoleID;
        lltypes::S32 MembershipFee;
    };
    InviteDataBlock InviteData;
};

QDataStream &operator<<(QDataStream & out, const InviteGroupResponseMessage & o);
QDataStream &operator>>(QDataStream & in,  InviteGroupResponseMessage & o);

struct GroupProfileRequestMessage : UdpMessage {
    static const quint32 id=351U;
    static const IdByte byte=Low;

    GroupProfileRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupProfileRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupProfileRequestMessage & o);

struct GroupProfileReplyMessage : UdpMessage {
    static const quint32 id=352U;
    static const IdByte byte=Low;

    GroupProfileReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::Variable<1> Name;
        lltypes::Variable<2> Charter;
        lltypes::BOOL ShowInList;
        lltypes::Variable<1> MemberTitle;
        lltypes::U64 PowersMask;
        lltypes::LLUUID InsigniaID;
        lltypes::LLUUID FounderID;
        lltypes::S32 MembershipFee;
        lltypes::BOOL OpenEnrollment;
        lltypes::S32 Money;
        lltypes::S32 GroupMembershipCount;
        lltypes::S32 GroupRolesCount;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
        lltypes::LLUUID OwnerRole;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupProfileReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupProfileReplyMessage & o);

struct GroupAccountSummaryRequestMessage : UdpMessage {
    static const quint32 id=353U;
    static const IdByte byte=Low;

    GroupAccountSummaryRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountSummaryRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountSummaryRequestMessage & o);

struct GroupAccountSummaryReplyMessage : UdpMessage {
    static const quint32 id=354U;
    static const IdByte byte=Low;

    GroupAccountSummaryReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
        lltypes::Variable<1> StartDate;
        lltypes::S32 Balance;
        lltypes::S32 TotalCredits;
        lltypes::S32 TotalDebits;
        lltypes::S32 ObjectTaxCurrent;
        lltypes::S32 LightTaxCurrent;
        lltypes::S32 LandTaxCurrent;
        lltypes::S32 GroupTaxCurrent;
        lltypes::S32 ParcelDirFeeCurrent;
        lltypes::S32 ObjectTaxEstimate;
        lltypes::S32 LightTaxEstimate;
        lltypes::S32 LandTaxEstimate;
        lltypes::S32 GroupTaxEstimate;
        lltypes::S32 ParcelDirFeeEstimate;
        lltypes::S32 NonExemptMembers;
        lltypes::Variable<1> LastTaxDate;
        lltypes::Variable<1> TaxDate;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountSummaryReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountSummaryReplyMessage & o);

struct GroupAccountDetailsRequestMessage : UdpMessage {
    static const quint32 id=355U;
    static const IdByte byte=Low;

    GroupAccountDetailsRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountDetailsRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountDetailsRequestMessage & o);

struct GroupAccountDetailsReplyMessage : UdpMessage {
    static const quint32 id=356U;
    static const IdByte byte=Low;

    GroupAccountDetailsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
        lltypes::Variable<1> StartDate;
    };
    struct HistoryDataBlock {
        lltypes::Variable<1> Description;
        lltypes::S32 Amount;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
    QVector<HistoryDataBlock> HistoryData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountDetailsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountDetailsReplyMessage & o);

struct GroupAccountTransactionsRequestMessage : UdpMessage {
    static const quint32 id=357U;
    static const IdByte byte=Low;

    GroupAccountTransactionsRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountTransactionsRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountTransactionsRequestMessage & o);

struct GroupAccountTransactionsReplyMessage : UdpMessage {
    static const quint32 id=358U;
    static const IdByte byte=Low;

    GroupAccountTransactionsReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct MoneyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::S32 IntervalDays;
        lltypes::S32 CurrentInterval;
        lltypes::Variable<1> StartDate;
    };
    struct HistoryDataBlock {
        lltypes::Variable<1> Time;
        lltypes::Variable<1> User;
        lltypes::S32 Type;
        lltypes::Variable<1> Item;
        lltypes::S32 Amount;
    };
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
    QVector<HistoryDataBlock> HistoryData;
};

QDataStream &operator<<(QDataStream & out, const GroupAccountTransactionsReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupAccountTransactionsReplyMessage & o);

struct GroupActiveProposalsRequestMessage : UdpMessage {
    static const quint32 id=359U;
    static const IdByte byte=Low;

    GroupActiveProposalsRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;
};

QDataStream &operator<<(QDataStream & out, const GroupActiveProposalsRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupActiveProposalsRequestMessage & o);

struct GroupActiveProposalItemReplyMessage : UdpMessage {
    static const quint32 id=360U;
    static const IdByte byte=Low;

    GroupActiveProposalItemReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::U32 TotalNumItems;
    };
    struct ProposalDataBlock {
        lltypes::LLUUID VoteID;
        lltypes::LLUUID VoteInitiator;
        lltypes::Variable<1> TerseDateID;
        lltypes::Variable<1> StartDateTime;
        lltypes::Variable<1> EndDateTime;
        lltypes::BOOL AlreadyVoted;
        lltypes::Variable<1> VoteCast;
        lltypes::F32 Majority;
        lltypes::S32 Quorum;
        lltypes::Variable<1> ProposalText;
    };
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    QVector<ProposalDataBlock> ProposalData;
};

QDataStream &operator<<(QDataStream & out, const GroupActiveProposalItemReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupActiveProposalItemReplyMessage & o);

struct GroupVoteHistoryRequestMessage : UdpMessage {
    static const quint32 id=361U;
    static const IdByte byte=Low;

    GroupVoteHistoryRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;
};

QDataStream &operator<<(QDataStream & out, const GroupVoteHistoryRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupVoteHistoryRequestMessage & o);

struct GroupVoteHistoryItemReplyMessage : UdpMessage {
    static const quint32 id=362U;
    static const IdByte byte=Low;

    GroupVoteHistoryItemReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    struct TransactionDataBlock {
        lltypes::LLUUID TransactionID;
        lltypes::U32 TotalNumItems;
    };
    struct HistoryItemDataBlock {
        lltypes::LLUUID VoteID;
        lltypes::Variable<1> TerseDateID;
        lltypes::Variable<1> StartDateTime;
        lltypes::Variable<1> EndDateTime;
        lltypes::LLUUID VoteInitiator;
        lltypes::Variable<1> VoteType;
        lltypes::Variable<1> VoteResult;
        lltypes::F32 Majority;
        lltypes::S32 Quorum;
        lltypes::Variable<2> ProposalText;
    };
    struct VoteItemBlock {
        lltypes::LLUUID CandidateID;
        lltypes::Variable<1> VoteCast;
        lltypes::S32 NumVotes;
    };
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    HistoryItemDataBlock HistoryItemData;
    QVector<VoteItemBlock> VoteItem;
};

QDataStream &operator<<(QDataStream & out, const GroupVoteHistoryItemReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupVoteHistoryItemReplyMessage & o);

struct StartGroupProposalMessage : UdpMessage {
    static const quint32 id=363U;
    static const IdByte byte=Low;

    StartGroupProposalMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ProposalDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::S32 Quorum;
        lltypes::F32 Majority;
        lltypes::S32 Duration;
        lltypes::Variable<1> ProposalText;
    };
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;
};

QDataStream &operator<<(QDataStream & out, const StartGroupProposalMessage & o);
QDataStream &operator>>(QDataStream & in,  StartGroupProposalMessage & o);

struct GroupProposalBallotMessage : UdpMessage {
    static const quint32 id=364U;
    static const IdByte byte=Low;

    GroupProposalBallotMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ProposalDataBlock {
        lltypes::LLUUID ProposalID;
        lltypes::LLUUID GroupID;
        lltypes::Variable<1> VoteCast;
    };
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;
};

QDataStream &operator<<(QDataStream & out, const GroupProposalBallotMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupProposalBallotMessage & o);

struct TallyVotesMessage : UdpMessage {
    static const quint32 id=365U;
    static const IdByte byte=Low;

    TallyVotesMessage ();

};

QDataStream &operator<<(QDataStream & out, const TallyVotesMessage & o);
QDataStream &operator>>(QDataStream & in,  TallyVotesMessage & o);

struct GroupMembersRequestMessage : UdpMessage {
    static const quint32 id=366U;
    static const IdByte byte=Low;

    GroupMembersRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupMembersRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupMembersRequestMessage & o);

struct GroupMembersReplyMessage : UdpMessage {
    static const quint32 id=367U;
    static const IdByte byte=Low;

    GroupMembersReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
        lltypes::S32 MemberCount;
    };
    struct MemberDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::S32 Contribution;
        lltypes::Variable<1> OnlineStatus;
        lltypes::U64 AgentPowers;
        lltypes::Variable<1> Title;
        lltypes::BOOL IsOwner;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    QVector<MemberDataBlock> MemberData;
};

QDataStream &operator<<(QDataStream & out, const GroupMembersReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupMembersReplyMessage & o);

struct ActivateGroupMessage : UdpMessage {
    static const quint32 id=368U;
    static const IdByte byte=Low;

    ActivateGroupMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const ActivateGroupMessage & o);
QDataStream &operator>>(QDataStream & in,  ActivateGroupMessage & o);

struct SetGroupContributionMessage : UdpMessage {
    static const quint32 id=369U;
    static const IdByte byte=Low;

    SetGroupContributionMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
        lltypes::S32 Contribution;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const SetGroupContributionMessage & o);
QDataStream &operator>>(QDataStream & in,  SetGroupContributionMessage & o);

struct SetGroupAcceptNoticesMessage : UdpMessage {
    static const quint32 id=370U;
    static const IdByte byte=Low;

    SetGroupAcceptNoticesMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct DataBlock {
        lltypes::LLUUID GroupID;
        lltypes::BOOL AcceptNotices;
    };
    struct NewDataBlock {
        lltypes::BOOL ListInProfile;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
    NewDataBlock NewData;
};

QDataStream &operator<<(QDataStream & out, const SetGroupAcceptNoticesMessage & o);
QDataStream &operator>>(QDataStream & in,  SetGroupAcceptNoticesMessage & o);

struct GroupRoleDataRequestMessage : UdpMessage {
    static const quint32 id=371U;
    static const IdByte byte=Low;

    GroupRoleDataRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleDataRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleDataRequestMessage & o);

struct GroupRoleDataReplyMessage : UdpMessage {
    static const quint32 id=372U;
    static const IdByte byte=Low;

    GroupRoleDataReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
        lltypes::S32 RoleCount;
    };
    struct RoleDataBlock {
        lltypes::LLUUID RoleID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Title;
        lltypes::Variable<1> Description;
        lltypes::U64 Powers;
        lltypes::U32 Members;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    QVector<RoleDataBlock> RoleData;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleDataReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleDataReplyMessage & o);

struct GroupRoleMembersRequestMessage : UdpMessage {
    static const quint32 id=373U;
    static const IdByte byte=Low;

    GroupRoleMembersRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
    };
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleMembersRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleMembersRequestMessage & o);

struct GroupRoleMembersReplyMessage : UdpMessage {
    static const quint32 id=374U;
    static const IdByte byte=Low;

    GroupRoleMembersReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
        lltypes::U32 TotalPairs;
    };
    struct MemberDataBlock {
        lltypes::LLUUID RoleID;
        lltypes::LLUUID MemberID;
    };
    AgentDataBlock AgentData;
    QVector<MemberDataBlock> MemberData;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleMembersReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleMembersReplyMessage & o);

struct GroupTitlesRequestMessage : UdpMessage {
    static const quint32 id=375U;
    static const IdByte byte=Low;

    GroupTitlesRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const GroupTitlesRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupTitlesRequestMessage & o);

struct GroupTitlesReplyMessage : UdpMessage {
    static const quint32 id=376U;
    static const IdByte byte=Low;

    GroupTitlesReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID RequestID;
    };
    struct GroupDataBlock {
        lltypes::Variable<1> Title;
        lltypes::LLUUID RoleID;
        lltypes::BOOL Selected;
    };
    AgentDataBlock AgentData;
    QVector<GroupDataBlock> GroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupTitlesReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupTitlesReplyMessage & o);

struct GroupTitleUpdateMessage : UdpMessage {
    static const quint32 id=377U;
    static const IdByte byte=Low;

    GroupTitleUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
        lltypes::LLUUID TitleRoleID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const GroupTitleUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupTitleUpdateMessage & o);

struct GroupRoleUpdateMessage : UdpMessage {
    static const quint32 id=378U;
    static const IdByte byte=Low;

    GroupRoleUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID GroupID;
    };
    struct RoleDataBlock {
        lltypes::LLUUID RoleID;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::Variable<1> Title;
        lltypes::U64 Powers;
        lltypes::U8 UpdateType;
    };
    AgentDataBlock AgentData;
    QVector<RoleDataBlock> RoleData;
};

QDataStream &operator<<(QDataStream & out, const GroupRoleUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupRoleUpdateMessage & o);

struct LiveHelpGroupRequestMessage : UdpMessage {
    static const quint32 id=379U;
    static const IdByte byte=Low;

    LiveHelpGroupRequestMessage ();

    struct RequestDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::LLUUID AgentID;
    };
    RequestDataBlock RequestData;
};

QDataStream &operator<<(QDataStream & out, const LiveHelpGroupRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  LiveHelpGroupRequestMessage & o);

struct LiveHelpGroupReplyMessage : UdpMessage {
    static const quint32 id=380U;
    static const IdByte byte=Low;

    LiveHelpGroupReplyMessage ();

    struct ReplyDataBlock {
        lltypes::LLUUID RequestID;
        lltypes::LLUUID GroupID;
        lltypes::Variable<1> Selection;
    };
    ReplyDataBlock ReplyData;
};

QDataStream &operator<<(QDataStream & out, const LiveHelpGroupReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  LiveHelpGroupReplyMessage & o);

struct AgentWearablesRequestMessage : UdpMessage {
    static const quint32 id=381U;
    static const IdByte byte=Low;

    AgentWearablesRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentWearablesRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentWearablesRequestMessage & o);

struct AgentWearablesUpdateMessage : UdpMessage {
    static const quint32 id=382U;
    static const IdByte byte=Low;

    AgentWearablesUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 SerialNum;
    };
    struct WearableDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID AssetID;
        lltypes::U8 WearableType;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
};

QDataStream &operator<<(QDataStream & out, const AgentWearablesUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentWearablesUpdateMessage & o);

struct AgentIsNowWearingMessage : UdpMessage {
    static const quint32 id=383U;
    static const IdByte byte=Low;

    AgentIsNowWearingMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct WearableDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::U8 WearableType;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
};

QDataStream &operator<<(QDataStream & out, const AgentIsNowWearingMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentIsNowWearingMessage & o);

struct AgentCachedTextureMessage : UdpMessage {
    static const quint32 id=384U;
    static const IdByte byte=Low;

    AgentCachedTextureMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::S32 SerialNum;
    };
    struct WearableDataBlock {
        lltypes::LLUUID ID;
        lltypes::U8 TextureIndex;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
};

QDataStream &operator<<(QDataStream & out, const AgentCachedTextureMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentCachedTextureMessage & o);

struct AgentCachedTextureResponseMessage : UdpMessage {
    static const quint32 id=385U;
    static const IdByte byte=Low;

    AgentCachedTextureResponseMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::S32 SerialNum;
    };
    struct WearableDataBlock {
        lltypes::LLUUID TextureID;
        lltypes::U8 TextureIndex;
        lltypes::Variable<1> HostName;
    };
    AgentDataBlock AgentData;
    QVector<WearableDataBlock> WearableData;
};

QDataStream &operator<<(QDataStream & out, const AgentCachedTextureResponseMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentCachedTextureResponseMessage & o);

struct AgentDataUpdateRequestMessage : UdpMessage {
    static const quint32 id=386U;
    static const IdByte byte=Low;

    AgentDataUpdateRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentDataUpdateRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentDataUpdateRequestMessage & o);

struct AgentDataUpdateMessage : UdpMessage {
    static const quint32 id=387U;
    static const IdByte byte=Low;

    AgentDataUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::Variable<1> FirstName;
        lltypes::Variable<1> LastName;
        lltypes::Variable<1> GroupTitle;
        lltypes::LLUUID ActiveGroupID;
        lltypes::U64 GroupPowers;
        lltypes::Variable<1> GroupName;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentDataUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentDataUpdateMessage & o);

struct GroupDataUpdateMessage : UdpMessage {
    static const quint32 id=388U;
    static const IdByte byte=Low;

    GroupDataUpdateMessage ();

    struct AgentGroupDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
        lltypes::U64 AgentPowers;
        lltypes::Variable<1> GroupTitle;
    };
    QVector<AgentGroupDataBlock> AgentGroupData;
};

QDataStream &operator<<(QDataStream & out, const GroupDataUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  GroupDataUpdateMessage & o);

struct AgentGroupDataUpdateMessage : UdpMessage {
    static const quint32 id=389U;
    static const IdByte byte=Low;

    AgentGroupDataUpdateMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct GroupDataBlock {
        lltypes::LLUUID GroupID;
        lltypes::U64 GroupPowers;
        lltypes::BOOL AcceptNotices;
        lltypes::LLUUID GroupInsigniaID;
        lltypes::S32 Contribution;
        lltypes::Variable<1> GroupName;
    };
    AgentDataBlock AgentData;
    QVector<GroupDataBlock> GroupData;
};

QDataStream &operator<<(QDataStream & out, const AgentGroupDataUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentGroupDataUpdateMessage & o);

struct AgentDropGroupMessage : UdpMessage {
    static const quint32 id=390U;
    static const IdByte byte=Low;

    AgentDropGroupMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID GroupID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const AgentDropGroupMessage & o);
QDataStream &operator>>(QDataStream & in,  AgentDropGroupMessage & o);

struct LogTextMessageMessage : UdpMessage {
    static const quint32 id=391U;
    static const IdByte byte=Low;

    LogTextMessageMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID FromAgentId;
        lltypes::LLUUID ToAgentId;
        lltypes::F64 GlobalX;
        lltypes::F64 GlobalY;
        lltypes::U32 Time;
        lltypes::Variable<2> Message;
    };
    QVector<DataBlockBlock> DataBlock;
};

QDataStream &operator<<(QDataStream & out, const LogTextMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  LogTextMessageMessage & o);

struct ViewerEffectMessage : UdpMessage {
    static const quint32 id=17U;
    static const IdByte byte=Medium;

    ViewerEffectMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct EffectBlock {
        lltypes::LLUUID ID;
        lltypes::LLUUID AgentID;
        lltypes::U8 Type;
        lltypes::F32 Duration;
        lltypes::Fixed<4> Color;
        lltypes::Variable<1> TypeData;
    };
    AgentDataBlock AgentData;
    QVector<EffectBlock> Effect;
};

QDataStream &operator<<(QDataStream & out, const ViewerEffectMessage & o);
QDataStream &operator>>(QDataStream & in,  ViewerEffectMessage & o);

struct CreateTrustedCircuitMessage : UdpMessage {
    static const quint32 id=392U;
    static const IdByte byte=Low;

    CreateTrustedCircuitMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID EndPointID;
        lltypes::Fixed<32> Digest;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const CreateTrustedCircuitMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateTrustedCircuitMessage & o);

struct DenyTrustedCircuitMessage : UdpMessage {
    static const quint32 id=393U;
    static const IdByte byte=Low;

    DenyTrustedCircuitMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID EndPointID;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const DenyTrustedCircuitMessage & o);
QDataStream &operator>>(QDataStream & in,  DenyTrustedCircuitMessage & o);

struct RequestTrustedCircuitMessage : UdpMessage {
    static const quint32 id=394U;
    static const IdByte byte=Low;

    RequestTrustedCircuitMessage ();

};

QDataStream &operator<<(QDataStream & out, const RequestTrustedCircuitMessage & o);
QDataStream &operator>>(QDataStream & in,  RequestTrustedCircuitMessage & o);

struct RezSingleAttachmentFromInvMessage : UdpMessage {
    static const quint32 id=395U;
    static const IdByte byte=Low;

    RezSingleAttachmentFromInvMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID OwnerID;
        lltypes::U8 AttachmentPt;
        lltypes::U32 ItemFlags;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
    };
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RezSingleAttachmentFromInvMessage & o);
QDataStream &operator>>(QDataStream & in,  RezSingleAttachmentFromInvMessage & o);

struct RezMultipleAttachmentsFromInvMessage : UdpMessage {
    static const quint32 id=396U;
    static const IdByte byte=Low;

    RezMultipleAttachmentsFromInvMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct HeaderDataBlock {
        lltypes::LLUUID CompoundMsgID;
        lltypes::U8 TotalObjects;
        lltypes::BOOL FirstDetachAll;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID OwnerID;
        lltypes::U8 AttachmentPt;
        lltypes::U32 ItemFlags;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
    };
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const RezMultipleAttachmentsFromInvMessage & o);
QDataStream &operator>>(QDataStream & in,  RezMultipleAttachmentsFromInvMessage & o);

struct DetachAttachmentIntoInvMessage : UdpMessage {
    static const quint32 id=397U;
    static const IdByte byte=Low;

    DetachAttachmentIntoInvMessage ();

    struct ObjectDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID ItemID;
    };
    ObjectDataBlock ObjectData;
};

QDataStream &operator<<(QDataStream & out, const DetachAttachmentIntoInvMessage & o);
QDataStream &operator>>(QDataStream & in,  DetachAttachmentIntoInvMessage & o);

struct CreateNewOutfitAttachmentsMessage : UdpMessage {
    static const quint32 id=398U;
    static const IdByte byte=Low;

    CreateNewOutfitAttachmentsMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct HeaderDataBlock {
        lltypes::LLUUID NewFolderID;
    };
    struct ObjectDataBlock {
        lltypes::LLUUID OldItemID;
        lltypes::LLUUID OldFolderID;
    };
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const CreateNewOutfitAttachmentsMessage & o);
QDataStream &operator>>(QDataStream & in,  CreateNewOutfitAttachmentsMessage & o);

struct UserInfoRequestMessage : UdpMessage {
    static const quint32 id=399U;
    static const IdByte byte=Low;

    UserInfoRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const UserInfoRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  UserInfoRequestMessage & o);

struct UserInfoReplyMessage : UdpMessage {
    static const quint32 id=400U;
    static const IdByte byte=Low;

    UserInfoReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct UserDataBlock {
        lltypes::BOOL IMViaEMail;
        lltypes::Variable<1> DirectoryVisibility;
        lltypes::Variable<2> EMail;
    };
    AgentDataBlock AgentData;
    UserDataBlock UserData;
};

QDataStream &operator<<(QDataStream & out, const UserInfoReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  UserInfoReplyMessage & o);

struct UpdateUserInfoMessage : UdpMessage {
    static const quint32 id=401U;
    static const IdByte byte=Low;

    UpdateUserInfoMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct UserDataBlock {
        lltypes::BOOL IMViaEMail;
        lltypes::Variable<1> DirectoryVisibility;
    };
    AgentDataBlock AgentData;
    UserDataBlock UserData;
};

QDataStream &operator<<(QDataStream & out, const UpdateUserInfoMessage & o);
QDataStream &operator>>(QDataStream & in,  UpdateUserInfoMessage & o);

struct ParcelRenameMessage : UdpMessage {
    static const quint32 id=402U;
    static const IdByte byte=Low;

    ParcelRenameMessage ();

    struct ParcelDataBlock {
        lltypes::LLUUID ParcelID;
        lltypes::Variable<1> NewName;
    };
    QVector<ParcelDataBlock> ParcelData;
};

QDataStream &operator<<(QDataStream & out, const ParcelRenameMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelRenameMessage & o);

struct InitiateDownloadMessage : UdpMessage {
    static const quint32 id=403U;
    static const IdByte byte=Low;

    InitiateDownloadMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct FileDataBlock {
        lltypes::Variable<1> SimFilename;
        lltypes::Variable<1> ViewerFilename;
    };
    AgentDataBlock AgentData;
    FileDataBlock FileData;
};

QDataStream &operator<<(QDataStream & out, const InitiateDownloadMessage & o);
QDataStream &operator>>(QDataStream & in,  InitiateDownloadMessage & o);

struct SystemMessageMessage : UdpMessage {
    static const quint32 id=404U;
    static const IdByte byte=Low;

    SystemMessageMessage ();

    struct MethodDataBlock {
        lltypes::Variable<1> Method;
        lltypes::LLUUID Invoice;
        lltypes::Fixed<32> Digest;
    };
    struct ParamListBlock {
        lltypes::Variable<1> Parameter;
    };
    MethodDataBlock MethodData;
    QVector<ParamListBlock> ParamList;
};

QDataStream &operator<<(QDataStream & out, const SystemMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  SystemMessageMessage & o);

struct MapLayerRequestMessage : UdpMessage {
    static const quint32 id=405U;
    static const IdByte byte=Low;

    MapLayerRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const MapLayerRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MapLayerRequestMessage & o);

struct MapLayerReplyMessage : UdpMessage {
    static const quint32 id=406U;
    static const IdByte byte=Low;

    MapLayerReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 Flags;
    };
    struct LayerDataBlock {
        lltypes::U32 Left;
        lltypes::U32 Right;
        lltypes::U32 Top;
        lltypes::U32 Bottom;
        lltypes::LLUUID ImageID;
    };
    AgentDataBlock AgentData;
    QVector<LayerDataBlock> LayerData;
};

QDataStream &operator<<(QDataStream & out, const MapLayerReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  MapLayerReplyMessage & o);

struct MapBlockRequestMessage : UdpMessage {
    static const quint32 id=407U;
    static const IdByte byte=Low;

    MapBlockRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    struct PositionDataBlock {
        lltypes::U16 MinX;
        lltypes::U16 MaxX;
        lltypes::U16 MinY;
        lltypes::U16 MaxY;
    };
    AgentDataBlock AgentData;
    PositionDataBlock PositionData;
};

QDataStream &operator<<(QDataStream & out, const MapBlockRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MapBlockRequestMessage & o);

struct MapNameRequestMessage : UdpMessage {
    static const quint32 id=408U;
    static const IdByte byte=Low;

    MapNameRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    struct NameDataBlock {
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    NameDataBlock NameData;
};

QDataStream &operator<<(QDataStream & out, const MapNameRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MapNameRequestMessage & o);

struct MapBlockReplyMessage : UdpMessage {
    static const quint32 id=409U;
    static const IdByte byte=Low;

    MapBlockReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 Flags;
    };
    struct DataBlock {
        lltypes::U16 X;
        lltypes::U16 Y;
        lltypes::Variable<1> Name;
        lltypes::U8 Access;
        lltypes::U32 RegionFlags;
        lltypes::U8 WaterHeight;
        lltypes::U8 Agents;
        lltypes::LLUUID MapImageID;
    };
    AgentDataBlock AgentData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const MapBlockReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  MapBlockReplyMessage & o);

struct MapItemRequestMessage : UdpMessage {
    static const quint32 id=410U;
    static const IdByte byte=Low;

    MapItemRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::U32 Flags;
        lltypes::U32 EstateID;
        lltypes::BOOL Godlike;
    };
    struct RequestDataBlock {
        lltypes::U32 ItemType;
        lltypes::U64 RegionHandle;
    };
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;
};

QDataStream &operator<<(QDataStream & out, const MapItemRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  MapItemRequestMessage & o);

struct MapItemReplyMessage : UdpMessage {
    static const quint32 id=411U;
    static const IdByte byte=Low;

    MapItemReplyMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::U32 Flags;
    };
    struct RequestDataBlock {
        lltypes::U32 ItemType;
    };
    struct DataBlock {
        lltypes::U32 X;
        lltypes::U32 Y;
        lltypes::LLUUID ID;
        lltypes::S32 Extra;
        lltypes::S32 Extra2;
        lltypes::Variable<1> Name;
    };
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;
    QVector<DataBlock> Data;
};

QDataStream &operator<<(QDataStream & out, const MapItemReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  MapItemReplyMessage & o);

struct SendPostcardMessage : UdpMessage {
    static const quint32 id=412U;
    static const IdByte byte=Low;

    SendPostcardMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
        lltypes::LLUUID AssetID;
        lltypes::LLVector3d PosGlobal;
        lltypes::Variable<1> To;
        lltypes::Variable<1> From;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Subject;
        lltypes::Variable<2> Msg;
        lltypes::BOOL AllowPublish;
        lltypes::BOOL MaturePublish;
    };
    AgentDataBlock AgentData;
};

QDataStream &operator<<(QDataStream & out, const SendPostcardMessage & o);
QDataStream &operator>>(QDataStream & in,  SendPostcardMessage & o);

struct RpcChannelRequestMessage : UdpMessage {
    static const quint32 id=413U;
    static const IdByte byte=Low;

    RpcChannelRequestMessage ();

    struct DataBlockBlock {
        lltypes::U32 GridX;
        lltypes::U32 GridY;
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const RpcChannelRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  RpcChannelRequestMessage & o);

struct RpcChannelReplyMessage : UdpMessage {
    static const quint32 id=414U;
    static const IdByte byte=Low;

    RpcChannelReplyMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID ChannelID;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const RpcChannelReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  RpcChannelReplyMessage & o);

struct RpcScriptRequestInboundMessage : UdpMessage {
    static const quint32 id=415U;
    static const IdByte byte=Low;

    RpcScriptRequestInboundMessage ();

    struct TargetBlockBlock {
        lltypes::U32 GridX;
        lltypes::U32 GridY;
    };
    struct DataBlockBlock {
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID ChannelID;
        lltypes::U32 IntValue;
        lltypes::Variable<2> StringValue;
    };
    TargetBlockBlock TargetBlock;
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const RpcScriptRequestInboundMessage & o);
QDataStream &operator>>(QDataStream & in,  RpcScriptRequestInboundMessage & o);

struct RpcScriptRequestInboundForwardMessage : UdpMessage {
    static const quint32 id=416U;
    static const IdByte byte=Low;

    RpcScriptRequestInboundForwardMessage ();

    struct DataBlockBlock {
        lltypes::IPADDR RPCServerIP;
        lltypes::IPPORT RPCServerPort;
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID ChannelID;
        lltypes::U32 IntValue;
        lltypes::Variable<2> StringValue;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const RpcScriptRequestInboundForwardMessage & o);
QDataStream &operator>>(QDataStream & in,  RpcScriptRequestInboundForwardMessage & o);

struct RpcScriptReplyInboundMessage : UdpMessage {
    static const quint32 id=417U;
    static const IdByte byte=Low;

    RpcScriptReplyInboundMessage ();

    struct DataBlockBlock {
        lltypes::LLUUID TaskID;
        lltypes::LLUUID ItemID;
        lltypes::LLUUID ChannelID;
        lltypes::U32 IntValue;
        lltypes::Variable<2> StringValue;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const RpcScriptReplyInboundMessage & o);
QDataStream &operator>>(QDataStream & in,  RpcScriptReplyInboundMessage & o);

struct ScriptMailRegistrationMessage : UdpMessage {
    static const quint32 id=418U;
    static const IdByte byte=Low;

    ScriptMailRegistrationMessage ();

    struct DataBlockBlock {
        lltypes::Variable<1> TargetIP;
        lltypes::IPPORT TargetPort;
        lltypes::LLUUID TaskID;
        lltypes::U32 Flags;
    };
    DataBlockBlock DataBlock;
};

QDataStream &operator<<(QDataStream & out, const ScriptMailRegistrationMessage & o);
QDataStream &operator>>(QDataStream & in,  ScriptMailRegistrationMessage & o);

struct ParcelMediaCommandMessageMessage : UdpMessage {
    static const quint32 id=419U;
    static const IdByte byte=Low;

    ParcelMediaCommandMessageMessage ();

    struct CommandBlockBlock {
        lltypes::U32 Flags;
        lltypes::U32 Command;
        lltypes::F32 Time;
    };
    CommandBlockBlock CommandBlock;
};

QDataStream &operator<<(QDataStream & out, const ParcelMediaCommandMessageMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelMediaCommandMessageMessage & o);

struct ParcelMediaUpdateMessage : UdpMessage {
    static const quint32 id=420U;
    static const IdByte byte=Low;

    ParcelMediaUpdateMessage ();

    struct DataBlockBlock {
        lltypes::Variable<1> MediaURL;
        lltypes::LLUUID MediaID;
        lltypes::U8 MediaAutoScale;
    };
    struct DataBlockExtendedBlock {
        lltypes::Variable<1> MediaType;
        lltypes::Variable<1> MediaDesc;
        lltypes::S32 MediaWidth;
        lltypes::S32 MediaHeight;
        lltypes::U8 MediaLoop;
    };
    DataBlockBlock DataBlock;
    DataBlockExtendedBlock DataBlockExtended;
};

QDataStream &operator<<(QDataStream & out, const ParcelMediaUpdateMessage & o);
QDataStream &operator>>(QDataStream & in,  ParcelMediaUpdateMessage & o);

struct LandStatRequestMessage : UdpMessage {
    static const quint32 id=421U;
    static const IdByte byte=Low;

    LandStatRequestMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct RequestDataBlock {
        lltypes::U32 ReportType;
        lltypes::U32 RequestFlags;
        lltypes::Variable<1> Filter;
        lltypes::S32 ParcelLocalID;
    };
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;
};

QDataStream &operator<<(QDataStream & out, const LandStatRequestMessage & o);
QDataStream &operator>>(QDataStream & in,  LandStatRequestMessage & o);

struct LandStatReplyMessage : UdpMessage {
    static const quint32 id=422U;
    static const IdByte byte=Low;

    LandStatReplyMessage ();

    struct RequestDataBlock {
        lltypes::U32 ReportType;
        lltypes::U32 RequestFlags;
        lltypes::U32 TotalObjectCount;
    };
    struct ReportDataBlock {
        lltypes::U32 TaskLocalID;
        lltypes::LLUUID TaskID;
        lltypes::F32 LocationX;
        lltypes::F32 LocationY;
        lltypes::F32 LocationZ;
        lltypes::F32 Score;
        lltypes::Variable<1> TaskName;
        lltypes::Variable<1> OwnerName;
    };
    RequestDataBlock RequestData;
    QVector<ReportDataBlock> ReportData;
};

QDataStream &operator<<(QDataStream & out, const LandStatReplyMessage & o);
QDataStream &operator>>(QDataStream & in,  LandStatReplyMessage & o);

struct ErrorMessage : UdpMessage {
    static const quint32 id=423U;
    static const IdByte byte=Low;

    ErrorMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
    };
    struct DataBlock {
        lltypes::S32 Code;
        lltypes::Variable<1> Token;
        lltypes::LLUUID ID;
        lltypes::Variable<1> System;
        lltypes::Variable<2> Message;
        lltypes::Variable<2> Data;
    };
    AgentDataBlock AgentData;
    DataBlock Data;
};

QDataStream &operator<<(QDataStream & out, const ErrorMessage & o);
QDataStream &operator>>(QDataStream & in,  ErrorMessage & o);

struct ObjectIncludeInSearchMessage : UdpMessage {
    static const quint32 id=424U;
    static const IdByte byte=Low;

    ObjectIncludeInSearchMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct ObjectDataBlock {
        lltypes::U32 ObjectLocalID;
        lltypes::BOOL IncludeInSearch;
    };
    AgentDataBlock AgentData;
    QVector<ObjectDataBlock> ObjectData;
};

QDataStream &operator<<(QDataStream & out, const ObjectIncludeInSearchMessage & o);
QDataStream &operator>>(QDataStream & in,  ObjectIncludeInSearchMessage & o);

struct RezRestoreToWorldMessage : UdpMessage {
    static const quint32 id=425U;
    static const IdByte byte=Low;

    RezRestoreToWorldMessage ();

    struct AgentDataBlock {
        lltypes::LLUUID AgentID;
        lltypes::LLUUID SessionID;
    };
    struct InventoryDataBlock {
        lltypes::LLUUID ItemID;
        lltypes::LLUUID FolderID;
        lltypes::LLUUID CreatorID;
        lltypes::LLUUID OwnerID;
        lltypes::LLUUID GroupID;
        lltypes::U32 BaseMask;
        lltypes::U32 OwnerMask;
        lltypes::U32 GroupMask;
        lltypes::U32 EveryoneMask;
        lltypes::U32 NextOwnerMask;
        lltypes::BOOL GroupOwned;
        lltypes::LLUUID TransactionID;
        lltypes::S8 Type;
        lltypes::S8 InvType;
        lltypes::U32 Flags;
        lltypes::U8 SaleType;
        lltypes::S32 SalePrice;
        lltypes::Variable<1> Name;
        lltypes::Variable<1> Description;
        lltypes::S32 CreationDate;
        lltypes::U32 CRC;
    };
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;
};

QDataStream &operator<<(QDataStream & out, const RezRestoreToWorldMessage & o);
QDataStream &operator>>(QDataStream & in,  RezRestoreToWorldMessage & o);

UdpMessage * fromBytes(QByteArray &bytes);

const char * typeName(MessageType type);

}
}
#endif
