# Asset Loading
Test a few different ways of loading assets from C++, including:

- [FObjectFinder](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/ConstructorHelpers/FObjectFinder/index.html)
- [LoadObject](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/LoadObject/index.html)
- [StaticLoadObject](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/StaticLoadObject/index.html)

Observe that font assets are not loaded from FObjectFinder when the `-server` flag is passed to UE4Editor.exe.

See [Referencing Assets](https://docs.unrealengine.com/en-us/Programming/Assets/ReferencingAssets) for more info.
