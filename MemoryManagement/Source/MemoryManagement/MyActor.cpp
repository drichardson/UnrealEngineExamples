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

	WeakInterface = TWeakInterfacePtr<IMyInterface>(NewObject<UMyObject>(this));
	ScriptInterfaceUProperty = NewObject<UMyObject>(this);
	// NakedInterface = NewObject<UMyObject>(this); // Crashes, see header for details.
	// ScriptInterfaceNonUProperty = NewObject<UMyObject>(this); // Crashes, see header for details.

	constexpr int Num = 2;
	static int Counter = 1;

	for (int i = 0; i < Num; i++)
	{
		UObject* Obj = NewObject<UMyObject>(
			this, *FString::Format(TEXT("UPropertyArrayItem{0}"), {Counter++}));
		UPropertyArray.Add(Obj);
	}

	for (int i = 0; i < Num; i++)
	{
		UObject* Obj = NewObject<UMyObject>(
			this, *FString::Format(TEXT("NonUPropertyArrayItem{0}"), {Counter++}));
		NonUPropertyArray.Add(Obj);
	}

	for (int i = 0; i < Num; i++)
	{
		UObject* Obj = NewObject<UMyObject>(
			this, *FString::Format(TEXT("UPropertyScriptInterfaceArrayItem{0}"), {Counter++}));
		UPropertyScriptInterfaceArray.Add(Obj);
		WeakInterfaceArray.Add(Obj); // Add some objects to the weak array that are strongly
									 // referenced by the UPropertyScriptInterfaceArray.
	}

	for (int i = 0; i < Num; i++)
	{
		UObject* Obj = NewObject<UMyObject>(
			this, *FString::Format(TEXT("WeakInterfaceArrayItem{0}"), {Counter++}));
		WeakInterfaceArray.Add(Obj);
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

template <typename TInterface>
static void CheckInterfaceInternal(TInterface I, FString Name)
{
	if (I)
	{
		UE_LOG(MMLog, Log, TEXT("Calling I->Foo() on %s"), *Name);
		I->Foo();
	}
	else
	{
		UE_LOG(MMLog, Error, TEXT("%s is null."), *Name);
	}
}

#define CheckInterface(I) CheckInterfaceInternal(I, #I)

static void CheckScriptInterfaceArrayInternal(TArray<TScriptInterface<IMyInterface>> const& Array,
											  FString Name)
{
	UE_LOG(MMLog, Log, TEXT("Script Interface Array %s has %d Items."), *Name, Array.Num());

	int Index = 0;
	int InvalidObjects = 0;
	for (TScriptInterface<IMyInterface> const& I : Array)
	{
		if (I)
		{
			I->Foo();
		}
		else
		{
			UE_LOG(MMLog,
				   Error,
				   TEXT("ScriptInterface Array %s object at index %d is null."),
				   *Name,
				   Index);
			InvalidObjects++;
		}
		Index++;
	}

	UE_LOG(MMLog,
		   Log,
		   TEXT("ScriptInterface Array %s has %d null interfaces out of %d total interface"),
		   *Name,
		   InvalidObjects,
		   Array.Num());
}

#define CheckScriptInterfaceArray(Array) CheckScriptInterfaceArrayInternal(Array, #Array)

static void CheckWeakInterfaceArrayInternal(TArray<TWeakInterfacePtr<IMyInterface>> const& Array,
											FString Name)
{
	UE_LOG(MMLog, Log, TEXT("Weak Interface Array %s has %d Items."), *Name, Array.Num());

	int Index = 0;
	int InvalidObjects = 0;
	for (TWeakInterfacePtr<IMyInterface> const& I : Array)
	{
		if (I.IsValid())
		{
			I->Foo();
		}
		else
		{
			UE_LOG(MMLog,
				   Error,
				   TEXT("Weak Interface Array %s object at index %d is null."),
				   *Name,
				   Index);
			InvalidObjects++;
		}
		Index++;
	}

	UE_LOG(MMLog,
		   Log,
		   TEXT("Weak Interface Array %s has %d null interfaces out of %d total interface"),
		   *Name,
		   InvalidObjects,
		   Array.Num());
}

#define CheckWeakInterfaceArray(Array) CheckWeakInterfaceArrayInternal(Array, #Array)

void AMyActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TickCount++;

	UE_LOG(MMLog,
		   Log,
		   TEXT("#### AMyActor::Tick TickCount=%d DeltaSeconds=%f Name=%s ####"),
		   TickCount,
		   DeltaSeconds,
		   *GetName());

	CheckPointer(UPropertyDefaultSubobject);
	CheckPointer(UPropertyNewObject);
	CheckPointer(Naked);
	CheckPointer(Weak.Get());

	CheckInterface(ScriptInterfaceUProperty);
	// CheckInterface(ScriptInterfaceNonUProperty); // Crashes, see header for details.
	CheckInterface(WeakInterface.ToScriptInterface());
	// CheckInterface(NakedInterface); // Crashes, see header for details.

	CheckArray(UPropertyArray);
	CheckArray(NonUPropertyArray);
	CheckScriptInterfaceArray(UPropertyScriptInterfaceArray);
	CheckWeakInterfaceArray(WeakInterfaceArray);

	if (TickCount == 2)
	{
		// Remove one of the items in UPropertyScriptInterfaceArray that is referenced by
		// WeakInterfaceArray to observe it getting nulled out.
		UPropertyScriptInterfaceArray.Remove(WeakInterfaceArray[0].ToScriptInterface());
	}

	UE_LOG(MMLog, Log, TEXT("Requesting force GC at end of current frame"));
	GEngine->ForceGarbageCollection(true);
}
