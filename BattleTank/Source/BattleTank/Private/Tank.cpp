// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankTurret.h"
#include "Projectile.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;    

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("67714f27: ATank - ATank constructor called!"));
    }
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("67714f27: ATank - Begin play called!"));
    }
}




void ATank::AimAt(FVector HitLocation)
{
    if (! ensure(TankAimingComponent) ) { return; }
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);    
}



void ATank::Fire()
{
    if ( !ensure(Barrel && ProjectileBlueprint) ) { return; }

    bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

    // if reloaded fire!
    if (bIsReloaded)
    {
        // Spawn a projectile at the socket location on the barrel
        auto Projectile = GetWorld()->SpawnActor<AProjectile>(
            ProjectileBlueprint,
            Barrel->GetSocketLocation(FName("Projectile")),
            Barrel->GetSocketRotation(FName("Projectile"))
        );

        Projectile->LaunchProjectile(LaunchSpeed);
        LastFireTime = FPlatformTime::Seconds();
    }
    else 
    { /*UE_LOG(LogTemp, Warning, TEXT("[ %f ] [ %s ] Reloading barrel . . ."), GetWorld()->GetTimeSeconds(), *GetName());*/ }
}
