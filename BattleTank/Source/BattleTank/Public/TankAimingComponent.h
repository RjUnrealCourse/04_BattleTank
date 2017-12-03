// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

/* Forward declarations */
class UTankBarrel;




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
    void AimAt(FVector WorldSpaceAim, float LaunchSpeed);   

    // TODO Add SetTurretReference later

    void SetBarrelReference(UTankBarrel * BarrelToSet); // will be called frwom tank, needs to be public

protected:
    UTankBarrel *Barrel = nullptr;

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

};
