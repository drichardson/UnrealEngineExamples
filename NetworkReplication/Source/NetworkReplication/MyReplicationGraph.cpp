#include "MyReplicationGraph.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyRepGraph, Log, All)

UMyReplicationGraph::UMyReplicationGraph()
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);
}

void UMyReplicationGraph::InitGlobalActorClassSettings()
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	Super::InitGlobalActorClassSettings();
}

void UMyReplicationGraph::InitGlobalGraphNodes()
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	Super::InitGlobalGraphNodes();
}

void UMyReplicationGraph::InitConnectionGraphNodes(
	UNetReplicationGraphConnection* RepGraphConnection)
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	Super::InitConnectionGraphNodes(RepGraphConnection);
}
void UMyReplicationGraph::RouteAddNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo,
													  FGlobalActorReplicationInfo& GlobalInfo)
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	Super::RouteAddNetworkActorToNodes(ActorInfo, GlobalInfo);
}
void UMyReplicationGraph::RouteRemoveNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo)
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	Super::RouteRemoveNetworkActorToNodes(ActorInfo);
}

int32 UMyReplicationGraph::ServerReplicateActors(float DeltaSeconds)
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%s"), __func__);

	return Super::ServerReplicateActors(DeltaSeconds);
}
