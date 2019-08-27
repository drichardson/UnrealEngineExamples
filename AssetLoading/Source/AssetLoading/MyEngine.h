#pragma once

#include "Engine/GameEngine.h"
#include "MyEngine.generated.h"

UCLASS()
class UMyEngine : public UGameEngine
{
	GENERATED_BODY()

public:
	UMyEngine();
	~UMyEngine();

private:

	void Init(class IEngineLoop* InEngineLoop) override;
};
