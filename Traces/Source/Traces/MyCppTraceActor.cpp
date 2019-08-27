// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCppTraceActor.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


AMyCppTraceActor::AMyCppTraceActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Start = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Start"));
	RootComponent = Start;

	End = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("End"));
	End->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);
}

void AMyCppTraceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector const& StartLocation = Start->GetComponentTransform().GetLocation();
	FVector const& EndLocation = End->GetComponentTransform().GetLocation();

	FCollisionObjectQueryParams ObjQueryParams = ObjQueryParams.AllObjects;

	FCollisionQueryParams CollisionQueryParams = FCollisionQueryParams::DefaultQueryParam;
	CollisionQueryParams.bReturnFaceIndex = true;
	CollisionQueryParams.AddIgnoredActor(this);

	FHitResult Hit;
	bool const bHaveBlockingHit = GetWorld()->LineTraceSingleByObjectType(Hit, StartLocation, EndLocation, ObjQueryParams, CollisionQueryParams);

	if (bHaveBlockingHit)
	{
		FString Message = FString::Printf(TEXT("Hit: FaceIndex=%d, actor=%s, component=%s, hit location=%s"), Hit.FaceIndex, *Hit.GetActor()->GetName(), *Hit.GetComponent()->GetName(), *Hit.Location.ToString());
		GEngine->AddOnScreenDebugMessage((uint64)-1, 1.0f, FColor::Red, Message);

#if ENABLE_DRAW_DEBUG
		//DrawDebugBox(GetWorld(), FVector(0, 0, 200.f), FVector(100.f, 100.f, 100.f), FColor::Green);
		// DrawDebugDirectionalArrow(GetWorld(), StartLocation, Hit.Location, 20.0f, FColor::Red);
		DrawDebugLine(GetWorld(), StartLocation, Hit.Location, FColor::Red);
		DrawDebugPoint(GetWorld(), Hit.Location, 20.0f, FColor::Green);
#endif
	}
	else
	{
#if ENABLE_DRAW_DEBUG
		DrawDebugDirectionalArrow(GetWorld(), StartLocation, EndLocation, 20.0f, FColor::Blue);
#endif
	}
}
