#pragma once

#include "CoreMinimal.h"

#include "MyNativeObject.generated.h"

UCLASS()
class UMyNativeObject : public UObject
{
	GENERATED_BODY()

public:
	UMyNativeObject();

private:
	UPROPERTY()
	int MyInt = 444;
};
