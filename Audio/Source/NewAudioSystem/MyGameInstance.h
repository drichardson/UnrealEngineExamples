#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class NEWAUDIOSYSTEM_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;

	// Initialize the WorldMusicComponent with the given Sound, but only if it
	// hasn't already been initialized.
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	class UAudioComponent* InitializeWorldMusicComponentOnce(UObject* WorldContextObject,
															 class USoundBase* Sound);

private:
	UPROPERTY(Transient)
	class UAudioComponent* WorldMusicComponent;
};
