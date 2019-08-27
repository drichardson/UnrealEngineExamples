#pragma once

#include "AssetTypeActions_Base.h"

class FTextAssetActions : public FAssetTypeActions_Base
{
public:

	FTextAssetActions(const TSharedRef<ISlateStyle>& InStyle);

private:

	bool CanFilter() override;
	void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	uint32 GetCategories() override;
	FText GetName() const override;
	UClass* GetSupportedClass() const override;
	FColor GetTypeColor() const override;
	bool HasActions(const TArray<UObject*>& InObjects) const override;

	TSharedRef<class ISlateStyle> Style;
};