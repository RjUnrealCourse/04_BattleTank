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
    void LaunchProjectile(float Speed);

private:
    // Sets default values for this actor's properties
    AProjectile();

    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComponent,
        FVector NormalImpuls,
        const FHitResult& Hit
    );

    UPROPERTY(VisibleAnywhere, Category="Components")
    UStaticMeshComponent *CollisionMesh = nullptr;
	
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent* LaunchBlast = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent* ImpactBlast = nullptr;



    UProjectileMovementComponent *ProjectileMovement = nullptr;
};
