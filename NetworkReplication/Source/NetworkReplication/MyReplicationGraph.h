#pragma once

#include "CoreMinimal.h"

#include "ReplicationGraph.h"

#include "MyReplicationGraph.generated.h"

UCLASS(transient, config = Engine)
class UMyReplicationGraph : public UReplicationGraph
{
	GENERATED_BODY()

public:
	UMyReplicationGraph();

	void InitGlobalActorClassSettings() override;
	void InitGlobalGraphNodes() override;
	void InitConnectionGraphNodes(UNetReplicationGraphConnection* RepGraphConnection) override;
	void RouteAddNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo,
									 FGlobalActorReplicationInfo& GlobalInfo) override;
	void RouteRemoveNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo) override;

	int32 ServerReplicateActors(float DeltaSeconds) override;

private:
	UReplicationGraphNode_ActorList* AlwaysRelevantNode;

	// Actors that are only supposed to replicate to their owning connection, but that did not have
	// a connection on spawn
	TArray<AActor*> PendingOnlyRelevantToOwnerActors;

	TMap<UNetConnection*, UReplicationGraphNode_AlwaysRelevant_ForConnection*>
		AlwaysRelevantForConnection;
};
