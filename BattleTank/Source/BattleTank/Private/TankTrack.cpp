// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
    // TODO clamp actual throttle value so player can't over-drive    
    // calculate force
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivaingforce;
    // get force location
    auto ForceLocation = GetComponentLocation();
    // get to root component
    auto TankRoot = Cast<UPrimitiveComponent> (GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

    return;
}