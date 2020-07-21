#include "MyGameInstance.h"

#include "AudioDevice.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogGameInstance, Log, All)

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogGameInstance, Verbose, TEXT("MyGameInstance::Init"));
}

UAudioComponent* UMyGameInstance::InitializeWorldMusicComponentOnce(UObject* WorldContextObject,
																	USoundBase* Sound)
{
	// Technique for keeping the audio component around accross level loads came from this UE
	// AnwerHub question:
	// https://answers.unrealengine.com/questions/517785/cannot-get-sound-to-play-through-level-loads.html

	if (Sound == nullptr)
	{
		UE_LOG(
			LogGameInstance, Error, TEXT("Cannot initialize WorldMusicComponent, sound is null"));
		return nullptr;
	}

	if (WorldMusicComponent != nullptr)
	{
		UE_LOG(LogGameInstance, Verbose, TEXT("WorldMusicComponent already set."));
		return WorldMusicComponent;
	}

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,
													   EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr)
	{
		UE_LOG(LogGameInstance,
			   Error,
			   TEXT("World is null. Make sure WorldContextObjec (%p) is valid."),
			   WorldContextObject);
		return nullptr;
	}

	FAudioDevice* AudioDevice = World->GetAudioDeviceRaw();

	if (AudioDevice == nullptr)
	{
		UE_LOG(LogGameInstance, Error, TEXT("AudioDevice is null"));
		return nullptr;
	}

	UE_LOG(LogGameInstance,
		   Verbose,
		   TEXT("Initializing WorldMusicComponent with sound %s and audio device %u"),
		   *Sound->GetName(),
		   AudioDevice->DeviceID);

	FAudioDevice::FCreateComponentParams P(AudioDevice);
	P.bPlay = false;
	P.bStopWhenOwnerDestroyed = false;
	WorldMusicComponent = FAudioDevice::CreateComponent(Sound, P);

	if (WorldMusicComponent == nullptr)
	{
		UE_LOG(LogGameInstance, Error, TEXT("Failed to create WorldMusicComponent"));
		WorldMusicComponent->bAllowSpatialization = false;
		WorldMusicComponent->bIsUISound = true;
		WorldMusicComponent->bIgnoreForFlushing = true;
		WorldMusicComponent->Play();
		return nullptr;
	}

	UE_LOG(LogGameInstance,
		   Verbose,
		   TEXT("Created WorldMusicComponent: %s"),
		   *WorldMusicComponent->GetName());
	return WorldMusicComponent;
}
