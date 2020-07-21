// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorCPP.h"

DECLARE_LOG_CATEGORY_EXTERN(MyProject, Log, All);


// Sets default values
AMyActorCPP::AMyActorCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(MyProject, Error, TEXT("AMyActorCPP::Tick called"));

}

