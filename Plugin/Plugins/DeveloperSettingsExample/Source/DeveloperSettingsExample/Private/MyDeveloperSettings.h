#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"

#include "MyDeveloperSettings.generated.h"

//
// Test UDeveloperSettings with different config options.
//
// UDeveloperSettings sub-classes show up automatically in the Project Settings
// window.
//
// defaultconfig means that the configuration file will only be saved to Config/DefaultXYZ.ini.
// Without defaultconfig, changes will be saved in Saved/Config/Windows/XYZ.ini.
//

UCLASS(config = Game)
class UMyGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};

UCLASS(config = Game, defaultconfig)
class UMyGameDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};

UCLASS(config = Engine)
class UMyEngineSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};

UCLASS(config = Engine, defaultconfig)
class UMyEngineDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};

UCLASS(config = MyCustom)
class UMyCustomSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};

UCLASS(config = MyCustom, defaultconfig)
class UMyCustomDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;
};
