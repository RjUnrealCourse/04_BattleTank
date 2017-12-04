// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"  // IMP
#include "TankAIController.generated.h"


/// Forward Declaration
class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
    GENERATED_BODY()

private:
    ATank * GetControlledTank() const;

    ATank * GetPlayerTank() const;

public:
    virtual void BeginPlay();	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
