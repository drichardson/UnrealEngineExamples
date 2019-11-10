# Blender Pipeline

Testing out folder structure described by Mike Erwin in
[Blender + Unreal Asset Pipeline Foundations](https://conference.blender.org/2019/presentations/563/).

There are 3 top level repository folders:

- Art
- Inter
- Game

*Art* contains all original art sources, including Blender files.

*Inter* contains all exported art files that can be imported by the game engine, like FBX, gITF, and OBJ.

*Game* contains everything you need to run the game.

An artist might only have *Art* and *Inter* checked out (if their version control system supports it).

A level designer might only have *Inter* and *Game* checked out. When an artist updates exports, the level designer
can reimport the asset in UE4. Since the assets are at the same relative place for every user, the UE4 reimport command works fine (NOTE: Need to verify this works as expected).

A programmer might only have *Game* checked out.
