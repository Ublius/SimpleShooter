// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/* --< Classes >-- */
class UBehaviorTree;

UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
/* --< Constructor >-- */
	// AShooterAIController();
	
	virtual void Tick(float DeltaTime) override;

/* --< Functions >-- */
	bool IsDead() const;
	
protected:
	virtual void BeginPlay() override;

private:
/* --< Pointers >-- */
	APawn* PlayerPawn;

	/* --< UProperties >-- */
	UPROPERTY(EditAnywhere)
		UBehaviorTree* AIBehavior;

/* --< Variables >-- */
	/* --< UProperties >-- */
	UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 200.f;

};
