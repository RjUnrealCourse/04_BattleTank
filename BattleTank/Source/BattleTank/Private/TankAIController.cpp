// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"





void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    return;
}



// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    auto FirstPlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());

    // protect pointers on both AI and player tank 
    if (FirstPlayerTank && ControlledTank) // even AI tank can be killed and become inoperable in game or vanish completely
    {   
        ControlledTank->AimAt(FirstPlayerTank->GetActorLocation());
        // aim / move towards the first player
        MoveToActor(FirstPlayerTank, AcceptanceRadius);
        // FIRE IF READY
        ControlledTank->Fire();
    }
}
