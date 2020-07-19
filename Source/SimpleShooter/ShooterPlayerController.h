// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/* --< Classes >-- */
class UUserWidget;

UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
/* --< Functions >-- */
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

protected:
	virtual void BeginPlay() override;
	
private:
/* --< Pointers >-- */
		UUserWidget* HUD;
	
/* --< Variables >-- */
	FTimerHandle RestartTimer;
	
	/* --< UProperties >-- */
	UPROPERTY(EditAnywhere)
		float RestartDelay = 5.f;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> HudClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> LoseScreenClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WinScreenClass;

};
