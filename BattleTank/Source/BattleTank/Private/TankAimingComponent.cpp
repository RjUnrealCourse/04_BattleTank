// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
    if (!Barrel) { return; }
    
    // get start location AKA barrel socket
    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));


    // calculate out launch velocity
    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
    (
        this,
        OutLaunchVelocity,
        StartLocation,
        WorldSpaceAim,
        LaunchSpeed,
        false,
        0.f,
        0,
        ESuggestProjVelocityTraceOption::DoNotTrace
    );


    if (bHaveAimSolution)
    {
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(AimDirection);

        auto Time = GetWorld()->GetTimeSeconds();        
        // change turret to match the yaw and barrel to match the pitch 
    }
    else
    {
        auto Time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Error, TEXT("%f: [ - ] No solution found!"), Time);
    }

    return;
}



void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
    if (!Barrel) { return; }

    // Work-out difference between curretn barrel rotation, and AimDirection
    FRotator AimAsRotator = AimDirection.Rotation(); 
    FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
    FRotator DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(DeltaRotator.Pitch);
}



void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
    Barrel = BarrelToSet;
}

