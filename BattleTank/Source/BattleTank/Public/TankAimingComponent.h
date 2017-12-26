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
class AProjectile;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	    
    UFUNCTION(BlueprintCallable)
    void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);
    
    // Fire barrel
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();

    virtual void BeginPlay();

    void AimAt(FVector WorldSpaceAim);


protected:
    UPROPERTY(BlueprintReadOnly)
    EFiringStatus FiringStatus = EFiringStatus::Reloading;


private:
    // copied from **Tank**
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 4000;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;
    
    float ReloadTimeInSeconds = 3.f;
    double LastFireTime = 0.f;


    UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;


    // Sets default values for this component's properties
    UTankAimingComponent();

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

    // add tick component here
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
