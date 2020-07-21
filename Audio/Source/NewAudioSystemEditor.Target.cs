using UnrealBuildTool;
using System.Collections.Generic;

public class NewAudioSystemEditorTarget : TargetRules
{
	public NewAudioSystemEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "NewAudioSystem" } );
	}
}
