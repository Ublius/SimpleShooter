// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/* --< Includes >-- */
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

/* --< Classes >-- */
class UCameraComponent;
class USpringArmComponent;
class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
/* --< Constructor >-- */
	AShooterCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

/* --< Functions >-- */
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &ADamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	/* --< Actions >-- */
	void Shoot();
	
	/* --< UFunctions >-- */
		/* --< Getters >-- */
	UFUNCTION(BlueprintPure)
    float GetHealthPercent() const;
	
		/* --< Checks >-- */
	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	
protected:
	virtual void BeginPlay() override;

private:
/* --< Pointers >-- */
	/* --< UProperties >-- */
	UPROPERTY(EditAnywhere, Category = "Components")
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category = "Components")
		UCameraComponent* Camera;
	UPROPERTY()
		AGun* Gun;
	
/* --< Variables >-- */ 
	/* --< UProperties >-- */
	UPROPERTY(EditDefaultsOnly, Category = "Health", meta = (AllowPrivateAccess = "true"))
		float MaxHealth  = 100;
	UPROPERTY(VisibleAnywhere)
		float Health;
	UPROPERTY(EditAnywhere)
		float RotationRate = 70;
	UPROPERTY(EditDefaultsOnly)
        TSubclassOf<AGun> GunClass;
	
/* --< Functions >-- */
	/* --< Movement >-- */
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	
	/* --< Rotation >-- */
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);


};