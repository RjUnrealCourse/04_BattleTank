// Ramachandra Junior.  Copyright 2016. All rights reserved.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"



int32 UTankAimingComponent::GetRoundsLeft() const
{
    return RoundsLeft;
}



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}



void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
    Barrel = BarrelToSet;
    Turret = TurretToSet;
    return;
}



void UTankAimingComponent::BeginPlay()
{
    LastFireTime = FPlatformTime::Seconds();
}



void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
    if (RoundsLeft == 0) 
    {
        FiringState = EFiringState::OutOfAmmo; 
    }
    else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
    {
        FiringState = EFiringState::Reloading;
    }    
    else if (IsBarrelMoving())
    {
        FiringState = EFiringState::Aiming;
    }
    else
    {
        FiringState = EFiringState::Locked;
    }
}



EFiringState UTankAimingComponent::GetFiringState() const
{
    return FiringState;
}



void UTankAimingComponent::AimAt(FVector WorldSpaceAim)
{
    if (! ensure(Barrel) ) { return; }
    
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
        AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(AimDirection);

        auto Time = GetWorld()->GetTimeSeconds();        
        // change turret to match the yaw and barrel to match the pitch 
    }
    else
    {
        auto Time = GetWorld()->GetTimeSeconds();        
    }

    return;
}



void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
    if ( !ensure(Barrel && Turret) ) { return; }

    // Work-out difference between curretn barrel rotation, and AimDirection
    FRotator AimAsRotator = AimDirection.Rotation(); 
    FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
    FRotator DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(DeltaRotator.Pitch);

    // Always Yaw the shortest way
    if (DeltaRotator.Yaw > 180.f) { DeltaRotator.Yaw = 180 - DeltaRotator.Yaw; }
    Turret->Rotate(DeltaRotator.Yaw);
}



bool UTankAimingComponent::IsBarrelMoving()
{
    if (!ensure(Barrel)) { return false; }
    // get tank's forward vector
    auto BarrelForward = Barrel->GetForwardVector();
    return !AimDirection.Equals(BarrelForward, 0.1); // vectors are not equal
}



void UTankAimingComponent::Fire()
{       
    // if reloaded fire!
    if (
        FiringState == EFiringState::Aiming ||
        FiringState == EFiringState::Locked
        ) {

        //UE_LOG(LogTemp, Warning, TEXT("EFiringState loading: %s"), *FiringState.ToString());

        if (!ensure(Barrel) || !ensure(ProjectileBlueprint)) { return; }
        // Spawn a projectile at the socket location on the barrel
        auto Projectile = GetWorld()->SpawnActor<AProjectile>(
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
            );

        Projectile->LaunchProjectile(LaunchSpeed);
        LastFireTime = FPlatformTime::Seconds();

        --RoundsLeft;
    }
}

