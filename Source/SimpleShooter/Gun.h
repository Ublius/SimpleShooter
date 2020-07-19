// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:
/* --< Constructor >-- */
	AGun();

	virtual void Tick(float DeltaTime) override;

/* --< Functions >-- */
	/* --< Actions >-- */
	void PullTrigger();
protected:
	virtual void BeginPlay() override;

private:
/* --< Pointers >-- */
	/* --< UProperties >-- */
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		UParticleSystem* MussleFlash;
	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffect;
	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

/* --< Variables >-- */
	FHitResult HitResult;
	
	/* --< UProperties >-- */
	UPROPERTY(EditAnywhere)
		float MaxRange = 1000;
	UPROPERTY(EditAnywhere)
		float Damage = 10.f;
	
/* --< Functions >-- */
	/* --< Getters >-- */
	AController* GetOwnerController() const; 
	
	/* --< Checks >-- */
	bool GunTrace(FVector& ShotDirection);
};
