// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"  // IMP
#include "TankPlayerController.generated.h"

// Forward declarations
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UTankAimingComponent* AimCompRef);


public:
    virtual void Tick(float DeltaTime) override;
    void BeginPlay() override;


private:
    UPROPERTY(EditDefaultsOnly)
    float CrossHairXLocation = 0.5;

    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 1.f/3.f;

    UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000.f;

    /* Start the tank moving the barrel so that a shot would it where  the crosshair intersects the world */
    void AimTowardsCrosshair();

    /* Aiming location from Crosshair POV */
    bool GetSightRayHitLocation(FVector &OutHitLocation) const;
    /* Get camera view rotation */
    bool GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const;    
};
