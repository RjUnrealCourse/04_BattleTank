// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void Tick(float DeltaTime) override;
    void BeginPlay() override;


private:
    UPROPERTY(EditAnywhere)
    float CrossHairXLocation = 0.5;

    UPROPERTY(EditAnywhere)
    float CrossHairYLocation = 1.f/3.f;

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.f;


    ATank * GetControlledTank() const;

    /* Start the tank moving the barrel so that a shot would it where  the crosshair intersects the world */
    void AimTowardsCrosshair();

    /* Aiming location from Crosshair POV */
    bool GetSightRayHitLocation(FVector &OutHitLocation) const;
    /* Get camera view rotation */
    bool GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;    
};
