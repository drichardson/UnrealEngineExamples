# Houdini Landscape Test
This UE4 project is a test for referencing UE4 Physical Materials from a
Houdini HDA generated landscape. The code for this is implemented in a [branch of
the UE4 Houdini Engine plugin](https://github.com/drichardson/HoudiniEngineForUnreal/tree/landscape-layerinfo-physicsmaterial).

## To Test
1. Install the Houdini Engine plugin at the above link.
2. Open HoudiniLandscapeTest.uproject
3. Drag in the landscape houdini asset from the UE4 Content browser into the TestMap level.
4. After import, view the landscape layer infos that are created. One of them should be set to PM_Dirt, one of them should be set to PM_Snow, and the other should be set to None.

## Setting the Landscape Layer Info's Physical Material in Houdini

See landscape.hdalc for the full example.

Create a primitive string attribute named `unreal_landscape_layer_physical_material` for the layer you want to add a physical
material to. The value of the attribute should be a string reference to the physical material in UE4.

Here's an example Attribute Create node in Houdini:

![Attribute Create](https://github.com/drichardson/UE4Examples/blob/master/HoudiniLandscapeTest/attributes.png)

Here's what the Geometry Spreadsheet should look like after you've set two different physical materials on two different layers:

![Geometry Spreadhsheet](https://github.com/drichardson/UE4Examples/blob/master/HoudiniLandscapeTest/geometry_spreadsheet.png)

Here's what the layer info should look like with a physical material set:

![Layer Info with Physical Material Set](https://github.com/drichardson/UE4Examples/blob/master/HoudiniLandscapeTest/layer_info.png)

