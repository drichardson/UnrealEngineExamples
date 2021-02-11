// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class AssetLoadingEditorTarget : TargetRules
{
	public AssetLoadingEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;


        DefaultBuildSettings = BuildSettingsVersion.V2;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

        ExtraModuleNames.AddRange( new string[] { "AssetLoading" } );
	}
}
