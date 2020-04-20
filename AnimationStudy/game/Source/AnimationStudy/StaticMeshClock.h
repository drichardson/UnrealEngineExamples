#include "CoreMinimal.h"

#include "StaticMeshClock.generated.h"

UCLASS()
class AStaticMeshClock : public AActor
{
	GENERATED_BODY()

public:
	AStaticMeshClock();

	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Face;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* HourHand;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MinuteHand;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SecondHand;
};
