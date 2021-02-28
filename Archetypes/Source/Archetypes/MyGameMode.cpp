#include "MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.TickInterval = 1;
}

void AMyGameMode::Tick(float DeltaSeconds)
{
	UE_LOG(LogGameMode, Log, TEXT("Tick: %d"), DeltaSeconds);
}
