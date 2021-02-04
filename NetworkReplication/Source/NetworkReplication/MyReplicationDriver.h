#pragma once

#include "CoreMinimal.h"

#include "Engine/ReplicationDriver.h"

#include "MyReplicationDriver.generated.h"

class UMyReplicationConnectionDriver;

UCLASS(transient)
class UMyReplicationDriver : public UReplicationDriver
{
	GENERATED_BODY()

public:
	UMyReplicationDriver();

	/** Called to associate a world with a rep driver. This will be called before  InitForNetDriver
	 */
	void SetRepDriverWorld(UWorld* InWorld) override;

	/** Called to associate a netdriver with a rep driver. The rep driver can "get itself ready"
	 * here. SetRepDriverWorld() will have already been caleld */
	void InitForNetDriver(UNetDriver* InNetDriver) override;

	/** Called after World and NetDriver have been set. This is where RepDriver should possibly look
	 * at existing actors in the world */
	void InitializeActorsInWorld(UWorld* InWorld) override;

	void TearDown() override;

	void ResetGameWorldState() override;

	void AddClientConnection(UNetConnection* NetConnection) override;

	void RemoveClientConnection(UNetConnection* NetConnection) override;

	void AddNetworkActor(AActor* Actor) override;

	void RemoveNetworkActor(AActor* Actor) override;

	void ForceNetUpdate(AActor* Actor) override;

	void FlushNetDormancy(AActor* Actor, bool WasDormInitial) override;

	void NotifyActorTearOff(AActor* Actor) override;

	void NotifyActorFullyDormantForConnection(AActor* Actor, UNetConnection* Connection) override;

	void NotifyActorDormancyChange(AActor* Actor, ENetDormancy OldDormancyState) override;

	/** Called when a destruction info is created for an actor. Can be used to override some of the
	 * destruction info struct */
	void NotifyDestructionInfoCreated(AActor* Actor,
									  FActorDestructionInfo& DestructionInfo) override;

	void SetRoleSwapOnReplicate(AActor* Actor, bool bSwapRoles) override;

	/** The main function that will actually replicate actors. Called every server tick. */
	int32 ServerReplicateActors(float DeltaSeconds) override;

private:
	UPROPERTY()
	UNetDriver* NetDriver;

	TArray<AActor*> NetworkActors;
	TMap<UNetConnection*, UMyReplicationConnectionDriver*> ConnectionDrivers;

	float TimeLeftUntilUpdate = -1.f;
};

UCLASS(transient)
class UMyReplicationConnectionDriver : public UReplicationConnectionDriver
{
	GENERATED_BODY()

public:
	UMyReplicationConnectionDriver();

	void NotifyActorChannelAdded(AActor* Actor, UActorChannel* Channel) override;

	void NotifyActorChannelRemoved(AActor* Actor) override;

	void NotifyActorChannelCleanedUp(UActorChannel* Channel) override;

	void NotifyAddDestructionInfo(FActorDestructionInfo* DestructInfo) override;

	void NotifyAddDormantDestructionInfo(AActor* Actor) override;

	void NotifyRemoveDestructionInfo(FActorDestructionInfo* DestructInfo) override;

	void NotifyResetDestructionInfo() override;

	void NotifyClientVisibleLevelNamesAdd(FName LevelName, UWorld* StreamingWorld) override;

	void NotifyClientVisibleLevelNamesRemove(FName LevelName) override;

public:
	TMap<AActor*, UActorChannel*> ActorChannels;
};
