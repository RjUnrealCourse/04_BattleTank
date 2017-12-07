// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{    
    // calculate force
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivaingforce;
    // get force location
    auto ForceLocation = GetComponentLocation();
    // get to root component
    auto TankRoot = Cast<UPrimitiveComponent> (GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

    return;
}