// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "SimpleShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/* --< Classes >-- */
// class AController;

UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()

public:
/* --< Functions >-- */
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
/* --< Functions >-- */
	void EndGame(bool bIsPlayerWinner);
};
