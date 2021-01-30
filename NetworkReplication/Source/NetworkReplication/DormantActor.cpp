#include "DormantActor.h"

#include "Net/UnrealNetwork.h"

DEFINE_LOG_CATEGORY_STATIC(LogDormantActor, Log, All)

ADormantActor::ADormantActor()
{
	bReplicates = true;

	NetDormancy = DORM_DormantAll;
}

void ADormantActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADormantActor, TimerCounter);
}

void ADormantActor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADormantActor::TimerFired, 0.5f, true);
	}
}

void ADormantActor::TimerFired()
{
	check(HasAuthority());

	TimerCounter++;

	constexpr int32 Threshold = 30;

	if (TimerCounter < Threshold)
	{
		// While dormant, periodically force replication without changing dormancy.
		check(NetDormancy == DORM_DormantAll);

		if (TimerCounter % 7 == 0 && TimerCounter > 0)
		{
			FlushNetDormancy();
		}
	}
	else if (TimerCounter == Threshold)
	{
		// Change to awake, and observe the client gets updates every time TimerCounter is updated.
		SetNetDormancy(DORM_Awake);
	}
}

void ADormantActor::OnRep_TimerCounter()
{
	UE_LOG(LogDormantActor,
		   Log,
		   TEXT("OnRep_TimerCounter (client): TimerCounter=%d, actor=%s"),
		   TimerCounter,
		   *GetNameSafe(this));
}
