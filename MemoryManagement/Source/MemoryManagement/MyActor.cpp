#include "MyActor.h"

#include "Components/SceneComponent.h"
#include "EngineUtils.h"
#include "MMLog.h"
#include "MyComponent1.h"
#include "MyGCObject.h"

static FName DeleteMeTag = TEXT("DeleteMe");

AMyActor::AMyActor()
{
	UE_LOG(MMLog, Log, TEXT("AMyActor::AMyActor"));

	PrimaryActorTick.bCanEverTick = true;

	UPropertyDefaultSubobject = CreateDefaultSubobject<UMyComponent1>(TEXT("UPropertyDefaultSubobject"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("My Root"));
}

AMyActor::~AMyActor()
{
	delete MyGCObj;
}

static void CheckPointerInternal(UObject* Pointer, FString Name)
{
	if (Pointer == nullptr || !Pointer->IsValidLowLevel())
	{
		UE_LOG(MMLog, Error, TEXT("%s going away %p"), *Name, Pointer);
	}
}

#define CheckPointer(Pointer) CheckPointerInternal(Pointer, #Pointer)

void AMyActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UE_LOG(MMLog, Log, TEXT("AMyActor::Tick %f, %s"), DeltaSeconds, *GetName());

	CheckPointer(UPropertyDefaultSubobject);
	CheckPointer(UPropertyNewObject);
	CheckPointer(Naked);
	CheckPointer(Weak.Get());
}


void AMyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(MMLog, Log, TEXT("AMyActor::PostInitializeComponents: %s"), *GetName());

	if (ActorHasTag(DeleteMeTag))
	{
		UPropertyNewObject = NewObject<UMyComponent1>(this, TEXT("UPropertyNewObject"));
		UPropertyNewObject->RegisterComponent();

		Naked = NewObject<UMyComponent1>(this, TEXT("Naked"));
		Naked->RegisterComponent();

		Weak = NewObject<UMyComponent1>(this, TEXT("Weak"));
		Weak->RegisterComponent();
	}

	MyGCObj = new MyGCObject();
}


void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(MMLog, Log, TEXT("AMyActor::BeginPlay: %s"), *GetName());

	AMyActor* ActorToCopy = nullptr;
	for (TActorIterator<AMyActor> It(GetWorld()); It; ++It)
	{
		if (It->ActorHasTag(DeleteMeTag))
		{
			ActorToCopy = *It;
		}
	}


	if (ActorToCopy)
	{
		UE_LOG(MMLog, Log, TEXT("AMyActor::BeginPlay Copying pointers from %s to %s"), *ActorToCopy->GetName(), *GetName());
		UPropertyDefaultSubobject = ActorToCopy->UPropertyDefaultSubobject;
		UPropertyNewObject = ActorToCopy->UPropertyNewObject;
		Naked = ActorToCopy->Naked;
		Weak = ActorToCopy->Weak;
	}


}

