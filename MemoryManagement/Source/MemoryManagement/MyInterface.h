#pragma once

#include "CoreMinimal.h"

#include "MyInterface.generated.h"

UINTERFACE()
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

class IMyInterface
{
	GENERATED_BODY()

public:
	virtual void Foo() = 0;
};
