#include "MyEditorEngine.h"

#include "Log.h"

UMyEditorEngine::UMyEditorEngine()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEditorEngine::UMyEditorEngine"));
}

UMyEditorEngine::~UMyEditorEngine()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEditorEngine::~UMyEditorEngine"));
}

void UMyEditorEngine::Init(class IEngineLoop* InEngineLoop)
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEditorEngine::Init before Super"));
	Super::Init(InEngineLoop);
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEditorEngine::Init after Super"));
}
