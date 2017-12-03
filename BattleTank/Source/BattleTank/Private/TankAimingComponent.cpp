// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
    auto OurTankName = GetOwner()->GetName();
    FVector BarrelLocation{ 0.f };

    // get start location AKA barrel socket
    if (Barrel) { BarrelLocation = Barrel->GetSocketLocation(FName("Projectile")); }

    UE_LOG(LogTemp, Warning, TEXT("Launching at %f"), LaunchSpeed);
}



void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent *BarrelToSet)
{
    Barrel = BarrelToSet;
}




// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

