# Lighting Examples

This example contains a level named Geometry that contains scene geometry used in different lighting
setups.

A Post Processing volume is set around the geometry to give all levels a consistent set of post processing settings.


## LightingScenarios Level
This level demonstrates the use of [Precomputed Lighting Scenarios](https://docs.unrealengine.com/en-us/Engine/Rendering/LightingAndShadows/PrecomputedLightingScenarios),
which allow you to store baked lighting into a special lighting scenario level.

To build the lighting for this level, follow these steps:

1. Open the LightingScenarios level.
2. Open the Levels tab. Under Persistent Level, you should see 3 levels: Geometry, Scenario1_Lighting, and Scenario2_Lighting.
3. Bake lighting. To do this, you must bake lighting for each lighting scenario with only that one lighting scenario visible.
  1. Make Geometry and Scenario1_Lighting visible (the eyeball icon or right click > Visibility)
  2. Make Scenario2_Lighting invisible. If you skip this step the light from Scenario2 will be used, and we don't want that.
  3. Press Build button on toolbar.
  4. When message about hidden levels pops up, choose Yes (NOT Yes All). We want the other lighting scenario levels to be hidden.
  5. Ignore the Rebuild Lighting warning that Scenario2_Lighting will not have lighting rebuilt, this is precisely what we want.
  6. Ignore the MapCheck error about multiple sky lights being active. This is bug [UE-39327](https://issues.unrealengine.com/issue/UE-39327).
  7. Repeat for Scenario2_Lighting.

To test the different lighting scenarios in the editor, make either Scenario1_Lighting or Scenario2_Lighting visible in the Levels tab.
Don't leave both enabled at the same time or the lighting will not be what you expect.

To cycle between lighting scenarios during play, press L.

## Dynamic Lighting

The Dynamic Lighting scene is lit with a Directional Light and SkyLight. A Sky Sphere is used to give the SkyLight something interesting to sample from.


[Distance Field Ambient Occlusion](https://docs.unrealengine.com/en-us/Engine/Rendering/LightingAndShadows/DistanceFieldAmbientOcclusion) is enabled in this
project. To adjust the DFAO, see the settings under the SkyLight actor.

## Eye Adaptation

When you play this scene the HDR visualizer is diplayed and then the intesity of the level's direction light is animated from
120000 lux to 0. The scene uses eye adaptation and the HDR visualizer shows you the exposure compensation that's happening.

This scene is also interesting to use in editor mode. Enable HDR vizualier with `ShowFlag.VisualizeHDR 1` and then scrub around the intensity of
the directional light. You can also play with the Eye Adaptation exposure compensation settings on the Post Processing Volume to see how that
effects the exposure compensation (which the HDR visualizer helps you to understand).

