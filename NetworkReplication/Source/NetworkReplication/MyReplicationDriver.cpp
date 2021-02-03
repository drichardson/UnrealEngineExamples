#include "MyReplicationDriver.h"

#include "Engine/ActorChannel.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyRep, Log, All)

UMyReplicationDriver::UMyReplicationDriver()
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

void UMyReplicationDriver::SetRepDriverWorld(UWorld* InWorld)
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

/** Called to associate a netdriver with a rep driver. The rep driver can "get itself ready"
 * here. SetRepDriverWorld() will have already been caleld */
void UMyReplicationDriver::InitForNetDriver(UNetDriver* InNetDriver)
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

/** Called after World and NetDriver have been set. This is where RepDriver should possibly look
 * at existing actors in the world */
void UMyReplicationDriver::InitializeActorsInWorld(UWorld* InWorld)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: InWorld=%s"), __func__, *GetNameSafe(InWorld));
}

void UMyReplicationDriver::TearDown()
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);

	// just copied default implementation
	MarkPendingKill();
}

void UMyReplicationDriver::ResetGameWorldState()
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

void UMyReplicationDriver::AddClientConnection(UNetConnection* NetConnection)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: NetConnection=%s"), __func__, *GetNameSafe(NetConnection));
}

void UMyReplicationDriver::RemoveClientConnection(UNetConnection* NetConnection)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: NetConnection=%s"), __func__, *GetNameSafe(NetConnection));
}

void UMyReplicationDriver::AddNetworkActor(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationDriver::RemoveNetworkActor(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationDriver::ForceNetUpdate(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationDriver::FlushNetDormancy(AActor* Actor, bool WasDormInitial)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: Actor=%s WasDormInitial=%d"),
		   __func__,
		   *GetNameSafe(Actor),
		   WasDormInitial);
}

void UMyReplicationDriver::NotifyActorTearOff(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationDriver::NotifyActorFullyDormantForConnection(AActor* Actor,
																UNetConnection* Connection)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: Actor=%s Connection=%s"),
		   __func__,
		   *GetNameSafe(Actor),
		   *GetNameSafe(Connection));
}

void UMyReplicationDriver::NotifyActorDormancyChange(AActor* Actor, ENetDormancy OldDormancyState)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: Actor=%s OldDormancyState=%d"),
		   __func__,
		   *GetNameSafe(Actor),
		   *UEnum::GetValueAsName(OldDormancyState).ToString());
}

void UMyReplicationDriver::NotifyDestructionInfoCreated(AActor* Actor,
														FActorDestructionInfo& DestructionInfo)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationDriver::SetRoleSwapOnReplicate(AActor* Actor, bool bSwapRoles)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: Actor=%s bSwapRoles=%d"),
		   __func__,
		   *GetNameSafe(Actor),
		   bSwapRoles);
}

int32 UMyReplicationDriver::ServerReplicateActors(float DeltaSeconds)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: DeltaSeconds=%d"), __func__, DeltaSeconds);
	return 0;
}

UMyReplicationGraphConnectionDriver::UMyReplicationGraphConnectionDriver()
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelAdded(AActor* Actor,
																  UActorChannel* Channel)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: Actor=%s Channel=%s"),
		   __func__,
		   *GetNameSafe(Actor),
		   *GetNameSafe(Channel));
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelRemoved(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelCleanedUp(UActorChannel* Channel)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Channel=%s"), __func__, *GetNameSafe(Channel));
}

void UMyReplicationGraphConnectionDriver::NotifyAddDestructionInfo(
	FActorDestructionInfo* DestructInfo)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: PathName=%s Reason=%d NetGUID=%d"),
		   __func__,
		   *DestructInfo->PathName,
		   DestructInfo->Reason,
		   DestructInfo->NetGUID.Value);
}

void UMyReplicationGraphConnectionDriver::NotifyAddDormantDestructionInfo(AActor* Actor)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: Actor=%s"), __func__, *GetNameSafe(Actor));
}

void UMyReplicationGraphConnectionDriver::NotifyRemoveDestructionInfo(
	FActorDestructionInfo* DestructInfo)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: PathName=%s CloseReason=%d NetGUID=%d"),
		   __func__,
		   *DestructInfo->PathName,
		   DestructInfo->Reason,
		   DestructInfo->NetGUID.Value);
}

void UMyReplicationGraphConnectionDriver::NotifyResetDestructionInfo()
{
	UE_LOG(LogMyRep, Log, TEXT("%s"), __func__);
}

void UMyReplicationGraphConnectionDriver::NotifyClientVisibleLevelNamesAdd(FName LevelName,
																		   UWorld* StreamingWorld)
{
	UE_LOG(LogMyRep,
		   Log,
		   TEXT("%s: LevelName=%s StreamingWorld=%s"),
		   __func__,
		   *LevelName.ToString(),
		   *GetNameSafe(StreamingWorld));
}

void UMyReplicationGraphConnectionDriver::NotifyClientVisibleLevelNamesRemove(FName LevelName)
{
	UE_LOG(LogMyRep, Log, TEXT("%s: LevelName=%s"), __func__, *LevelName.ToString());
}
