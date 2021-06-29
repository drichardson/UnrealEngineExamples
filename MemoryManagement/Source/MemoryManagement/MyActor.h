#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyActor.generated.h"

// Example actor that has UPROPERTY and non-UPROPERTY references to UObjects.
UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();
	~AMyActor() override;
	void Tick(float DeltaSeconds) override;
	void BeginPlay() override;
	void PostInitializeComponents() override;

private:

	UPROPERTY(Transient)
	UActorComponent* UPropertyDefaultSubobject;

	UPROPERTY(Transient)
	UActorComponent* UPropertyNewObject;

	UActorComponent* Naked;

	TWeakObjectPtr<class UActorComponent> Weak;

	class MyGCObject* MyGCObj;

	UPROPERTY(Transient)
	TArray<class UObject*> UPropertyArrayThisOuter;

	UPROPERTY(Transient)
	TArray<class UObject*> UPropertyArrayNoOuter;

	TArray<class UObject*> NonUPropertyArrayThisOuter;
	TArray<class UObject*> NonUPropertyArrayNoOuter;
};
