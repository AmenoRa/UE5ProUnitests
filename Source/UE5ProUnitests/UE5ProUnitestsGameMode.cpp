// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5ProUnitestsGameMode.h"
#include "UE5ProUnitestsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5ProUnitestsGameMode::AUE5ProUnitestsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
