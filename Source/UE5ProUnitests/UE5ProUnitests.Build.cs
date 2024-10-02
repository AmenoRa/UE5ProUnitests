// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5ProUnitests : ModuleRules
{
	public UE5ProUnitests(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AutomationController" });

		PublicIncludePaths.Add("UE5ProUnitests");
	}
}
