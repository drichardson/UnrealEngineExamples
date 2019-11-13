# Blender UE4 Examples
Examples of using Blender with UE4.

Uses folder structure defined by [ArtPipeline](https://github.com/drichardson/UE4Examples/master/ArtPipeline).

To use efficiently, you may want to change the following Editor Preferences:

- Set *Editor Preferences > General > Miscellaneous > Data Source Folder* to the *inter* folder.
- Change *Editor Preferences > General > Loading & Saving > Directories to Monitor* as follows:
	1. Delete entry 0. We are never going to store art sources or export files in the Content directory, only files required to run the game/editor are there (per the ArtPipeline rules above).
	1. Add a new entry.
		1. Set the path to the *inter* folder.
		1. Set *Map Directory To* to */Game/Art*.


*Data Source Folder* allows us to more easily collaborate with teammates by storing a consistent relative path to each of the imported assets, so that in UE4 a right click > Reimport can be used without having to navigate to a source file.

*Directories to Monitor* automatically imports/reimports files from the *inter* directory into our */Game/Art* virtual folder (*game/Content/Art* on disk).

## See Also

- [Auto Reimport | UE4 Documentation](https://docs.unrealengine.com/en-US/Engine/Content/AutoReImport/index.html)
- [WTF Is? Auto Re-import in Unreal Engine 4 ( UE4 )](https://www.youtube.com/watch?v=-aK9P29eNTg)
