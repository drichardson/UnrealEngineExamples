# HoudiniEngine Example

Experiments with HoudiniEngine for Unreal.

- Using Houdini packed primitives to do instanced drawing in UE4
- Scattering packed primitives over meshes and landscapes

## Setup

Make sure you have the HoudiniEngine plugin installed.

If you don't, you can also pull a version from the [sideeffects/HoudiniEngineForUnreal](https://github.com/sideeffects/HoudiniEngineForUnreal) git repository, but you'll need to make sure you get a version of it that is compatible with the version of Houdini you have installed.  

For my own testing, I use a submodule that I update whenever I change Houdini versions, which you can get with:

  git submodule update --init --recursive

This custom version of HoudiniEngineForUnreal should match your installed version of Houdini.

If you use this submodule, I *think* it will take precedence over the HoudiniEngine plugin you installed with the Houdini installer (though I didn't verify that).

## See Also

* [Houdini Engine for Unreal](https://www.sidefx.com/docs/unreal/)
