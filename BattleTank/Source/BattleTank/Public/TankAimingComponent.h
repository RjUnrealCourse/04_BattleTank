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
    void AimAt(FVector WorldSpaceAim, float LaunchSpeed);   
    
    UFUNCTION(BlueprintCallable)
    void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);


protected:
    UPROPERTY(BlueprintReadOnly)
        EFiringStatus FiringStatus = EFiringStatus::Aiming;



private:
    // Sets default values for this component's properties
    UTankAimingComponent();

    UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

};
