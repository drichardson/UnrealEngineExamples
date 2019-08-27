#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyActor.generated.h"

// Example actor that has UPROPERTY and non-UPROPERTY references to UObjects.
UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()

private:

	UPROPERTY(Transient)
	UActorComponent* UPropertyDefaultSubobject;

	UPROPERTY(Transient)
	UActorComponent* UPropertyNewObject;

	UActorComponent* Naked;

	TWeakObjectPtr<class UActorComponent> Weak;

	class MyGCObject* MyGCObj;

	AMyActor();
	~AMyActor();
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
};
