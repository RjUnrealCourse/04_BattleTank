// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" // IMP
#include "TankAimingComponent.generated.h"



// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 
{
    Reloading,
    Aiming,
    Locked
};



/* Forward declarations */
class UTankBarrel;
class UTankTurret;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	    
    UFUNCTION(BlueprintCallable)
    void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

    void AimAt(FVector WorldSpaceAim);

protected:
    UPROPERTY(BlueprintReadOnly)
    EFiringStatus FiringStatus = EFiringStatus::Aiming;

    // copied from **Tank**
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 4000;


private:
    // Sets default values for this component's properties
    UTankAimingComponent();

    UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

};
