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



ATank * ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
