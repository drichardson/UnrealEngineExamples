// Fill out your copyright notice in the Description page of Project Settings.


#include "PluginGameModeBase.h"

#include "IBlankPlugin.h"
#include "IUObjectPlugin.h"

DECLARE_LOG_CATEGORY_EXTERN(MyExample, Log, All);
DEFINE_LOG_CATEGORY(MyExample);

void APluginGameModeBase::BeginPlay()
{
	UE_LOG(MyExample, Log, TEXT("APluginGameModeBase::BeginPlay"));

	Super::BeginPlay();

	UE_LOG(MyExample, Log, TEXT("IBlankPlugin: is available? %d"), IBlankPlugin::IsAvailable());
	UE_LOG(MyExample, Log, TEXT("IUObjectPlugin: is available? %d"), IUObjectPlugin::IsAvailable());
}
