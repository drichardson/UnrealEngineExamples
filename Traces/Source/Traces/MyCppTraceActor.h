// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCppTraceActor.generated.h"

UCLASS()
class TRACES_API AMyCppTraceActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Start;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* End;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
	FName Profile;
	
public:	
	AMyCppTraceActor();

	virtual void Tick(float DeltaTime) override;

};
