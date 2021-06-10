namespace UnrealBuildTool.Rules
{
	public class BlankPlugin : ModuleRules
	{
		public BlankPlugin(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    "Core",
					"CoreUObject",
				}
				);
		}
	}
}
