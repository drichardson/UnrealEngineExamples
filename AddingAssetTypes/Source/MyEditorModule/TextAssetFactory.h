#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "TextAssetFactory.generated.h"

// Handle Content Browser > Add New
UCLASS()
class UTextAssetFactoryNew : public UFactory
{
	GENERATED_BODY()

	UTextAssetFactoryNew(const FObjectInitializer& ObjectInitializer);
	UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	bool ShouldShowInNewMenu() const override;
};

// Handle Drag and Drop File on Content Browser
UCLASS()
class UTextAssetFactoryDragAndDrop : public UFactory
{
	GENERATED_BODY()

	UTextAssetFactoryDragAndDrop(const FObjectInitializer& ObjectInitializer);
	UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};