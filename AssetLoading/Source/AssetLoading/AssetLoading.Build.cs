// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class AssetLoading : ModuleRules
{
    public AssetLoading(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[] {
                "ApplicationCore",
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "Slate",
                "SlateCore",
                });


        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                    "UnrealEd",
                    });
        }
    }
}
