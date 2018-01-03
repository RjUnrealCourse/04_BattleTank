// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/RadialForceComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" // for GameplayStatics::x
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


    CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
    SetRootComponent((USceneComponent*)CollisionMesh);
    CollisionMesh->SetNotifyRigidBodyCollision(true);
    CollisionMesh->SetVisibility(true); // TODO set to false

    // how to use AttachToComponent
    // bool USceneComponent::AttachToComponent(USceneComponent* Parent, const FAttachmentTransformRules& AttachmentRules, FName SocketName)

    LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
    LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);    
    
    ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
    ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    ImpactBlast->bAutoActivate = false;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    ProjectileMovement->bAutoActivate = false;

    ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
    ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}



// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();	       
    // if projectile hits something then call OnHit.
    CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit); 
}




void AProjectile::OnTimerExpire()
{
    // destroy current projectile actor
    this->Destroy();
    return;
}




void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpuls, const FHitResult & Hit)
{    
    LaunchBlast->Deactivate();
    ImpactBlast->Activate();
    ExplosionForce->FireImpulse();

    // Destroy collision mesh
    SetRootComponent(ImpactBlast); // set primary component before destroy
    CollisionMesh->DestroyComponent();    

    // apply damage to tank
    UGameplayStatics::ApplyRadialDamage(
        this,
        ProjectileDamage, // amount of damage projectile has to do, create this float member first
        GetActorLocation(),
        ExplosionForce->Radius, // for consistancy
        UDamageType::StaticClass(),
        TArray<AActor *>() // damage all actors
    );
        
    // we set timer on the current object and we use the delegate method
    FTimerHandle Timer;
    GetWorld()->GetTimerManager().SetTimer(Timer, this, &AProjectile::OnTimerExpire, DestroyDelay, false);     
}




void AProjectile::LaunchProjectile(float Speed)
{    
    ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
    ProjectileMovement->Activate();
}

