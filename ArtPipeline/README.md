# Blender Pipeline

Testing out folder structure described by Mike Erwin in
[Blender + Unreal Asset Pipeline Foundations](https://conference.blender.org/2019/presentations/563/).

There are 3 top level repository folders:

- Art
- Inter
- Game

*Art* contains all original art sources (Blender, Maya, Houdini, Photoshop, etc).

*Inter* contains all exported art files that can be imported by the game engine (FBX, glTF, OBJ, etc).

*Game* contains everything you need to run the game. In UE4 the imported assets will be .uasset files.


## Workflow

### Artist
An artist checks out *Art* and *Inter* from source control. Original files are stored in *Art*.
When the artist is ready, they export their files to *Inter* as an FBX, glTF, OBJ, etc and submit
them to source control.

### Level Designer
A level designer checks out *Inter* and *Game*. When they are ready to use an asset an artist has
added to *Inter*, they import the asset into UE4 and it becomes a .uasset. This .uasset is also submitted
to source control.

If an artist updates one of the files in *Inter*, the level designer can right click on the corresponding
.uasset in the UE4 Content Browser and select *Reimport*. They do not need to navigate to the folder again
since UE4 stores relative paths to the imported assets.

**NOTE:** In order for *Reimport* to work across multiple checkouts (by different users or by the same user in different locations), the *Data Source Folder* Editor Preference must be set to the *Inter* folder by all users. You can find this preference in *Editor Preferences > General > Miscellaneous > Data Source Folder*. If a level designer forgets to set the *Data Source Folder* preference and imports a file, that file will have an incorrect relative path tthat will most likely not work on other user's checkouts.

### Programmer
A programmer only needs to check out *Game*, which contains all files necessary to play the UE4 game.

## Reference

- [UE4 FBX Content Pipeline](https://docs.unrealengine.com/en-US/Engine/Content/FBX/index.html)
- [Blender FBX](https://docs.blender.org/manual/en/latest/addons/io_scene_fbx.html)
- [glTF Overview](https://www.khronos.org/gltf/)
- [Blender glTF 2.0](https://docs.blender.org/manual/en/latest/addons/io_scene_gltf2.html)
