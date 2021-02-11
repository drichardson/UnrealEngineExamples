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
	UPROPERTY(VisibleAnywhere)
	class UFont* Font;

	UPROPERTY(VisibleAnywhere)
	class UTexture* Texture;

	UPROPERTY(VisibleAnywhere)
	class UFontFace* FontFace;

	class UFontFace* LastFontFace = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UMaterialInterface* Mat;

	class UMaterialInterface* LastMat = nullptr;
};

UCLASS()
class UMyObj : public UObject
{
	GENERATED_BODY()

public:
	UMyObj();
	~UMyObj();
};
