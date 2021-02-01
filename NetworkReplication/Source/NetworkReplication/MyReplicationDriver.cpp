#include "MyReplicationDriver.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyRep, Log, All)

UMyReplicationDriver::UMyReplicationDriver()
{
	UE_LOG(LogMyRep, Verbose, TEXT("%s"), __func__);
}

void UMyReplicationDriver::SetRepDriverWorld(UWorld* InWorld)
{
}

/** Called to associate a netdriver with a rep driver. The rep driver can "get itself ready"
 * here. SetRepDriverWorld() will have already been caleld */
void UMyReplicationDriver::InitForNetDriver(UNetDriver* InNetDriver)
{
}

/** Called after World and NetDriver have been set. This is where RepDriver should possibly look
 * at existing actors in the world */
void UMyReplicationDriver::InitializeActorsInWorld(UWorld* InWorld)
{
}

void UMyReplicationDriver::TearDown()
{
	// just copied default implementation
	MarkPendingKill();
}

void UMyReplicationDriver::ResetGameWorldState()
{
}

void UMyReplicationDriver::AddClientConnection(UNetConnection* NetConnection)
{
}

void UMyReplicationDriver::RemoveClientConnection(UNetConnection* NetConnection)
{
}

void UMyReplicationDriver::AddNetworkActor(AActor* Actor)
{
}

void UMyReplicationDriver::RemoveNetworkActor(AActor* Actor)
{
}

void UMyReplicationDriver::ForceNetUpdate(AActor* Actor)
{
}

void UMyReplicationDriver::FlushNetDormancy(AActor* Actor, bool WasDormInitial)
{
}

void UMyReplicationDriver::NotifyActorTearOff(AActor* Actor)
{
}

void UMyReplicationDriver::NotifyActorFullyDormantForConnection(AActor* Actor,
																UNetConnection* Connection)
{
}

void UMyReplicationDriver::NotifyActorDormancyChange(AActor* Actor, ENetDormancy OldDormancyState)
{
}

void UMyReplicationDriver::NotifyDestructionInfoCreated(AActor* Actor,
														FActorDestructionInfo& DestructionInfo)
{
}

void UMyReplicationDriver::SetRoleSwapOnReplicate(AActor* Actor, bool bSwapRoles)
{
}

int32 UMyReplicationDriver::ServerReplicateActors(float DeltaSeconds)
{
	return 0;
}

UMyReplicationGraphConnectionDriver::UMyReplicationGraphConnectionDriver()
{
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelAdded(AActor* Actor,
																  UActorChannel* Channel)
{
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelRemoved(AActor* Actor)
{
}

void UMyReplicationGraphConnectionDriver::NotifyActorChannelCleanedUp(UActorChannel* Channel)
{
}

void UMyReplicationGraphConnectionDriver::NotifyAddDestructionInfo(
	FActorDestructionInfo* DestructInfo)
{
}

void UMyReplicationGraphConnectionDriver::NotifyAddDormantDestructionInfo(AActor* Actor)
{
}

void UMyReplicationGraphConnectionDriver::NotifyRemoveDestructionInfo(
	FActorDestructionInfo* DestructInfo)
{
}

void UMyReplicationGraphConnectionDriver::NotifyResetDestructionInfo()
{
}

void UMyReplicationGraphConnectionDriver::NotifyClientVisibleLevelNamesAdd(FName LevelName,
																		   UWorld* StreamingWorld)
{
}

void UMyReplicationGraphConnectionDriver::NotifyClientVisibleLevelNamesRemove(FName LevelName)
{
}
