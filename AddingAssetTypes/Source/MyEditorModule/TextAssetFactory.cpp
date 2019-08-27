#include "TextAssetFactory.h"

#include "TextAsset.h"
#include "Misc/FileHelper.h"

UTextAssetFactoryNew::UTextAssetFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UTextAssetFactoryNew::FactoryCreateNew(
	UClass* InClass,
	UObject* InParent,
	FName InName,
	EObjectFlags Flags,
	UObject* Context,
	FFeedbackContext* Warn)
{
	return NewObject<UTextAsset>(InParent, InClass, InName, Flags);
}
bool UTextAssetFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}




UTextAssetFactoryDragAndDrop::UTextAssetFactoryDragAndDrop(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FString const FormatString = FString(TEXT("txt;")) + NSLOCTEXT("UTextAssetFactoryDragAndDrop", "FormatTxt", "Text File").ToString();
	Formats.Add(FormatString);

	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UTextAssetFactoryDragAndDrop::FactoryCreateFile(
	UClass* InClass,
	UObject* InParent,
	FName InName,
	EObjectFlags Flags,
	const FString& Filename,
	const TCHAR* Parms,
	FFeedbackContext* Warn, 
	bool& bOutOperationCanceled)
{
	UTextAsset* TextAsset = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		TextAsset = NewObject<UTextAsset>(InParent, InClass, InName, Flags);
		TextAsset->Text = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;
	
	return TextAsset;
}
