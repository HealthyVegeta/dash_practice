// Copyright Epic Games, Inc. All Rights Reserved.

#include "DashGameMode.h"
#include "DashCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADashGameMode::ADashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
