// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"



// Forward declarations
class UProjectileMovementComponent;
class UParticleSystemComponent;




UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    void LaunchProjectile(float Speed);

private:
    // Sets default values for this actor's properties
    AProjectile();


    UProjectileMovementComponent *ProjectileMovement = nullptr;

    UPROPERTY(VisibleAnywhere, Category="Setup")
    UStaticMeshComponent *CollisionMesh = nullptr;
	
    UPROPERTY(VisibleAnywhere, Category = "Setup")
    UParticleSystemComponent* LaunchBlast = nullptr;
};
