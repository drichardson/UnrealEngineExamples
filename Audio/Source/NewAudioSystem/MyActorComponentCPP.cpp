// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponentCPP.h"

DECLARE_LOG_CATEGORY_EXTERN(MyProject, Log, All);
DEFINE_LOG_CATEGORY(MyProject);


// Sets default values for this component's properties
UMyActorComponentCPP::UMyActorComponentCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyActorComponentCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyActorComponentCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(MyProject, Error, TEXT("UMyActorComponentCPP::TickComponent called"));


	// ...
}

