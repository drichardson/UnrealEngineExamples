#include "CoreMinimal.h"

#include "SkeletalMeshClock.generated.h"

UCLASS()
class ASkeletalMeshClock : public AActor
{
	GENERATED_BODY()

public:
	ASkeletalMeshClock();

	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* Mesh;
};
