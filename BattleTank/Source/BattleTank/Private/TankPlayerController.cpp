// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Engine/World.h"



void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();

    if (AimingComponent)
    {
        FoundAimingComponent(AimingComponent);
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    AimTowardsCrosshair();    
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if ( !ensure(GetControlledTank()) ) { return; }    

    FVector HitLocation; // Out parameter    
    if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
    {        
        // TODO Tell controlled tank to aim at this point     
        GetControlledTank()->FindComponentByClass<UTankAimingComponent>()->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{   
    // Find the cross hair postition
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

    // "De-project" the screen position of the crosshair to a world direction    
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {        
        // Line-trace along that look direction, and see what we hit (up to max range)
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }

    return true;
}



bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation;

    if (PlayerCameraManager) { StartLocation = PlayerCameraManager->GetCameraLocation(); }
    
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(
        HitResult,
        StartLocation,
        EndLocation,
        ECollisionChannel::ECC_Visibility)
      )
    { 
        OutHitLocation = HitResult.Location;
        return true;
    }
    OutHitLocation = FVector(0);
    return false; // Line trace didn't succeed
}

/** 
 * "De-project" the screen position of the crosshair to a world direction
 */
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{    
    FVector CameraWorldLocation; // To be discarded
    return DeprojectScreenPositionToWorld(
        ScreenLocation.X,
        ScreenLocation.Y,
        CameraWorldLocation,
        OutLookDirection
    );     
}


