// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"  // IMP
#include "TankAIController.generated.h"


/// Forward Declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
    GENERATED_BODY()

private:
    virtual void BeginPlay();	
    // Called every frame
    virtual void Tick(float DeltaTime) override;
protected:
    UPROPERTY(EditDefaultsOnly, Category="Setup") // Consider 
    float AcceptanceRadius = 8000;

};
