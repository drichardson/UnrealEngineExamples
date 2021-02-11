#pragma once

#include "Editor/UnrealEdEngine.h"

#include "MyEditorEngine.generated.h"

UCLASS()
class UMyEditorEngine : public UUnrealEdEngine
{
	GENERATED_BODY()

public:
	UMyEditorEngine();
	~UMyEditorEngine();

private:
	void Init(class IEngineLoop* InEngineLoop) override;
};
