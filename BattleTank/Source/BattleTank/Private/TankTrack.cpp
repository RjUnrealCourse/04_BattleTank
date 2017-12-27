// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankTrack.h"



UTankTrack::UTankTrack()
{
    PrimaryComponentTick.bCanEverTick = false;
}



void UTankTrack::BeginPlay()
{
    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}



void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpuls, const FHitResult & Hit)
{
    // Drive the tracks
    ApplySidewaysForce();
}



void UTankTrack::ApplySidewaysForce()
{
    auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());


    // work-out the required acceleration this frame to correct
    auto DeltaTime = GetWorld()->GetDeltaSeconds();
    auto CorrectionAcceleration = -(SlippageSpeed / DeltaTime) * GetRightVector();

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
    CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
    DriveTrack();
    CurrentThrottle = 0;
}



void UTankTrack::DriveTrack()
{
    // calculate force
    auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivaingforce;
    // get force location
    auto ForceLocation = GetComponentLocation();
    // get to root component
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    if (ensure(TankRoot))
    {
        TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
    }
}
