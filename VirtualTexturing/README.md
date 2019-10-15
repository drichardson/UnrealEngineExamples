# Virtual Texturing

Demonstration of Streaming Virtual Texturing and Runtime Virtual Texturing, which is new to UE4
in 4.23.

Shows how use runtime virtual texturing to:

- render landscape materials to a virtual texture
- use materials that sample from the landscape's virtual texture to blend into the terrain
- create a decal-like material that renders into the landscape's virtual texture. Note this is not
an actual decal, it is just a static mesh that renders into a virtual texture. The resolution of the
this decal like object is determined by the Runtime Virtual Texture asset's parameters.


## Useful CVARs and commands are:

- `r.VT.Borders 1` to see Streaming Virtual Texture tiles
- `r.VT.Flush` to see changes to previous border command
- `stat virtualtextures`

## See also:

- [Virtual Texturing](https://docs.unrealengine.com/en-US/Engine/Rendering/VirtualTexturing/index.html)

## Troubleshooting
I've had some problems with the RuntimeVirtualTexture level crashing in 4.23. I reported the crash to
Epic. In the meantime, you can try to workaround by trying again (the crash doesn't happen all the time for me)
or by first opening M_PickupLandscape material, moving a node, and hitting save before opening RuntimeVirtualTexturing
level (I have no idea why this would make any difference, but it did for me).
