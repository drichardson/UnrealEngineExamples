#include "TextAssetActions.h"

#include "MultiBox/MultiBoxBuilder.h"
#include "TextAsset.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FTextAssetActions::FTextAssetActions(const TSharedRef<ISlateStyle>& InStyle)
	: Style(InStyle)
{
}

bool FTextAssetActions::CanFilter()
{
	return true;
}

static bool CanReverseActionExecute(TWeakObjectPtr<UTextAsset> TextAsset)
{
	return TextAsset.IsValid() && !TextAsset->Text.IsEmpty();
}

void FTextAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	auto TextAssets = GetTypedWeakObjectPtrs<UTextAsset>(InObjects);

	FUIAction Action(
		FExecuteAction::CreateLambda([TextAssets] {
			for (auto TextAsset : TextAssets)
			{
				if (CanReverseActionExecute(TextAsset))
				{
					TextAsset->Text = FText::FromString(TextAsset->Text.ToString().Reverse());
					TextAsset->PostEditChange();
					TextAsset->MarkPackageDirty();
				}
			}
		}),
		FCanExecuteAction::CreateLambda([TextAssets] {
			for (auto TextAsset : TextAssets)
			{
				if (CanReverseActionExecute(TextAsset))
				{
					return true;
				}
			}

			return false;
		})
	);

	MenuBuilder.AddMenuEntry(
		LOCTEXT("TextAsset_ReverseText", "Reverse Text"),
		LOCTEXT("TextAsset_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
		FSlateIcon(),
		Action);

}

uint32 FTextAssetActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

FText FTextAssetActions::GetName() const
{
	return LOCTEXT("AssetTypeActions_TextAsset", "Text Asset");
}

UClass* FTextAssetActions::GetSupportedClass() const
{
	return UTextAsset::StaticClass();
}

FColor FTextAssetActions::GetTypeColor() const
{
	return FColor::White;
}

bool FTextAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}
