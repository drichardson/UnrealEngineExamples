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

// config = Game, but defaultconfig not specified. Changes made in Project
// Settings will be saved to Saved/Config/Windows/Game.ini.  If you press the
// "Set Default" button in Project Settings, Config/DefaultGame.ini will be
// updated.
UCLASS(config = Game)
class UMyGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// config = Game and defaultconfig. Changes made in Project Settings will be
// saved to Config/DefaultGame.ini.
UCLASS(config = Game, defaultconfig)
class UMyGameDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// config = Engine but no defaultconfig. Changes made in Project Settings will
// be saved to Saved/Config/Windows/Engine.ini. If you press "Set Default"
// button in Project Settings, it will update COnfig/DefaultEngine.ini.
UCLASS(config = Engine)
class UMyEngineSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// config = Engine and defaultconfig. Changes made in Project Settings editor
// will be saved to Config/DefaultEngine.ini.
UCLASS(config = Engine, defaultconfig)
class UMyEngineDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// config = MyCustom (not one of the default values) and no defaultconfig.
// Changes made in Project Settings editor will be saved to
// Saved/Config/Windows/MyCustom.ini. If "Set Default" button is pressed,
// changes made to Config/DefaultMyCustom.ini.
UCLASS(config = MyCustom)
class UMyCustomSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// config = MyCustom and defaultconfig. Changes made in Project Settings saved
// to Config/DefaultMyCustom.iini.
UCLASS(config = MyCustom, defaultconfig)
class UMyCustomDefaultConfigSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};

// A bug testing a defaultconfig settings with a custom config.
UCLASS(config = BugTest, defaultconfig)
class UBugTestgSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere)
	int32 SomeInt = 33;

	UPROPERTY(Config, EditAnywhere)
	float MyFloat = 3.14;

	UPROPERTY(Config, EditAnywhere)
	FSoftObjectPath MyPath;
};
