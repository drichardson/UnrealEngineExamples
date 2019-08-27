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
