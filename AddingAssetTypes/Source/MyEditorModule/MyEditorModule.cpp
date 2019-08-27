// Fill out your copyright notice in the Description page of Project Settings.

#include "MyEditorModule.h"

#include "Modules/ModuleManager.h"
#include "Styling/SlateStyle.h"
#include "TextAssetActions.h"

class MyEditorModule : public IModuleInterface
{
	TSharedPtr<ISlateStyle> Style;
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;

	void StartupModule() override
	{
		Style = MakeShareable(new FSlateStyleSet("MyModuleStyle"));
		RegisterAssetTools();
	}

	void ShutdownModule() override
	{
		UnregisterAssetTools();
	}

	void RegisterAssetTools()
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		TSharedRef<IAssetTypeActions> Action = MakeShareable(new FTextAssetActions(Style.ToSharedRef()));
		AssetTools.RegisterAssetTypeActions(Action);
		RegisteredAssetTypeActions.Add(Action);
	}

	void UnregisterAssetTools()
	{
		FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");

		if (AssetToolsModule)
		{
			IAssetTools& AssetTools = AssetToolsModule->Get();

			for (auto Action : RegisteredAssetTypeActions)
			{
				AssetTools.UnregisterAssetTypeActions(Action);
			}

			RegisteredAssetTypeActions.Empty();
		}
	}
};

IMPLEMENT_GAME_MODULE(MyEditorModule, MyEditorModule);
