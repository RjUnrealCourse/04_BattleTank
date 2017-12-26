// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankTrack.h"



void UTankTrack::BeginPlay()
{
    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpuls, const FHitResult & Hit)
{
    UE_LOG(LogTemp, Warning, TEXT("hit!!"));
}



void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{    
    auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    // work-out the required acceleration this frame to correct
    auto CorrectionAcceleration = - (SlippageSpeed / DeltaTime) * GetRightVector();
    
    auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    if (ensure(TankRoot))
    {        
        // calculate and apply sideways force (F = m a)
        auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks
        TankRoot->AddForce(CorrectionForce);
    }
}



void UTankTrack::SetThrottle(float Throttle)
{    
    
    // calculate force
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivaingforce;
    // get force location
    auto ForceLocation = GetComponentLocation();
    // get to root component
    auto TankRoot = Cast<UPrimitiveComponent> (GetOwner()->GetRootComponent());

    if ( ensure(TankRoot) )
    {           
        TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
    }

    return;
}