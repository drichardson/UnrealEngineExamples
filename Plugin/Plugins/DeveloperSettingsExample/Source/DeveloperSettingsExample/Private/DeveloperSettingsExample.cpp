
#include "DeveloperSettingsExample.h"

#include "MyDeveloperSettings.h"

#define LOCTEXT_NAMESPACE "FDeveloperSettingsExampleModule"

DEFINE_LOG_CATEGORY_STATIC(LogDeveloperSettingsExample, Log, All);

template <typename SettingsClass>
void LogMySettings()
{
	SettingsClass const* Settings = GetDefault<SettingsClass>();

	UE_LOG(LogDeveloperSettingsExample,
		   Log,
		   TEXT("%s: SomeInt=%d MyFloat=%f MyPath=%s"),
		   *Settings->GetName(),
		   Settings->SomeInt,
		   Settings->MyFloat,
		   *Settings->MyPath.GetAssetPathName().ToString());
}

void FDeveloperSettingsExampleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(
		LogDeveloperSettingsExample, Log, TEXT("FDeveloperSettingsExampleModule::StartupModule"));

	LogMySettings<UMyGameSettings>();
	LogMySettings<UMyGameDefaultConfigSettings>();
	LogMySettings<UMyEngineSettings>();
	LogMySettings<UMyEngineDefaultConfigSettings>();
	LogMySettings<UMyCustomSettings>();
	LogMySettings<UMyCustomDefaultConfigSettings>();
}

void FDeveloperSettingsExampleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(
		LogDeveloperSettingsExample, Log, TEXT("FDeveloperSettingsExampleModule::ShutdownModule"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDeveloperSettingsExampleModule, DeveloperSettingsExample)
