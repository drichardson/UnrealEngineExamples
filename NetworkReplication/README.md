# Network Replication Example

Demonstrates how to replicate with Blueprints and C++.

The Blueprint example replicates a Color variable that is used to drive the color of a material.

The C++ example demonstrates replication of:

- C++ primitive types (int, float, bool)
- UE4 structs (FVector)
- UE4 string types (FName, FString, and FText)
- References to UObject members created in the constructor
- References to UObject members created outside of the constructor (see AMyCppActor::ReplicateSubobjects for this)
- References to AActors

Also includes examples of UReplicationDriver and UReplicationGraph sub-classes,
which can be enabled by changing the ReplicationDriverClassName in the
IpNetDriver section of Config/DefaultEngine.ini.

    [/Script/OnlineSubsystemUtils.IpNetDriver]
    ReplicationDriverClassName="/Script/NetworkReplication.MyReplicationDriver"
    ;ReplicationDriverClassName="/Script/NetworkReplication.MyReplicationGraph"
    ;ReplicationDriverClassName="/Script/ReplicationGraph.BasicReplicationGraph"

For more details, see the following UE4 source code files:

    Engine/Plugins/ReplicationGraph/Source/Public/ReplicationGraph.h
    Engine/Source/Runtime/CoreUObject/Public/UObject/CoreNet.h
    Engine/Source/Runtime/Engine/Classes/Engine/ActorChannel.h
    Engine/Source/Runtime/Engine/Classes/Engine/NetDriver.h
    Engine/Source/Runtime/Engine/Classes/Engine/NetSerialization.h
    Engine/Source/Runtime/Engine/Private/ActorReplication.cpp
    Engine/Source/Runtime/Engine/Public/Net/RepLayout.h

## See Also

- [Gaffer on Games](https://gafferongames.com/)
- [Replication Graph Blog Post](https://www.unrealengine.com/en-US/tech-blog/replication-graph-overview-and-proper-replication-methods)
- [Screenshot of Fortnite Replication Graph Setup](https://youtu.be/CDnNAAzgltw?t=2511)
- [The Replication Graph - UE4 Livestream](https://www.youtube.com/watch?v=CDnNAAzgltw)
- [UE4 Networking Replication Flow](https://docs.unrealengine.com/en-US/InteractiveExperiences/Networking/Actors/ReplicationFlow/index.html)
- [UE4 Networking](https://docs.unrealengine.com/en-US/InteractiveExperiences/Networking/index.html)
- [Understanding Net Dormancy (with examples)](https://www.youtube.com/watch?v=18LbGKf6QQw)
