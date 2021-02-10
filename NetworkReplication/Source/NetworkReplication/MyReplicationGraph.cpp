#include "MyReplicationGraph.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyRepGraph, Log, All)

UMyReplicationGraph::UMyReplicationGraph()
{
	UE_LOG(LogMyRepGraph, Log, TEXT("%S"), __func__);
}

void UMyReplicationGraph::InitGlobalActorClassSettings()
{
	UE_LOG(LogMyRepGraph, Log, TEXT("%S"), __func__);

	Super::InitGlobalActorClassSettings();
}

void UMyReplicationGraph::InitGlobalGraphNodes()
{
	UE_LOG(LogMyRepGraph, Log, TEXT("%S"), __func__);

	// no call to Super necessary here

	// TODO: Preallocate some replication lists.

	// Preallocation some replication lists. If you don't make them large enough, then you will get
	//		LogOutputDevice: Error: Very large replication list size requested.
	//
	// Use Net.RepGraph.Lists.Stats and Net.RepGraph.Lists.Details console commands to inspect.

	PreAllocateRepList(30, 1);

	AlwaysRelevantNode = CreateNewNode<UReplicationGraphNode_ActorList>();

	AddGlobalGraphNode(AlwaysRelevantNode);
}

void UMyReplicationGraph::InitConnectionGraphNodes(
	UNetReplicationGraphConnection* RepGraphConnection)
{
	UE_LOG(LogMyRepGraph,
		   Log,
		   TEXT("%S: RepGraphConnection=%s"),
		   __func__,
		   *GetNameSafe(RepGraphConnection));

	// Call super, it handles tear off actors.
	Super::InitConnectionGraphNodes(RepGraphConnection);

	UReplicationGraphNode_AlwaysRelevant_ForConnection* Node =
		CreateNewNode<UReplicationGraphNode_AlwaysRelevant_ForConnection>();

	AddConnectionGraphNode(Node, RepGraphConnection);

	ConnectionNodes.Emplace(RepGraphConnection->NetConnection, Node);
}
void UMyReplicationGraph::RouteAddNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo,
													  FGlobalActorReplicationInfo& GlobalInfo)
{
	UE_LOG(LogMyRepGraph,
		   Verbose,
		   TEXT("%S: Actor=%s bOnlyRelevantToOwner=%d"),
		   __func__,
		   *GetNameSafe(ActorInfo.Actor),
		   ActorInfo.Actor->bOnlyRelevantToOwner);

	// DO NOT CALL Super::RouteAddNetworkActorToNodes(ActorInfo, GlobalInfo);

	if (ActorInfo.Actor->bOnlyRelevantToOwner)
	{
		// Only relevant to owner, but we don't know who the owner is yet.
		PendingOnlyRelevantToOwnerActors.Add(ActorInfo.Actor);
	}
	else
	{
		AlwaysRelevantNode->NotifyAddNetworkActor(ActorInfo);
	}
}
void UMyReplicationGraph::RouteRemoveNetworkActorToNodes(const FNewReplicatedActorInfo& ActorInfo)
{
	UE_LOG(LogMyRepGraph, Verbose, TEXT("%S: Actor=%s"), __func__, *GetNameSafe(ActorInfo.Actor));

	// DO NOT CALL Super::RouteRemoveNetworkActorToNodes(ActorInfo);

	AlwaysRelevantNode->NotifyRemoveNetworkActor(ActorInfo);
}

int32 UMyReplicationGraph::ServerReplicateActors(float DeltaSeconds)
{
	UE_LOG(LogMyRepGraph, VeryVerbose, TEXT("%S: DeltaSeconds=%f"), __func__, DeltaSeconds);

	ProcessPendingOnlyRelevantToOwnerActors();

	return Super::ServerReplicateActors(DeltaSeconds);
}

UMyReplicationGraph::ProcessPendingOnlyRelevantToOwnerActors()
{
	for (int32 idx = PendingOnlyRelevantToOwnerActors.Num() - 1; idx >= 0; --idx)
	{
		bool bRemove = false;

		if (AActor* Actor = ActorsWithoutNetConnection[idx])
		{
			if (UNetConnection* Connection = Actor->GetNetConnection())
			{
				bRemove = true;

				if (UReplicationGraphNode_AlwaysRelevant_ForConnection* Node =
						AlwaysRelevantForConnection.FindRef(Actor->GetNetConnection()))
				{
					Node->NotifyAddNetworkActor(FNewReplicatedActorInfo(Actor));
				}
			}
		}
		else
		{
			bRemove = true;
		}

		if (bRemove)
		{
			PendingOnlyRelevantToOwnerActors.RemoveAtSwap(idx, 1, false);
		}
	}
}
