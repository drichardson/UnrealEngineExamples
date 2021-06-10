namespace UnrealBuildTool.Rules
{
	public class UObjectPlugin : ModuleRules
	{
		public UObjectPlugin(ReadOnlyTargetRules Target) : base(Target)
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
