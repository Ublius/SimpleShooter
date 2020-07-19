// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGameModeBase.generated.h"


UCLASS()
class SIMPLESHOOTER_API ASimpleShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
/* --< Functions >-- */
	virtual void PawnKilled(APawn* PawnKilled);
};
