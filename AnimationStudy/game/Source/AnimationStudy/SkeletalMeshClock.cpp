#include "SkeletalMeshClock.h"

#include "Components/SkeletalMeshComponent.h"
#include "Misc/DateTime.h"

DECLARE_LOG_CATEGORY_EXTERN(LogClock, Log, All);
DEFINE_LOG_CATEGORY(LogClock);

ASkeletalMeshClock::ASkeletalMeshClock()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));

	RootComponent = Mesh;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASkeletalMeshClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FDateTime Time = FDateTime::Now();

	UE_LOG(LogClock,
		   VeryVerbose,
		   TEXT("Hour: %d, Minutes: %d, Seconds: %d, Milliseconds %d"),
		   Time.GetHour12(),
		   Time.GetMinute(),
		   Time.GetSecond(),
		   Time.GetMillisecond());

	float const DegreesPerSecond = 360.0f / 60.0f;
	float const DegreesPerMinute = 360.0f / 60.0f;
	float const DegreesPerHour = 360.0f / 12.0f;

	// HourHand->SetRelativeRotation(FRotator(0, Time.GetHour() * DegreesPerHour, 0));
	// MinuteHand->SetRelativeRotation(FRotator(0, Time.GetMinute() * DegreesPerMinute, 0));
	// SecondHand->SetRelativeRotation(FRotator(0, Time.GetSecond() * DegreesPerSecond, 0));
}
