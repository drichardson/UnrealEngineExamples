// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "IUObjectPlugin.h"

#include "Modules/ModuleManager.h"
#include "MyLog.h"



class FUObjectPlugin : public IUObjectPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FUObjectPlugin, UObjectPlugin )



void FUObjectPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	UE_LOG(MyUObjectPlugin, Log, TEXT("FUObjectPlugin::StartupModule"));

}


void FUObjectPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(MyUObjectPlugin, Log, TEXT("FUObjectPlugin::ShutdownModule"));
}



