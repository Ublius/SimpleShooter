// Fill out your copyright notice in the Description page of Project Settings.

/* --< Includes >-- */
#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


/* --< Defines >-- */
#define OUT

/* --< Constructor >-- */
AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/* --< Functions >-- */
	/* --< Getters >-- */
AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(OwnerPawn == nullptr) { return nullptr; }

	return OwnerPawn->GetController();
}

	/* --< Checks >-- */
bool AGun::GunTrace(FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if(!OwnerController) { return false; }
	
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;
	FCollisionQueryParams QueryParams;
	
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(GetOwner());
	
	OwnerController->GetPlayerViewPoint(OUT PlayerViewLocation, OUT PlayerViewRotation);
	ShotDirection = -PlayerViewRotation.Vector();
	
	FVector EndPoint = PlayerViewLocation + PlayerViewRotation.Vector() * MaxRange;
	return GetWorld()->LineTraceSingleByChannel(OUT HitResult, PlayerViewLocation, EndPoint, ECC_GameTraceChannel1, QueryParams);
}

	/* --< Actions >-- */
void AGun::PullTrigger()
{
	AController* OwnerController = GetOwnerController();
	FVector ShotDirection;
	bool bHit = GunTrace(ShotDirection);

	UGameplayStatics::SpawnEmitterAttached(MussleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	if(bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactEffect, HitResult.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, HitResult.Location);

		if(HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, HitResult, ShotDirection, nullptr);
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}
}

