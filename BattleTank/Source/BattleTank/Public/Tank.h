// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"


/* Forward declarations */
class UTankBarrel;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    // aiming component
    UTankAimingComponent *TankAimingComponent = nullptr;


public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // sets barrel
    UFUNCTION(BlueprintCallable, Category = Setup) // never end with a semicolon
    void SetBarrelReference(UTankBarrel * BarrelToSet);

    void AimAt(FVector HitLocation);

private:
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; // TODO find sensible
	
};
