// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"  // IMP
#include "Tank.generated.h"



UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:	    
    // returns current health as a percentage of starting health, between 0 and 1
    UFUNCTION(BlueprintPure, Category = "Setup")    
    float GetHealthPercent() const;

    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

private:
    // Sets default values for this pawn's properties
    ATank();

    UPROPERTY(EditDefaultsOnly, Category="Setup")
    int32 StartingHealth = 100;

    UPROPERTY(EditDefaultsOnly, Category = "Health")
    int32 CurrentHealth = StartingHealth;

};
