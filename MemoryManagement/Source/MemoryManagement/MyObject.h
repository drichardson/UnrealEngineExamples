#pragma once

#include "CoreMinimal.h"

#include "MyInterface.h"

#include "MyObject.generated.h"

UCLASS()
class UMyObject : public UObject, public IMyInterface
{
	GENERATED_BODY()

public:

	UMyObject();
	~UMyObject();

	void Foo() override;
};
