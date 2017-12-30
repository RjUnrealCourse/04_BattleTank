// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" // IMP
#include "TankAimingComponent.generated.h"



// Enum for aiming state
UENUM()
enum class EFiringState : uint8 
{
    Reloading,
    Aiming,
    Locked,
    OutOfAmmo
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
    EFiringState GetFiringState() const;


protected:
    UPROPERTY(BlueprintReadOnly)
    EFiringState FiringState = EFiringState::Reloading;
    
    // Get number of rounds left to show on screen
    UFUNCTION(BlueprintCallable, Category = Firing)
    int32 GetRoundsLeft() const;



private:
    // Sets default values for this component's properties
    UTankAimingComponent();

    void MoveBarrelTowards(FVector AimDirection); // TODO move to private

    // add tick component here
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
    
    bool IsBarrelMoving();
    
    // copied from **Tank**
    UPROPERTY(EditDefaultsOnly, Category="Firing")
    float LaunchSpeed = 4000;

    UPROPERTY(EditDefaultsOnly, Category="Firing")
    float ReloadTimeInSeconds = 3.f;

    UPROPERTY(EditDefaultsOnly, Category="Firing")
    // Number of rounds left in the tank
    int32 RoundsLeft = 3;

    UPROPERTY(EditDefaultsOnly, Category="Setup")
    TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;
    
    double LastFireTime = 0.f;
    FVector AimDirection = FVector(0.f); // we get this from AimAt() and we save as a member
    
    UTankBarrel *Barrel = nullptr;
    UTankTurret *Turret = nullptr;
};
