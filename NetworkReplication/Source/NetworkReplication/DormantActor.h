#pragma once

#include "CoreMinimal.h"

#include "DormantActor.generated.h"

UCLASS()
class ADormantActor : public AActor
{
	GENERATED_BODY()

public:
	ADormantActor();
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void BeginPlay() override;

private:
	FTimerHandle TimerHandle;
	void TimerFired();

	UPROPERTY(ReplicatedUsing = OnRep_TimerCounter, Transient)
	int32 TimerCounter;

	UFUNCTION()
	void OnRep_TimerCounter();
};
