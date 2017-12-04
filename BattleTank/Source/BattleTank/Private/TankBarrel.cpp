// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
    // Move the barrel the right amount this frame
    // Given a max elevation speed, and the frame time

    // clamp speed
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    
    // clamp the elevation    
    float ClampedElevation = FMath::Clamp<float> (RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
    SetRelativeRotation(FRotator(ClampedElevation, 0, 0));

    return;
    
}


