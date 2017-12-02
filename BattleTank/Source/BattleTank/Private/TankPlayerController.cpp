// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ATank *PossessedTank = GetControlledTank();

    if (PossessedTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("[ + ] player possessed tank: %s"), *PossessedTank->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[ - ] player controller not possessing tank"));
    }
    
    return;
}



void ATankPlayerController::Tick(float DeltaTime)
{
    // Super
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();    
}





ATank * ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}




void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }    

    FVector HitLocation; // Out parameter
    
    // Get world location if linetrace throught cross hair
    if (GetSightRayHitLocation(HitLocation))
    {
        // if it hits the landscape
        // TODO Tell controlled tank to aim at this point
        //GetControlledTank()->AimAt(HitLocation);
        UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
    }
}




bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
    OutHitLocation = FVector(1.0);
    // Get direction we're looking at

    // send linetrace in that direction
    // return hit location if trace successful
    return true ;
}
