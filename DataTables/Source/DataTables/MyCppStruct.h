// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "MyCppStruct.generated.h"

USTRUCT(BlueprintType)
struct DATATABLES_API FMyCppStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MyInt = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MyFloat = 3.14f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UParticleSystem *ParticleSystem;
};

USTRUCT(BlueprintType)
struct DATATABLES_API FMyCppStructTableData : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MyInt = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MyFloat = 3.14f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UParticleSystem *ParticleSystem;
};


USTRUCT(BlueprintType)
struct DATATABLES_API FMyStructWithHandleReferences
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FDataTableRowHandle RowHandle;
};



USTRUCT(BlueprintType)
struct DATATABLES_API FMyCppStructTableDataEmbedded : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditInline)
	FMyCppStruct MyStructEmbedded;
};
