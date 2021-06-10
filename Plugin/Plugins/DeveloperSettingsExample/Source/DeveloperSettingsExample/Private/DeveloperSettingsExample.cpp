
#include "DeveloperSettingsExample.h"

#include "MyDeveloperSettings.h"

#define LOCTEXT_NAMESPACE "FDeveloperSettingsExampleModule"

DEFINE_LOG_CATEGORY_STATIC(LogDeveloperSettingsExample, Log, All);

void FDeveloperSettingsExampleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(
		LogDeveloperSettingsExample, Log, TEXT("FDeveloperSettingsExampleModule::StartupModule"));

	UMyDeveloperSettings const* Settings = GetDefault<UMyDeveloperSettings>();

	UE_LOG(LogDeveloperSettingsExample,
		   Log,
		   TEXT("Settings: SomeInt=%d MyFloat=%f"),
		   Settings->SomeInt,
		   Settings->MyFloat);
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
