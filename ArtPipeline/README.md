# Blender Pipeline

Testing out folder structure described by Mike Erwin in
[Blender + Unreal Asset Pipeline Foundations](https://conference.blender.org/2019/presentations/563/).

There are 3 top level repository folders:

- Art
- Inter
- Game

*Art* contains all original art sources, including Blender files.

*Inter* contains all exported art files that can be imported by the game engine, like FBX, glTF, and OBJ.

*Game* contains everything you need to run the game.

An artist might only have *Art* and *Inter* checked out (if their version control system supports it).

A level designer might only have *Inter* and *Game* checked out. When an artist updates exports, the level designer
can reimport the asset in UE4. Since all imported content is stored in *Inter*, a simple *Reimport* can be used by anyone to update to the latest content in *Inter*. Note that the *Data Source Folder* Editor Preference should be set to the *Inter* folder. You can find this preference in *Editor Preferences > General > Miscellaneous > Data Source Folder*.

## Reference

- [UE4 FBX Content Pipeline](https://docs.unrealengine.com/en-US/Engine/Content/FBX/index.html)
- [Blender FBX](https://docs.blender.org/manual/en/latest/addons/io_scene_fbx.html)
- [glTF Overview](https://www.khronos.org/gltf/)
- [Blender glTF 2.0](https://docs.blender.org/manual/en/latest/addons/io_scene_gltf2.html)
