#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "MyCharacter.generated.h"

UCLASS()
class AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	void MoveForward(float Val);
	void MoveRight(float Val);
	void MoveUp(float Val);
	void Rotate(float Val);
};
