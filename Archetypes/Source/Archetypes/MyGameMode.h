#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"

#include "MyGameMode.generated.h"

UCLASS()
class AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameMode();

	void Tick(float DeltaSeconds) override;
};
