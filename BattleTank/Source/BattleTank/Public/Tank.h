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
    // Sets default values for this pawn's properties
    ATank();    

    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

private:
    UPROPERTY(EditDefaultsOnly, Category="Setup")
    int32 StartingHealth = 100;

    UPROPERTY(EditDefaultsOnly, Category = "Health")
    int32 CurrentHealth = StartingHealth;

};
