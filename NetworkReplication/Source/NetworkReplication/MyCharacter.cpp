#include "MyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AMyCharacter::AMyCharacter()
{
	UCharacterMovementComponent* M = GetCharacterMovement();
	M->DefaultLandMovementMode = MOVE_Flying;
	M->BrakingDecelerationFlying = 600.f;
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* IC)
{
	IC->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	IC->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	IC->BindAxis("MoveUp", this, &AMyCharacter::MoveUp);
	IC->BindAxis("Rotate", this, &AMyCharacter::Rotate);
}

void AMyCharacter::MoveForward(float Val)
{
	FRotator const Rot = Controller ? Controller->GetControlRotation() : FRotator::ZeroRotator;
	AddMovementInput(FRotationMatrix(Rot).GetScaledAxis(EAxis::X), Val);
}

void AMyCharacter::MoveRight(float Val)
{
	FRotator const Rot = Controller ? Controller->GetControlRotation() : FRotator::ZeroRotator;
	AddMovementInput(FRotationMatrix(Rot).GetScaledAxis(EAxis::Y), Val);
}

void AMyCharacter::MoveUp(float Val)
{
	AddMovementInput(FVector::UpVector, Val);
}

void AMyCharacter::Rotate(float Val)
{
	float const Yaw = Val * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(Yaw);
}
