#include "MyActor.h"

#include "Components/SceneComponent.h"
#include "EngineUtils.h"
#include "MMLog.h"
#include "MyComponent1.h"
#include "MyGCObject.h"
#include "MyObject.h"

static FName DeleteMeTag = TEXT("DeleteMe");

AMyActor::AMyActor()
{
	UE_LOG(MMLog, Log, TEXT("AMyActor::AMyActor"));

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 2.0f;

	UPropertyDefaultSubobject = CreateDefaultSubobject<UMyComponent1>(TEXT("UPropertyDefaultSubobject"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("My Root"));
}

AMyActor::~AMyActor()
{
	delete MyGCObj;
}

void AMyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(MMLog, Log, TEXT("AMyActor::PostInitializeComponents: %s"), *GetName());

	if (ActorHasTag(DeleteMeTag))
	{
		UPropertyNewObject = NewObject<UMyComponent1>(this, TEXT("UPropertyNewObject"));
		UPropertyNewObject->RegisterComponent();

		Naked = NewObject<UMyComponent1>(this, TEXT("NakedThisOuter"));
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

	for (int i = 0; i < 5; i++)
	{
		UObject* Obj = NewObject<UMyObject>(this, TEXT("1"));
		UPropertyArrayThisOuter.Add(Obj);
	}

	for (int i = 0; i < 5; i++)
	{
		UObject* Obj = NewObject<UMyObject>(GetTransientPackage(), TEXT("2"));
		UPropertyArrayNoOuter.Add(Obj);
	}

	for (int i = 0; i < 5; i++)
	{
		UObject* Obj = NewObject<UMyObject>(this, TEXT("3"));
		NonUPropertyArrayThisOuter.Add(Obj);
	}

	for (int i = 0; i < 5; i++)
	{
		UObject* Obj = NewObject<UMyObject>(GetTransientPackage(), TEXT("4"));
		NonUPropertyArrayNoOuter.Add(Obj);
	}
}

static void CheckPointerInternal(UObject* Pointer, FString Name)
{
	if (Pointer == nullptr || !Pointer->IsValidLowLevel())
	{
		UE_LOG(MMLog, Error, TEXT("%s going away %p"), *Name, Pointer);
	}
}

#define CheckPointer(Pointer) CheckPointerInternal(Pointer, #Pointer)

static void CheckArrayInternal(TArray<UObject*> const& Array, FString Name)
{
	UE_LOG(MMLog, Log, TEXT("Array %s has %d Items."), *Name, Array.Num());

	int Index = 0;
	int InvalidObjects = 0;
	for (UObject const* Obj : Array)
	{
		if (Obj == nullptr || !Obj->IsValidLowLevel())
		{
			UE_LOG(MMLog,
				   Error,
				   TEXT("Array %s object at index %d is not valid low level. Pointer=%p"),
				   *Name,
				   Index,
				   Obj);
			InvalidObjects++;
		}
		Index++;
	}

	UE_LOG(MMLog,
		   Log,
		   TEXT("Array %s has %d invalid objects out of %d total objects"),
		   *Name,
		   InvalidObjects,
		   Array.Num());
}

#define CheckArray(Array) CheckArrayInternal(Array, #Array)

void AMyActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UE_LOG(MMLog, Log, TEXT("AMyActor::Tick %f, %s"), DeltaSeconds, *GetName());

	CheckPointer(UPropertyDefaultSubobject);
	CheckPointer(UPropertyNewObject);
	CheckPointer(Naked);
	CheckPointer(Weak.Get());
	CheckArray(UPropertyArrayThisOuter);
	CheckArray(UPropertyArrayNoOuter);
	CheckArray(NonUPropertyArrayThisOuter);
	CheckArray(NonUPropertyArrayNoOuter);

	UE_LOG(MMLog, Log, TEXT("Requesting force GC at end of current frame"));
	GEngine->ForceGarbageCollection(true);
}
