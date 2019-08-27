// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PluginGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PLUGIN_API APluginGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay() override;
};
