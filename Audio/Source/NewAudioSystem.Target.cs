using UnrealBuildTool;
using System.Collections.Generic;

public class NewAudioSystemTarget : TargetRules
{
	public NewAudioSystemTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "NewAudioSystem" } );
	}
}
