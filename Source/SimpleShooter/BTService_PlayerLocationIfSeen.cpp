// Fill out your copyright notice in the Description page of Project Settings.

/* --< Includes >-- */
#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SimpleShooter/ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = TEXT("Update Player Location If Seen");
}

/* --< Functions >-- */
void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, ::uint8* NodeMemory,
    float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if(PlayerPawn == nullptr)
        return;

    if(OwnerComp.GetAIOwner() == nullptr)
        return;

    if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
    else
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
