#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"

#include "MyDeveloperSettings.generated.h"

UCLASS(config = "Game")
class UMyDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};
