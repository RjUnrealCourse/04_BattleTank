// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    // init
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));    
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


/* Will be called from Blueprints with barrel staticmesh as argument */
void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
    TankAimingComponent->SetBarrelReference(BarrelToSet);
}



/* Will be called from Blueprints with turret staticmesh as argument */
void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
    TankAimingComponent->SetTurretReference(TurretToSet);
}



void ATank::AimAt(FVector HitLocation)
{
    if (TankAimingComponent) { TankAimingComponent->AimAt(HitLocation, LaunchSpeed); }    
    return;
}


void ATank::Fire()
{
    UE_LOG(LogTemp, Warning, TEXT("Fire is called!"));
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

