using UnrealBuildTool;

public class Plugin : ModuleRules
{
	public Plugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] {
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
            "BlankPlugin",
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UObjectPlugin",
        });
	}
}
