// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Shoot.generated.h"

/* --< Classes >-- */
class AShooterAIController;

UCLASS()
class SIMPLESHOOTER_API UBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
/* --< Constructor >-- */
	UBTTask_Shoot();

protected:
/* --< Functions >-- */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
/* --< Pointers >-- */
	AShooterAIController* AICharacter;
};
