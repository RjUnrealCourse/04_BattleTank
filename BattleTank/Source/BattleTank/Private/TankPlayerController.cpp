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

    UE_LOG(LogTemp, Warning, TEXT("Aim towards cross hair"));
    // Get world location if linetrace throught cross hair
    // if it hits the landscape
        // Tell controlled tank to aim at this point
}