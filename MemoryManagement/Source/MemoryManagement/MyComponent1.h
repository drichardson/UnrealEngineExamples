#pragma once

#include "CoreMinimal.h"

#include "Components/ArrowComponent.h"

#include "MyComponent1.generated.h"

UCLASS()
class UMyComponent1 : public UActorComponent
{
	GENERATED_BODY()

public:
	UMyComponent1();

	virtual ~UMyComponent1() override;

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginDestroy() override;
	virtual void DestroyComponent(bool bPromoteChildren) override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
