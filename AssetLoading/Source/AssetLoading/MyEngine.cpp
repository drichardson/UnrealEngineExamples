#include "MyEngine.h"

#include "Engine/Font.h"
#include "Log.h"

UMyEngine::UMyEngine()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEngine::UMyEngine"));
}

UMyEngine::~UMyEngine()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEngine::~UMyEngine"));
}

void UMyEngine::Init(class IEngineLoop* InEngineLoop)
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEngine::Init before Super"));
	Super::Init(InEngineLoop);
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEngine::Init after Super"));

	// "E:\UE4Examples\AssetLoading\AssetLoading.uproject" -skipcompile -game
	// OR
	// "E:\UE4Examples\AssetLoading\AssetLoading.uproject" -skipcompile
	// Font will be non-null.

	// "E:\UE4Examples\AssetLoading\AssetLoading.uproject" -skipcompile -server
	// Font will be null.

	// I believe this behavior is because Slate and the Font Services system is not initialized when
	// -server is passed to UE4Editor.exe. See LaunchEngineLoop.cpp for details.

	UFont* Font =
		LoadObject<UFont>(this, TEXT("Font'/Game/Roboto-Regular_Font.Roboto-Regular_Font'"));
	UE_LOG(LogAssetLoading, Log, TEXT("UMyEngine::Init - Font is %p"), Font);
}
