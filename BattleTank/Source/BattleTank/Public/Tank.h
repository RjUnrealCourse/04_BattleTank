// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"  // IMP
#include "Tank.generated.h"


/// Forward declarations 
class UTankBarrel;
class UTankTurret;
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

    float ReloadTimeInSeconds = 3.f;
    double LastFireTime = 0.f;

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadWrite, Category = Setup)
    UTankBarrel *Barrel = nullptr; // TODO remove

public:	
    // Sets default values for this pawn's properties
    ATank();

    // Fire barrel
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();
};
