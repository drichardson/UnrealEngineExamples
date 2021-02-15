#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()

private:
	AMyActor();
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;


public:

	// Indirect Property Reference. Have to manually load.
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<class UMaterialInterface> MatSoftObjectPtr;

	// Indirect Property Reference. Have to manually load.
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<class UMaterialInterface> MatSoftObjectPtr_Async;

	TSharedPtr<struct FStreamableHandle> MatSoftObjectPtr_Async_Handle;

	// Shows up in the editor as a UObject.
	UPROPERTY(EditDefaultsOnly)
	FSoftObjectPath MatSoftObjectPath;

private:
	UPROPERTY()
	class UFont* Font;

	UPROPERTY()
	class UTexture* Texture;

	UPROPERTY()
	class UFontFace* FontFace;

	UPROPERTY()
	class UFontFace* LastFontFace = nullptr;

	// Loaded with StaticLoadObject
	UPROPERTY()
	class UMaterialInterface* Mat = nullptr;

	UPROPERTY()
	class UMaterialInterface* LastMat = nullptr;

	void OnAsyncLoadComplete();
};

UCLASS()
class UMyObj : public UObject
{
	GENERATED_BODY()

public:
	UMyObj();
	~UMyObj();
};
