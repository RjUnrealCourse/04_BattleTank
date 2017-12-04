// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    // Move the Turret the right amount this frame
    // Given a max Azimuth speed, and the frame time

    // clamp speed
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

    // Set the rotation of turret
    SetRelativeRotation(FRotator(0, RawNewRotation, 0));

    return;

}
