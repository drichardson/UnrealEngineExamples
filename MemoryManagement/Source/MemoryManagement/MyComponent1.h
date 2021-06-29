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

	~UMyComponent1() override;

	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void BeginDestroy() override;
	void DestroyComponent(bool bPromoteChildren) override;

	void TickComponent(float DeltaTime,
					   enum ELevelTick TickType,
					   FActorComponentTickFunction* ThisTickFunction) override;
};
