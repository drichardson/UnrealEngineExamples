#pragma once

#include "CoreMinimal.h"

#include "TextAsset.generated.h"

UCLASS()
class ADDINGASSETTYPES_API UTextAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "TextAsset")
	FText Text;
};

