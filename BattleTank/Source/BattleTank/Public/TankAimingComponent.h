// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" // IMP
#include "TankAimingComponent.generated.h"

/* Forward declarations */
class UTankBarrel;
class UTankTurret;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    void AimAt(FVector WorldSpaceAim, float LaunchSpeed);   
    

    // will be called from tank, needs to be public
    void SetBarrelReference(UTankBarrel * BarrelToSet); 
    void SetTurretReference(UTankTurret * TurretToSet);

protected:
    UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

};
