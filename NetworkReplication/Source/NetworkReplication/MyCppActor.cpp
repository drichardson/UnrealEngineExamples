#include "MyCppActor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/ActorChannel.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

DECLARE_LOG_CATEGORY_EXTERN(NetTest, Log, All);
DEFINE_LOG_CATEGORY(NetTest);



UMyObject::UMyObject()
{
}

void UMyObject::GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMyObject, IntValue);
}

UMyObject2::UMyObject2()
{
}

void UMyObject2::GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMyObject2, IntValue);
}


AMyOtherActor::AMyOtherActor()
{
	bReplicates = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	UStaticMeshComponent* SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SM->SetupAttachment(RootComponent);

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(this, TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Ball_01.SM_Ball_01'"));
	check(Mesh);
	SM->SetStaticMesh(Mesh);
}

void AMyOtherActor::GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyOtherActor, IntValue);
}

void AMyOtherActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(NetTest, Log, TEXT("BeginPlay %p"), this);
}

AMyCppActor::AMyCppActor()
{
	bReplicates = true;

	LastIntValue = IntValue;
	MyObject = CreateDefaultSubobject<UMyObject>(TEXT("MyObject"));
	MyObject->IntValue = 3;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	UStaticMeshComponent *SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Comp"));
	SM->SetupAttachment(RootComponent);
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(this, TEXT("StaticMesh'/Engine/VREditor/BasicMeshes/SM_Pyramid_01.SM_Pyramid_01'"));
	check(Mesh);
	SM->SetStaticMesh(Mesh);
}

void AMyCppActor::GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyCppActor, IntValue);
	DOREPLIFETIME(AMyCppActor, FloatValue);
	DOREPLIFETIME(AMyCppActor, VectorValue);
	DOREPLIFETIME(AMyCppActor, BoolValue);
	DOREPLIFETIME(AMyCppActor, FNameValue);
	DOREPLIFETIME(AMyCppActor, FStringValue);
	DOREPLIFETIME(AMyCppActor, FTextValue);
	DOREPLIFETIME(AMyCppActor, MyStructValue);
	DOREPLIFETIME(AMyCppActor, MyObject);
	DOREPLIFETIME(AMyCppActor, MyObject2);
	DOREPLIFETIME(AMyCppActor, OtherActor);
}

void AMyCppActor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyCppActor::ServerChangeValues, 2.0, true);
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyCppActor::ClientCheckForChangedValues, 1.0, true);
	}
}

bool AMyCppActor::ReplicateSubobjects(UActorChannel* Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags)
{
	bool bWroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);

	if (MyObject2)
	{
		bWroteSomething |= Channel->ReplicateSubobject(MyObject2, *Bunch, *RepFlags);
	}

	return bWroteSomething;

}

void AMyCppActor::ServerChangeValues()
{
	check(HasAuthority());

	static FName NameOne = FName("FName1");
	static FName NameTwo = FName("FName2");

	IntValue++;
	FloatValue++;
	VectorValue += FVector(1, 1, 1);
	BoolValue = !BoolValue;
	FNameValue = FNameValue == NameOne ? NameTwo : NameOne;
	FStringValue = FString::Printf(TEXT("String%d"), IntValue);
	FTextValue = FText::FromString(FString::Printf(TEXT("Text%d"), IntValue));
	MyStructValue = { MyStructValue.IntValue * 2, MyStructValue.FloatValue * 2.5f };
	MyObject->IntValue += 7;

	if (MyObject2)
	{
		MyObject2->IntValue += 10;
	}
	else
	{
		MyObject2 = NewObject<UMyObject2>(this);
		MyObject2->IntValue = 431;
	}

	FActorSpawnParameters p;
	p.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FVector Location = FMath::RandPointInBox(FBox(FVector(-200, -200, 0), FVector(200, 200, 400)));
	FRotator Rotation = FRotator(0, FMath::RandRange(-45, 45), 0);
	AMyOtherActor* o = GetWorld()->SpawnActor<AMyOtherActor>(Location, Rotation, p);
	UE_LOG(NetTest, Log, TEXT("OtherActor Spawned: %p"), o);
	o->IntValue = FMath::RandRange(1, 100) * 10;
	o->SetLifeSpan(FMath::RandRange(4.f, 8.f));

	if (IsValid(OtherActor))
	{
		OtherActor->IntValue++;
		UE_LOG(NetTest, Log, TEXT("Server: Incrementing OtherActor->IntValue to %d"), OtherActor->IntValue);
	}
	else
	{
		UE_LOG(NetTest, Log, TEXT("Server: Setting OtherActor reference"));
		OtherActor = o;
	}

	UE_LOG(NetTest, Log, TEXT("Server: Change Values. IntValue=%d"), IntValue);
}

void AMyCppActor::ClientCheckForChangedValues()
{
	if (LastIntValue != IntValue)
	{
		LastIntValue = IntValue;
		UE_LOG(NetTest, Log, TEXT("Client: Changed IntValue=%d FloatValue=%.2f VectorValue=(%.2f,%.2f,%.2f) BoolValue=%d FName=%s FString=%s FText=%s MyStruct={%d,%.2f} MyObject=%p={%d} MyObject2=%p={%d} OtherActor=%p={%d}"),
			IntValue, FloatValue,
			VectorValue.X, VectorValue.Y, VectorValue.Z,
			BoolValue,
			*FNameValue.ToString(), *FStringValue, *FTextValue.ToString(),
			MyStructValue.IntValue, MyStructValue.FloatValue,
			MyObject, MyObject ? MyObject->IntValue : -1,
			MyObject2, MyObject2 ? MyObject2->IntValue : -1,
			OtherActor, OtherActor ? OtherActor->IntValue : -1
		);
	}
	else
	{
		UE_LOG(NetTest, Log, TEXT("Client: No change."));
	}
}
