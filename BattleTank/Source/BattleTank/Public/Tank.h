// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"  // IMP
#include "Tank.generated.h"


/// Forward declarations 
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;




UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 4000; 

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;

    UTankBarrel *Barrel = nullptr; // TODO remove
    float ReloadTimeInSeconds = 3.f;
    double LastFireTime = 0.f;

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // aiming component
    UPROPERTY(BlueprintReadOnly)
    UTankAimingComponent *TankAimingComponent = nullptr;

    // movement component
    UPROPERTY(BlueprintReadOnly)
    UTankMovementComponent *TankMovementComponent = nullptr;


public:	
    // Sets default values for this pawn's properties
    ATank();

    // Fire barrel
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();


    void AimAt(FVector HitLocation);
};
