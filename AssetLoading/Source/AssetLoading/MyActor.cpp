#include "MyActor.h"

#include "Engine/Engine.h"
#include "Engine/Font.h"
#include "Engine/FontFace.h"
#include "Engine/Texture2D.h"
#include "EngineFontServices.h"
#include "Log.h"
#include "Materials/MaterialInterface.h"
#include "SlateApplication.h"
#include "UObject/ConstructorHelpers.h"

AMyActor::AMyActor()
{
	static bool once = false;
	if (!once)
	{
		once = true;
//		FEngineFontServices::Create();

		//TSharedRef<FSlateRenderer> SlateRenderer = FModuleManager::Get().GetModuleChecked<ISlateRHIRendererModule>("SlateRHIRenderer").CreateSlateRHIRenderer();
		//FSlateApplication& CurrentSlateApp = FSlateApplication::Get();
		//CurrentSlateApp.InitializeRenderer(SlateRenderer);

#if 0
		{
			SCOPED_BOOT_TIMING("FEngineFontServices::Create");
			// Create the engine font services now that the Slate renderer is ready
			FEngineFontServices::Create();
		}
#endif
	}

	static ConstructorHelpers::FObjectFinder<UFont> FontFinder(TEXT("Font'/Game/Roboto-Regular_Font.Roboto-Regular_Font'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> TextureFinder(TEXT("Texture2D'/Game/Circle.Circle'"));

	Font = FontFinder.Object;
	Texture = TextureFinder.Object;

	UE_LOG(MyLog, Log, TEXT("CTOR: Font is %p, Texture is %p"), Font, Texture);

	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UObject* TmpObject = NewObject<UMyObj>();

	FontFace = LoadObject<UFontFace>(TmpObject, TEXT("FontFace'/Game/Roboto-Regular.Roboto-Regular'"));
	LastFontFace = FontFace;

	UObject* PreCastMat = StaticLoadObject(UMaterialInterface::StaticClass(), TmpObject, TEXT("Material'/Game/Folder1/Mat1.Mat1'"));
	Mat = Cast<UMaterialInterface>(PreCastMat);
	LastMat = Mat;

	UE_LOG(MyLog, Log, TEXT("BeginPlay: FontFace is %p, Mat is %p (pre-cast Mat %p), TmpObject is %p"), Font, Mat, PreCastMat, TmpObject);

	if (FontFace == nullptr)
	{
		Font = LoadObject<UFont>(this, TEXT("Font'/Game/Roboto-Regular_Font.Roboto-Regular_Font'"));
		UE_LOG(MyLog, Log, TEXT("Font was null, after LoadObject is now %p"), Font);
	}
}

void AMyActor::Tick(float DeltaSeconds)
{
	if (FontFace != LastFontFace)
	{
		UE_LOG(MyLog, Log, TEXT("Tick: FontFace changed from %p to %p"), LastFontFace, FontFace);
		LastFontFace = FontFace;
	}

	if (Mat != LastMat)
	{
		UE_LOG(MyLog, Log, TEXT("Tick: Mat changed from %p to %p"), LastMat, Mat);
		LastMat = Mat;
	}

	GEngine->ForceGarbageCollection();
}

UMyObj::UMyObj()
{
	UE_LOG(MyLog, Log, TEXT("UMyObj::UMyObj"));
}

UMyObj::~UMyObj()
{
	UE_LOG(MyLog, Log, TEXT("UMyObj::~UMyObj"));
}
