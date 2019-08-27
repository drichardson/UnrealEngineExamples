#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyCppActor.generated.h"

USTRUCT()
struct FMyStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int IntValue;

	UPROPERTY()
	float FloatValue;
};

UCLASS()
class UMyObject : public UObject
{
	GENERATED_BODY()

private:

	void GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const override;

public:

	UPROPERTY(Transient, Replicated)
	int IntValue = 1;

	UMyObject();
};

UCLASS()
class UMyObject2 : public UObject
{
	GENERATED_BODY()

private:

	void GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const override;
	bool IsSupportedForNetworking() const override { return true;  }

public:

	UPROPERTY(Transient, Replicated)
	int IntValue = 1;

	UMyObject2();
};

UCLASS()
class AMyOtherActor : public AActor
{
	GENERATED_BODY()

private:

	void GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const override;
	void BeginPlay() override;

public:

	UPROPERTY(Replicated, Transient)
	int IntValue;

	AMyOtherActor();
};

UCLASS()
class AMyCppActor : public AActor
{
	GENERATED_BODY()

private:

	void GetLifetimeReplicatedProps(TArray < FLifetimeProperty > & OutLifetimeProps) const override;
	void BeginPlay() override;

	// IntValue is used to determine when properties update.
	int LastIntValue;

	bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags) override;

	FTimerHandle TimerHandle;
	void ServerChangeValues();
	void ClientCheckForChangedValues();

protected:

	UPROPERTY(Transient, Replicated)
	int IntValue = 1;

	UPROPERTY(Transient, Replicated)
	float FloatValue = 3.14f;

	UPROPERTY(Transient, Replicated)
	FVector VectorValue = FVector(1.1,2.2,3.3);

	UPROPERTY(Transient, Replicated)
	bool BoolValue = true;

	UPROPERTY(Transient, Replicated)
	FName FNameValue = FName("MyFName");

	UPROPERTY(Transient, Replicated)
	FString FStringValue = FString("MyFString");

	UPROPERTY(Transient, Replicated)
	FText FTextValue = FText::FromString(TEXT("My Text"));

	UPROPERTY(Transient, Replicated)
	FMyStruct MyStructValue = { 10, 20.2 };

	UPROPERTY(Transient, Replicated)
	UMyObject* MyObject;

	UPROPERTY(Transient, Replicated)
	UMyObject2* MyObject2;

	UPROPERTY(Transient, Replicated)
	AMyOtherActor* OtherActor;

	AMyCppActor();
};
