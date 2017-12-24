// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"





void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    return;
}



// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    auto FirstPlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

    // protect pointers on both AI and player tank 
    if (!ensure(FirstPlayerTank) && !ensure(AimingComponent)) { return; } // even AI tank can be killed and become inoperable in game or vanish completely
    
    // aim / move towards the first player
    AimingComponent->AimAt(FirstPlayerTank->GetActorLocation());    
    MoveToActor(FirstPlayerTank, AcceptanceRadius);

    // TODO fix firing
    AimingComponent->Fire();
}
