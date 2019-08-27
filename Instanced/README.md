# Instanced
Test differences between [UStaticMeshComponent](https://api.unrealengine.com/INT/API/Runtime/Engine/Components/UStaticMeshComponent/index.html)
and
[UInstancedStaticMeshComponent](https://api.unrealengine.com/INT/API/Runtime/Engine/Components/UInstancedStaticMeshComponent/index.html)

Open InstancedTest map and then play with the Divisions parameter on the BP_CubeVolumeSpawner actor (set to something between 1 and 30...
though note anything over 16 takes a while for the construction script to complete). When monitor rendering stats when the Instanced
parameter is enabled and disabled.

Run `stat rhi` in the console to see DrawPrimitive calls. When Instanced is used, far fewer calls are made to DrawPrimitive. If you are viewing in PIE (Play In Editor), make sure BP_CubeVolumeSpawner is not selected while looking at stats because the outline rendered creates extra rendering work.
