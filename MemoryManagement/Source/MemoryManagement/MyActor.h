#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "UObject/WeakInterfacePtr.h"

#include "MyActor.generated.h"

// Example actor that has UPROPERTY and non-UPROPERTY references to UObjects.
UCLASS()
class AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();
	~AMyActor() override;
	void Tick(float DeltaSeconds) override;
	void BeginPlay() override;
	void PostInitializeComponents() override;

private:
	//
	// Various ways to reference a Actor Component
	//
	UPROPERTY(Transient)
	UActorComponent* UPropertyDefaultSubobject;

	UPROPERTY(Transient)
	UActorComponent* UPropertyNewObject;

	UActorComponent* Naked;

	TWeakObjectPtr<UActorComponent> Weak;

	//
	// Custom GC Object
	//
	class MyGCObject* MyGCObj;

	//
	// Pointers to Interfaces
	//

	// Interface, with weak reference to underlying UObject.
	TWeakInterfacePtr<IMyInterface> WeakInterface;

	// Interface, with strong reference to underlying UObject.
	UPROPERTY(Transient)
	TScriptInterface<IMyInterface> ScriptInterfaceUProperty;

#if 0
	// Don't do this. If you don't mark as UPROPERTY, it does not provide a
	// strong reference to the item it points to, nor does it get nulled out if
	// the pointed at object is garbage collected.
	//
	// Use TWeakInterfacePtr instead in this situation.
	TScriptInterface<IMyInterface> ScriptInterfaceNonUProperty;

	// Don't do this either. Same problem as ScriptInterfaceNonUProperty.
	IMyInterface* NakedInterface;
#endif

	//
	// Arrays of UObjects
	//

	UPROPERTY(Transient)
	TArray<UObject*> UPropertyArray;

	TArray<UObject*> NonUPropertyArray;

	//
	// Arrays of Interfaces
	//

#if 0
	// Unreal Header Tool Error:
	// UPROPERTY pointers cannot be interfaces - did you mean TScriptInterface<TArray<IMyInterface*>?
	UPROPERTY(Transient)
	TArray<IMyInterface*> UPropertyInterfaceArray;
#endif

	UPROPERTY(Transient)
	TArray<TScriptInterface<IMyInterface>> UPropertyScriptInterfaceArray;

	TArray<TWeakInterfacePtr<IMyInterface>> WeakInterfaceArray;

	int TickCount = 0;
};
