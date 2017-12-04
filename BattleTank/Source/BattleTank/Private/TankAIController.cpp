// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"





void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank *PossessedTank = GetControlledTank();
    ATank *FirstPlayer = GetPlayerTank();

    if (PossessedTank && FirstPlayer)
    {
        // Do None
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


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    auto FirstPlayerTank = GetPlayerTank();
    auto ControlledTank = GetControlledTank();

    // protecting pointers on both AI and player tank, even AI tank 
    // can be killed and become inoperable in game or vanish completely
    if (FirstPlayerTank && ControlledTank)
    {         
        ControlledTank->AimAt(FirstPlayerTank->GetActorLocation());
        // TPDPD move towards the first player
        // FIRE IF READY
    }
}
