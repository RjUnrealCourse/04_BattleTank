// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

    // TODO clamp actual throttle value so player can't over-drive

    return;
}