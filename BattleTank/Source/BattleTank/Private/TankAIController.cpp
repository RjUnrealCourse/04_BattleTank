// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank *PossessedTank = GetControlledTank();
    ATank *FirstPlayer = GetPlayerTank();

    if (PossessedTank && FirstPlayer)
    {
        UE_LOG(LogTemp, Warning, TEXT("[ + ] AI found first player tank"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[ - ] player controller not possessing tank"));
    }


    return;
}



ATank * ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}



ATank * ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    if (PlayerPawn) { return Cast<ATank>(PlayerPawn); }
    else { return nullptr; }
}
