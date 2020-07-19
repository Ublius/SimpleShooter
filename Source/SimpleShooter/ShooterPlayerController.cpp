// Fill out your copyright notice in the Description page of Project Settings.

/* --< Includes >-- */
#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HUD = CreateWidget(this, HudClass);
    if(HUD != nullptr)
        HUD->AddToViewport();
}

/* --< Functions >-- */
void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUD->RemoveFromViewport();
    if(bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if(WinScreen != nullptr)
            WinScreen->AddToViewport();
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if(LoseScreen != nullptr)
            LoseScreen->AddToViewport();
    }
        
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

