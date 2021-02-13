# Asset Loading
Test a few different ways of loading assets from C++, including:

- [FObjectFinder](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/ConstructorHelpers/FObjectFinder/index.html)
- [LoadObject](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/LoadObject/index.html)
- [StaticLoadObject](https://api.unrealengine.com/INT/API/Runtime/CoreUObject/UObject/StaticLoadObject/index.html)

Observe that font assets are not loaded from FObjectFinder when the `-server` flag is passed to UE4Editor.exe.


# Observations

- In PIE, TSoftObjectPtr.IsPending() returns 0, indicator the asset is already loaded, even before you have loaded it. That's because it may actually be loaded by the editor. To test a more game like scenario, run in Standalone mode.


# See also

- [Referencing Assets](https://docs.unrealengine.com/en-us/Programming/Assets/ReferencingAssets)
- [Asynchronous Asset Loading](https://docs.unrealengine.com/en-US/ProgrammingAndScripting/ProgrammingWithCPP/Assets/AsyncLoading/index.html)
