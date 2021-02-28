#pragma once

#include "CoreMinimal.h"

#include "MyNativeActor.generated.h"

UCLASS()
class AMyNativeActor : public AActor
{
	GENERATED_BODY()

public:
	AMyNativeActor();

private:
	UPROPERTY()
	int MyInt;
};
