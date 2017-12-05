// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"  // IMP
#include "Tank.generated.h"


/// Forward declarations 
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;




UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 100000; // TODO find sensible

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;

    UTankBarrel *Barrel = nullptr;
    float ReloadTimeInSeconds = 3.f;
    double LastFireTime = 0.f;

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // aiming component
    UTankAimingComponent *TankAimingComponent = nullptr;


public:	
    // Sets default values for this pawn's properties
    ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // sets barrel
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel * BarrelToSet);

    // sets turret
    UFUNCTION(BlueprintCallable, Category = Setup) 
    void SetTurretReference(UTankTurret * TurretToSet);

    // Fire barrel
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();

    void AimAt(FVector HitLocation);
};
