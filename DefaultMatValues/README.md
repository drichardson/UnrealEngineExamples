# Default Material Values
Test project to compare changes in roughness and specularity to the default material values.

Also used as a test for a custom build of UE4 that changed the default material values set
in Engine\Source\Runtime\Engine\Private\Materials\MaterialShared.cpp:

```c++
Add(FGuid(0x69B8D336, 0x16ED4D49, 0x9AA49729, 0x2F050F7A), TEXT("BaseColor"),     MP_BaseColor,     MCT_Float3, FVector4(0,0,0,0),  SF_Pixel);
Add(FGuid(0x57C3A161, 0x7F064296, 0xB00B24A5, 0xA496F34C), TEXT("Metallic"),      MP_Metallic,      MCT_Float,  FVector4(0,0,0,0),  SF_Pixel);
Add(FGuid(0x9FDAB399, 0x25564CC9, 0x8CD2D572, 0xC12C8FED), TEXT("Specular"),      MP_Specular,      MCT_Float,  FVector4(.5,0,0,0), SF_Pixel);
Add(FGuid(0xD1DD967C, 0x4CAD47D3, 0x9E6346FB, 0x08ECF210), TEXT("Roughness"),     MP_Roughness,     MCT_Float,  FVector4(.5,0,0,0), SF_Pixel);
Add(FGuid(0xB769B54D, 0xD08D4440, 0xABC21BA6, 0xCD27D0E2), TEXT("EmissiveColor"), MP_EmissiveColor, MCT_Float3, FVector4(0,0,0,0),  SF_Pixel);
Add(FGuid(0xB8F50FBA, 0x2A754EC1, 0x9EF672CF, 0xEB27BF51), TEXT("Opacity"),       MP_Opacity,       MCT_Float,  FVector4(1,0,0,0),  SF_Pixel);
Add(FGuid(0x679FFB17, 0x2BB5422C, 0xAD520483, 0x166E0C75), TEXT("OpacityMask"),   MP_OpacityMask,   MCT_Float,  FVector4(1,0,0,0),  SF_Pixel);
Add(FGuid(0x0FA2821A, 0x200F4A4A, 0xB719B789, 0xC1259C64), TEXT("Normal"),        MP_Normal,        MCT_Float3, FVector4(0,0,1,0),  SF_Pixel);

// Advanced attributes
Add(FGuid(0xF905F895, 0xD5814314, 0x916D2434, 0x8C40CE9E), TEXT("WorldPositionOffset"),    MP_WorldPositionOffset,     MCT_Float3,  FVector4(0,0,0,0),  SF_Vertex);
Add(FGuid(0x2091ECA2, 0xB59248EE, 0x8E2CD578, 0xD371926D), TEXT("WorldDisplacement"),      MP_WorldDisplacement,       MCT_Float3,  FVector4(0,0,0,0),  SF_Domain);
Add(FGuid(0xA0119D44, 0xC456450D, 0x9C39C933, 0x1F72D8D1), TEXT("TessellationMultiplier"), MP_TessellationMultiplier,  MCT_Float,   FVector4(1,0,0,0),  SF_Hull);
Add(FGuid(0x5B8FC679, 0x51CE4082, 0x9D777BEE, 0xF4F72C44), TEXT("SubsurfaceColor"),        MP_SubsurfaceColor,         MCT_Float3,  FVector4(1,1,1,0),  SF_Pixel);
Add(FGuid(0x9E502E69, 0x3C8F48FA, 0x94645CFD, 0x28E5428D), TEXT("ClearCoat"),              MP_CustomData0,             MCT_Float,   FVector4(1,0,0,0),  SF_Pixel);
Add(FGuid(0xBE4F2FFD, 0x12FC4296, 0xB0124EEA, 0x12C28D92), TEXT("ClearCoatRoughness"),     MP_CustomData1,             MCT_Float,   FVector4(.1,0,0,0), SF_Pixel);
Add(FGuid(0xE8EBD0AD, 0xB1654CBE, 0xB079C3A8, 0xB39B9F15), TEXT("AmbientOcclusion"),       MP_AmbientOcclusion,        MCT_Float,   FVector4(1,0,0,0),  SF_Pixel);
Add(FGuid(0xD0B0FA03, 0x14D74455, 0xA851BAC5, 0x81A0788B), TEXT("Refraction"),             MP_Refraction,              MCT_Float2,  FVector4(1,0,0,0),  SF_Pixel);
Add(FGuid(0x0AC97EC3, 0xE3D047BA, 0xB610167D, 0xC4D919FF), TEXT("PixelDepthOffset"),       MP_PixelDepthOffset,        MCT_Float,   FVector4(0,0,0,0),  SF_Pixel);
```

Because of some of the materials were created with a custom build of UE4 where Roughness default was set to 0, the default value of one of the materials is non-standard, it is not hooked up but it is completely shiny (roughness 0) rather than standard default roughness (0.5).

[Related UE4 Forum Post](https://forums.unrealengine.com/development-discussion/rendering/60519-default-roughness)
