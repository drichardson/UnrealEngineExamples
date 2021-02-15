#include "MyActor.h"

#include "Engine/Engine.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/StreamableManager.h"
#include "Engine/Texture2D.h"
#include "EngineFontServices.h"
#include "Framework/Application/SlateApplication.h"
#include "Log.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

static FStreamableManager& GetMyStreamableManager()
{
	static FStreamableManager* M = nullptr;
	if (M == nullptr)
	{
		M = new FStreamableManager();
	}
	return *M;
}

AMyActor::AMyActor()
{
	static bool once = false;
	if (!once)
	{
		once = true;
		//		FEngineFontServices::Create();

		// TSharedRef<FSlateRenderer> SlateRenderer =
		// FModuleManager::Get().GetModuleChecked<ISlateRHIRendererModule>("SlateRHIRenderer").CreateSlateRHIRenderer();
		// FSlateApplication& CurrentSlateApp = FSlateApplication::Get();
		// CurrentSlateApp.InitializeRenderer(SlateRenderer);

#if 0
		{
			SCOPED_BOOT_TIMING("FEngineFontServices::Create");
			// Create the engine font services now that the Slate renderer is ready
			FEngineFontServices::Create();
		}
#endif
	}

	static ConstructorHelpers::FObjectFinder<UFont> FontFinder(
		TEXT("Font'/Game/Roboto-Regular_Font.Roboto-Regular_Font'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> TextureFinder(
		TEXT("Texture2D'/Game/Circle.Circle'"));

	Font = FontFinder.Object;
	Texture = TextureFinder.Object;

	UE_LOG(LogAssetLoading, Log, TEXT("CTOR: Font is %p, Texture is %p"), Font, Texture);

	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UObject* TmpObject = NewObject<UMyObj>();

	FontFace =
		LoadObject<UFontFace>(TmpObject, TEXT("FontFace'/Game/Roboto-Regular.Roboto-Regular'"));
	LastFontFace = FontFace;

	UObject* PreCastMat = StaticLoadObject(
		UMaterialInterface::StaticClass(), TmpObject, TEXT("Material'/Game/Folder1/Mat1.Mat1'"));
	Mat = Cast<UMaterialInterface>(PreCastMat);
	LastMat = Mat;

	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("BeginPlay: FontFace is %p, Mat is %p (pre-cast Mat %p), TmpObject is %p"),
		   Font,
		   Mat,
		   PreCastMat,
		   TmpObject);

	if (FontFace == nullptr)
	{
		Font = LoadObject<UFont>(this, TEXT("Font'/Game/Roboto-Regular_Font.Roboto-Regular_Font'"));
		UE_LOG(LogAssetLoading, Log, TEXT("Font was null, after LoadObject is now %p"), Font);
	}

	if (GetWorld()->IsPlayInEditor())
	{
		UE_LOG(LogAssetLoading,
			   Warning,
			   TEXT("Indirect property references (e.g. TSoftObjectPtr) cannot be properly "
					"demonstrated in PIE, since assets may have already been loaded by the editor. "
					"Run in standalone for a better test."));
	}

	//
	// TSoftObjectPtr - synchronous loading
	//
	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr pending? %d path=%s"),
		   MatSoftObjectPtr.IsPending(),
		   *MatSoftObjectPtr.ToString());

	if (MatSoftObjectPtr.IsPending())
	{
		UMaterialInterface* M = MatSoftObjectPtr.LoadSynchronous();
		UE_LOG(LogAssetLoading, Log, TEXT("LoadSynchronous returned %s"), *GetNameSafe(M));
	}

	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr pending? %d, name=%s"),
		   MatSoftObjectPtr.IsPending(),
		   *GetNameSafe(MatSoftObjectPtr.Get()));

	//
	// TSoftObjectPtr - synchronous loading with IStreamingManager.
	//
	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr pending? %d path=%s"),
		   MatSoftObjectPtr.IsPending(),
		   *MatSoftObjectPtr.ToString());

	if (MatSoftObjectPtr.IsPending())
	{
		UMaterialInterface* M = MatSoftObjectPtr.LoadSynchronous();
		UE_LOG(LogAssetLoading, Log, TEXT("LoadSynchronous returned %s"), *GetNameSafe(M));
	}

	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr pending? %d, name=%s"),
		   MatSoftObjectPtr.IsPending(),
		   *GetNameSafe(MatSoftObjectPtr.Get()));

	//
	// TSoftObjectPtr - asynchronous loading
	//
	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr_Async pending? %d path=%s"),
		   MatSoftObjectPtr_Async.IsPending(),
		   *MatSoftObjectPtr_Async.ToString());

	if (MatSoftObjectPtr_Async.IsPending())
	{
		TSharedPtr<FStreamableHandle>& H = MatSoftObjectPtr_Async_Handle;
		H = GetMyStreamableManager().RequestAsyncLoad(
			MatSoftObjectPtr_Async.ToSoftObjectPath(),
			FStreamableDelegate::CreateUObject(this, &AMyActor::OnAsyncLoadComplete));

		UE_LOG(LogAssetLoading,
			   Log,
			   TEXT("Async_Handle: DebugName=%s HasLoadCompleted=%d IsLoadingInProgress=%d"),
			   *H->GetDebugName(),
			   H->HasLoadCompleted(),
			   H->IsLoadingInProgress());
	}

	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("MatSoftObjectPtr_Async pending? %d, name=%s"),
		   MatSoftObjectPtr_Async.IsPending(),
		   *GetNameSafe(MatSoftObjectPtr_Async.Get()));
}

void AMyActor::OnAsyncLoadComplete()
{
	TSharedPtr<FStreamableHandle>& H = MatSoftObjectPtr_Async_Handle;
	UE_LOG(LogAssetLoading,
		   Log,
		   TEXT("OnAsyncLoadComplete: name=%s, HasLoadCompleted=%d"),
		   *GetNameSafe(MatSoftObjectPtr_Async.Get()),
		   H->HasLoadCompleted());
}

void AMyActor::Tick(float DeltaSeconds)
{
	if (FontFace != LastFontFace)
	{
		UE_LOG(LogAssetLoading, Log, TEXT("Tick: FontFace changed from %p to %p"), LastFontFace, FontFace);
		LastFontFace = FontFace;
	}

	if (Mat != LastMat)
	{
		UE_LOG(LogAssetLoading, Log, TEXT("Tick: Mat changed from %p to %p"), LastMat, Mat);
		LastMat = Mat;
	}

	GEngine->ForceGarbageCollection();
}

UMyObj::UMyObj()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyObj::UMyObj"));
}

UMyObj::~UMyObj()
{
	UE_LOG(LogAssetLoading, Log, TEXT("UMyObj::~UMyObj"));
}
